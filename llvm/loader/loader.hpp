#ifndef LLCCEP_LLVM_LOADER_HPP
#define LLCCEP_LLVM_LOADER_HPP

namespace LLCCEP_llvm {
	class programLoader {
		struct programHeaderInfo_t {
			size_t offset;
			size_t sz;
			size_t mainOffset;
		};

		enum programLoaderReady_t {
			PLR_T_NOTHING    = 0x0,
			PLR_T_INPUT      = 0x1,
			PLR_T_INFO       = 0x2,
			PLR_T_EVERYTHING = 0x3
		};

	public:
		programLoader();
		~programLoader();

		void setInputPath(::std::string str);
		instructionInfo_t readInstruction(size_t id);
		void closeInput();

	private:
		unsigned ready:2;

		::std::string inputPath;
		::std::ifstream input;

		programHeaderInfo_t info;
	};
}

#endif /* LLCCEP_LLVM_LOADER_HPP */
