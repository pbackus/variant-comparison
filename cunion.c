#include <assert.h>

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

enum tag
{
	TAG_T0,
	TAG_T1,
	TAG_T2,
	TAG_T3,
	TAG_T4,
	TAG_T5,
	TAG_T6,
	TAG_T7,
	TAG_T8,
	TAG_T9
};

struct variant
{
	union {
		struct T0 t0;
		struct T1 t1;
		struct T2 t2;
		struct T3 t3;
		struct T4 t4;
		struct T5 t5;
		struct T6 t6;
		struct T7 t7;
		struct T8 t8;
		struct T9 t9;
	} data;
	enum tag tag;
};

int visit_T0() { return 3; }
int visit_T1() { return 5; }
int visit_T2() { return 8; }
int visit_T3() { return 13; }
int visit_T4() { return 21; }
int visit_T5() { return 34; }
int visit_T6() { return 55; }
int visit_T7() { return 89; }
int visit_T8() { return 144; }
int visit_T9() { return 233; }

int do_visit(struct variant v)
{
	switch(v.tag) {
		case TAG_T0: return visit_T0();
		case TAG_T1: return visit_T1();
		case TAG_T2: return visit_T2();
		case TAG_T3: return visit_T3();
		case TAG_T4: return visit_T4();
		case TAG_T5: return visit_T5();
		case TAG_T6: return visit_T6();
		case TAG_T7: return visit_T7();
		case TAG_T8: return visit_T8();
		case TAG_T9: return visit_T9();
		default: assert(0);
	}
}
