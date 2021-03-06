(* ::Package:: *)

(************************************************************************)
(* This file was generated automatically by the Mathematica front end.  *)
(* It contains Initialization cells from a Notebook file, which         *)
(* typically will have the same name as this file except ending in      *)
(* ".nb" instead of ".m".                                               *)
(*                                                                      *)
(* This file is intended to be loaded into the Mathematica kernel using *)
(* the package loading commands Get or Needs.  Doing so is equivalent   *)
(* to using the Evaluate Initialization Cells menu command in the front *)
(* end.                                                                 *)
(*                                                                      *)
(* DO NOT EDIT THIS FILE.  This entire file is regenerated              *)
(* automatically each time the parent Notebook file is saved in the     *)
(* Mathematica front end.  Any changes you make to this file will be    *)
(* overwritten.                                                         *)
(************************************************************************)



(* ::Code:: *)
Int[(c_.*ProductLog[a_.+b_.*x_])^p_,x_Symbol] :=
  (a+b*x)*(c*ProductLog[a+b*x])^p/(b*(p+1)) +
  Dist[p/(c*(p+1)),Int[(c*ProductLog[a+b*x])^(p+1)/(1+ProductLog[a+b*x]),x]] /;
FreeQ[{a,b,c},x] && RationalQ[p] && p<-1


(* ::Code:: *)
Int[(c_.*ProductLog[a_.+b_.*x_])^p_.,x_Symbol] :=
  (a+b*x)*(c*ProductLog[a+b*x])^p/b -
  Dist[p,Int[(c*ProductLog[a+b*x])^p/(1+ProductLog[a+b*x]),x]] /;
FreeQ[{a,b,c},x] && Not[RationalQ[p] && p<-1]


(* ::Code:: *)
Int[1/(d_+d_.*ProductLog[a_.+b_.*x_]),x_Symbol] :=
  (a+b*x)/(b*d*ProductLog[a+b*x]) /;
FreeQ[{a,b,d},x]


(* ::Code:: *)
Int[ProductLog[a_.+b_.*x_]/(d_+d_.*ProductLog[a_.+b_.*x_]),x_Symbol] :=
  d*x - 
  Int[1/(d+d*ProductLog[a+b*x]),x] /;
FreeQ[{a,b,d},x]


(* ::Code:: *)
Int[1/(ProductLog[a_.+b_.*x_]*(d_+d_.*ProductLog[a_.+b_.*x_])),x_Symbol] :=
  ExpIntegralEi[ProductLog[a+b*x]]/(b*d) /;
FreeQ[{a,b,d},x]


(* ::Code:: *)
Int[1/(Sqrt[c_.*ProductLog[a_.+b_.*x_]]*(d_+d_.*ProductLog[a_.+b_.*x_])),x_Symbol] :=
  Rt[Pi*c,2]*Erfi[Sqrt[c*ProductLog[a+b*x]]/Rt[c,2]]/(b*c*d) /;
FreeQ[{a,b,c,d},x] && PosQ[c]


(* ::Code:: *)
Int[1/(Sqrt[c_.*ProductLog[a_.+b_.*x_]]*(d_+d_.*ProductLog[a_.+b_.*x_])),x_Symbol] :=
  Rt[-Pi*c,2]*Erf[Sqrt[c*ProductLog[a+b*x]]/Rt[-c,2]]/(b*c*d) /;
FreeQ[{a,b,c,d},x] && NegQ[c]


(* ::Code:: *)
Int[(c_.*ProductLog[a_.+b_.*x_])^p_/(d_+d_.*ProductLog[a_.+b_.*x_]),x_Symbol] :=
  c*(a+b*x)*(c*ProductLog[a+b*x])^(p-1)/(b*d) -
  Dist[c*p,Int[(c*ProductLog[a+b*x])^(p-1)/(d+d*ProductLog[a+b*x]),x]] /;
FreeQ[{a,b,c,d},x] && RationalQ[p] && p>0


