#include "loader.hpp"

LLCCEP_llvm::programLoader::programLoader():
	ready(LLCCEP_llvm::programLoader::PLR_T_NOTHING),
	inputPath(),
	input()
{ }

LLCCEP_llvm::programLoader::~programLoader()
{
	if (ready & LLCCEP_llvm::programLoader::PLR_T_INPUT)
		input.close();
}

void LLCCEP_llvm::programLoader::setInputPath(::std::string str)
{
	REQUIRE(!(ready & LLCCEP_llvm::programLoader::PLR_T_INPUT));

	inputPath = str;
	input.open(inputPath);
	CHECK_FILE(input);

	ready |= LLCCEP_llvm::programLoader::PLR_T_INPUT;
}

void LLCCEP_llvm::programLoader::readProgramHeader()
{
	REQUIRE(ready & LLCCEP_llvm::programLoader::PLR_T_INPUT);
	REQUIRE(!(ready & LLCCEP_llvm::programLoader::PLR_T_INFO));

	uint8_t wordSizeSourceMachine = 0;
	input.seekg(0);
	wordSizeSourceMachine = input.get();

	CHECK_WORDSIZE(wordSizeSourceMachine);

	input.read(reinterpret_cast<char *>(&info.mainId),
	           sizeof(size_t));

	size_t pl = get_length(input) - sz - 1;

	CHECK_INSTRUCTION_NUM(pl);

	info.size = pl / 28;
	info.offset = wordSizeSourceMachine + 1;

	wordSizeSourceMachine = input.get();
}

LLCCEP_llvm::instructionInfo_t LLCCEP_llvm::programLoader::readInstruction(size_t id)
{

}
