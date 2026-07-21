/*
Order of evaluation for most of the binary operators is left undefined
to give the compiler opportunities for optimization. This strategy presents
a trade-off between efficient code generation and potential pitfalls in the use
of the language by the programmer. Do you consider that an acceptable trade-off?
Why or why not?
*/

// yes it is acceptable.
// if the programmer wants to force a particular order of evaluation,
// they can define the results of the various functions they wish to call 
// in the desired order, e.g.:
// 
// f() + g() * h() + j()
// 
// can become something like
//
// auto eff = f();
// auto gee = g();
// auto aych = h();
// auto jay = j();
//
// if a left-to-right order of evaluation is desired, etc.
