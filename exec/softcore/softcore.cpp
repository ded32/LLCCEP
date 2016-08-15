#include <stack>
#include <cmath>
#include <fstream>
#include <cstddef>
#include <iostream>

#include <STDExtras.hpp>
#include <STLExtras.hpp>

#include "softcore.hpp"
#include "fp.hpp"

#include "./../mm/mm.hpp"
#include "./../window/window.hpp"
#include "./../program/program.hpp"
#include "./../../common/def/def_inst.hpp"

LLCCEP_exec::softcore::softcore():
	_stk(),
	_call(),
	_cmp(0b1000),
	_regs({ }),
	_pc(0),
	_files(),
	_windows(),
	_mm(),
	_prog(),
	_ready(false),
	_quit(false)
{ }

LLCCEP_exec::softcore::~softcore()
{ }

void LLCCEP_exec::softcore::setProgram(LLCCEP_exec::program_data prog)
{
	_prog = prog;
	_ready = true;
}

void LLCCEP_exec::softcore::executeProgram()
{
	if (!_ready) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Error!\n"
			"Softcore at %p is not ready for "
			"program execution: "
			"no input!\n"))
	}

	while (!_quit)
		executeNextInstruction();
}

double LLCCEP_exec::softcore::get(LLCCEP_exec::arg data)
{
	switch (data.type) {
	case LLCCEP_exec::ARG_T_REG:
		if (DBL_AE(data.val, 32) ||
		    DBL_LESS(data.val, 0)) {
			throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
				"Error!\n"
				"Overbounding while reading data from register!\n"));
		} else {
			return _regs[static_cast<long long>(data.val)];
		}
		break;

	case LLCCEP_exec::ARG_T_MEM:
		if (DBL_AE(data.val, LLCCEP_exec::get_mem_size()) ||
		    DBL_LESS(data.val, 0)) {
			throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
				"Error!\n"
				"Overbouding while reading data from RAM!\n"));
		} else {
			return _mm[static_cast<size_t>(data.val)];
		}
		break;

	case LLCCEP_exec::ARG_T_COND:
	case LLCCEP_exec::ARG_T_VAL:
		return data.val;
		break;

	default:
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Error!\n"
			"Invalid or damaged binary file: invalid reading!\n"));
	}

	return 0;
}

void LLCCEP_exec::softcore::set(LLCCEP_exec::arg data, double val)
{
	switch (data.type) {
	case LLCCEP_exec::ARG_T_REG:
		if (DBL_AE(data.val, 32) ||
		    DBL_LESS(data.val, 0)) {
			throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
				"Error!\n"
				"Overbounding while writing data to register!\n"));
		} else {
			_regs[static_cast<size_t>(data.val)] = val;
		}
		break;

	case LLCCEP_exec::ARG_T_MEM:
		if (DBL_AE(data.val, LLCCEP_exec::get_mem_size()) ||
		    DBL_LESS(data.val, 0)) {
			throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
				"Error!\n"
				"Overbounding while writing data to mem!\n"));
		} else {
			_mm[static_cast<size_t>(data.val)] = val;
		}
		break;

	case LLCCEP_exec::ARG_T_VAL:
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Error!\n"
			"An attempt of writing data to non-memory!\n"));
		break;

	default:
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Error!\n"
			"Invalid or damaged binary file: invalid writing!\n"));
	}
}

void LLCCEP_exec::softcore::executeNextInstruction()
{

}

void LLCCEP_exec::softcore::emulated_mov(LLCCEP_exec::instruction data)
{
	set(data.args[0], get(data.args[1]));
}

void LLCCEP_exec::softcore::emulated_mva(LLCCEP_exec::instruction data)
{
	_mm[get(data.args[0])] = get(data.args[1]);
}

void LLCCEP_exec::softcore::emulated_push(LLCCEP_exec::instruction data)
{
	_stk.push(get(data.args[0]));
}

void LLCCEP_exec::softcore::emulated_pop(LLCCEP_exec::instruction data)
{
	if (!_stk.size()) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Error!\n"
			"Stack is empty!\n"
			"Can't pop!"))
	}

	_stk.pop();
}