(* ::Code:: *)
Int[(c_.*ProductLog[a_.+b_.*x_])^p_/(d_+d_.*ProductLog[a_.+b_.*x_]),x_Symbol] :=
  (a+b*x)*(c*ProductLog[a+b*x])^p/(b*d*(p+1)) -
  Dist[1/(c*(p+1)),Int[(c*ProductLog[a+b*x])^(p+1)/(d+d*ProductLog[a+b*x]),x]] /;
FreeQ[{a,b,c,d},x] && RationalQ[p] && p<-1


(* ::Code:: *)
Int[(c_.*ProductLog[a_.+b_.*x_])^p_./(d_+d_.*ProductLog[a_.+b_.*x_]),x_Symbol] :=
  Gamma[p+1,-ProductLog[a+b*x]]*(c*ProductLog[a+b*x])^p/(b*d*(-ProductLog[a+b*x])^p) /;
FreeQ[{a,b,c,d,p},x]


(* ::Code:: *)
Int[x_^m_.*(c_.*ProductLog[a_+b_.*x_])^p_.,x_Symbol] :=
  Dist[1/b,Subst[Int[Dist[(c*ProductLog[x])^p,Expand[(-a/b+x/b)^m]],x],x,a+b*x]] /;
FreeQ[{a,b,c,p},x] && IntegerQ[m] && m>0


(* ::Code:: *)
Int[x_^m_./(d_+d_.*ProductLog[a_+b_.*x_]),x_Symbol] :=
  Dist[1/b,Subst[Int[Dist[1/(d+d*ProductLog[x]),Expand[(-a/b+x/b)^m]],x],x,a+b*x]] /;
FreeQ[{a,b,d},x] && IntegerQ[m] && m>0


(* ::Code:: *)
Int[x_^m_.*(c_.*ProductLog[a_+b_.*x_])^p_./(d_+d_.*ProductLog[a_+b_.*x_]),x_Symbol] :=
  Dist[1/b,Subst[Int[Dist[(c*ProductLog[x])^p/(d+d*ProductLog[x]),Expand[(-a/b+x/b)^m]],x],x,a+b*x]] /;
FreeQ[{a,b,c,d,p},x] && IntegerQ[m] && m>0


(* ::Code:: *)
Int[(c_.*ProductLog[a_.*x_^n_])^p_.,x_Symbol] :=
  x*(c*ProductLog[a*x^n])^p -
  Dist[n*p,Int[(c*ProductLog[a*x^n])^p/(1+ProductLog[a*x^n]),x]] /;
FreeQ[{a,c,n,p},x] && (ZeroQ[n*(p-1)+1] || IntegerQ[p-1/2] && ZeroQ[n*(p-1/2)+1])


(* ::Code:: *)
Int[(c_.*ProductLog[a_.*x_^n_])^p_.,x_Symbol] :=
  x*(c*ProductLog[a*x^n])^p/(n*p+1) +
  Dist[n*p/(c*(n*p+1)),Int[(c*ProductLog[a*x^n])^(p+1)/(1+ProductLog[a*x^n]),x]] /;
FreeQ[{a,c,n},x] && (IntegerQ[p] && ZeroQ[n*(p+1)+1] || IntegerQ[p-1/2] && ZeroQ[n*(p+1/2)+1])


(* ::Code:: *)
Int[(c_.*ProductLog[a_.*x_^n_])^p_.,x_Symbol] :=
  -Subst[Int[(c*ProductLog[a*x^(-n)])^p/x^2,x],x,1/x] /;
FreeQ[{a,c,p},x] && IntegerQ[n] && n<0


(* ::Code:: *)
Int[1/(d_+d_.*ProductLog[a_.*x_^n_]),x_Symbol] :=
  -Subst[Int[1/(x^2*(d+d*ProductLog[a*x^(-n)])),x],x,1/x] /;
FreeQ[{a,d},x] && IntegerQ[n] && n<0


(* ::Code:: *)
Int[(c_.*ProductLog[a_.*x_^n_.])^p_./(d_+d_.*ProductLog[a_.*x_^n_.]),x_Symbol] :=
  c*x*(c*ProductLog[a*x^n])^(p-1)/d /;
FreeQ[{a,c,d,n,p},x] && ZeroQ[n*(p-1)+1]


