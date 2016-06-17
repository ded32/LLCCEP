#include <stack>
#include <cmath>
#include <fstream>
#include <cstddef>
#include <iostream>

#include <STDExtras.hpp>
#include <STLExtras.hpp>

#include "./../drivers/ram/ram.hpp"

#include "softcore.hpp"
#include "fp.hpp"

#include "./../program/program.hpp"
#include "./../selection/selection.hpp"
#include "./../window/window.hpp"

#include "./../../common/def/def_inst.hpp"

#if VM
#include "./../drivers/display/display.hpp"
#endif //VM

namespace LLCCEP_vm {
	namespace __added__ {
		::std::stack<double> stk;
		int cmp = 0b1000;
		double regs[32] = {};

#if !VM
		::std::vector<FILE *> files;
		::std::vector<window> windows;
#endif // VM
	}
}

static double get(LLCCEP_vm::arg &data) 
{
	switch (data.type) {
		case LLCCEP_vm::ARG_T_REG:
			if (DBL_AE(data.val, 31) || 
			    DBL_LESS(data.val, 0)) {
				throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
					"Error!\n"
					"Overbounding while reading data from register!\n"));
			} else
				return LLCCEP_vm::__added__::regs[static_cast<long long>(data.val)];
			break;

		case LLCCEP_vm::ARG_T_MEM:
			if (DBL_AE(data.val, LLCCEP_vm::get_mem_size()) ||
			    DBL_LESS(data.val, 0)) {
				throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
					"Error!\n"
					"Overbouding while reading data from RAM!\n"));
			} else
				return LLCCEP_vm::access_mem_data<double>(static_cast<size_t>(data.val));
			break;

		case LLCCEP_vm::ARG_T_VAL:
			return data.val;
			break;

		default:
			throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
				"Error!\n"
				"Invalid or damaged binary file!\n"));
	}

	return 0;
}

static void set(LLCCEP_vm::arg &data, double val)
{
	switch (data.type) {
		case LLCCEP_vm::ARG_T_REG:
			if (DBL_AE(data.val, 31) ||
			    DBL_LESS(data.val, 0)) {
				throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
					"Error!\n"
					"Overbounding while writing data to register!\n"));
			} else
				LLCCEP_vm::__added__::regs[static_cast<size_t>(data.val)] = val;
			break;

		case LLCCEP_vm::ARG_T_MEM:
			if (DBL_AE(data.val, LLCCEP_vm::get_mem_size()) ||
			    DBL_LESS(data.val, 0)) {
				throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
					"Error!\n"
					"Overbounding while writing data to mem!\n"));
			} else
				LLCCEP_vm::access_mem_data<double>(static_cast<size_t>(data.val), val);
			break;

		case LLCCEP_vm::ARG_T_VAL:
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
	LLCCEP_vm::access_mem_data<double>(
		static_cast<size_t>(get(data.args[0])), 
		get(data.args[1]));
}