void LLCCEP_exec::softcore::emulated_top(LLCCEP_exec::instruction data)
{
	if (!_stk.size()) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Error!\n"
			"Stack is empty!\n"
			"Can't get top!"))
	}

	set(data.args[0], _stk.top());
}

void LLCCEP_exec::softcore::emulated_add(LLCCEP_exec::instruction data)
{
	set(data.args[0], get(data.args[1]) + get(data.args[2]));
}

void LLCCEP_exec::softcore::emulated_sub(LLCCEP_exec::instruction data)
{
	set(data.args[0], get(data.args[1]) + get(data.args[2]));
}

void LLCCEP_exec::softcore::emulated_mul(LLCCEP_exec::instruction data)
{
	set(data.args[0], get(data.args[1]) * get(data.args[2]));
}

void LLCCEP_exec::softcore::emulated_div(LLCCEP_exec::instruction data)
{
	set(data.args[0], get(data.args[1]) / get(data.args[2]));
}

void LLCCEP_exec::softcore::emulated_and(LLCCEP_exec::instruction data)
{
	set(data.args[0], 
	    static_cast<long long>(get(data.args[1]))
	    static_cast<long long>(get(data.args[2])));
}

void LLCCEP_exec::softcore::emulated_or(LLCCEP_exec::instruction data)
{
	set(data.args[0],
	    static_cast<long long>(get(data.args[1])) |
	    static_cast<long long>(get(data.args[2])));
}

void LLCCEP_exec::softcore::emulated_xor(LLCCEP_exec::instruction data)
{
	set(data.args[0],
	    static_cast<long long>(get(data.args[1])) ^
	    static_cast<long long>(get(data.args[2])));
}

void LLCCEP_exec::softcore::emulated_off(LLCCEP_exec::instruction data)
{
	int direction = ((get(data.args[0]) >= 0)?(1):(-1));
	set(data.args[0],
	    ((direction == -1)
            ?(static_cast<long long>(get(data.args[1])) <<
	      static_cast<long long>(get(data.args[2])))
	    :(static_cast<long long>(get(data.args[1])) >>
	      static_cast<long long>(get(data.args[2])))));
}

void LLCCEP_exec::softcore::emulated_nop(LLCCEP_exec::instruction data)
{
	(void)0;
}

static void LLCCEP_exec::softcore::emulated_swi(LLCCEP_exec::instruction data)
{
	switch (static_cast<size_t>(get(data.args[0]))) {
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
	case 0: {
		::std::printf("%c", static_cast<unsigned char>(_regs[0]));
		break;
	}

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
	case 1: {
		_regs[1] = static_cast<long long>(_regs[0]);
		break;
	}

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
	case 2: {
		::std::printf("%s", _mm.getString(static_cast<size_t>(_regs[0])).c_str());
		break;
	}

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
		::std::scanf("%c", val);
		_regs[0] = val;
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

		LLCCEP_exec::write_string(static_cast<size_t>(LLCCEP_exec::__added__::regs[0]), val);
		break;
	}

	case 5: {
		_quit = true;
		break;
	}

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
		long long r00 = static_cast<long long>(LLCCEP_exec::__added__::regs[0]);

		bool attrs[2] = {
			static_cast<bool>(r00  0b0100),
			static_cast<bool>(r00  0b1000)
		};

		if ((r00  0b11) >= 0b11)
			throw RUNTIME_EXCEPTION("No file mode #3!")

		::std::string mode = modes[r00  0b11];
		if (attrs[0])
			mode += "+";

		if (attrs[1])
			mode += 'b';

		::std::string path = LLCCEP_exec::get_string(static_cast<size_t>(LLCCEP_exec::__added__::regs[1]));

		FILE *fd = fopen(path.c_str(),
				 mode.c_str());

		LLCCEP_exec::__added__::files.push_back(fd);
		LLCCEP_exec::__added__::regs[1] = *(double *)((void *)&fd);
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
		FILE *r00 = *(FILE **)((void *)((double *)(&LLCCEP_exec::__added__::regs[0])));
		fclose(r00);
		LLCCEP_exec::__added__::files.erase(vec_find(LLCCEP_exec::__added__::files, r00));
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
		FILE *r00 = *(FILE **)((void *)((double *)(&LLCCEP_exec::__added__::regs[0])));

		if (DBL_EQ(LLCCEP_exec::__added__::regs[1], 0)) {
			fprintf(r00, "%c", static_cast<uint8_t>(LLCCEP_exec::__added__::regs[2]));
		} else {
			uint8_t c = 0;
			fscanf(r00, "%c", c);
			LLCCEP_exec::__added__::regs[2] = c;
		}

		break;
	}

	case 10: {
		FILE *r00 = *(FILE **)((void *)((double *)(&LLCCEP_exec::__added__::regs[0])));

		if (DBL_EQ(LLCCEP_exec::__added__::regs[1], 0)) {
			fprintf(r00, "%s", LLCCEP_exec::get_string(static_cast<size_t>(LLCCEP_exec::__added__::regs[2])).c_str());
		} else {
			std::string str = "";
			char c = 0;

			for (size_t i = 0; !feof(r00); i++) {
				c = fgetc(r00);
				if (isspace(c) || !c)
					break;

				str += c;
			}

			LLCCEP_exec::write_string(static_cast<size_t>(LLCCEP_exec::__added__::regs[2]), str);
		}
		break;
	}

	default: {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
					"Error!\n"
					"No swi #%llu",
					static_cast<long long unsigned>(get(data.args[0]))));
	}
	}
}