(* ::Code:: *)
Int[ProductLog[a_.*x_^n_.]^p_./(d_+d_.*ProductLog[a_.*x_^n_.]),x_Symbol] :=
  a^p*ExpIntegralEi[-p*ProductLog[a*x^n]]/(d*n) /;
FreeQ[{a,d},x] && IntegerQ[1/n] && ZeroQ[p+1/n]


(* ::Code:: *)
Int[(c_.*ProductLog[a_.*x_^n_.])^p_/(d_+d_.*ProductLog[a_.*x_^n_.]),x_Symbol] :=
  Rt[Pi*c*n,2]/(d*n*a^(1/n)*c^(1/n))*Erfi[Sqrt[c*ProductLog[a*x^n]]/Rt[c*n,2]] /;
FreeQ[{a,c,d},x] && IntegerQ[1/n] && ZeroQ[p-1/2+1/n] && PosQ[c*n]


(* ::Code:: *)
Int[(c_.*ProductLog[a_.*x_^n_.])^p_/(d_+d_.*ProductLog[a_.*x_^n_.]),x_Symbol] :=
  Rt[-Pi*c*n,2]/(d*n*a^(1/n)*c^(1/n))*Erf[Sqrt[c*ProductLog[a*x^n]]/Rt[-c*n,2]] /;
FreeQ[{a,c,d},x] && IntegerQ[1/n] && ZeroQ[p-1/2+1/n] && NegQ[c*n]


(* ::Code:: *)
Int[(c_.*ProductLog[a_.*x_^n_.])^p_./(d_+d_.*ProductLog[a_.*x_^n_.]),x_Symbol] :=
  c*x*(c*ProductLog[a*x^n])^(p-1)/d -
  Dist[c*(n*(p-1)+1),Int[(c*ProductLog[a*x^n])^(p-1)/(d+d*ProductLog[a*x^n]),x]] /;
FreeQ[{a,c,d},x] && RationalQ[{n,p}] && n>0 && n*(p-1)+1>0


(* ::Code:: *)
Int[(c_.*ProductLog[a_.*x_^n_.])^p_./(d_+d_.*ProductLog[a_.*x_^n_.]),x_Symbol] :=
  x*(c*ProductLog[a*x^n])^p/(d*(n*p+1)) -
  Dist[1/(c*(n*p+1)),Int[(c*ProductLog[a*x^n])^(p+1)/(d+d*ProductLog[a*x^n]),x]] /;
FreeQ[{a,c,d},x] && RationalQ[{n,p}] && n>0 && n*p+1<0


(* ::Code:: *)
Int[(c_.*ProductLog[a_.*x_^n_])^p_./(d_+d_.*ProductLog[a_.*x_^n_]),x_Symbol] :=
  -Subst[Int[(c*ProductLog[a*x^(-n)])^p/(x^2*(d+d*ProductLog[a*x^(-n)])),x],x,1/x] /;
FreeQ[{a,c,d,p},x] && IntegerQ[n] && n<0


(* ::Code:: *)
Int[x_^m_.*(c_.*ProductLog[a_.*x_^n_.])^p_.,x_Symbol] :=
  x^(m+1)*(c*ProductLog[a*x^n])^p/(m+1) -
  Dist[n*p/(m+1),Int[x^m*(c*ProductLog[a*x^n])^p/(1+ProductLog[a*x^n]),x]] /;
FreeQ[{a,c,m,n,p},x] && NonzeroQ[m+1] &&
(IntegerQ[p-1/2] && IntegerQ[2*Simplify[p+(m+1)/n]] && Simplify[p+(m+1)/n]>0 ||
 Not[IntegerQ[p-1/2]] && IntegerQ[Simplify[p+(m+1)/n]] && Simplify[p+(m+1)/n]>=0)


(* ::Code:: *)
Int[x_^m_.*(c_.*ProductLog[a_.*x_^n_.])^p_.,x_Symbol] :=
  x^(m+1)*(c*ProductLog[a*x^n])^p/(m+n*p+1) +
  Dist[n*p/(c*(m+n*p+1)),Int[x^m*(c*ProductLog[a*x^n])^(p+1)/(1+ProductLog[a*x^n]),x]] /;