static inline void emulated_push(LLCCEP_vm::instruction &data)
{
	LLCCEP_vm::__added__::stk.push(get(data.args[0]));
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
		/***************************************************************************
		 * Output character
		 *
		 * Inputs:
		 * r00 - (double)chr
		 * 
		 * Outputs:
		 * None
		 *
		 * Used data:
		 * chr - characted being printed
		 **************************************************************************/
		case 0:
			::std::cout << static_cast<unsigned char>(LLCCEP_vm::__added__::regs[0]);
			break;

		/***************************************************************************
		 * Integer number
		 *
		 * Inputs:
		 * r00 - val
		 *
		 * Outputs:
		 * r01 - (long long)r00
		 *
		 * Used data:
		 * val - value being integered
		 **************************************************************************/
		case 1:
			LLCCEP_vm::__added__::regs[1] = static_cast<long long>(LLCCEP_vm::__added__::regs[0]);
			break;

		/***************************************************************************
		 * Output string
		 * 
		 * Inputs:
		 * r00 - ptr
		 * 
		 * Outputs:
		 * None
		 *
		 * Used data:
		 * ptr - pointer to string being printed
		 **************************************************************************/
		case 2:
			for (size_t i = LLCCEP_vm::__added__::regs[0]; i < LLCCEP_vm::get_mem_size(); i++) {
				if (DBL_EQ(LLCCEP_vm::access_mem_data<double>(i), 0))
					break;
				else
					::std::cout << static_cast<uint8_t>(LLCCEP_vm::access_mem_data<double>(i));
			}
			break;

		/***************************************************************************
		 * Read char
		 * 
		 * Inputs:
		 * None
		 *
		 * Outputs:
		 * r00 - val
		 *
		 * Used data:
		 * val - char was entered last time
		 **************************************************************************/
		case 3: {
			unsigned char val = 0;
			::std::cin >> val;
			LLCCEP_vm::__added__::regs[0] = val;
			break;
		}

		/***************************************************************************
		 * Read string
		 *
		 * Inputs:
		 * r00 - ptr
		 * 
		 * Outputs:
		 * ram[r00] - str
		 *
		 * Used data:
		 * ptr - pointer to place, where to put string
		 * str - string was entered
		 **************************************************************************/
		case 4: {
			::std::string val = "";
			::std::cin >> val;

			for (size_t i = 0; i < val.length(); i++)
				LLCCEP_vm::access_mem_data<char>(static_cast<size_t>(LLCCEP_vm::__added__::regs[0]) + i, val[i]);

			break;
		}

		/***************************************************************************
		 * Only emulator interrupts[sys calls]
		 **************************************************************************/

#if !VM
		/***************************************************************************
		 * Open file.
		 *
		 * Inputs:
		 * r00 - addition mode chars
		 * the two lower bits mean main mode data:
		 * |--[0] - read
		 * |--[1] - write
		 * |--[2] - append
		 *
		 * The third bit is '+' indicator
		 * |--r+ open file both for write and read
		 * |--w+ create empty file and open it both for read and write
		 * |--a+ open file both for write and read with all output at
		 * the end of the file
		 *
		 * The forth bit is 'b' indicator
		 * If it's passed, file will be opened as 'binary'
		 *
		 * And, as final, r01 is pointer to mem, where path to file is
		 * contained.
		 *
		 * Outputs:
		 * r01 - ptr
		 *
		 * Data used:
		 * ptr - pointer to file been opened
		 **************************************************************************/
		case 7: {
			::std::string modes[] = {
				"r",
				"w",
				"a"
			};
			long long r00 = static_cast<long long>(LLCCEP_vm::__added__::regs[0]);

			bool attrs[2] = {
				static_cast<bool>(r00 & 0b0100),
				static_cast<bool>(r00 & 0b1000)
			};

			if ((r00 & 0b11) >= 0b11)
				throw RUNTIME_EXCEPTION("No file mode #3!")

			::std::string mode = modes[r00 & 0b11];
			if (attrs[0]) 
				mode += "+";

			if (attrs[1])
				mode += 'b';

			::std::string path = "";
			for (size_t i = static_cast<size_t>(LLCCEP_vm::__added__::regs[1]); 
			     i < LLCCEP_vm::get_mem_size(); i++) {
				path += static_cast<uint8_t>(LLCCEP_vm::access_mem_data<double>(i));
			}

			FILE *fd = fopen(path.c_str(),
			                 mode.c_str());

			LLCCEP_vm::__added__::files.push_back(fd);
			LLCCEP_vm::__added__::regs[1] = *(double *)((void *)&fd);
			break;
		}

		/***************************************************************************
		 * Close file
		 *
		 * Inputs:
		 * r00 - ptr
		 *
		 * Outputs:
		 * None
		 *
		 * Data used:
		 * ptr - pointer to file being closed
		 **************************************************************************/
		case 8: {
			FILE *r00 = *(FILE **)((void *)((double *)(&LLCCEP_vm::__added__::regs[0])));
			fclose(r00);
			LLCCEP_vm::__added__::files.erase(vec_find(LLCCEP_vm::__added__::files, r00));
			break;
		}


		/***************************************************************************
		 * Read/write byte from/to file
		 *
		 * Inputs:
		 * r02 - byte
		 * r01 - action
		 * r00 - ptr
		 *
		 * Outputs:
		 * None
		 *
		 * Data used:
		 * action - if zero, byte will be written, else it will be read
		 * ptr - pointer to file, with which we are working
		 * byte - byte beeing written/read
		 **************************************************************************/
		case 9: {
			FILE *r00 = *(FILE **)((void *)((double *)(&LLCCEP_vm::__added__::regs[0])));

			if (DBL_EQ(LLCCEP_vm::__added__::regs[1], 0))
				fprintf(r00, "%c", static_cast<uint8_t>(LLCCEP_vm::__added__::regs[2]));
			else {
				uint8_t c = 0;
				fscanf(r00, "%c", &c);
				LLCCEP_vm::__added__::regs[2] = c;
			}

			break;
		}

		case 10: {
			FILE *r00 = *(FILE **)((void *)((double *)(&LLCCEP_vm::__added__::regs[0])));

			if (DBL_EQ(LLCCEP_vm::__added__::regs[1], 0)) {
				::std::string tmp = "";
				for (size_t i = static_cast<size_t>(LLCCEP_vm::__added__::regs[2]);
				     i < LLCCEP_vm::get_mem_size(); i++)
					tmp += static_cast<uint8_t>(LLCCEP_vm::access_mem_data<double>(i));

				fprintf(r00, "%s", tmp.c_str());
			} else {
				for (size_t i = static_cast<size_t>(LLCCEP_vm::__added__::regs[2]);
				     (i < LLCCEP_vm::get_mem_size()) && (!feof(r00)); i++) {
					char c = fgetc(r00);
					if (isspace(c) || !c)
						break;

					LLCCEP_vm::access_mem_data<double>(i, c);
				}
			}
			break;
		}

		case 11: { // create window
			LLCCEP_vm::size sz = {
				static_cast<int>((static_cast<long>(LLCCEP_vm::__added__::regs[1]) >> 16) & 0xFFFF),
				static_cast<int>(static_cast<long>(LLCCEP_vm::__added__::regs[1]) & 0xFFFF)
			};
			LLCCEP_vm::point pos = {
				static_cast<int>((static_cast<long>(LLCCEP_vm::__added__::regs[2]) >> 16) & 0xFFFF),
				static_cast<int>(static_cast<long>(LLCCEP_vm::__added__::regs[2]) & 0xFFFF)
			};

			LLCCEP_vm::window new_wnd;
			new_wnd.create(LLCCEP_vm::access_mem_data<char *>(static_cast<size_t>(LLCCEP_vm::__added__::regs[0])),
			               sz, pos, static_cast<uint32_t>(LLCCEP_vm::__added__::regs[3]));

			LLCCEP_vm::__added__::windows.push_back(new_wnd);
			break;
		}

		case 12: { // delete window
			if (static_cast<size_t>(LLCCEP_vm::__added__::regs[0]) >= LLCCEP_vm::__added__::windows.size()) {
				throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
					"Overbounding due window accessing: no window %zu",
					static_cast<size_t>(LLCCEP_vm::__added__::regs[1])));
			}

			LLCCEP_vm::__added__::windows[static_cast<size_t>(LLCCEP_vm::__added__::regs[0])].destroy();
			LLCCEP_vm::__added__::windows.erase(LLCCEP_vm::__added__::windows.begin() + static_cast<size_t>(
				LLCCEP_vm::__added__::regs[0]));

			break;
		}

		case 13: { // window stuff
			size_t id = static_cast<size_t>(LLCCEP_vm::__added__::regs[0]);
			if (id >= LLCCEP_vm::__added__::windows.size()) {
				throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
					"Overbounding due window accessing: no window %zu",
					static_cast<size_t>(LLCCEP_vm::__added__::regs[0])));
			}

			break;	
		}
