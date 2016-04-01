#include <stack>
#include <vector>
#include <ctime>

#include "../window/window.hpp"

#define emufunc static void

// AL - EQ - LS - MR
enum cond_t: short {
	COND_T_AL = 0b1000,
	COND_T_EQ = 0b0100,
	COND_T_NE = 0b0011,
	COND_T_AE = 0b0101,
	COND_T_LE = 0b0110,
	COND_T_LS = 0b0010,
	COND_T_AV = 0b0001
};

enum cmp_state: short {
	CMP_STATE_MORE = 0b1001,
	CMP_STATE_LESS = 0b1010,
	CMP_STATE_EQU  = 0b1100,
	CMP_STATE_NONE = 0b1000
};

static std::stack <double> stk;
static cmp_state cmp = CMP_STATE_NONE;
static clock_t began = 0;

emufunc emulate_mov(LLCCEP::inst& data);
emufunc emulate_mva(LLCCEP::inst& data);
emufunc emulate_push(LLCCEP::inst& data);
emufunc emulate_pop(LLCCEP::inst& data);
emufunc emulate_top(LLCCEP::inst& data);
emufunc emulate_add(LLCCEP::inst& data);
emufunc emulate_sub(LLCCEP::inst& data);
emufunc emulate_mul(LLCCEP::inst& data);
emufunc emulate_dev(LLCCEP::inst& data);
emufunc emulate_and(LLCCEP::inst& data);
emufunc emulate_or(LLCCEP::inst& data);
emufunc emulate_xor(LLCCEP::inst& data);
emufunc emulate_off(LLCCEP::inst& data);
emufunc emulate_nop(LLCCEP::inst& data);
emufunc emulate_swi(LLCCEP::inst& data);
emufunc emulate_cmp(LLCCEP::inst& data);
emufunc emulate_inc(LLCCEP::inst& data);
emufunc emulate_dec(LLCCEP::inst& data);

emufunc (*funcs[]) = {
	emulate_mov,
	emulate_mva,
	emulate_push,
	emulate_pop,
	emulate_top,
	emulate_add,
	emulate_sub,
	emulate_mul,
	emulate_dev,
	emulate_and,
	emulate_or,
	emulate_xor,
	emulate_off,
	emulate_nop,
	emulate_swi,
	emulate_cmp,
	emulate_inc,
	emulate_dec
};

namespace LLCCEP {
	bool Start()
	{
		began = clock();
		return InitSDL() && InitWindow() && InitRenderer();
	}

	void run(inst& data)
	{
		if (inst.cond & cmp)
			funcs[data.opcode](inst);
	}

	void Stop()
	{
		std::cout << "Emulation ended!\nTime is: " << static_cast<double>(clock() - began) / CLOCKS_PER_SEC;
	}
}
