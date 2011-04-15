/**
\file
\brief ��ϵ��һԪ����ʽ���ӷֽ�
\todo �ر�أ�Ҫ���ϲ���Լ�Եļ�⣬���ٷֽ�����x^10000-2; x^n-1�Ͷ���ʽ�ķֽ�
*/
#include "common.h"

namespace mU {

namespace{

}

/**
\brief ��ϵ������ʽ���ӷֽ�.
\param f ��ϵ��һԪ����ʽ.
\return f�ķֽ���.
*/
var UniFacZ(Var f)
{
	var result=Vec();
	poly_z fz;
	std::vector<poly_z> faclist;
	std::vector<uint> exponents;
	var b = Int();
	to_poly_z(fz,f);
	UniFacZ(fz,CInt(b),faclist,exponents);
	Push(result,b);
	var factor;
	for(size_t i=0;i<faclist.size();i++)
	{
		factor=Vec();
		from_poly_z(factor,faclist[i]);
		Push(result,Vec(factor,Int(exponents[i])));
	}
	clear_poly_z_list(faclist);
	return result;
}

var UniFacZp(Var f,Var p)
{
	var result=Vec();
	poly_z fz;
	std::vector<poly_z> faclist;
	std::vector<uint> exponents;
	static mpz_t p_z;
	mpz_init(p_z);
	mpz_set(p_z,CInt(p));
	var b = Int();
	to_poly_z(fz,f);
	UniFacZp(fz,p_z,CInt(b),faclist,exponents);
	Push(result,b);
	var factor;
	for(size_t i=0;i<faclist.size();i++)
	{
		factor=Vec();
		from_poly_z(factor,faclist[i]);
		Push(result,Vec(factor,Int(exponents[i])));
	}
	clear_poly_z_list(faclist);
	mpz_clear(p_z);
	return result;
}

}
