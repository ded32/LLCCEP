#ifndef DISASSEMBLER_DISASSEMBLER_HPP
#define DISASSEMBLER_DISASSEMBLER_HPP

#include <string>
#include <iostream>

#include <codeReader.hpp>
#include <STDExtras.hpp>

namespace LLCCEP_DisASM {
	class disassembler {
		UNCOPIABLE_CLASS(disassembler)
	
		::std::vector<LLCCEP::instruction> instructions;
		size_t mainID;
	
	public:
		disassembler();
		~disassembler();

		void readFile(::std::istream *in);
		void dumpDisassembly(::std::ostream *out);
	};
}

#endif /* DISASSEMBLER_DISASSEMBLER_HPP */
