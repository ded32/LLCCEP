#ifndef SOFTCORE_HPP
#define SOFTCORE_HPP

#include <vector>
#include <stack>
#include <fstream>
#include <cstddef>

#include "./../mm/mm.hpp"
#include "./../window/window.hpp"
#include "./../program/program.hpp"

namespace LLCCEP_exec {
	class softcore {
	public:
		softcore();
		~softcore();

		void setProgram(::std::ifstream &prog);
		void executeProgram();

	protected:
		double get(arg data);
		void set(arg data, double val);

		void executeNextInstruction();
		void emulated_mov(LLCCEP_vm::instruction data);
		void emulated_mva(LLCCEP_vm::instruction data);
		void emulated_push(LLCCEP_vm::instruction data);
		void emulated_pop(LLCCEP_vm::instruction data);
		void emulated_top(LLCCEP_vm::instruction data);
		void emulated_add(LLCCEP_vm::instruction data);
		void emulated_sub(LLCCEP_vm::instruction data);
		void emulated_mov(LLCCEP_vm::instruction data);
		void emulated_div(LLCCEP_vm::instruction data);
		void emulated_and(LLCCEP_vm::instruction data);
		void emulated_or(LLCCEP_vm::instruction data);
		void emulated_xor(LLCCEP_vm::instruction data);
		void emulated_off(LLCCEP_vm::instruction data);
		void emulated_nop(LLCCEP_vm::instruction data);
		void emulated_swi(LLCCEP_vm::instruction data);
		void emulated_cmp(LLCCEP_vm::instruction data);
		void emulated_inc(LLCCEP_vm::instruction data);
		void emulated_dec(LLCCEP_vm::instruction data);
		void emulated_sqrt(LLCCEP_vm::instruction data);
		void emulated_sin(LLCCEP_vm::instruction data);
		void emulated_ptan(LLCCEP_vm::instruction data);
		void emulated_patan(LLCCEP_vm::instruction data);
		void emulated_ldc(LLCCEP_vm::instruction data);
		void emulated_call(LLCCEP_vm::instruction data);
		void emulated_jmp(LLCCEP_vm::instruction data);
		void emulated_ret(LLCCEP_vm::instruction data);

	private:
		::std::stack<double> _stk;
		::std::stack<size_t> _call;

		int _cmp;
		double _regs[32];
		double _pc;

		::std::vector<FILE *> _files;
		::std::vector<window> _windows;
		memoryManager _mm;
		::std::ifstream &_prog;
		bool _ready;
		bool _quit;
	};
}

#endif // SOFT_CORE_HPP
