#include <stack>

#include "softcore.hpp"
#include "./../program.hpp"

namespace LLCCEP_vm {
	namespace __added__ {
		::std::stack<double> stk;
	}
}

inline void emulated_mov(LLCCEP_vm::instruction &data)
{
	set(data.args[0], get(data.args[1]));
}

inline void emulated_mva(LLCCEP_vm::instruction &data)
{
	set
}

inline void emulated_push(LLCCEP_vm::instruction &data)
{
	LLCCEP_vm::__added__::stk.push(get(data.args[0]))
}

inline void emulated_pop(LLCCEP_vm::instruction &data)
{
	LLCCEP_vm::__added__::stk.pop();
}

inline void emulated_top(LLCCEP_vm::instruction &data)
{
	set(data.args[0], LLCCEP_vm::__added__::stk.top());
}

inline void emulated_add(LLCCEP_vm::instruction &data)
{
	set(data.args[0], get(data.args[1]) + get(data.args[2]));
}

inline void emulated_sub(LLCCEP_vm::instruction &data)
{
	set(data.args[0], get(data.args[1]) + get(data.args[2]));
}

inline void emulated_mul(LLCCEP_vm::instruction &data)
{
	set(data.args[0], get(data.args[1]) * get(data.args[2]));
}

inline void emulated_dev(LLCCEP_vm::instruction &data)
{
	set(data.args[0], get(data.args[1]) / get(data.args[2]));
}

inline void emulated_and(LLCCEP_vm::instruction &data)
{
	set(data.args[0], 
	    static_cast<long long>(get(data.args[1])) & 
	    static_cast<long long>(get(data.args[2])));
}

inline void emulated_or(LLCCEP_vm::instruction &data)
{
	set(data.args[0],
	    static_cast<long long>(get(data.args[1])) |
	    static_cast<long long>(get(data.args[2])));
}

inline void emulated_xor(LLCCEP_vm::instruction &data)
{
	set(data.args[0],
	    static_cast<long long>(get(data.args[1])) ^
	    static_cast<long long>(get(data.args[2])));
}

inline void emulated_off(LLCCEP_vm::instruction &data)
{
	unsigned direction = ((get(data.args[0]) >= 0)?(1):(-1));
	set(data.args[0],
	    ((direction == -1)
            ?(static_cast<long long>(get(data.args[1])) <<
	      static_cast<long long>(get(data.args[2])))
	    :(static_cast<long long>(get(data.args[1])) >>
	      static_cast<long long>(get(data.args[2])))));
}

inline void emulated_nop(LLCCEP_vm::instruction &data)
{
	(void)0;
}

inline void emulated_swi(LLCCEP_vm::instruction &data)
{
	// TODO: internal swi stuff
}

inline void emulated_cmp(LLCCEP_vm::instruction &data)
{
	// TODO: internal cmp stuff
}

inline void emulated_inc(LLCCEP_vm::instruction &data)
{
	set(data.args[0], get(data.args[0]) + 1);
}

inline void emulated_dec(LLCCEP_vm::instruction &data)
{
	set(data.args[0], get(data.args[0]) - 1);
}

inline void emulated_sqrt(LLCCEP_vm::instruction &data)
{
	set(data.args[0], sqrt(get(data.args[1])));
}

inline void emulated_sin(LLCCEP_vm::instruction &data)
{
	set(data.args[0], sin(get(data.args[1])));
}

inline void emulated_cos(LLCCEP_vm::instruction &data)
{
	set(data.args[0], cos(get(data.args[1])));
}

inline void emulated_ptan(LLCCEP_vm::instruction &data)
{
	set(data.args[0], tan(get(data.args[1])));
}

inline void emulated_patan(LLCCEP_vm::instruction &data)
{
	set(data.args[0], atan(get(data.args[1])));
}

inline void emulated_ldc(LLCCEP_vm::instruction &data)
{
	switch (get(data.args[1])) {
		case 0:
			set(data.args[0], 1);
			break;

		case 1:
			set(data.args[0], log2(10));
			break;

		case 2:
			set(data.args[0], M_LOG2E);
			break;

		case 3:
			set(data.args[0], M_PI);
			break;

		case 4:
			set(data.args[0], log10(2));
			break;

		case 5:
			set(data.args[0], M_LN2);
			break;

		case 6:
			set(data.args[0], 0);
			break;

		default:
			break;
	}
}

inline void emulated_outp(LLCCEP_vm::instruction &data)
{
	// TODO: Internal stuff, do later
}
