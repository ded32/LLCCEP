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
	class softcore {
	public:
		softcore();
		~softcore();

		void setMm(memoryManager *newMm);
		void setCodeReader(codeReader *newReader);
		void executeProgram();

		::std::vector<window *> getWindows() const;
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

		::std::stack<double> stk;
		::std::stack<size_t> call;
		::std::vector<double *> registersStore;

		int cmp;
		double regs[32];
		double pc;

		::std::vector<window *> windows;
		memoryManager *mm;
		codeReader *reader;
		int ready;
		bool quit;
	};
}

#endif // EXEC_SOFTCORE_HPP
