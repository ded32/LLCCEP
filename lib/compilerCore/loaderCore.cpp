#include <string>
#include <fstream>

#include <compilerCore/coreInterface.hpp>
#include <compilerCore/loaderCore.hpp>

#define READY_INPUT (ready & LLCCEP_compilerCore::loaderCore::CCL_READY_INPUT)
#define READY_INFO  (ready & LLCCEP_compilerCore::loaderCore::CCL_READY_INFO)

LLCCEP_compilerCore::loaderCore::compilerCoreLoader::compilerCoreLoader():
	inputStream(),
	inputPath(),
	info(),
	ready(LLCCEP_compilerCore::loaderCore::CCL_READY_NOTHING)
{ }

LLCCEP_compilerCore::loaderCore::compilerCoreLoader:~compilerCoreLoader()
{
	if (ready & LLCCEP_compilerCore::loaderCore::CCL_READY_INPUT)
		inputStream.close();
}

void LLCCEP_compilerCore::loaderCore::compilerCoreLoader::initializeInputFile(
	::std::string in_path)
{
	REQUIRE(!READY_INPUT);

	inputPath = in_path;
	inputStream.open(inputPath);
	CHECK_FILE(inputStream);
	MARK(ready, LLCCEP_compilerCore::loaderCore::CCL_READY_INPUT);

	REQUIRE(READY_INPUT);
}

void LLCCEP_compilerCore::loaderCore::compilerCoreLoader::readProgramHeaderInfo()
{
	REQUIRE(!READY_INFO);

	uint8_t wordSz;
	size_t programLength;

	input.seekg(0);
	wordSz = input.get();

	if (wordSz > sizeof(size_t)) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Can't load program: a capacity conflict!\n"
			"The machine, produced this object module has\n"
			"another capacity!"));
	}

	input.read(reinterpret_cast<uint8_t *>(&(info.mainId)),
	           sizeof(size_t));
	programLength = get_length(input) - wordSz - 1;
	if (programLength % 28) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Invalid or damaged object module"));
	}


	info.size = programLength / 28;
	info.offset = wordSz + 1;
	MARK(ready, LLCCEP_compilerCore::loaderCore::CCL_READY_INFO);

	REQUIRE(READY_INFO);
}

LLCCEP_compilerCore::loaderCore::instructionInfo_t LLCCEP_compilerCore::loaderCore::readInstruction(size_t id)
{
	REQUIRE(READY_INFO);
	REQUIRE(READY_INPUT);

	if (id >= info.size) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Invalid instruction id to get: overbounding"));
	}

	input.seekg(info.offset + id * LLCCEP_compilerCore::loaderCore::INSTRUCTION_LENGTH);

	LLCCEP_compilerCore::loaderCore::instructionInfo_t res{};
	res.opcode = input.get();

	for (unsigned i = 0; i < 3; i++) {
		res.args[i].type = input.get();
		input.read(reinterpret_cast<uint8_t *>(&(res.args[i].val)),
		           sizeof(double));
	}

	return res;
}

LLCCEP_compilerCore::loaderCore::programHeaderInfo_t LLCCEP_compilerCore::loaderCore::compilerCoreLoader::getHeaderInfo() const
{
	REQUIRE(READY_INFO);
	REQUIRE(READY_INPUT);

	return info;
}

void LLCCEP_compilerCore::loaderCore::compilerCoreLoader::closeInput()
{
	REQUIRE(READY_INPUT);

	input.close();
	UNMARK(ready, LLCCEP_compilerCore::loaderCore::CCL_READY_INPUT);

	REQUIRE(!READY_INPUT);
}

#undef READY_INPUT
#undef READY_INFO
