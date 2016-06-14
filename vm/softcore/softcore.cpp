#include <stack>

#include "./../drivers/ram/ram.hpp"

#include "softcore.hpp"
#include "fp.hpp"
#include "./../program/program.hpp"

namespace LLCCEP_vm {
	namespace __added__ {
		::std::stack<double> stk;
		double cmp = 0;
		double regs[32] = {};
	}
}

double get(LLCCEP_vm::arg &data) 
{
	switch (data.type) {
		case ARG_T_REG:
			if (DBL_AE(data.val, 31) || 
			    DBL_L(data.val, 0)) {
				throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
					"Error!\n"
					"Overbounding while reading data from register!\n"));
			} else
				return LLCCEP_vm::__added__::regs[static_cast<long long>(data.val)];
			break;

		case ARG_T_MEM:
			if (DBL_AE(data.val, get_mem_size()) ||
			    DBL_L(data.val, 0)) {
				throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
					"Error!\n"
					"Overbouding while reading data from RAM!\n"));
			} else
				return access_mem_data<double>(static_cast<long long>(data.val));
			break;

		case ARG_T_VAL:
			return data.val;
			break;

		default:
			throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
				"Error!\n"
				"Invalid or damaged binary file!\n"));
	}

	return 0;
}

void set(LLCCEP_vm::arg &what, double val)
{
	switch (data.type) {
		case ARG_T_REG:
			if (DBL_AE(data.val, 31) ||
			    DBL_L(data.val, 0)) {
				throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
					"Error!\n"
					"Overbounding while writing data to register!\n"));
			} else
				LLCCEP_vm::__added__::regs[what.val] = val;
			break;

		case ARG_T_MEM:
			if (DBL_AE(data.val, get_mem_size()) ||
			    DBL_L(data.val, 0)) {
				throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
					"Error!\n"
					"Overbounding while writing data to mem!\n"));
			} else
				access_mem_data<double>(static_cast<long long>(data.val), val);
			break;

		case ARG_T_VAL:
			throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
				"Error!\n"
				"An attempt of writing data to non-memory!\n"));
			break;

		default:
			throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
				"Error!\n"
				"Invalid or damaged binary file!\n"));
	}
}

inline void emulated_mov(LLCCEP_vm::instruction &data)
{
	set(data.args[0], get(data.args[1]));
}

inline void emulated_mva(LLCCEP_vm::instruction &data)
{
	access_mem_data<double>(
		static_cast<long long unsigned>(get(data.args[0])), 
		get(data.args[1]));
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
	switch (static_cast<long long unsigned>(get(data.args[0]))) {
		case 0: // out char
			::std::cout << static_cast<unsigned char(get(data.args[1]));
			break;

		case 1: // out num
			::std::cout << get(data.args[1]);
			break;

		case 2: // round num
			set(data.args[1], static_cast<long long>(get(data.args[2]) + 0.5));
			break;

		case 3: // out string
			::std::cout << access_mem_data<char *>(static_cast<long long unsigned>(get(data.args[1])));
			break;

		case 4: {
			unsigned char val = 0;
			::std::cin >> val;
			set(data.args[1], val);
			break;
		}

		case 5: {
			double val = 0;
			::std::cin >> val;
			set(data.args[1], val);
			break
		}

		case 6: {
			::std::string val = "";
			::std::cin >> val;

			for (size_t i = 0; i < val.length(); i++)
				access_mem_data<char>(static_cast<long long unsigned>(get(data.args[1])), val[i]);

			break;
		}

		default:
			throw DEFAULT_EXCEPTION(CONSTRUCT_MSG(
				"Error!\n"
				"No swi #%llu", 
				static_cast<long long unsigned>(get(data.args[0]))));
	}
}

inline void emulated_cmp(LLCCEP_vm::instruction &data)
{
	LLCCEP_vm::__added__::cmp = get(data.args[0]) - get(data.args[1]);
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
	switch (get(data.args[0])) {
		case 0:
			LLCCEP_vm::set_clr(static_cast<uint32_t>(get(data.args[1])));
			break;

		case 1: {
			uint16_t data[2] = {
				get(data.args[1]) & 0xFFFF,
				(get(data.args[1]) >> 16) & 0xFFFF
			};
			LLCCEP_vm::set_pix(data[0], data[1]);

			break;
		}

		default:
			throw DEFAULT_EXCEPTION(CONSTRUCT_MSG(
				"Error!\n"
				"No port #%llu!\n",
				static_cast<long long unsigned>(get(data.args[0]))));
	}
}
