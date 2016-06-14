#include <stack>
#include <cmath>

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

static double get(LLCCEP_vm::arg &data) 
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

static void set(LLCCEP_vm::arg &what, double val)
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

static inline void emulated_mov(LLCCEP_vm::instruction &data)
{
	set(data.args[0], get(data.args[1]));
}

static inline void emulated_mva(LLCCEP_vm::instruction &data)
{
	access_mem_data<double>(
		static_cast<long long unsigned>(get(data.args[0])), 
		get(data.args[1]));
}

static inline void emulated_push(LLCCEP_vm::instruction &data)
{
	LLCCEP_vm::__added__::stk.push(get(data.args[0]))
}

static inline void emulated_pop(LLCCEP_vm::instruction &data)
{
	LLCCEP_vm::__added__::stk.pop();
}

static inline void emulated_top(LLCCEP_vm::instruction &data)
{
	set(data.args[0], LLCCEP_vm::__added__::stk.top());
}

static inline void emulated_add(LLCCEP_vm::instruction &data)
{
	set(data.args[0], get(data.args[1]) + get(data.args[2]));
}

static inline void emulated_sub(LLCCEP_vm::instruction &data)
{
	set(data.args[0], get(data.args[1]) + get(data.args[2]));
}

static inline void emulated_mul(LLCCEP_vm::instruction &data)
{
	set(data.args[0], get(data.args[1]) * get(data.args[2]));
}

static inline void emulated_dev(LLCCEP_vm::instruction &data)
{
	set(data.args[0], get(data.args[1]) / get(data.args[2]));
}

static inline void emulated_and(LLCCEP_vm::instruction &data)
{
	set(data.args[0], 
	    static_cast<long long>(get(data.args[1])) & 
	    static_cast<long long>(get(data.args[2])));
}

static inline void emulated_or(LLCCEP_vm::instruction &data)
{
	set(data.args[0],
	    static_cast<long long>(get(data.args[1])) |
	    static_cast<long long>(get(data.args[2])));
}

static inline void emulated_xor(LLCCEP_vm::instruction &data)
{
	set(data.args[0],
	    static_cast<long long>(get(data.args[1])) ^
	    static_cast<long long>(get(data.args[2])));
}

static inline void emulated_off(LLCCEP_vm::instruction &data)
{
	unsigned direction = ((get(data.args[0]) >= 0)?(1):(-1));
	set(data.args[0],
	    ((direction == -1)
            ?(static_cast<long long>(get(data.args[1])) <<
	      static_cast<long long>(get(data.args[2])))
	    :(static_cast<long long>(get(data.args[1])) >>
	      static_cast<long long>(get(data.args[2])))));
}

static inline void emulated_nop(LLCCEP_vm::instruction &data)
{
	(void)0;
}

static void emulated_swi(LLCCEP_vm::instruction &data)
{
	switch (static_cast<long long unsigned>(get(data.args[0]))) {
		case 0: // out char
			::std::cout << static_cast<unsigned char>(LLCCEP_vm::__added__::regs[0]);
			break;

		case 1: // round num
			LLCCEP_vm::__added__::regs[1] = static_cast<long long>(LLCCEP_vm::__added__::regs[0] + 0.5);
			break;

		case 2: // out string
			::std::cout << access_mem_data<char *>(static_cast<long long unsigned>(LLCCEP_vm::__added__::regs[0]));
			break;

		case 3: { // read char
			unsigned char val = 0;
			::std::cin >> val;
			LLCCEP_vm::__added__::regs[0] = val;
			break;
		}

		case 4: {  // read string
			::std::string val = "";
			::std::cin >> val;

			for (size_t i = 0; i < val.length(); i++)
				access_mem_data<char>(static_cast<long long unsigned>(LLCCEP_vm::__added__::regs[0] + i, val[i]);

			break;
		}

#if !VM
		case 7: { // open file
			if (static_cast<long long>(LLCCEP_vm::__added__::regs[0]) == 0)) {
				::std::ifstream in;
				in.open(LLCCEP_vm::get_mem(static_cast<size_t>(LLCCEP_vm::__added__::regs[1])));
				LLCCEP_vm::__added__::inputs.push_back(::std::move(in));
			} else {
				::std::ofstream out;
				out.open(LLCCEP_vm::get_mem(static_cast<size_t>(LLCCEP_vm::__added__::regs[0])));
				LLCCEP_vm::__added__::outputs.push_back(::std::move(out));
			}
			break;
		}

		case 9: { // close file
			if (static_cast<long long>(LLCCEP_vm::__added__::regs[0]) == 0) {
				if (static_cast<long long>(LLCCEP_vm::__added__::regs[1]) >= LLCCEP_vm::__added__::inputs.size() ||
				    static_cast<long long>(LLCCEP_vm::__added__::regs[1]) < 0) {
					throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
						"Overbounding due file accessing: no 'r' file %lls",
						static_cast<long long>(LLCCEP_vm::__added__::regs[1])));
				}

				LLCCEP_vm::__added__::inputs[static_cast<long long>(LLCCEP_vm::__added__::regs[1])].close();
			} else {
				if (static_cast<long long>(LLCCEP_vm::__added__::regs[1]) >= LLCCEP_vm::__added__::outputs.size() ||
				    static_cast<long long>(LLCCEP_vm::__added__::regs[1]) < 0) {
					throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
						"Overbounding due file accessing: no 'w' file %lls",
						static_cast<long long>(LLCCEP_vm::__added__::regs[1]))));
				}

				LLCCEP_vm::__added__::outputs[static_cast<long long>(LLCCEP_vm::__added__::regs[1])].close();
			}
			break;
		}

		case 10: { // r/w byte to/from file
			if (static_cast<long long>(LLCCEP_vm::__added__::regs[0]) == 0) {
				if (static_cast<long long>(LLCCEP_vm::__added__::regs[1]) >= LLCCEP_vm::__added__::inputs.size() ||
				    static_cast<long long>(LLCCEP_vm::__added__::regs[1]) < 0) {
					throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
						"Overbounding due file accessing: no 'r' file %lls",
						static_cast<long long>(LLCCEP_vm::__added__::regs[1])));
				}

				uint8_t val;
				LLCCEP_vm::__added__::inputs[static_cast<long long>(LLCCEP_vm::__added__::regs[1])] >> val;
				LLCCEP_vm::__added__::regs[2] = val;
			} else {
				if (static_cast<long long>(LLCCEP_vm::__added__::regs[1]) >= LLCCEP_vm::__added__::outputs.size() ||
				    static_cast<long long>(LLCCEP_vm::__added__::regs[1]) < 0) {
					throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
						"Overbounding due file accessing: no 'w' file %lls",
						static_cast<long long>(LLCCEP_vm::__added__::regs[1])));
				}

				LLCCEP_vm::__added__::inputs[static_cast<long long>(LLCCEP_vm::__added__::regs[1])] <<
					static_cast<uint8_t>(LLCCEP_vm::__added__::regs[2]);
			}
			break;
		}
