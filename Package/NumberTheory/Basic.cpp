/** \file
\brief �������ۺ���.
*/
#include "common.h"
#include "objects/integer.h"
#include <gmp.h>
#include <ctime>
#include <algorithm>
#pragma comment(lib, "gmp")

#include "numtheory.h"

namespace Integer = maTHmU::Objects::Integer;
namespace Rational = maTHmU::Objects::Rational;

namespace maTHmU {
namespace
{
	inline mpz_ptr PTR(VOID *x) { return (mpz_ptr)x; }
	inline mpz_ptr PTR(VAR x) { return PTR(x.ptr); }
	inline Z& CAST(VAR x) { return *(Z*)(&x); }
// 	inline var gMod(VAR x, VAR y)
// 	{
// 		if(GetType(x) == Objects::Integer::INTEGER)
// 			return Mod(x,y);
// 		if(GetType(x) == Objects::Polynomial::POLYNOMIAL)
// 			return Objects::Polynomial::Mod(x,y);
// 	}
// 	/** \brief
// 		\param
// 		\return
// 		\note
// 		\todo PolynomialExtendedGCD
// 	*/
// 	inline var ExtendedGCD(VAR x, VAR y)
// 	{
// 		if(GetType(x) == Objects::Integer::INTEGER)
// 			return ExtendedGCD(x,y);
// 		if(GetType(x) == Objects::Polynomial::POLYNOMIAL)
// 			return 0;
// 	}
	inline var operator * (VAR x, VAR y)
	{
		return Integer::Mul(x,y);
	}
	inline var operator +(VAR x, VAR y)
	{
		return Integer::Add(x,y);
	}
	inline var operator -(VAR x, VAR y)
	{
		return Integer::Sub(x,y);
	}
	inline bool operator ==(VAR x, VAR y)
	{
		return Integer::Cmp(x,y)==0;
	}

	inline bool operator <=(VAR x, VAR y)
	{
		return Integer::Cmp(x,y)<=0;
	}
	inline bool operator >=(VAR x, VAR y)
	{
		return Integer::Cmp(x,y)>=0;
	}
	inline bool operator <(VAR x, VAR y)
	{
		return Integer::Cmp(x,y)<0;
	}
	inline bool operator >(VAR x, VAR y)
	{
		return Integer::Cmp(x,y)>0;
	}
	inline var operator /(VAR x, VAR y)
	{
		return Modules::NumberTheory::Quotient(x,y);
	}