#endif

		default:
			throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
				"Error!\n"
				"No swi #%llu", 
				static_cast<long long unsigned>(get(data.args[0]))));
	}
}

static inline void emulated_cmp(LLCCEP_vm::instruction &data)
{
	double n0 = get(data.args[0]), n1 = get(data.args[1]);
	int &val = LLCCEP_vm::__added__::cmp;

	val = 0b1000;

	if (DBL_LESS(n0, n1))
		val |= 0b0010;
	if (DBL_ABOVE(n0, n1))
		val |= 0b0001;
	if (DBL_EQ(n0, n1))
		val |= 0b0100;
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
	switch (static_cast<long long>(get(data.args[1]))) {
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
	switch (static_cast<size_t>(get(data.args[0]))) {
#if VM
		case 0:
			LLCCEP_vm::set_clr(static_cast<uint32_t>(get(data.args[1])));
			break;

		case 1: {
			int pos[2] = {
				 static_cast<int>(get(data.args[1]))        & 0xFFFF,
				(static_cast<int>(get(data.args[1])) >> 16) & 0xFFFF
			};
			LLCCEP_vm::set_pix(pos[0], pos[1]);

			break;
		}
#endif // VM

		default:
			throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
				"Error!\n"
				"No port #%zu!\n",
				static_cast<size_t>(get(data.args[0]))));
	}
}

static void emulated_inp(LLCCEP_vm::instruction &data)
{
	switch (static_cast<size_t>(get(data.args[0]))) {
#if VM
		case 0:
			set(data.args[1], LLCCEP_vm::get_clr());
			break;

		case 1: {
			int pos[2] = {
				 static_cast<int>(get(data.args[1]))        & 0xFFFF,
				(static_cast<int>(get(data.args[1])) >> 16) & 0xFFFF
			};
			set(data.args[2], LLCCEP_vm::get_pix(pos[0], pos[1]));
			break;
		}
#endif // VM

		default:
			throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
				"Error!\n"
				"No port #%zu!\n",
				static_cast<size_t>(get(data.args[0]))));
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
	emulated_swi,
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
	if (data.opcode > LLCCEP_ASM::INST_NUM) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Error!\n"
			"Invalid opcode: %d", static_cast<int>(data.opcode)));
	}

	if (LLCCEP_vm::__added__::cmp & data.cond)
		funcs[data.opcode](data);
}

namespace LLCCEP_vm {
	void execute(::std::vector<instruction> &data)
	{
		double &i = LLCCEP_vm::__added__::regs[14];

#if VM
		i = 1;

		while (handle_msg()) {
			if (i <= data.size()) {
				emulate(data[i - 1]);
				i++;
			}
		}
#else
		for (i = 1; i <= data.size(); i++)
			emulate(data[i - 1]);
#endif
	}
}
