#ifndef LLCCEP_COMPILERCORE_LOADERCORE_HPP
#define LLCCEP_COMPILERCORE_LOADERCORE_HPP

#include <string>
#include <fstream>

namespace LLCCEP_compilerCore {
	namespace loaderCore {
		const size_t INSTRUCTION_LENGTH = 28;

		struct argumentInfo_t {
			LLCCEP_ASM::lex_t type;
			double val;
		} __attribute__((aligned(8)));

		struct instructionInfo_t {
			uint8_t opcode;
			argumentInfo_t arguments;
		} __attribute__((aligned(8)));

		struct programHeaderInfo_t {
			size_t offset;
			size_t mainId;
			size_t size;
		};

		enum compilerCoreLoaderReadyState_t {
			CCL_READY_NOTHING    = 0x0,
			CCL_READY_INPUT      = 0x1,
			CCL_READY_INFO       = 0x2,
			CCL_READY_EVERYTHING = 0x3
		};

		class compilerCoreLoader {
		public:
			compilerCoreLoader();
			explicit codeReader(::std::string in_path);

			~compilerCoreLoader();

			void initializeInputFile(::std::string in_path);
			void readProgramHeaderInfo();
			instructionInfo_t readInstruction(size_t id);
			programHeaderInfo_t getHeaderInfo() const;
			void closeInput();

		private:
			unsigned ready;
			::std::ifstream inputStream;
			::std::string inputPath;
			programHeaderInfo_t info;
		};
	}
}

#endif /* LLCCEP_COMPILERCORE_LOADERCORE_HPP */