#endif

		default:
			throw DEFAULT_EXCEPTION(CONSTRUCT_MSG(
				"Error!\n"
				"No swi #%llu", 
				static_cast<long long unsigned>(get(data.args[0]))));
	}
}

static inline void emulated_cmp(LLCCEP_vm::instruction &data)
{
	LLCCEP_vm::__added__::cmp = get(data.args[0]) - get(data.args[1]);
}

static inline void emulated_inc(LLCCEP_vm::instruction &data)
{
	set(data.args[0], get(data.args[0]) + 1);
}

static inline void emulated_dec(LLCCEP_vm::instruction &data)
{
	set(data.args[0], get(data.args[0]) - 1);
}

static inline void emulated_sqrt(LLCCEP_vm::instruction &data)
{
	set(data.args[0], ::std::sqrt(get(data.args[1])));
}

static inline void emulated_sin(LLCCEP_vm::instruction &data)
{
	set(data.args[0], ::std::sin(get(data.args[1])));
}

static inline void emulated_cos(LLCCEP_vm::instruction &data)
{
	set(data.args[0], ::std::cos(get(data.args[1])));
}

static inline void emulated_ptan(LLCCEP_vm::instruction &data)
{
	set(data.args[0], ::std::tan(get(data.args[1])));
}

static inline void emulated_patan(LLCCEP_vm::instruction &data)
{
	set(data.args[0], ::std::atan(get(data.args[1])));
}

static void emulated_ldc(LLCCEP_vm::instruction &data)
{
	switch (get(data.args[1])) {
		case 0:
			set(data.args[0], 1);
			break;

		case 1:
			set(data.args[0], ::std::log2(10));
			break;

		case 2:
			set(data.args[0], M_LOG2E);
			break;

		case 3:
			set(data.args[0], M_PI);
			break;

		case 4:
			set(data.args[0], ::std::log10(2));
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

static void emulated_outp(LLCCEP_vm::instruction &data)
{
	switch (static_cast<long long>(get(data.args[0]))) {
		case 0:
			LLCCEP_vm::set_clr(static_cast<uint32_t>(get(data.args[1])));
			break;

		case 1: {
			uint16_t pos[2] = {
				static_cast<long long>(get(data.args[1])) & 0xFFFF,
				(static_cast<long long>(get(data.args[1])) >> 16) & 0xFFFF
			};
			LLCCEP_vm::set_pix(pos[0], pos[1]);

			break;
		}

		default:
			throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
				"Error!\n"
				"No port #%lls!\n",
				static_cast<long long>(get(data.args[0]))));
	}
}

static void emulated_inp(LLCCEP_vm::instruction &data)
{
	switch (static_cast<long long>(get(data.args[0]))) {
		case 0:
			set(data.args[1], LLCCEP_vm::get_clr());
			break;

		case 1: {
			uint16_t pos[2] = {
				static_cast<long long>(get(data.args[1]) & 0xFFFF,
				(static_cast<long long>(get(data.args[1])) >> 16) & 0xFFFF;
			};
			set(data.args[2], LLCCEP_vm::get_pix(pos[0], pos[1]));
			break;
		}

		default:
			throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
				"Error!\n"
				"No port #%lls!\n",
				static_cast<long long>(get(data.args[0]))));
	}
}

static void (*funcs[])(LLCCEP_vm::instruction &data) = {
	emulated_mov,
	emulated_mva,
	emulated_push,
	emulated_pop,
	emulated_top,
	emulated_add,
	emulated_sub,
	emulated_mul,
	emulated_dev,
	emulated_and,
	emulated_or,
	emulated_xor,
	emulated_off,
	emulated_nop,
	emulated_sqi,
	emulated_cmp,
	emulated_inc,
	emulated_dec,
	emulated_sqrt,
	emulated_sin,
	emulated_cos,
	emulated_ptan,
	emulated_patan,
	emulated_ldc,
	emulated_outp,
	emulated_inp	
};

static inline void emulate(LLCCEP_vm::instruction &data)
{
	if (data.opcode > INST_NUM) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Error!\n"
			"Invalid opcode: %d", static_cast<int>(data.opcode)));
	}

	funcs[data.opcode](data);
}

namespace LLCCEP_vm {
	void execute(::std::vector<instruction> &data)
	{
		double &i = LLCCEP_vm::__added__::regs[14];
		for (i = 1; i <= data.size(); i++)
			emulate(data[i - 1]);
	}
}
