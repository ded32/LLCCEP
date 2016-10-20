#include <QColor>
#include <QEventLoop>
#include <QMediaPlayer>
#include <QAudioRecorder>
#include <QUrl>
#include <QString>
#include <QApplication>

#include <cmath>
#include <fstream>
#include <cstddef>
#include <iostream>

#include <STDExtras.hpp>
#include <STLExtras.hpp>
#include <os-specific.hpp>
#include <convert.hpp>

#include "softcore.hpp"
#include "fp.hpp"

#include "./../mm/mm.hpp"
#include "./../window/window.hpp"
#include "./../codeReader/codeReader.hpp"
#include "./../../common/def/def_inst.hpp"
#include "./../../assembler/lexer/lexer.hpp"

LLCCEP_exec::softcore::softcore():
	mm(0),
	reader(0),
	bindedApplication(0),
	stk(),
	call(),
	registersStore(),
	cmp(0x8),
	ready(0x0),
	quit(false),
	regs(),
	pc(0),
	windows()
{
	/* Fill registers with zeros */
	memset(regs, 0, sizeof(double) * 32);
}

LLCCEP_exec::softcore::~softcore()
{
	/* Execute QT application if needed */
	if (windows.size())
		bindedApplication->exec();

	/* For all windows, just living
	 * at the time
	 */
	for (const auto &i: windows) {
		/* Close the window */
		i->close();
		/* Free memory, allocated for it */
		delete i;
	}
}

void LLCCEP_exec::softcore::setMm(LLCCEP_exec::memoryManager *newMm)
{
	/* If memory manager is already
	 * setted up and ok */
	if (ready & LLCCEP_exec::softcore::MM_READY) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"An attempt of re-setting memory manager\n"
			"for softcore [" ptr_pf "]",
			this));
	}

	if (!newMm) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"An attempt of setting memory manager pointer to invalid\n"
			"for softcore [" ptr_pf "]",
			this));
	}

	mm = newMm;
	ready |= LLCCEP_exec::softcore::MM_READY;
}

void LLCCEP_exec::softcore::setCodeReader(LLCCEP_exec::codeReader *newReader)
{
	if (ready & LLCCEP_exec::softcore::CR_READY) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"An attempt of re-setting code reader\n"
			"for softocore [" ptr_pf "]",
			this));
	}

	if (!newReader) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"An attempt of setting reader pointer to invalid\n"
			"for softcore [" ptr_pf "]",
			this));
	}

	reader = newReader;
	ready |= LLCCEP_exec::softcore::CR_READY;
}

void LLCCEP_exec::softcore::executeProgram()
{
	if (ready != LLCCEP_exec::softcore::EVERYTHING_READY) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Error!\n"
			"Softcore at " ptr_pf " is not ready for "
			"program execution: "
			"no input!\n", this))
	}

	pc = reader->getProgramData().main_id;

	QEventLoop ev;
	while (!quit) {
		executeNextInstruction();
		ev.processEvents(QEventLoop::AllEvents, 100);
	}

	if (windows.size()) {
		for (const auto &i: windows)
			i->setMayClose();
	} else {
		QApplication::quit();
	}
}


bool LLCCEP_exec::softcore::OK() const
{
	return (cmp & 0b1000) && mm && reader && (ready & LLCCEP_exec::softcore::EVERYTHING_READY);
}