FreeQ[{a,c,m,n,p},x] &&
(ZeroQ[m+1] ||
 IntegerQ[p-1/2] && IntegerQ[Simplify[p+(m+1)/n]-1/2] && Simplify[p+(m+1)/n]<0 ||
 Not[IntegerQ[p-1/2]] && IntegerQ[Simplify[p+(m+1)/n]] && Simplify[p+(m+1)/n]<0)


(* ::Code:: *)
Int[x_^m_.*(c_.*ProductLog[a_.*x_])^p_.,x_Symbol] :=
  Int[x^m*(c*ProductLog[a*x])^p/(1+ProductLog[a*x]),x] +
  Dist[1/c,Int[x^m*(c*ProductLog[a*x])^(p+1)/(1+ProductLog[a*x]),x]] /;
FreeQ[{a,c,m},x]


(* ::Code:: *)
Int[x_^m_.*(c_.*ProductLog[a_.*x_^n_])^p_.,x_Symbol] :=
  -Subst[Int[(c*ProductLog[a*x^(-n)])^p/x^(m+2),x],x,1/x] /;
FreeQ[{a,c,p},x] && IntegersQ[m,n] && n<0 && NonzeroQ[m+1]


(* ::Code:: *)
Int[1/(x_*(d_+d_.*ProductLog[a_.*x_^n_.])),x_Symbol] :=
  Log[ProductLog[a*x^n]]/(d*n) /;
FreeQ[{a,d,n},x]


(* ::Code:: *)
Int[x_^m_./(d_+d_.*ProductLog[a_.*x_]),x_Symbol] :=
  x^(m+1)/(d*(m+1)*ProductLog[a*x]) -
  Dist[m/(m+1),Int[x^m/(ProductLog[a*x]*(d+d*ProductLog[a*x])),x]] /;
FreeQ[{a,d},x] && RationalQ[m] && m>0


(* ::Code:: *)
Int[x_^m_./(d_+d_.*ProductLog[a_.*x_]),x_Symbol] :=
  x^(m+1)/(d*(m+1)) -
  Int[x^m*ProductLog[a*x]/(d+d*ProductLog[a*x]),x] /;
FreeQ[{a,d},x] && RationalQ[m] && m<-1


(* ::Code:: *)
Int[x_^m_./(d_+d_.*ProductLog[a_.*x_]),x_Symbol] :=
  x^m*Gamma[m+1,-(m+1)*ProductLog[a*x]]/
	(a*d*(m+1)*E^(m*ProductLog[a*x])*(-(m+1)*ProductLog[a*x])^m) /;
FreeQ[{a,d},x] && NonzeroQ[m+1]


(* ::Code:: *)
Int[x_^m_./(d_+d_.*ProductLog[a_.*x_^n_]),x_Symbol] :=
  -Subst[Int[1/(x^(m+2)*(d+d*ProductLog[a*x^(-n)])),x],x,1/x] /;
FreeQ[{a,d},x] && IntegersQ[m,n] && n<0 && NonzeroQ[m+1]


(* ::Code:: *)
Int[(c_.*ProductLog[a_.*x_^n_.])^p_./(x_*(d_+d_.*ProductLog[a_.*x_^n_.])),x_Symbol] :=
  (c*ProductLog[a*x^n])^p/(d*n*p) /;
FreeQ[{a,c,d,n,p},x]


(* ::Code:: *)
Int[x_^m_.*(c_.*ProductLog[a_.*x_^n_.])^p_./(d_+d_.*ProductLog[a_.*x_^n_.]),x_Symbol] :=
  c*x^(m+1)*(c*ProductLog[a*x^n])^(p-1)/(d*(m+1)) /;
FreeQ[{a,c,d,m,n,p},x] && ZeroQ[m+n*(p-1)+1] && NonzeroQ[m+1]


(* ::Code:: *)
Int[x_^m_.*ProductLog[a_.*x_^n_.]^p_./(d_+d_.*ProductLog[a_.*x_^n_.]),x_Symbol] :=
  a^p*ExpIntegralEi[-p*ProductLog[a*x^n]]/(d*n) /;
