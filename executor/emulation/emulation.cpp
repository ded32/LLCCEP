#include <stack>
#include <vector>
#include <ctime>
#include <csignal>
#include <iostream>
#include <cfloat>

#include "../window/window.hpp"
#include "../loader/loader.hpp"
#include "emulation.hpp"

#define emufunc static void
#define MAX(a, b) ((a > b)?(a):(b))

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
double *mem = 0;
size_t mem_size = 0;

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

emufunc set(LLCCEP::arg& data, double value);
static double get(LLCCEP::arg& data);

emufunc set_mem(size_t id, double value);
static double get_mem(size_t id);

emufunc (*funcs[])(LLCCEP::inst& data) = {
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
		return init_sdl() && init_window() && init_renderer();
	}

	void run(inst& data)
	{
		if (data.cond & cmp)
			funcs[data.opcode](data);
	}

	void Quit()
	{
		std::cout << "Emulation ended!\nTime is: " << static_cast<double>(clock() - began) / CLOCKS_PER_SEC << "!\n";
                free((void *)mem);
	}
}

emufunc emulate_mov(LLCCEP::inst& data)
{
	set(data.args[0], get(data.args[1]));
}

emufunc emulate_mva(LLCCEP::inst& data)
{
	set_mem(static_cast<size_t>(get(data.args[0])), get(data.args[1]));
}

emufunc emulate_push(LLCCEP::inst& data)
{
	stk.push(get(data.args[0]));
}

emufunc emulate_pop(LLCCEP::inst& data)
{
	stk.pop();
}

emufunc emulate_top(LLCCEP::inst& data)
{
	set(data.args[0], stk.top());
}

emufunc emulate_add(LLCCEP::inst& data)
{
	set(data.args[0], get(data.args[1]) + get(data.args[2]));
}

emufunc emulate_sub(LLCCEP::inst& data)
{
	set(data.args[0], get(data.args[1]) - get(data.args[2]));
}

emufunc emulate_mul(LLCCEP::inst& data)
{
	set(data.args[0], get(data.args[1]) * get(data.args[2]));
}

emufunc emulate_dev(LLCCEP::inst& data)
{
	set(data.args[0], get(data.args[1]) / get(data.args[2]));
}

emufunc emulate_and(LLCCEP::inst& data)
{
	set(data.args[0], static_cast<int64_t>(get(data.args[1])) & static_cast<int64_t>(get(data.args[2])));
}

emufunc emulate_or(LLCCEP::inst& data)
{
	set(data.args[0], static_cast<int64_t>(get(data.args[1])) | static_cast<int64_t>(get(data.args[2])));
}

emufunc emulate_xor(LLCCEP::inst& data)
{
	set(data.args[0], static_cast<int64_t>(get(data.args[1])) ^ static_cast<int64_t>(get(data.args[2])));
}

emufunc emulate_off(LLCCEP::inst& data)
{
	int64_t off = get(data.args[2]);

	if (off < 0)
		set(data.args[0], static_cast<int64_t>(get(data.args[1])) << off);
	else
		set(data.args[0], static_cast<int64_t>(get(data.args[1])) >> off);
}

emufunc emulate_nop(LLCCEP::inst& data)
{
	LLCCEP::Delay(0);
}

emufunc emulate_swi(LLCCEP::inst& data)
{
	int64_t id = static_cast<int64_t>(get(data.args[0]));
	switch (id) {
		case 0:
			std::cout << static_cast<char>(LLCCEP::reg[0]);
			break;

		case 1: {
			size_t count = LLCCEP::reg[0];
			while (mem[count]) {
				std::cout << static_cast<char>(mem[count]);
				count++;
			}
			break;
		}

		case 2:
			std::cout << static_cast<int64_t>(LLCCEP::reg[0]);
			break;

		case 3:
			std::cout << LLCCEP::reg[0];
			break;

		case 4: {
			char chr = 0;
			std::cin >> chr;
			LLCCEP::reg[0] = static_cast<double>(chr);
			break;
		}

		case 5: {
			std::string str = "";
			std::cin >> str;

			for (size_t i = 0; i < str.length(); i++)
				set_mem(LLCCEP::reg[0] + i, str[i]);
			
			LLCCEP::reg[1] = str.length();
			break;
		}

		case 6:
			std::cin >> LLCCEP::reg[0];
			break;

		case 7:
			LLCCEP::set_color(LLCCEP::reg[0]);
			break;

		case 8:
			LLCCEP::set_pixel(static_cast<int>(LLCCEP::reg[0]), static_cast<int>(LLCCEP::reg[1]));
			break;
	
		default:
			std::cerr << "Error!\nAn attempt to do interrupt " << id << " which unknown!\n";
			raise(SIGILL);
	}
}

emufunc emulate_cmp(LLCCEP::inst& data)
{
	double deltha = get(data.args[0]) - get(data.args[1]);
	if (deltha < -DBL_EPSILON)
		cmp = CMP_STATE_LESS;
	else if (deltha > DBL_EPSILON)
		cmp = CMP_STATE_MORE;
	else
		cmp = CMP_STATE_EQU;
}

emufunc emulate_inc(LLCCEP::inst& data)
{
	set(data.args[0], get(data.args[0]) + 1);
}

emufunc emulate_dec(LLCCEP::inst& data)
{
	set(data.args[0], get(data.args[0]) - 1);
}

emufunc set(LLCCEP::arg& data, double value)
{
	switch (data.type) {
		case LLCCEP::ARG_T_MEM:
			set_mem(static_cast<int64_t>(data.value), value);
			break;

		case LLCCEP::ARG_T_REG:
			if (static_cast<int64_t>(data.value) > 31 || static_cast<int64_t>(data.value) < 0) {
				std::cerr << "An attempt to move data to unexisting register!\n";
				raise(SIGSEGV);
			} else
				LLCCEP::reg[static_cast<int64_t>(data.value)] = value;
			break;
	
		default:
			std::cerr << "Error!\nAn attempt to move data to something not memory!\n";
			raise(SIGILL);
	}
}

static double get(LLCCEP::arg& data)
{
	switch (data.type) {
		case LLCCEP::ARG_T_MEM:
			return get_mem(static_cast<size_t>(data.value));
			break;

		case LLCCEP::ARG_T_REG:
			if (static_cast<int64_t>(data.value) > 31 || static_cast<int64_t>(data.value) < 0) {
				std::cerr << "Error!\nAn attempt to get data from unexisting register!\n";
				raise(SIGSEGV);
			} else
				return LLCCEP::reg[static_cast<size_t>(data.value)];
			break;


		case LLCCEP::ARG_T_VAL:
			return data.value;
			break;

		default:
			std::cerr << "Error!\nAn attempt to get data from something unknown by soft-CPU!\n";
			raise(SIGILL);
	}

	return 0;
}

emufunc set_mem(size_t id, double value)
{
	mem_size = MAX(id + 1, mem_size);
	mem = (double *)realloc(mem, mem_size * sizeof(double));
	mem[id] = value;
}

static double get_mem(size_t id)
{
	if (id >= mem_size) {
		std::cout << "Going out of frames of memory!\n";
		raise(SIGSEGV);
	}

	return mem[id];
}

#undef emufunc
#undef MAX