double LLCCEP_exec::softcore::get(LLCCEP_exec::arg data)
{
	switch (data.type) {
	case LLCCEP_ASM::LEX_T_REG:
		if (static_cast<size_t>(data.val) >= 32) {
			throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
				"Error!\n"
				"Overbounding while reading data from register!\n"));
		} else {
			return regs[static_cast<size_t>(data.val)];
		}
		break;

	case LLCCEP_ASM::LEX_T_MEM:
		if (DBL_AE(data.val, mm->getMemSize()) || DBL_LESS(data.val, 0)) {
			throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
				"Error!\n"
				"Overbouding while reading data from RAM!\n"));
		} else {
			return (*mm)[static_cast<size_t>(data.val)];
		}
		break;

	case LLCCEP_ASM::LEX_T_COND:
	case LLCCEP_ASM::LEX_T_VAL:
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
	case LLCCEP_ASM::LEX_T_REG:
		if (DBL_AE(data.val, 32) || DBL_LESS(data.val, 0)) {
			throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
				"Error!\n"
				"Overbounding while writing data to register!\n"));
		} else {
			regs[static_cast<size_t>(data.val)] = val;
		}
		break;

	case LLCCEP_ASM::LEX_T_MEM:
		if (DBL_AE(data.val, mm->getMemSize()) ||
		    DBL_LESS(data.val, 0)) {
			throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
				"Error!\n"
				"Overbounding while writing data to mem!\n"));
		} else {
			(*mm)[static_cast<size_t>(data.val)] = val;
		}
		break;

	default:
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Error!\n"
			"Invalid or damaged binary file: invalid writing!\n"));
	}
}

void LLCCEP_exec::softcore::executeNextInstruction()
{
	void (LLCCEP_exec::softcore::*funcs[])(LLCCEP_exec::instruction) = {
		&LLCCEP_exec::softcore::emulated_mov,
		&LLCCEP_exec::softcore::emulated_mva,
		&LLCCEP_exec::softcore::emulated_push,
		&LLCCEP_exec::softcore::emulated_pop,
		&LLCCEP_exec::softcore::emulated_top,
		&LLCCEP_exec::softcore::emulated_add,
		&LLCCEP_exec::softcore::emulated_sub,
		&LLCCEP_exec::softcore::emulated_mul,
		&LLCCEP_exec::softcore::emulated_div,
		&LLCCEP_exec::softcore::emulated_and,
		&LLCCEP_exec::softcore::emulated_or,
		&LLCCEP_exec::softcore::emulated_xor,
		&LLCCEP_exec::softcore::emulated_off,
		&LLCCEP_exec::softcore::emulated_nop,
		&LLCCEP_exec::softcore::emulated_swi,
		&LLCCEP_exec::softcore::emulated_cmp,
		&LLCCEP_exec::softcore::emulated_inc,
		&LLCCEP_exec::softcore::emulated_dec,
		&LLCCEP_exec::softcore::emulated_sqrt,
		&LLCCEP_exec::softcore::emulated_sin,
		&LLCCEP_exec::softcore::emulated_cos,
		&LLCCEP_exec::softcore::emulated_ptan,
		&LLCCEP_exec::softcore::emulated_patan,
		&LLCCEP_exec::softcore::emulated_ldc,
		&LLCCEP_exec::softcore::emulated_call,
		&LLCCEP_exec::softcore::emulated_jmp,
		&LLCCEP_exec::softcore::emulated_ret,
		&LLCCEP_exec::softcore::emulated_stregs,
		&LLCCEP_exec::softcore::emulated_ldregs
	};

	LLCCEP_exec::instruction inst{};
	if (pc >= reader->getProgramData().size) {
		quit = true;
		return;
	}

	inst = reader->getInstruction(pc);
	if (inst.opcode >= LLCCEP_ASM::INST_NUM) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Opcode overbound!"));
	}

	(this->*funcs[inst.opcode])(inst);
	pc++;
}

void LLCCEP_exec::softcore::emulated_mov(LLCCEP_exec::instruction data)
{
	set(data.args[0], get(data.args[1]));
}

void LLCCEP_exec::softcore::emulated_mva(LLCCEP_exec::instruction data)
{	
	(*mm)[get(data.args[0])] = get(data.args[1]);
}

void LLCCEP_exec::softcore::emulated_push(LLCCEP_exec::instruction data)
{	
	stk.push(get(data.args[0]));
}

void LLCCEP_exec::softcore::emulated_pop(LLCCEP_exec::instruction data)
{
	static_cast<void>(data);

	if (!stk.size()) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Error!\n"
			"Can't pop: stack is empty!\n"));
	}

	stk.pop();
}

void LLCCEP_exec::softcore::emulated_top(LLCCEP_exec::instruction data)
{	
	if (!stk.size()) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Error!\n"
			"Can't get top: stack is empty!\n"));
	}

	set(data.args[0], stk.top());
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
	    static_cast<long long>(get(data.args[1])) &
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
	static_cast<void>(data);
}

