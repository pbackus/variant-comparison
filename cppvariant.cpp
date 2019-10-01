#include <variant>

// Source: https://en.cppreference.com/w/cpp/utility/variant/visit
template<class... Ts> struct overloaded : Ts... { using Ts::operator()...; };
template<class... Ts> overloaded(Ts...) -> overloaded<Ts...>;

struct T0 {};
struct T1 {};
struct T2 {};
struct T3 {};
struct T4 {};
struct T5 {};
struct T6 {};
struct T7 {};
struct T8 {};
struct T9 {};

using example_variant = std::variant<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9>;

int do_visit(example_variant v)
{
	return std::visit(overloaded {
		[](T0 val) { return 3; },
		[](T1 val) { return 5; },
		[](T2 val) { return 8; },
		[](T3 val) { return 13; },
		[](T4 val) { return 21; },
		[](T5 val) { return 34; },
		[](T6 val) { return 55; },
		[](T7 val) { return 89; },
		[](T8 val) { return 144; },
		[](T9 val) { return 233; },
	}, v);
}