FreeQ[{a,d,m,n},x] && IntegerQ[p] && ZeroQ[m+n*p+1]


(* ::Code:: *)
Int[x_^m_.*(c_.*ProductLog[a_.*x_^n_.])^p_/(d_+d_.*ProductLog[a_.*x_^n_.]),x_Symbol] :=
  a^(p-1/2)*c^(p-1/2)*Rt[Pi*c/(p-1/2),2]*Erf[Sqrt[c*ProductLog[a*x^n]]/Rt[c/(p-1/2),2]]/(d*n) /;
FreeQ[{a,c,d,m,n},x] && IntegerQ[p-1/2] && p-1/2!=0 && ZeroQ[m+n*(p-1/2)+1] && PosQ[c/(p-1/2)]


(* ::Code:: *)
Int[x_^m_.*(c_.*ProductLog[a_.*x_^n_.])^p_/(d_+d_.*ProductLog[a_.*x_^n_.]),x_Symbol] :=
  a^(p-1/2)*c^(p-1/2)*Rt[-Pi*c/(p-1/2),2]*Erfi[Sqrt[c*ProductLog[a*x^n]]/Rt[-c/(p-1/2),2]]/(d*n) /;
FreeQ[{a,c,d,m,n},x] && IntegerQ[p-1/2] && p-1/2!=0 && ZeroQ[m+n*(p-1/2)+1] && NegQ[c/(p-1/2)]


(* ::Code:: *)
Int[x_^m_.*(c_.*ProductLog[a_.*x_^n_.])^p_./(d_+d_.*ProductLog[a_.*x_^n_.]),x_Symbol] :=
  c*x^(m+1)*(c*ProductLog[a*x^n])^(p-1)/(d*(m+1)) -
  Dist[c*(m+n*(p-1)+1)/(m+1),Int[x^m*(c*ProductLog[a*x^n])^(p-1)/(d+d*ProductLog[a*x^n]),x]] /;
FreeQ[{a,c,d,m,n,p},x] && NonzeroQ[m+1] && RationalQ[Simplify[p+(m+1)/n]] && Simplify[p+(m+1)/n]>1


(* ::Code:: *)
Int[x_^m_.*(c_.*ProductLog[a_.*x_^n_.])^p_./(d_+d_.*ProductLog[a_.*x_^n_.]),x_Symbol] :=
  x^(m+1)*(c*ProductLog[a*x^n])^p/(d*(m+n*p+1)) -
  Dist[(m+1)/(c*(m+n*p+1)),Int[x^m*(c*ProductLog[a*x^n])^(p+1)/(d+d*ProductLog[a*x^n]),x]] /;
FreeQ[{a,c,d,m,n,p},x] && NonzeroQ[m+1] && RationalQ[Simplify[p+(m+1)/n]] && Simplify[p+(m+1)/n]<0


(* ::Code:: *)
Int[x_^m_.*(c_.*ProductLog[a_.*x_])^p_./(d_+d_.*ProductLog[a_.*x_]),x_Symbol] :=
  x^m*Gamma[m+p+1,-(m+1)*ProductLog[a*x]]*(c*ProductLog[a*x])^p/
	(a*d*(m+1)*E^(m*ProductLog[a*x])*(-(m+1)*ProductLog[a*x])^(m+p)) /;
FreeQ[{a,c,d,m,p},x] && NonzeroQ[m+1]


(* ::Code:: *)
Int[x_^m_.*(c_.*ProductLog[a_.*x_^n_.])^p_./(d_+d_.*ProductLog[a_.*x_^n_.]),x_Symbol] :=
  -Subst[Int[(c*ProductLog[a*x^(-n)])^p/(x^(m+2)*(d+d*ProductLog[a*x^(-n)])),x],x,1/x] /;
FreeQ[{a,c,d,p},x] && IntegersQ[m,n] && n<0 && NonzeroQ[m+1]


(* ::Code:: *)
Int[u_,x_Symbol] :=
  Subst[Int[Regularize[(x+1)*E^x*SubstFor[ProductLog[x],u,x],x],x],x,ProductLog[x]] /;
FunctionOfQ[ProductLog[x],u,x]