	inline bool less(VAR n,VAR m) {
		return Integer::Cmp(Z::cast(n),Z::cast(m))<0;
	}
}
namespace Modules {
/** \brief ����ģ��

�����������ۺ���.
*/
namespace NumberTheory {

gmp_randstate_t rstate; /**< ���״̬����. */

/** \brief �������ʼ��.
	\note ���ڵ���::RandomInteger֮ǰִ��.
*/
VOID Randomize() {
	gmp_randinit_default(rstate);
	gmp_randseed_ui(rstate,time(NULL));
}

/** \brief ʹ��\f$n\f$��Ϊ������������������������.
	\param n ����.
*/
VOID SeedRandom(VAR n) {
	gmp_randseed(rstate,PTR(n));
}

/** \brief ʹ��ϵͳʱ����Ϊ������������������������.
*/
VOID SeedRandom() {
	gmp_randseed_ui(rstate,time(NULL));
}

/** \brief �����������.
	\param n ������.
	\return 0��n֮��һ�·ֲ��������.
	\param {a,b} ��������.
	\return a��b֮��һ�·ֲ��������.
	\note ����ִ��::Randomize.
	\todo �жϽ�.
*/
Z RandomInteger(VAR n) {
	var r=Z(0);
	if (list::type(n)) {
		var diff = list::cast(n)[1]-list::cast(n)[0];
		mpz_urandomm(PTR(r),rstate,PTR(diff+Z(1)));
		r=r+list::cast(n)[0];
	}
	else {
		mpz_urandomm(PTR(r),rstate,PTR(n+Z(1)));
	}
	return Z::cast(r);
}

/** \brief �����������.
\param n ����1������.
\return 0��n֮��һ�·ֲ����������.
\param {a,b} ������������������.
\return a��b֮��һ�·ֲ����������.
\note ����ִ��::Randomize.
\todo �жϽ�.
*/
Z RandomPrime(VAR n) {
	var m;
	var a,b;
	if (list::type(n)) {
		a=list::cast(n)[0];
		b=list::cast(n)[1];
	}
	else {
		a=Z(0);
		b=n;
	}
	while (1) {
		m=RandomInteger(n);
		if (EvenQ(m) && !(m==Z(2)) ) m=m-Z(1);
		while (m<=b && a<=m) {
			if (PrimeQ(m)) return Z::cast(m);
			else m=m+Z(2);
		}
	}
}

/** \brief �����\f$n\f$�ĵ�һ������.
	\param n ����.
	\return ����\f$n\f$�ĵ�һ������.
	\todo �������ж�.
*/
Z NextPrime(VAR n) {
	if (n<=Z(1) && Z(-2)<=n) return Z(2);
	if (n==Z(-3)) return Z(-2);
	var m;
	if (EvenQ(n)) m=n+Z(1); else m=n+Z(2);
	while (1) {
		if (PrimeQ(m)) return Z::cast(m);
		else m=m+Z(2);
	}
}
/** \brief �����\f$n\f$�ĵ�\f$k\f$������.
\param n ����.
\param k ����.
\return ����\f$n\f$�ĵ�\f$k\f$������. ��\f$k\f$Ϊ����ʱ����С��\f$n\f$�ĵ�\f$k\f$������.
\todo �������ж�.
*/
Z NextPrime(VAR n, VAR k) {
	var count=k;
	var temp1=n;
	var temp2;
	if (count<Z(0)) {
		count=Abs(k);
		temp1=Z(0)-temp1;
	}
	else if (count==Z(0)) count=Z(1);
	while (count>=Z(1)) {
		temp2=NextPrime(temp1);
		temp1=temp2;
		count=count-Z(1);
	}
	if (k<Z(0)) return Z::cast(Z(0)-temp2);
	else return Z::cast(temp2);
}

/** \brief ������\f$n\f$��\f$b\f$���Ʊ�ʾ�µĳ���.
	\param n ����.
	\param b 2 - 62.
	\return ������\f$b\f$���Ʊ�ʾ�µĳ���.
*/
INT IntegerLength(VAR n, UINT b) {
	return mpz_sizeinbase(PTR(n),b);
}

/** \brief λ������.
	\param n, m ����.
	\return \f$n\f$, \f$m\f$��λ������.
*/
Z BitAnd(VAR n, VAR m) {
	Z r;
	mpz_and(PTR(r),PTR(n),PTR(m));
	return r;
}

/** \brief λ������.
	\param n, m ����.
	\return \f$n\f$, \f$m\f$��λ������.
*/
Z BitOr(VAR n, VAR m) {
	Z r;
	mpz_ior(PTR(r),PTR(n),PTR(m));
	return r;
}

/** \brief λ�������.
	\param n, m ����.
	\return \f$n\f$, \f$m\f$��λ�������.
*/
Z BitXor(VAR n, VAR m) {
	Z r;
	mpz_xor(PTR(r),PTR(n),PTR(m));
	return r;
}

/** \brief λ������.
	\param n ����.
	\return \f$n\f$��λ������.
*/
Z BitNot(VAR n) {
	Z r;
	mpz_com(PTR(r),PTR(n));
	return r;
}

/** \brief ����\f$n\f$��\f$2^k\f$λΪ1.
	\param n ����.
	\param k �Ǹ�����.
	\return ����\f$n\f$��\f$2^k\f$λΪ1.
*/
Z BitSet(VAR n, UINT k) {
	var r=n;
	mpz_setbit(PTR(r),k);
	return Z::cast(r);
}

/** \brief ����\f$n\f$��\f$2^k\f$λΪ0.
\param n ����.
\param k �Ǹ�����.
\return ����\f$n\f$��\f$2^k\f$λΪ0.
*/
Z BitClear(VAR n, UINT k) {
	var r=n;
	mpz_clrbit(PTR(r),k);
	return Z::cast(r);
}


/** \brief ��\f$n\f$��\f$2^k\f$λ.
\param n, k ������.
\return \f$n\f$��\f$2^k\f$λ.
*/
INT BitGet(VAR n, UINT k) {
	return mpz_tstbit(PTR(n),k);
}

/** \brief ��\f$n\f$����\f$k\f$λ.
	\param n, k ����. Ĭ��\f$k=1\f$.
	\return ��\f$n\f$����\f$k\f$λ. ��\f$k\f$Ϊ����ʱΪ����.
*/
Z BitShiftLeft(VAR n, INT k) {
	Z r;
	if (k<0) mpz_tdiv_q_2exp(PTR(r),PTR(n),-k);
	else mpz_mul_2exp(PTR(r),PTR(n),k);
	return r;
}

/** \brief ��\f$n\f$����\f$k\f$λ.
	\param n, k ����. Ĭ��\f$k=1\f$.
	\return ��\f$n\f$����\f$k\f$λ. ��\f$k\f$Ϊ����ʱΪ����.
*/
Z BitShiftRight(VAR n, INT k) {
	Z r;
	if (k<0) mpz_mul_2exp(PTR(r),PTR(n),-k);
	else mpz_tdiv_q_2exp(PTR(r),PTR(n),k);
	return r;
}

/** \brief �ж�һ�������Ƿ�Ϊ����.
	\param n ����.
	\retval 1 ��.
	\retval 0 ��.
*/
INT OddQ(VAR n) {
	return mpz_odd_p(PTR(n));
}

/** \brief �ж�һ�������Ƿ�Ϊż��.
	\param n ����.
	\retval 1 ��.
	\retval 0 ��.
*/
INT EvenQ(VAR n) {
	return mpz_even_p(PTR(n));
}

/** \brief �������ľ���ֵ.
	\param n ����
	\return n�ľ���ֵ.
*/
Z Abs(VAR n) {
	Z r;
	mpz_abs(PTR(r),PTR(n));
	return r;
}

/** \brief ������ƽ��.
	\param n ����.
	\return ƽ��������������\f$\lfloor\sqrt{n}\rfloor\f$.
	\note ʹ��Karatsubaƽ�����㷨.
	\todo �����ĵ�.
*/
Z Sqrt(VAR n) {
	Z r;
	mpz_sqrt(PTR(r),PTR(n));
	return r;
}

/** \brief �ж�һ�������Ƿ�Ϊ��ȫƽ����.
	\param n ��������.
	\retval 1 ��.
	\retval 0 ��.
	\note ʹ��\f$\mathbb{Z}/k\mathbb{Z}\f$��ƽ��������.
	��256��45��17��13��7Ϊģ, ����99.25%, ʹ�û��д��mpn_mod_34lsub1����.
*/
INT SquareQ(VAR n) {
	return mpz_perfect_square_p(PTR(n));
}

/** \brief �ж�\f$m\f$�Ƿ�������\f$n\f$.
	\param n ����.
	\param m ��������.
	\retval 1 ��.
	\retval 0 ��.
	\todo �ж�m����.
*/
INT Divisible(VAR n, VAR m) {
	if (mpz_fits_uint_p(PTR(m))) {
		return mpz_divisible_ui_p(PTR(n),mpz_get_ui(PTR(m)));
	}
	else {
		return mpz_divisible_p(PTR(n),PTR(m));
	}
}

/** \brief �ж�\f$m\f$�Ƿ�������\f$n\f$.
\param n ����.
\param m ��������.
\retval 1 ��.
\retval 0 ��.
\todo �ж�m����.
*/
INT Divisible(VAR n, UINT m) {
	return mpz_divisible_ui_p(PTR(n),m);
}

/** \brief ��\f$m\f$����\f$n\f$����.
	\param m ����.
	\param n ��������.
	\return ��\f$\lfloor m/n\rfloor\f$.
	\todo ���ӷ����ж�, ���ӷ���������.
	\todo ��Ҫ�ĵ�����.
*/
Z Quotient(VAR m, VAR n) {
	Z r;
	if (mpz_fits_uint_p(PTR(n))) {
		mpz_div_ui(PTR(r),PTR(m),mpz_get_ui(PTR(n)));
	}
	else {
		mpz_div(PTR(r),PTR(m),PTR(n));
	}
	return r;
}

/** \brief ��\f$m\f$����\f$n\f$����(��֪\f$n\f$����\f$m\f$).
	\param m ����.
	\param n ��������.
	\return \f$m/n\f$.
*/
Z ExactQuotient(VAR m, UINT n) {
	Z r;
	mpz_divexact_ui(PTR(r),PTR(m),n);
	return r;
}
/** \brief ��\f$m\f$����\f$n\f$������.
	\param m ����.
	\param n ��������.
	\return ����\f$m \bmod n\f$.
	\note
	\todo ���ӷ����ж�, ���ӷ���������.
	\todo ��Ҫ�ĵ�����.
*/
Z Mod(VAR m, VAR n) {
	Z r;
	if (mpz_fits_uint_p(PTR(n))) {
		mpz_mod_ui(PTR(r),PTR(m),mpz_get_ui(PTR(n)));
	}
	else {
		mpz_mod(PTR(r),PTR(m),PTR(n));
	}
	return r;
}
/** \brief ����������������.
	\param a ����.
	\param b �Ǹ�����.
	\return \f$a^b\f$.
	\note ʹ���������ҵĶ�������.
	\todo a=0
*/
Z Power(VAR a, UINT b) {
	Z r;
	if (mpz_fits_uint_p(PTR(a))) {
		mpz_ui_pow_ui(PTR(r),mpz_get_ui(PTR(a)),b);
	}
	else {
		mpz_pow_ui(PTR(r),PTR(a),b);
	}
	return r;
}

/** \brief ��\f$a^b \bmod m\f$.
	\param a,b ����.
	\param m ��������.
	\return \f$a^b \bmod m\f$.
	\note ģ��mpz_powm����\f$2^k\f$�����ڷ�����\f$k\f$����ָ��ѡ��.
	\note ��Сģʹ����MontgomeryԼ������(ֻ�������ģ),
	���Ҷ�POWM_THRESHOLD����ģʹ�ô������.
	\todo a=0.
*/

Z PowerMod(VAR a, VAR b, VAR m) {
	Z r;
	if (mpz_fits_uint_p(PTR(b))) {
		mpz_powm_ui(PTR(r),PTR(a),mpz_get_ui(PTR(b)),PTR(m));
	}
	else {
		mpz_powm(PTR(r),PTR(a),PTR(b),PTR(m));
	}
	return r;
}

/** \brief ��\f$a\f$ģ\f$n\f$����.
	\param a, n ����.
	\return \f$a\f$ģ\f$n\f$����.
	\todo �����ж�.
*/
Z InverseMod(VAR a, VAR n) {
	Z r;
	mpz_invert(PTR(r),PTR(a),PTR(n));
	return r;
}

/** \brief �������������������.
\param n1, n2 ����.
\return �������.
\note mpz_gcd�Խ�С����ʹ��Binary GCD,
�Գ���GCD_ACCEL_THRESHOLD������ʹ��Jebelean-Weber-Sorenson�����㷨.
*/
Z GCD(VAR n1, VAR n2) {
	Z r;
	if (mpz_fits_uint_p(PTR(n2))) {
		mpz_gcd_ui(PTR(r),PTR(n1),mpz_get_ui(PTR(n2)));
	}
	else {
		if (mpz_fits_uint_p(PTR(n1))) {
			mpz_gcd_ui(PTR(r),PTR(n2),mpz_get_ui(PTR(n1)));
		}
		else {
		mpz_gcd(PTR(r),PTR(n1),PTR(n2));
		}
	}
	return r;
}

/** \brief ��\f$n_i\f$���������.
	\param n \f$\{n_1,n_2,\ldots\}\f$.
	\return \f$n_i\f$���������.
*/
Z GCD(LIST n) {
	var t=n[0];
	for (INT i=1;i<=n.size()-1;i++)
	{
		t=GCD(t,n[i]);
		if (Z::cast(t)==1) break;
	}
	return Z::cast(t);
}

/** \brief ��������������С������.
\param n1, n2 ����.
\return ��С������.
*/
Z LCM(VAR n1, VAR n2) {
	Z r;
	if (mpz_fits_uint_p(PTR(n2))) {
		mpz_lcm_ui(PTR(r),PTR(n1),mpz_get_ui(PTR(n2)));
	}
	else {
		if (mpz_fits_uint_p(PTR(n1))) {
			mpz_lcm_ui(PTR(r),PTR(n2),mpz_get_ui(PTR(n1)));
		}
		else {
			mpz_lcm(PTR(r),PTR(n1),PTR(n2));
		}
	}
	return r;
}

/** \brief ��\f$n_i\f$����С������.
\param n \f$\{n_1,n_2,\ldots\}\f$.
\return \f$n_i\f$����С������.
*/
Z LCM(LIST n) {
	var t=n[0];
	for (INT i=1;i<=n.size()-1;i++)
	{
		t=LCM(t,n[i]);
	}
	return Z::cast(t);
}

/** \brief ��������������չ�������.
\param n1, n2 ����.
\return ��չ�������\f$\{g,\{r_1,r_2\}\}\f$, ����\f$g=r_1n_1+r_2n_2\f$.
\note ��GCDEXT_THRESHOLD����ʹ��Lehmer�����㷨.
\todo ��չ�������.
*/
list ExtendedGCD(VAR n1, VAR n2) {
	Z g=GCD(n1,n2);
	Z r1,r2;
	mpz_gcdext(PTR(g),PTR(r1),PTR(r2),PTR(n1),PTR(n2));
	return list(g,list(r1,r2));
}

/** \brief �ж����������Ƿ���.
\param n1,n2 ����.
\retval 1 ��.
\retval 0 ��.
*/
INT CoprimeQ(VAR n1, VAR n2) {
	return (GCD(n1, n2)==1);
}
/** \brief �������������������չʽǰ\f$n\f$��.
	\param d �Ǹ������ҷ���ȫƽ��.
	\param P ����.
	\param Q ��������.
	\param n ������.
	\return \f$(\sqrt{d}+P)/Q\f$��������չʽ��ǰ\f$n\f$��\f$\{a_0,a_1,\ldots,a_{n-1}\}\f$.
	\note ʹ��ȫ��������ĵ��ƹ�ϵ.
*/
list ContinuedFraction(VAR d, VAR P, VAR Q, UINT n) {
	list a;
	var t, r, D, s;
	if (Divisible(d-P*P,Q)) {
		D=d;
		r=P;
		t=Q;
	}
	else {
		D=d*Q*Q;
		r=P*Integer::Abs(Q);
		t=Q*Integer::Abs(Q);
	}
	s=(D-r*r)/t;
	var p,q;
	for (INT i=0;i<=n-1;i++)
	{
		a.push((Sqrt(D)+r)/t);
		p=a[i]*t-r;
		q=a[i]*(r-p)+s;
		s=t;
		t=q;
		r=p;
		if (Z::cast(t)==0) break;
	}
	return a;
}

/** \brief �������������������չʽ.
	\param d �Ǹ������ҷ���ȫƽ��.
	\param P ����.
	\param Q ��������.
	\return \f$\{\{a_0,a_1,\ldots,a_m\},\{a_{m+1},\ldots,a_{m+l}\}\}\f$.
	\f$(\sqrt{d}+P)/Q\f$��������չʽ. ���еĵ�һ��Ϊ��ѭ������, �ڶ���Ϊѭ������.
	\note ��ʹ��Floyd�㷨�����ѭ������, �������Сѭ������.
*/
list ContinuedFraction(VAR d, VAR P, VAR Q) {
	list p,q,a;
	var D;
	if (Divisible(d-P*P,Q)) {
		D=d;
		p.push(P);
		q.push(Q);
	}
	else {
		D=d*Q*Q;
		p.push(P*Integer::Abs(Q));
		q.push(Q*Integer::Abs(Q));
	}
	INT i=0;
	INT j=0;
	INT l=0;
	while (1) {
		a.push((Sqrt(D)+p[i])/q[i]);
		p.push(a[i]*q[i]-p[i]);
		if (i==0) {
			q.push(a[i]*(p[i]-p[i+1])+(D-p[0]*p[0])/q[0]);
		}
		else {
			q.push(a[i]*(p[i]-p[i+1])+q[i-1]);
		}

		if (Z::cast(q[i+1])==0) return list(a,list());
		if (i%2==0 && p[i+1]==p[i/2] && q[i+1]==q[i/2]) {
			l=i/2+1;
			j=i/2-1;
			while (j>=0 && p[j]==p[j+l] && q[j]==q[j+l]) {
				j--;
			}
			j++;
			for (INT k=1;k<=l;k++) {
				if (l%k==0 && p[j]==p[j+k] && q[j]==q[j+k]) {
					l=k;
					break;
				}
			}
			break;
		}
		i++;
	}
	return list(a.mid(0,j),a.mid(j,j+l));
}

/** \brief ������������Ľ�������.
	\param d �Ǹ������ҷ���ȫƽ��.
	\param P ����.
	\param Q ��������.
	\param n ������.
	\return \f$(\sqrt{d}+P)/Q\f$��ǰ\f$n\f$������������ɵı�.
	\note ʹ�õ��ƹ�ϵ.
*/
list Convergents(VAR d, VAR P, VAR Q, UINT n) {
	list h,k;
	h.push(Z(0));
	h.push(Z(1));
	k.push(Z(1));
	k.push(Z(0));
	var h0=Z(0),h1=Z(1),h2,k0=Z(1),k1=Z(0),k2;
	list a=ContinuedFraction(d,P,Q,n);
	list r;
	for (INT i=0;i<=n-1;i++) {
		h2=a[i]*h1+h0;
		k2=a[i]*k1+k0;
		h0=h1;
		h1=h2;
		k0=k1;
		k1=k2;
		r.push(Rational::NewZ(h2,k2));
	}
	return r;
}

/** \brief �������ͬ�෽����\f$x\equiv x_i\pmod{m_i}\f$.
\param x ��\f$\{x_1,\ldots,x_n\}\f$.
\param m ��\f$\{m_1,\ldots,m_n\}\f$.
\return ����ͬ�෽������С��������.
\note ʹ�øĽ����й�ʣ�ඨ���㷨.
\todo ����Ч��.
*/
Z ChineseRemainder(LIST x, LIST m) {
	UINT n=m.size();
	list y(n),p(n),u(n);
	y[0]=Mod(x[0],m[0]);
	var t=Z(1);
	for (INT i=1;i<=n-1;i++) {
		t=t*m[i-1];
		p[i]=Mod(t,m[i]);
		u[i]=list::cast(ExtendedGCD(p[i],m[i])[1])[0];
		var s=y[i-1];
		for (INT j=i-2;j>=0;j--) {
			s=s*m[j]+y[j];
		}
		y[i]=Mod((x[i]-s)*u[i],m[i]);
	}
	var r=y[n-1];
	for (INT i=n-2;i>=0;i--) {
		r=r*m[i]+y[i];
	}
	return Z::cast(r);
}

/** \brief ��Legendre����\f$\legendre{n}{m}\f$.
\param n ����.
\param m ��������.
\return Legendre����\f$\legendre{n}{m}\f$.
\note ʹ�ö�������.
\todo �������������ж�.
*/
Z LegendreSymbol(VAR n, VAR m) {
	return Z(mpz_legendre(PTR(n),PTR(m)));
}
/** \brief ��Jacobi����\f$\legendre{n}{m}\f$.
\param n ����.
\param m ������.
\return Jacobi����\f$\legendre{n}{m}\f$.
\note ʹ�ö�������.
\todo �����������ж�.
*/
Z JacobiSymbol(VAR n, VAR m) {
	return Z(mpz_legendre(PTR(n),PTR(m)));
}

/** \brief ��Kronecker����\f$\legendre{n}{m}\f$.
\param n,m ����.
\return Kronecker����\f$\legendre{n}{m}\f$.
\note ʹ�ö�������.
*/
Z KroneckerSymbol(VAR n, VAR m) {
	return Z(mpz_kronecker(PTR(n),PTR(m)));
}

/** \brief ��Euler����\f$\varphi(n)\f$.
	\param n ����.
	\return Euler����\f$\varphi(n)\f$.
*/
Z EulerPhi(VAR n) {
	if (n==Z(0)) return Z(0);
	if (Abs(n)==Z(1)) return Z(1);
	list s=FactorInteger(Abs(n));
	var m=Z(1);
	for (UINT i=0;i<s.size();i++)
	{
		m=m*Power(list::cast(s[i])[0],mpz_get_ui(PTR(list::cast(s[i])[1]))-1)*(list::cast(s[i])[0]-Z(1));
	}
	return Z::cast(m);
}

/** \brief ��Moebius����\f$\mU(n)\f$.
\param n ����.
\return Moebius����\f$\mU(n)\f$.
*/
Z MoebiusMu(VAR n) {
	list r;
	var m=Abs(n);
	if (m==Z(0)) { return Z(0); }
	if (m==Z(1)) { return Z(1); }
	/* ֱ���ж��Ƿ����������� */
	try {
		r=FactorInteger(m,1);
	}
	catch (int e) {
		if (e==MoebiusMu_0)
			return Z(0);
		else throw(e);
	}
	if (r.size()%2==0) return Z(1);
	else return Z(-1);
}

/** \cond */
inline var first(VAR x) {return list::cast(x)[0];}
inline var second(VAR x) {return list::cast(x)[1];}
/** \endcond */

/** \brief ��\f$n\f$����������.
	\param n ��������.
	\return \f$n\f$����������.
	\todo �ж���.
*/
list Divisors(VAR n) {
	if (Abs(n)==Z(1)) return list().push(Z(1));
	list f=FactorInteger(Abs(n));
	list p=list::map(first,f);	/* ���� */
	list e=list::map(second,f);	/* ���� */
	list r;
	UINT t,l;
	r.push(Z(1));
	for (UINT i=0;i<p.size();i++) {
		t=0;
		l=r.size();
		for (UINT k=0;k<Z::cast(e[i]);k++)
		{
			for (UINT j=t;j<l;j++)
			{
				r.push(r[j]*p[i]);
			}
			t=l;
			l=r.size();
		}
	}
	std::sort(r.begin(),r.end(),less);
	return r;
}

/** \brief ��\f$n\f$�Ĳ�ͬ�����Ӹ���\f$\nu(n)\f$.
\param n ��������.
\return \f$n\f$�Ĳ�ͬ�����Ӹ���\f$\nu(n)\f$.
\todo �ж���.
*/
Z PrimeNu(VAR n) {
	if (Abs(n)==Z(1)) return Z(0);
	return Z(FactorInteger(Abs(n)).size());
}


}
}
}