void LLCCEP_exec::softcore::emulated_swi(LLCCEP_exec::instruction data)
{
	auto getFmtString = [](char c) -> ::std::string {
		switch (c) {
		case 'x':
			return "%x";
			break;

		case 'b':
			return "%b";
			break;

		case 'o':
			return "%o";
			break;

		default:
			throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
				"Error!\n"
				"Invalid format!\n"));
		}
	};

	auto getWindow = [this]() {
		size_t id = static_cast<size_t>(regs[1]);
		if (id >= windows.size()) {
			throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
				"Error!\n"
				"Overbounding while access to windows: "
				"no window with " size_t_pf " ID!\n",
				id));
		}

		return windows[id];
	};

	auto checkf = [](FILE *fd, size_t function) {
		if (!fd) {
			throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
				"Error!\n"
				"File pointer at &01 register is 0.\n"
				"Interrupt 0:" size_t_pf "!\n",
				function));
		}
	};

	auto noFunction = [this](size_t interrupt) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Error!\n"
			"No function " size_t_pf " of " size_t_pf " interrupt.\n",
			static_cast<size_t>(regs[1]), interrupt));
	};

	switch (static_cast<size_t>(get(data.args[0]))) {
	/**************************************************
	 * Files stuff
	 *************************************************/
	case 0: {
		/**************************************************
		 * Function selection
		 *************************************************/
		switch (static_cast<size_t>(regs[0])) {
		/**************************************************
		 * Load standard file ptr to r02
		 *
		 * r01 -- id of standard file
		 * |-- 0 - stdin
		 * |-- 1 - stdout
		 * |-- 2 - stderr
		 *************************************************/
		case 0: {
			FILE *stdf[] = {
				stdin,
				stdout,
				stderr
			};

			if (static_cast<size_t>(regs[1]) > 2) {
				throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
					"Error!\n"
					"In interrupt 0,0:\n"
					"not admitted id of standard file.\n"
					"Only values between 0 and 2 are allowed!\n"));
			}

			regs[2] = *reinterpret_cast<double *>(&(stdf[static_cast<size_t>(regs[1])]));
			break;
		}

		/**************************************************
		 * Output to file.
		 *
		 * r01 -- pointer to file.
		 * r02 -- output format.
		 * r03 -- output value.
		 *
		 * Output formats:
		 * - n -- number
		 * - c -- character
		 * - s -- string
		 * - x -- hexadecimal number
		 * - b -- binary number
		 * - o -- octal number
		 *
		 * Output values by formats:
		 * - n -- number
		 * - c -- ASCII character id
		 * - s -- string pointer
		 * - x -- number
		 * - b -- number
		 * - o -- octal number
		 *************************************************/
		case 1: {
			FILE *out = reinterpret_cast<FILE *>(*reinterpret_cast<void **>(&regs[1]));
			char fmt = static_cast<char>(regs[2]);
			checkf(out, 1);

			switch (fmt) {
			case 'n': {
				::std::fprintf(out, "%lg", regs[3]);
				break;
			}

			case 'c': {
				::std::fprintf(out, "%c", static_cast<uint8_t>(regs[3]));
				break;
			}

			case 's': {
				::std::fprintf(out, "%s", mm->getString(static_cast<size_t>(regs[3])).c_str());
				break;
			}

			case 'x':
			case 'b':
			case 'o': {
				::std::fprintf(out, getFmtString(static_cast<char>(regs[2])).c_str(),
					       *reinterpret_cast<size_t *>(&regs[3]));
				break;
			}

			default:
				throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
					"Error!\n"
					"Forbidden format for 0,1 interrupt."))
			}

			break;
		}

		/**************************************************
		 * Input from file
		 *
		 * r01 -- pointer to file
		 * r02 -- input format
		 * r03 -- input place
		 *************************************************/
		case 2: {
			FILE *in = reinterpret_cast<FILE *>(*reinterpret_cast<void **>(&regs[1]));
			checkf(in, 2);

			switch (static_cast<char>(regs[2])) {
			case 'n': {
				::std::fscanf(in, "%lg", &regs[3]);
				break;
			}

			case 'c': {
				char tmp = 0;
				::std::fscanf(in, "%c", &tmp);
				regs[3] = tmp;
				break;
			}

			case 's': {
				::std::string str;
				char tmp = 0;
				bool beg = true;

				do {
					if (beg)
						beg = false;
					else
						str += tmp;
					tmp = fgetc(in);
				} while (tmp && !isspace(tmp));

				mm->writeString(static_cast<size_t>(regs[3]), str);
				break;
			}

			case 'x':
			case 'b':
			case 'o': {
				int64_t res;
				::std::fscanf(in, getFmtString(static_cast<char>(regs[2])).c_str(),
					      &res);
				break;
			}

			default: {
				throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
					"Error!\n"
					"Forbidden format for 0,2 interrupt."))
			}
			}
		}

		/**************************************************
		 * Open file.
		 *
		 * r01 will be pointer to opened file.
		 *
		 * r02 -- pointer to path's string
		 * r03 -- pointer to format's string
		 *
		 * In case of fail, an exception will be thrown.
		 *************************************************/
		case 3: {
			::std::string path = mm->getString(static_cast<size_t>(regs[2]));
			::std::string fmt = mm->getString(static_cast<size_t>(regs[3]));

			FILE *res = fopen(path.c_str(), fmt.c_str());
			if (!res) {
				throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
					"Error!\n"
					"Can't open '%s' file with '%s' mode: %s!\n",
					path.c_str(), fmt.c_str(), ::std::strerror(errno)));
			}

			regs[1] = *reinterpret_cast<double *>(&res);

			break;
		}

		/*************************************************
		 * Close file.
		 *
		 * r01 -- pointer to file being closed.
		 ************************************************/
		case 4: {
			FILE *fd = reinterpret_cast<FILE *>(*reinterpret_cast<void **>(&regs[1]));
			checkf(fd, 4);

			fclose(fd);

			break;
		}

		default: {
			noFunction(0);
		}
		}

		break;
	}

	/**************************************************
	 * Windows stuff
	 *************************************************/
	case 1: {
		/**************************************************
		 * Function selection
		 *************************************************/
		switch (static_cast<size_t>(regs[0])) {
		/**************************************************
		 * Create window
		 *
		 * r01 -- width of new window
		 * r02 -- height of new window
		 * r03 -- pointer to window title string
		 * r04 -- window flags
		 *
		 * r05 will be window's id.
		 *************************************************/
		case 0: {
			LLCCEP_exec::window *wnd = new (::std::nothrow) LLCCEP_exec::window;
			if (!wnd) {
				throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
					"Error!\n"
					"Can't allocate memory for window: %s",
					::std::strerror(errno)));
			}

			int width  = static_cast<int>(regs[1]),
			    height = static_cast<int>(regs[2]);

			wnd->resize(width, height);
			wnd->show();
			wnd->setWindowTitle(QApplication::translate(
						    "emulator",
						    mm->getString(static_cast<size_t>(regs[3])).c_str()));
			wnd->begin(width, height);
			wnd->setAntialiased(true);

			regs[4] = windows.size();
			windows.push_back(wnd);

			break;
		}

		case 1: {
			LLCCEP_exec::window *wnd = getWindow();
			wnd->painter().drawPoint(static_cast<int>(regs[2]), static_cast<size_t>(regs[3]));

			break;
		}

		case 2: {
			LLCCEP_exec::window *wnd = getWindow();
			wnd->painter().setPen(QColor(static_cast<QRgb>(regs[2])));

			break;
		}

		case 3: {
			LLCCEP_exec::window *wnd = getWindow();
			wnd->close();
			delete wnd;
			windows.erase(windows.begin() + static_cast<size_t>(regs[1]));

			break;
		}

		case 4: {
			LLCCEP_exec::window *wnd = getWindow();
			regs[3] = wnd->getKeyboardButtonState((static_cast<size_t>(regs[2]) > 0xFF)?
							       (0):
							       (static_cast<size_t>(regs[2])));
			regs[4] = wnd->getMousePos().x();
			regs[5] = wnd->getMousePos().y();
			regs[6] = wnd->getMouseButtons();

			break;
		}

		case 5: {
			LLCCEP_exec::window *wnd = getWindow();
			regs[2] = wnd->pos().x();
			regs[3] = wnd->pos().y();
			regs[4] = wnd->size().width();
			regs[5] = wnd->size().height();

			break;
		}

		case 6: {
			LLCCEP_exec::window *wnd = getWindow();

			wnd->resize(static_cast<int>(regs[2]),
				    static_cast<int>(regs[3]));
			break;
		}

		case 7: {
			LLCCEP_exec::window *wnd = getWindow();

			wnd->move(static_cast<int>(regs[2]),
				  static_cast<int>(regs[3]));
			break;
		}

		case 8: {
			LLCCEP_exec::window *wnd = getWindow();

			wnd->setWindowTitle(mm->getString(static_cast<size_t>(regs[2])).c_str());
			break;
		}

		case 9: {
			LLCCEP_exec::window *wnd = getWindow();

			wnd->setWindowFlags(Qt::WindowFlags(static_cast<int>(regs[2])));
			break;
		}

		default: {
			noFunction(1);
		}
		}

		break;
	}

	/**************************************************
	 * Sound stuff
	 *************************************************/
	case 2: {
		switch (static_cast<size_t>(regs[0])) {
		case 0: {
			QMediaPlayer *mp = new QMediaPlayer;
			mp->setMedia(QUrl(mm->getString(static_cast<size_t>(regs[1])).c_str()));
			mp->setVolume(static_cast<int>(regs[2]));
			mp->play();

			delete mp;

			break;
		}

		case 1: {
			break;
		}
		}

		break;
	}

	default: {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
					"Error!\n"
					"No swi #" size_t_pf,
					static_cast<size_t>(get(data.args[0]))));
	}
	}
}

