/*
 * Exceptions.h
 *
 *  Created on: 2010-1-8
 *      Author: baritono
 */

#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_

#include <deque>
#include <string>
#include <vector>
#include <mU/Var.h>

namespace mU
{
#define TAG(x) tag_##x

	// common property tags
	API var TAG(general), TAG(error), TAG(usage), TAG(argx), TAG(argt), TAG(argr), TAG(argrx), TAG(argb), TAG(argbu);
	API var TAG(nonopt), TAG(opttf), TAG(level), TAG(optx), TAG(atomicx);

	API std::stack<var> CprocSymbolStack;

	class Exception
	{
	public:
		Exception() {}

	};

	class ParserException : public Exception
	{

	};

	class UnexpectedTokenException : public ParserException
	{

	};

	class MoreInputNeededException : public ParserException
	{

	};

	class RuntimeException : public Exception
	{

	};

	class LogicError : public Exception
	{
	public:
		LogicError() {}
		LogicError(const std::wstring &msg)
			: symbol_(CprocSymbolStack.top()), tag_(TAG(error)), args_(Vec(Str(msg))) 
		{
		}
		LogicError(Var symbol, Var tag, Var args) : symbol_(symbol), tag_(tag), args_(args) {}

		var symbol() const { return symbol_; }
		var tag() const { return tag_; }
		var args() const { return args_; }
	private:
		var symbol_;
		var tag_;
		var args_;
	};

	class IllegalArgumentError : public LogicError
	{
	public:
		IllegalArgumentError() {}
		IllegalArgumentError(const std::wstring &msg) : LogicError(msg) {}
	};

	class UnrecognizedOptionError : public LogicError
	{
	public:
		UnrecognizedOptionError(Var args, Var offender)
			: LogicError(CprocSymbolStack.top(), TAG(optx), 
							Vec(offender, Ex(CprocSymbolStack.top(), args)))
		{

		}
	};

	class OptionsExpectedError : public LogicError
	{
	public:
		OptionsExpectedError(Var args, std::size_t offender_index, std::size_t start)
			: LogicError(CprocSymbolStack.top(), TAG(nonopt), 
							Vec(At(args, offender_index), 
								Int(static_cast<mU::uint>(start)),
								Ex(CprocSymbolStack.top(), args)))
		{
		}
	};

	class IllFormedLevelSpecError : public LogicError
	{
	public:
		IllFormedLevelSpecError(Var spec)
			: LogicError(CprocSymbolStack.top(), TAG(level), Vec(spec))
		{

		}
	};

	class BooleanOptionValueError : public LogicError
	{
	public:
		BooleanOptionValueError(Var option, Var value)
			: LogicError(CprocSymbolStack.top(), TAG(opttf), Vec(option, value))
		{

		}
	};

	class UserException : public Exception
	{
	private:
		var value_;
		var tag_;
	public:
		UserException(var value, var tag = 0) : value_(value), tag_(tag) {}

		var value() { return value_; }
		var tag() { return tag_; }
	};

	class IOException : public RuntimeException
	{

	};

	class InvalidCodePointException : public RuntimeException
	{

	};

	class InvalidUtf8StreamException : public InvalidCodePointException
	{

	};

	class UnsupportedCharacterException : public RuntimeException
	{

	};

#define OS_API_CALL(api_func, ...) api_func(__VA_ARGS__)
#define OS_API_CALL_R(r, api_func, ...) r = api_func(__VA_ARGS__)
}

#endif /* EXCEPTIONS_H_ */
