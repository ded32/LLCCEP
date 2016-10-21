#include "backend.hpp"

LLCCEP_llvm::backend::backend():
	context(),
	builder(),
	currentModule(),
	variables()
{ }

LLCCEP_llvm::backend::~backend() 
{
	/* Auto-call the other destructors */
}

void LLCCEP_llvm::backend::generate(LLCCEP_llvm::instructionInfo_t instructionInfo)
{
	void (LLCCEP_llvm::backend:: *functions[])(LLCCEP_llvm::instructionInfo_t) = {
		&LLCCEP_llvm::backend::generateMov,
		&LLCCEP_llvm::backend::generateMva,
		&LLCCEP_llvm::backend::generatePush,
		&LLCCEP_llvm::backend::generatePop,
		&LLCCEP_llvm::backend::generateTop,
		&LLCCEP_llvm::backend::generateAdd,
		&LLCCEP_llvm::backend::generateSub,
		&LLCCEP_llvm::backend::generateMul,
		&LLCCEP_llvm::backend::generateDiv,
		&LLCCEP_llvm::backend::generateAnd,
		&LLCCEP_llvm::backend::generateOr,
		&LLCCEP_llvm::backend::generateXor,
		&LLCCEP_llvm::backend::generateOff,
		&LLCCEP_llvm::backend::generateNop,
		&LLCCEP_llvm::backend::generateSwi,
		&LLCCEP_llvm::backend::generateCmp,
		&LLCCEP_llvm::backend::generateInc,
		&LLCCEP_llvm::backend::generateDec,
		&LLCCEP_llvm::backend::generateSqrt,
		&LLCCEP_llvm::backend::generateSin,
		&LLCCEP_llvm::backend::generateCos,
		&LLCCEP_llvm::backend::generatePtan,
		&LLCCEP_llvm::backend::generatePatan,
		&LLCCEP_llvm::backend::generateLdc,
		&LLCCEP_llvm::backend::generateCall,
		&LLCCEP_llvm::backend::generateJmp,
		&LLCCEP_llvm::backend::generateRet,
		&LLCCEP_llvm::backend::generateStregs,
		&LLCCEP_llvm::backend::generateLdregs
	};

	if (instructionInfo.opcode >= LLCCEP_ASM::INST_NUM) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Opcode overbound for codegenerator!"));
	}

	(this->*functions[instructionInfo.opcode])(info);
}
