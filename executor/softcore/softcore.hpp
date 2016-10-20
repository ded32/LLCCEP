#ifndef EXEC_SOFTCORE_HPP
#define EXEC_SOFTCORE_HPP

#include <vector>
#include <stack>
#include <fstream>
#include <cstddef>

#include "./../mm/mm.hpp"
#include "./../window/window.hpp"
#include "./../codeReader/codeReader.hpp"

namespace LLCCEP_exec {
	/**************************************************
	 * Soft-processor class.
	 * Used for code execution.
	 * It loads itself the code needed by
	 * executor, processes it
	 * and executes it
	 *************************************************/
	class softcore {
		enum readyInfo_t: int {
			MM_READY        = 0x2,
			CR_READY        = 0x1,
			EVERYTHING_READY = 0x3
		};

	public:
		/**************************************************
		 * Default constructor
		 *************************************************/
		softcore();

		/**************************************************
		 * Default destructor:
		 * - free attached memory
		 * - process created windows messages
		 * - close created windows
		 *************************************************/
		~softcore();

		/**************************************************
		 * Attach memory manager
		 *************************************************/
		void setMm(memoryManager *newMm);

		/**************************************************
		 * Attach code reader
		 *************************************************/
		void setCodeReader(codeReader *newReader);

		/**************************************************
		 * Execute program with specified
		 * memory manager and program reader
		 *************************************************/
		void executeProgram();

		/**************************************************
		 * Check softcore for being OK
		 *************************************************/
		bool OK() const;

	protected:
		double get(arg data);
		void set(arg data, double val);

		void executeNextInstruction();
		void emulated_mov(LLCCEP_exec::instruction data);
		void emulated_mva(LLCCEP_exec::instruction data);
		void emulated_push(LLCCEP_exec::instruction data);
		void emulated_pop(LLCCEP_exec::instruction data);
		void emulated_top(LLCCEP_exec::instruction data);
		void emulated_add(LLCCEP_exec::instruction data);
		void emulated_sub(LLCCEP_exec::instruction data);
		void emulated_mul(LLCCEP_exec::instruction data);
		void emulated_div(LLCCEP_exec::instruction data);
		void emulated_and(LLCCEP_exec::instruction data);
		void emulated_or(LLCCEP_exec::instruction data);
		void emulated_xor(LLCCEP_exec::instruction data);
		void emulated_off(LLCCEP_exec::instruction data);
		void emulated_nop(LLCCEP_exec::instruction data);
		void emulated_swi(LLCCEP_exec::instruction data);
		void emulated_cmp(LLCCEP_exec::instruction data);
		void emulated_inc(LLCCEP_exec::instruction data);
		void emulated_dec(LLCCEP_exec::instruction data);
		void emulated_sqrt(LLCCEP_exec::instruction data);
		void emulated_sin(LLCCEP_exec::instruction data);
		void emulated_cos(LLCCEP_exec::instruction data);
		void emulated_ptan(LLCCEP_exec::instruction data);
		void emulated_patan(LLCCEP_exec::instruction data);
		void emulated_ldc(LLCCEP_exec::instruction data);
		void emulated_call(LLCCEP_exec::instruction data);
		void emulated_jmp(LLCCEP_exec::instruction data);
		void emulated_ret(LLCCEP_exec::instruction data);
		void emulated_stregs(LLCCEP_exec::instruction data);
		void emulated_ldregs(LLCCEP_exec::instruction data);

		/**************************************************
		 * Memory manager pointer,
		 * for reading/writing data into
		 * managed Random-Access Memory
		 *************************************************/
		memoryManager *mm;

		/**************************************************
		 * Code reader, just for reading
		 * insutruction from input file one-by-one
		 * and executing them
		 *************************************************/
		codeReader *reader;

		/**************************************************
		 * Binded QT application.
		 * Needed just for processing the rest events
		 * at the end of life and some coming features
		 *************************************************/
		QApplication *bindedApplication;

		/**************************************************
		 * Stack, used by program for
		 * storing data
		 *************************************************/
		::std::stack<double> stk;

		/**************************************************
		 * Function call stack, for
		 * processing returns and calls.
		 * Jumps are not stored here, it's just
		 * PC substitution
		 *************************************************/
		::std::stack<size_t> call;

		/**************************************************
		 * Storage for registers.
		 * In v3.0, there was a new feature:
		 * single instructions for storing/restoring
		 * registers. So the storage is requested by
		 * them.
		 *************************************************/
		::std::vector<double *> registersStore;

		/**************************************************
		 * Comparision flag.
		 * Only 4 bits of it are used:
		 *  X Y Z W
		 *  _ _ _ _
		 *  | | | |- Above byte
		 *  | | |--- Less byte
		 *  | |----- Equal byte
		 *  |------- Always byte, constantly '1'
		 *************************************************/
		unsigned cmp:4;

		/**************************************************
		 * Sub-parts ready flag.
		 * Only 2 bits of it are used:
		 *  X Y
		 *  _ _
		 *  | |- Code reader flag
		 *  |--- Memory manager flag
		 *************************************************/
		unsigned ready:2;

		/**************************************************
		 * Should quit flag.
		 * Only one bit is used:
		 * X
		 * _
		 * |- Should the child application be ended at
		 *        the next instruction or not
		 *************************************************/
		bool quit:1;

		/**************************************************
		 * Registers of the machine:
		 * there are 32 and all of them are
		 * general-purpose.
		 * So, there is no such nonsence as in
		 * x86, each register can be used for
		 * each operation with it. But,
		 * some registers ase used for results
		 * of interrupts, getting information from
		 * runtime or user.
		 *************************************************/
		double regs[32];

		/**************************************************
		 * Program counter or instruction pointer.
		 * The pointer to currently executing instruction.
		 * Just its offset from the ones at beginning
		 *************************************************/
		long long unsigned pc;

		/**************************************************
		 * Vector of opended by application
		 * windows. It is needed to handle them
		 * at the end. In particular, process their
		 * messages and close them with releasing
		 * memory, allocated for them
		 *************************************************/
		::std::vector<window *> windows;
	};
}

#endif /* EXEC_SOFTCORE_HPP */