void LLCCEP_exec::softcore::emulated_cmp(LLCCEP_exec::instruction data)
{
	double n0 = get(data.args[0]), n1 = get(data.args[1]);
	_cmp = 0b1000;

	if (DBL_LESS(n0, n1))
		_cmp |= 0b0010;
	if (DBL_ABOVE(n0, n1))
		_cmp |= 0b0001;
	if (DBL_EQ(n0, n1))
		_cmp |= 0b0100;
}

void LLCCEP_exec::softcore::emulated_inc(LLCCEP_exec::instruction data)
{
	set(data.args[0], get(data.args[0]) + 1);
}

void LLCCEP_exec::softcore::emulated_dec(LLCCEP_exec::instruction data)
{
	set(data.args[0], get(data.args[0]) - 1);
}

void LLCCEP_exec::softcore::emulated_sqrt(LLCCEP_exec::instruction data)
{
	set(data.args[0], ::std::sqrt(get(data.args[1])));
}

void LLCCEP_exec::softcore::emulated_sin(LLCCEP_exec::instruction data)
{
	set(data.args[0], ::std::sin(get(data.args[1])));
}

void LLCCEP_exec::softcore::emulated_cos(LLCCEP_exec::instruction data)
{
	set(data.args[0], ::std::cos(get(data.args[1])));
}

void LLCCEP_exec::softcore::emulated_ptan(LLCCEP_exec::instruction data)
{
	set(data.args[0], ::std::tan(get(data.args[1])));
}

void LLCCEP_exec::softcore::emulated_patan(LLCCEP_exec::instruction data)
{
	set(data.args[0], ::std::atan(get(data.args[1])));
}

static void LLCCEP_exec::softcore::emulated_ldc(LLCCEP_exec::instruction data)
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

static void LLCCEP_exec::softcore::emulated_call(LLCCEP_exec::instruction data)
{
	if (static_cast<size_t>(get(data.args[0])) & _cmp) {
		_call.push(_pc);
		_pc = static_cast<size_t>(get(data.args[1]));
	}
}

static void LLCCEP_exec::softcore::emulated_jmp(LLCCEP_exec::instruction data)
{
	_pc = static_cast<size_t>(get(data.args[0]));
}

static void LLCCEP_exec::softcore::emulated_ret(LLCCEP_exec::instruction data)
{
	if (!_call.size()) {
		_quit = true;
	}

	_pc = _call.top();
	_call.pop();
}

static void (*funcs[])(LLCCEP_exec::instruction data) = {
	emulated_mov,
	emulated_mva,
	emulated_push,
	emulated_pop,
	emulated_top,
	emulated_add,
	emulated_sub,
	emulated_mul,
	emulated_div,
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
	emulated_call,
	emulated_jmp,
	emulated_ret	
};
