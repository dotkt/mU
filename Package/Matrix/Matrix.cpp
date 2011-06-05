#include "Matrix.h"
#include <mU/Kernel.h>

namespace mU {
namespace Matrix {
namespace {
//matrix z2q
inline var mz2q(Var x)
{
	size_t m=Size(x);
	size_t n=Size(At(x,0));
	var r=Vec(m);
	for(size_t i=0;i<m;++i)
	{
		var &c =At(r,i);
		c=Vec(n);
		for(size_t j=0;j<n;++j)
		{
			At(c,j)=Rat();
			Q::SetZ(At(c,j),Entry(x,i,j));
		}
	}
	return r;
}
//vector z2q
inline var vz2q(Var x)
{
	size_t m=Size(x);
	var r=Vec(m);
	for(size_t i=0;i<m;++i)
	{
			At(r,i)=Rat();
			Q::SetZ(At(r,i),At(x,i));
	}
	return r;
}
//scalar z2q
/*inline var z2q(Var x)
{
	var t=Rat();
	return Q::SetZ(t,x);
}*/
Wrap(mLinearSolve)
{
	//var t=Rat();
	//Q::SetZ(t,At(x,1));
	return mLinearSolve(At(x,0),At(x,1),At(x,2));
}
Wrap(LinearSolve)
{
	//var t=Rat();
	//Q::SetZ(t,At(x,1));
	//����Ҫ��ΪAΪ���࣬bΪ������ʽ��������һ�����⣬�����޷��жϱ��ʽΪ������
	return LinearSolve(At(x,0),At(x,1));
}
Wrap(StrassenMM)
{
	return StrassenMM(At(x,0),At(x,1));
}
Wrap(MDot)
{
	//���Դ�����ž��󡢾�ȷ��������������������
	return Matrix::Dot(At(x,0),At(x,1));
}
Wrap(MInverse)
{
	return qInverse(At(x,0));
}
Wrap(MDet)
{
	return qDet(At(x,0));
}
Wrap(NullSpace)
{
	return qNullSpace(At(x,0));
}
Wrap(Rank)
{
	var r=Int();
	Z::Set(r,(uint)qMatrixRank(At(x,0)));
	return r;
}
Wrap(LeastSquares)
{
	return LeastSquares(At(x,0),At(x,1));
}
}
void Initialize()
{
	static bool Initialized = false;
	if (Initialized) return;

	DECL_TAG_SYM_WRAPPED_CPROC(mLinearSolve)
    DECL_TAG_SYM_WRAPPED_CPROC(LinearSolve)
    DECL_TAG_SYM_WRAPPED_CPROC(StrassenMM)
    DECL_TAG_SYM_WRAPPED_CPROC(MDot)
    DECL_TAG_SYM_WRAPPED_CPROC(MInverse)
    DECL_TAG_SYM_WRAPPED_CPROC(MDet)
    DECL_TAG_SYM_WRAPPED_CPROC(NullSpace)
    DECL_TAG_SYM_WRAPPED_CPROC(Rank)
    DECL_TAG_SYM_WRAPPED_CPROC(LeastSquares)

	Initialized = true;
}
}
}
DLLMAIN(mU::Matrix::Initialize)
