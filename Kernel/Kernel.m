(* Begin["System`"] *)
(* CInstall["kernel"] *)

CProc["kernel",CInstall,CUninstall]

SetAttributes[Information, {HoldAll, Protected, ReadProtected}]
SetAttributes[Increment, {HoldFirst, Protected, ReadProtected}]
SetAttributes[Decrement, {HoldFirst, Protected, ReadProtected}]
SetAttributes[PreIncrement, {HoldFirst, Protected, ReadProtected}]
SetAttributes[PreDecrement, {HoldFirst, Protected, ReadProtected}]
SetAttributes[Defer,{HoldAll,Protected,ReadProtected}]
SetAttributes[Map,{Protected}]
SetAttributes[Part,{NHoldRest,Protected,ReadProtected}]
SetAttributes[Extract,{NHoldRest,Protected}]
SetAttributes[First,Protected]
SetAttributes[Last,Protected]
SetAttributes[Most,Protected]
SetAttributes[Rest,Protected]
SetAttributes[Take,{NHoldRest,Protected}]
SetAttributes[Drop,{NHoldRest,Protected}]
SetAttributes[Scan,Protected]
SetAttributes[Level,Protected]
SetAttributes[ReplacePart,Protected]
SetAttributes[Prepend,Protected]
SetAttributes[Append,Protected]
SetAttributes[Reverse,Protected]
SetAttributes[Distribute,Protected]
SetAttributes[Symbols,Protected]
SetAttributes[List,{Locked, Protected}]
SetAttributes[Range,{Listable,Protected}]
SetAttributes[Count,Protected]
SetAttributes[Union,{Flat, Protected}] (* Union has attribute OneIdentity in mathematica *)
SetAttributes[ConstantArray, Protected]
SetAttributes[Min, {Flat, NumericFunction, Orderless, Protected}]
SetAttributes[Max, {Flat, NumericFunction, Orderless, Protected, ReadProtected}]
SetAttributes[Function, Protected]
SetAttributes[TraceRule, {Protected, HoldAll}]
SetAttributes[Quiet, {Protected, HoldAll}]

Default[Plus] = 0
Default[Times] = 1
Default[Power] = 1

(* End[] *)