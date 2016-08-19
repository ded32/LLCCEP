#ifndef EXEC_CODEREADER_HPP
#define EXEC_CODEREADER_HPP

#include <STDExtras.hpp>

#include <vector>
#include <fstream>
#include <cstdint>

namespace LLCCEP_exec {
	enum arg_t: uint8_t {
		ARG_T_REG  = 0,
		ARG_T_MEM  = 1,
		ARG_T_VAL  = 2,
		ARG_T_COND = 3,
		ARG_T_NO   = 5
	};

	struct arg {
		arg_t type;
		double val;
	} __attribute__((aligned(8))) /* 16 bytes*/;

	struct instruction {
		uint8_t opcode;
		arg args[3];
	} __attribute__((aligned(8))) /* 56 bytes */;

	struct codeData {
		size_t offset;
		size_t main_id;
		size_t size;
	};

	class codeReader {
	public:
		codeReader();
		explicit codeReader(::std::string in_path);

		void initializeInputFile(::std::string in_path);
		void readProgramHeader();
		instruction getInstruction(size_t id);
		codeData getProgramData() const;
		void closeInput();

		bool OK() const;

	private:
		::std::ifstream _input;
		::std::string _path;
		codeData _data;
	};
}

#endif // EXEC_CODEREADER_HPP
