import std.variant;

struct T0 {}
struct T1 {}
struct T2 {}
struct T3 {}
struct T4 {}
struct T5 {}
struct T6 {}
struct T7 {}
struct T8 {}
struct T9 {}

alias ExampleAlgebraic = Algebraic!(T0, T1, T2, T3, T4, T5, T6, T7, T8, T9);

int do_visit(ExampleAlgebraic a)
{
	return a.visit!(
		(T0 val) => 3,
		(T1 val) => 5,
		(T2 val) => 8,
		(T3 val) => 13,
		(T4 val) => 21,
		(T5 val) => 34,
		(T6 val) => 55,
		(T7 val) => 89,
		(T8 val) => 144,
		(T9 val) => 233,
	);
}
