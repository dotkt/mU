#include <mU/Number.h>
#include <mU/String.h>
#include <mU/Pattern.h>
#include <mU/Kernel.h>
#include <mU/Exceptions.h>

namespace mU {
//////////////////////////////////////
unordered_set<Var> TraceRuleSymbols;

std::stack<var> CprocSymbolStack;

namespace {

var EvalSym(Var symbol)
{
	map_t::const_iterator iter = OwnValues.find(symbol);
	if (iter != OwnValues.end() && iter->second != symbol)
	{
		if (TraceRuleSymbols.count(symbol) != 0)
		{
			// FIXME: rewrite this after we implement the kernel message infrastructure
			Print(symbol);
			wcout << "::tracer : ";
			Print(symbol);
			wcout << "=";
			Print(iter->second);
			wcout << "\n";
		}
		return Eval(iter->second);
	}
	else
		return symbol;
}

var FlattenSequence(Var vector, bool evaluate)
{
	size_t n = Size(vector);
	var r = Vec();
	Reserve(r,n);
	for(size_t i = 0; i < n; ++i)
	{
		var c = evaluate ? Eval(At(vector, i)) : At(vector, i);
		if(ExQ(c,TAG(Sequence)))
			CVec(r).insert(
			CVec(r).end(),
			CVec(Body(c)).begin(),
			CVec(Body(c)).end());
		else
			Push(r,c);
	}
	return r;
}

var EvalVec(Var vector)
{
	return FlattenSequence(vector, true);
}

bool SearchFactValues(var &result, var head, var body)
{
	std::map<Var,dict_t>::const_iterator
		iter = FactValues.find(head);
	if(iter != FactValues.end())
	{
		dict_t::const_iterator
			iter2 = iter->second.find(body);
		if (Verbose >= 2) {
			wcerr << _W("Search factvalue for ");
			Println(Ex(head, body), wcerr);
		}
		if(iter2 != iter->second.end())
		{
			if (TraceRuleSymbols.count(head) != 0)
			{
				// FIXME: rewrite this after we implement the kernel message infrastructure
				Print(head);
				wcout << "::tracer : ";
				Print(Ex(head, body));
				wcout << " :> ";
				Print(iter2->second);
				wcout << "\n";
			}
			if (Verbose >= 2) {
				wcerr << _W("# Try ");
				Println(iter2->second, wcerr);
			}
			result = Eval(iter2->second);
			if (Verbose >= 2) {
				wcerr << _W("Result is ");
				Println(result, wcerr);
			}
			return true;
		}
	}
	return false;
}

bool SearchDownValues(var &result, var head, var body)
{
	std::map<Var,def_t>::const_iterator
		iter = DownValues.find(head);
	if(iter != DownValues.end())
	{
		const def_t &definitions = iter->second;
		if (Verbose >= 2) {
			wcerr << _W("Search downvalue for ");
			Println(Ex(head, body), wcerr);
		}
		if (definitions.is_vec()) {
			def_t::vec_t::const_iterator
				iter2 = definitions.vec->begin();
			while(iter2 != definitions.vec->end())
			{
				if (Verbose >= 2) {
					wcerr << _W("# Try ");
					Print(iter2->first);
					wcerr << _W(" :> ");
					Print(iter2->second.second);
					wcerr << std::endl;
				}
				map_t m;
				if(MatchQ(m,iter2->second.first,body))
				{
					if (TraceRuleSymbols.count(head) != 0)
					{
						// FIXME: rewrite this after we implement the kernel message infrastructure
						Print(head);
						wcout << _W("::tracer : ");
						Print(Ex(head, body));
						wcout << _W(" :> ");
						Print(iter2->second.second);
						wcout << "\n";
					}
					result = Eval(Subs(m,iter2->second.second));
					if (ExQ(result, TAG(Condition))) {
						++iter2;
						continue;
					}
					if (Verbose >= 2) {
						wcerr << _W("Result is ");
						Println(result, wcerr);
					}
					return true;
				}
				++iter2;
			}
		} else {
			def_t::map_t::const_iterator
				iter2 = definitions.map->begin();
			if (Verbose >= 2) {
				wcerr << _W("Search downvalue for ");
				Println(Ex(head, body), wcerr);
			}
			while(iter2 != definitions.map->end())
			{
				if (Verbose >= 2) {
					wcerr << _W("# Try ");
					Print(iter2->first);
					wcout << _W(" :> ");
					Print(iter2->second.second);
					wcout << std::endl;
				}
				map_t m;
				if(MatchQ(m,iter2->second.first,body))
				{
					if (TraceRuleSymbols.count(head) != 0)
					{
						// FIXME: rewrite this after we implement the kernel message infrastructure
						Print(head);
						wcout << _W("::tracer : ");
						Print(Ex(head, body));
						wcout << _W(" :> ");
						Print(iter2->second.second);
						wcout << "\n";
					}
					result = Eval(Subs(m,iter2->second.second));
					if (ExQ(result, TAG(Condition))) {
						++iter2;
						continue;
					}
					if (Verbose >= 2) {
						wcerr << _W("Result is ");
						Println(result, wcerr);
					}
					return true;
				}
				++iter2;
			}
		}
	}
	return false;
}

namespace
{
	class PushCProcSymbol
	{
	public:
		PushCProcSymbol(Var symbol) { CprocSymbolStack.push(symbol); }
		~PushCProcSymbol() { CprocSymbolStack.pop(); }
	};
}

bool SearchCProcs(var &result, var head, var body)
{
	unordered_map<Var,CProc>::const_iterator
		iter = CProcs.find(head);
	if(iter != CProcs.end())
	{
		PushCProcSymbol pcs(head);
		if (Verbose >= 3) {
			wcerr << _W("Enter cproc for ");
			Println(Ex(head, body), wcerr);
		}
		try {
			result = iter->second(body);
		}
// 		catch (std::exception& e) {
// 			wcerr << L"std::exception thrown: " << mbs2wcs(e.what()) << std::endl;
// 			wcerr << "CProc error while eval ";
// 			Println(Ex(head, body), wcerr);
// 			return false;
// 		}
		catch (...) {
			wcerr << "CProc error while eval ";
			Println(Ex(head, body), wcerr);
			throw;
		}
		if (result)
		{
			if (TraceRuleSymbols.count(head) != 0)
			{
				// FIXME: rewrite this after we implement the kernel message infrastructure
				Print(head);
				wcout << _W("::tracer : ");
				Print(Ex(head, body));
				wcout << _W(" :> ");
				Println(result);
			}
			if (Verbose >= 3) {
				wcerr << _W("Result is ");
				Println(result, wcerr);
			}
			return true;
		}
	}
	return false;
}

bool SearchSubValues(var &result, var head, var body)
{
	std::map<Var,def_t>::const_iterator
		iter = SubValues.find(Head(head));
	if(iter != SubValues.end())
	{
		const def_t &definitions = iter->second;
		if (definitions.is_vec()) {
			def_t::vec_t::const_iterator
				iter2 = definitions.vec->begin();
			var t = Vec(Body(head),body);
			while(iter2 != definitions.vec->end())
			{
				map_t m;
				if(MatchQ(m,iter2->second.first,t))
				{
					result = Eval(Subs(m,iter2->second.second));
					return true;
				}
				++iter2;
			}
		} else {
			def_t::map_t::const_iterator
				iter2 = definitions.map->begin();
			var t = Vec(Body(head),body);
			while(iter2 != definitions.map->end())
			{
				map_t m;
				if(MatchQ(m,iter2->second.first,t))
				{
					result = Eval(Subs(m,iter2->second.second));
					return true;
				}
				++iter2;
			}
		}
		
	}
	return false;
}

bool SearchCOpers(var &result, var head, var body)
{
	unordered_map<Var,COper>::const_iterator
		iter = COpers.find(Head(head));
	if(iter != COpers.end())
	{
		try {
			result = iter->second(Body(head),body);
		}
		catch (...) {
			wcerr << "COper error while eval ";
			Println(Ex(head, body), wcerr);
			throw;
		}
		if (result)
		{
			return true;
		}
	}
	return false;
}

bool HandleAttributes(var &result, Var expression, const attr_t &attributes,
						var head, var &body)
{
	if(attributes.count(SequenceHold))
	{
		body = Body(expression);
	}
	else
	{
		body = FlattenSequence(Body(expression), false);
	}
	size_t n = Size(body);
	// FIXME: in mathematica, OneIdentity means "x == f[x]" only for PATTERN MATCHING purposes
// 	if(n == 1 && attributes.count(OneIdentity))
// 	{
// 		result = Eval(At(body,0));
// 		return true;
// 	}
	if(!attributes.count(HoldAll))
	{
		if(n > 0 && !attributes.count(HoldFirst))
			At(body,0) = Eval(At(body,0));
		if(n > 1 && !attributes.count(HoldRest))
			for(size_t i = 1; i < n; ++i)
				At(body,i) = Eval(At(body,i));
	}
	if(attributes.count(Listable))
	{
		// TODO: handle the case where all list must be of same length, e.g. CoprimeQ
		var t = Thread(head,body);
		if(t)
		{
			result = Eval(t);
			return true;
		}
	}
	if(attributes.count(Flat))
	{
		var t = body;
		body = Vec();
		Reserve(body,n);
		Flatten(body,head,t);
	}
	if(attributes.count(Orderless))
		Sort(body);

	return false;
}

var EvalEx(Var expression)
{
	var head = Eval(Head(expression));
	var body;
	var result;
	if(SymQ(head))
	{
		std::map<Var,attr_t>::const_iterator
			iter = Attributes.find(head);
		if(iter != Attributes.end())
		{
			if (HandleAttributes(result, expression, iter->second, head, body))
			{
				return result;
			}
		}
		else
		{
			body = Eval(Body(expression));
		}

		if (SearchFactValues(result, head, body))
		{
			return result;
		}

		if (SearchDownValues(result, head, body))
		{
			return result;
		}

		if (SearchCProcs(result, head, body))
		{
			return result;
		}
	}
	else
	{
		body = Eval(Body(expression));

		if(ExQ(head) && SymQ(Head(head)))
		{
			if (SearchSubValues(result, head, body))
			{
				return result;
			}

			if (SearchCOpers(result, head, body))
			{
				return result;
			}
		}
	}
	return Ex(head,body);
}

}

var Eval(Var x)
{
	switch(Type(x))
	{
	case TYPE(obj):
	case TYPE(int):
	case TYPE(rat):
	case TYPE(flt):
	case TYPE(str):
		return x;
	case TYPE(sym):
		return EvalSym(x);
	case TYPE(vec):
		return EvalVec(x);
	case TYPE(ex):
		return EvalEx(x);
	default:
		//assert(false);		// TODO: �������
		return Null;
	}
}
//////////////////////////////////////
}