void LLCCEP_exec::softcore::emulated_cmp(LLCCEP_exec::instruction data)
{
	double n0 = get(data.args[0]), n1 = get(data.args[1]);
	cmp = 0b1000;

	if (DBL_LESS(n0, n1))
		cmp |= 0b0010;
	if (DBL_ABOVE(n0, n1))
		cmp |= 0b0001;
	if (DBL_EQ(n0, n1))
		cmp |= 0b0100;
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

void LLCCEP_exec::softcore::emulated_ldc(LLCCEP_exec::instruction data)
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

void LLCCEP_exec::softcore::emulated_call(LLCCEP_exec::instruction data)
{
	if (static_cast<size_t>(get(data.args[0])) & cmp) {
		call.push(pc);
		pc = get(data.args[1]) - 1;
	}
}

void LLCCEP_exec::softcore::emulated_jmp(LLCCEP_exec::instruction data)
{
	if (static_cast<size_t>(get(data.args[0])) & cmp)
		pc = get(data.args[1]) - 1;
}

void LLCCEP_exec::softcore::emulated_ret(LLCCEP_exec::instruction data)
{	
	(void)data;

	if (!call.size()) {
		quit = true;
		return;
	}

	pc = call.top();
	call.pop();
}

void LLCCEP_exec::softcore::emulated_stregs(LLCCEP_exec::instruction data)
{
	static_cast<void>(data);

	double *newRegs = new (::std::nothrow) double[32];
	if (!newRegs) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Cannot allocate memory for registers copy"));
	}

	memcpy(newRegs, regs, 32 * sizeof(double));
	registersStore.push_back(newRegs);
}

void LLCCEP_exec::softcore::emulated_ldregs(LLCCEP_exec::instruction data)
{
	static_cast<void>(data);

	if (!registersStore.size()) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Error: registersStore is empty, "
			"cannot rollback registers states"));
	}

	double *oldRegs = *(registersStore.end() - 1);
	if (!oldRegs) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Invalid registers storage pointer: cannot rollback"))
	}

	memcpy(regs, oldRegs, 32 * sizeof(double));

	delete oldRegs;
	registersStore.pop_back();
}
