Begin["System`"]

$SolutionFormula

Begin["`Private`"]

$SolutionFormula = 
{
a,
b,
c,
d,
e,
(*1*){-b/a},
(*2*){(-b - Sqrt[b^2 - 4 a c])/( 2 a), (-b + Sqrt[b^2 - 4 a c])/(2 a)},
(*3*){-(b/(3*a)) - (2^(1/3)*(-b^2 + 3*a*c))/
    (3*a*(-2*b^3 + 9*a*b*c - 27*a^2*d + Sqrt[4*(-b^2 + 3*a*c)^3 + (-2*b^3 + 9*a*b*c - 27*a^2*d)^
          2])^(1/3)) + (-2*b^3 + 9*a*b*c - 27*a^2*d + 
      Sqrt[4*(-b^2 + 3*a*c)^3 + (-2*b^3 + 9*a*b*c - 27*a^2*d)^2])^(1/3)/(3*2^(1/3)*a), 
  -(b/(3*a)) + ((1 + I*Sqrt[3])*(-b^2 + 3*a*c))/
    (3*2^(2/3)*a*(-2*b^3 + 9*a*b*c - 27*a^2*d + Sqrt[4*(-b^2 + 3*a*c)^3 + 
         (-2*b^3 + 9*a*b*c - 27*a^2*d)^2])^(1/3)) - 
   ((1 - I*Sqrt[3])*(-2*b^3 + 9*a*b*c - 27*a^2*d + Sqrt[4*(-b^2 + 3*a*c)^3 + 
         (-2*b^3 + 9*a*b*c - 27*a^2*d)^2])^(1/3))/(6*2^(1/3)*a), 
  -(b/(3*a)) + ((1 - I*Sqrt[3])*(-b^2 + 3*a*c))/
    (3*2^(2/3)*a*(-2*b^3 + 9*a*b*c - 27*a^2*d + Sqrt[4*(-b^2 + 3*a*c)^3 + 
         (-2*b^3 + 9*a*b*c - 27*a^2*d)^2])^(1/3)) - 
   ((1 + I*Sqrt[3])*(-2*b^3 + 9*a*b*c - 27*a^2*d + Sqrt[4*(-b^2 + 3*a*c)^3 + 
         (-2*b^3 + 9*a*b*c - 27*a^2*d)^2])^(1/3))/(6*2^(1/3)*a)},
(*4*){-(b/(4*a)) - (1/2)*Sqrt[b^2/(4*a^2) - (2*c)/(3*a) + (2^(1/3)*(c^2 - 3*b*d + 12*a*e))/
       (3*a*(2*c^3 - 9*b*c*d + 27*a*d^2 + 27*b^2*e - 72*a*c*e + 
          Sqrt[-4*(c^2 - 3*b*d + 12*a*e)^3 + (2*c^3 - 9*b*c*d + 27*a*d^2 + 27*b^2*e - 72*a*c*e)^
             2])^(1/3)) + (1/(3*2^(1/3)*a))*(2*c^3 - 9*b*c*d + 27*a*d^2 + 27*b^2*e - 72*a*c*e + 
         Sqrt[-4*(c^2 - 3*b*d + 12*a*e)^3 + (2*c^3 - 9*b*c*d + 27*a*d^2 + 27*b^2*e - 72*a*c*e)^
            2])^(1/3)] - (1/2)*Sqrt[b^2/(2*a^2) - (4*c)/(3*a) - 
      (2^(1/3)*(c^2 - 3*b*d + 12*a*e))/(3*a*(2*c^3 - 9*b*c*d + 27*a*d^2 + 27*b^2*e - 72*a*c*e + 
          Sqrt[-4*(c^2 - 3*b*d + 12*a*e)^3 + (2*c^3 - 9*b*c*d + 27*a*d^2 + 27*b^2*e - 72*a*c*e)^
             2])^(1/3)) - (1/(3*2^(1/3)*a))*(2*c^3 - 9*b*c*d + 27*a*d^2 + 27*b^2*e - 72*a*c*e + 
         Sqrt[-4*(c^2 - 3*b*d + 12*a*e)^3 + (2*c^3 - 9*b*c*d + 27*a*d^2 + 27*b^2*e - 72*a*c*e)^
            2])^(1/3) - (-(b^3/a^3) + (4*b*c)/a^2 - (8*d)/a)/
       (4*Sqrt[b^2/(4*a^2) - (2*c)/(3*a) + (2^(1/3)*(c^2 - 3*b*d + 12*a*e))/
           (3*a*(2*c^3 - 9*b*c*d + 27*a*d^2 + 27*b^2*e - 72*a*c*e + 
              Sqrt[-4*(c^2 - 3*b*d + 12*a*e)^3 + (2*c^3 - 9*b*c*d + 27*a*d^2 + 27*b^2*e - 
                  72*a*c*e)^2])^(1/3)) + (1/(3*2^(1/3)*a))*(2*c^3 - 9*b*c*d + 27*a*d^2 + 
             27*b^2*e - 72*a*c*e + Sqrt[-4*(c^2 - 3*b*d + 12*a*e)^3 + (2*c^3 - 9*b*c*d + 
                 27*a*d^2 + 27*b^2*e - 72*a*c*e)^2])^(1/3)])], 
  -(b/(4*a)) - (1/2)*Sqrt[b^2/(4*a^2) - (2*c)/(3*a) + (2^(1/3)*(c^2 - 3*b*d + 12*a*e))/
       (3*a*(2*c^3 - 9*b*c*d + 27*a*d^2 + 27*b^2*e - 72*a*c*e + 
          Sqrt[-4*(c^2 - 3*b*d + 12*a*e)^3 + (2*c^3 - 9*b*c*d + 27*a*d^2 + 27*b^2*e - 72*a*c*e)^
             2])^(1/3)) + (1/(3*2^(1/3)*a))*(2*c^3 - 9*b*c*d + 27*a*d^2 + 27*b^2*e - 72*a*c*e + 
         Sqrt[-4*(c^2 - 3*b*d + 12*a*e)^3 + (2*c^3 - 9*b*c*d + 27*a*d^2 + 27*b^2*e - 72*a*c*e)^
            2])^(1/3)] + (1/2)*Sqrt[b^2/(2*a^2) - (4*c)/(3*a) - 
      (2^(1/3)*(c^2 - 3*b*d + 12*a*e))/(3*a*(2*c^3 - 9*b*c*d + 27*a*d^2 + 27*b^2*e - 72*a*c*e + 
          Sqrt[-4*(c^2 - 3*b*d + 12*a*e)^3 + (2*c^3 - 9*b*c*d + 27*a*d^2 + 27*b^2*e - 72*a*c*e)^
             2])^(1/3)) - (1/(3*2^(1/3)*a))*(2*c^3 - 9*b*c*d + 27*a*d^2 + 27*b^2*e - 72*a*c*e + 
         Sqrt[-4*(c^2 - 3*b*d + 12*a*e)^3 + (2*c^3 - 9*b*c*d + 27*a*d^2 + 27*b^2*e - 72*a*c*e)^
            2])^(1/3) - (-(b^3/a^3) + (4*b*c)/a^2 - (8*d)/a)/
       (4*Sqrt[b^2/(4*a^2) - (2*c)/(3*a) + (2^(1/3)*(c^2 - 3*b*d + 12*a*e))/
           (3*a*(2*c^3 - 9*b*c*d + 27*a*d^2 + 27*b^2*e - 72*a*c*e + 
              Sqrt[-4*(c^2 - 3*b*d + 12*a*e)^3 + (2*c^3 - 9*b*c*d + 27*a*d^2 + 27*b^2*e - 
                  72*a*c*e)^2])^(1/3)) + (1/(3*2^(1/3)*a))*(2*c^3 - 9*b*c*d + 27*a*d^2 + 
             27*b^2*e - 72*a*c*e + Sqrt[-4*(c^2 - 3*b*d + 12*a*e)^3 + (2*c^3 - 9*b*c*d + 
                 27*a*d^2 + 27*b^2*e - 72*a*c*e)^2])^(1/3)])], 
  -(b/(4*a)) + (1/2)*Sqrt[b^2/(4*a^2) - (2*c)/(3*a) + (2^(1/3)*(c^2 - 3*b*d + 12*a*e))/
       (3*a*(2*c^3 - 9*b*c*d + 27*a*d^2 + 27*b^2*e - 72*a*c*e + 
          Sqrt[-4*(c^2 - 3*b*d + 12*a*e)^3 + (2*c^3 - 9*b*c*d + 27*a*d^2 + 27*b^2*e - 72*a*c*e)^
             2])^(1/3)) + (1/(3*2^(1/3)*a))*(2*c^3 - 9*b*c*d + 27*a*d^2 + 27*b^2*e - 72*a*c*e + 
         Sqrt[-4*(c^2 - 3*b*d + 12*a*e)^3 + (2*c^3 - 9*b*c*d + 27*a*d^2 + 27*b^2*e - 72*a*c*e)^
            2])^(1/3)] - (1/2)*Sqrt[b^2/(2*a^2) - (4*c)/(3*a) - 
      (2^(1/3)*(c^2 - 3*b*d + 12*a*e))/(3*a*(2*c^3 - 9*b*c*d + 27*a*d^2 + 27*b^2*e - 72*a*c*e + 
          Sqrt[-4*(c^2 - 3*b*d + 12*a*e)^3 + (2*c^3 - 9*b*c*d + 27*a*d^2 + 27*b^2*e - 72*a*c*e)^
             2])^(1/3)) - (1/(3*2^(1/3)*a))*(2*c^3 - 9*b*c*d + 27*a*d^2 + 27*b^2*e - 72*a*c*e + 
         Sqrt[-4*(c^2 - 3*b*d + 12*a*e)^3 + (2*c^3 - 9*b*c*d + 27*a*d^2 + 27*b^2*e - 72*a*c*e)^
            2])^(1/3) + (-(b^3/a^3) + (4*b*c)/a^2 - (8*d)/a)/
       (4*Sqrt[b^2/(4*a^2) - (2*c)/(3*a) + (2^(1/3)*(c^2 - 3*b*d + 12*a*e))/
           (3*a*(2*c^3 - 9*b*c*d + 27*a*d^2 + 27*b^2*e - 72*a*c*e + 
              Sqrt[-4*(c^2 - 3*b*d + 12*a*e)^3 + (2*c^3 - 9*b*c*d + 27*a*d^2 + 27*b^2*e - 
                  72*a*c*e)^2])^(1/3)) + (1/(3*2^(1/3)*a))*(2*c^3 - 9*b*c*d + 27*a*d^2 + 
             27*b^2*e - 72*a*c*e + Sqrt[-4*(c^2 - 3*b*d + 12*a*e)^3 + (2*c^3 - 9*b*c*d + 
                 27*a*d^2 + 27*b^2*e - 72*a*c*e)^2])^(1/3)])], 
  -(b/(4*a)) + (1/2)*Sqrt[b^2/(4*a^2) - (2*c)/(3*a) + (2^(1/3)*(c^2 - 3*b*d + 12*a*e))/
       (3*a*(2*c^3 - 9*b*c*d + 27*a*d^2 + 27*b^2*e - 72*a*c*e + 
          Sqrt[-4*(c^2 - 3*b*d + 12*a*e)^3 + (2*c^3 - 9*b*c*d + 27*a*d^2 + 27*b^2*e - 72*a*c*e)^
             2])^(1/3)) + (1/(3*2^(1/3)*a))*(2*c^3 - 9*b*c*d + 27*a*d^2 + 27*b^2*e - 72*a*c*e + 
         Sqrt[-4*(c^2 - 3*b*d + 12*a*e)^3 + (2*c^3 - 9*b*c*d + 27*a*d^2 + 27*b^2*e - 72*a*c*e)^
            2])^(1/3)] + (1/2)*Sqrt[b^2/(2*a^2) - (4*c)/(3*a) - 
      (2^(1/3)*(c^2 - 3*b*d + 12*a*e))/(3*a*(2*c^3 - 9*b*c*d + 27*a*d^2 + 27*b^2*e - 72*a*c*e + 
          Sqrt[-4*(c^2 - 3*b*d + 12*a*e)^3 + (2*c^3 - 9*b*c*d + 27*a*d^2 + 27*b^2*e - 72*a*c*e)^
             2])^(1/3)) - (1/(3*2^(1/3)*a))*(2*c^3 - 9*b*c*d + 27*a*d^2 + 27*b^2*e - 72*a*c*e + 
         Sqrt[-4*(c^2 - 3*b*d + 12*a*e)^3 + (2*c^3 - 9*b*c*d + 27*a*d^2 + 27*b^2*e - 72*a*c*e)^
            2])^(1/3) + (-(b^3/a^3) + (4*b*c)/a^2 - (8*d)/a)/
       (4*Sqrt[b^2/(4*a^2) - (2*c)/(3*a) + (2^(1/3)*(c^2 - 3*b*d + 12*a*e))/
           (3*a*(2*c^3 - 9*b*c*d + 27*a*d^2 + 27*b^2*e - 72*a*c*e + 
              Sqrt[-4*(c^2 - 3*b*d + 12*a*e)^3 + (2*c^3 - 9*b*c*d + 27*a*d^2 + 27*b^2*e - 
                  72*a*c*e)^2])^(1/3)) + (1/(3*2^(1/3)*a))*(2*c^3 - 9*b*c*d + 27*a*d^2 + 
             27*b^2*e - 72*a*c*e + Sqrt[-4*(c^2 - 3*b*d + 12*a*e)^3 + (2*c^3 - 9*b*c*d + 
                 27*a*d^2 + 27*b^2*e - 72*a*c*e)^2])^(1/3)])]},
a-b,
a (-1)^b
}

End[]

Install@StringJoin[$Package,"Polynomial.dll"];

End[]
