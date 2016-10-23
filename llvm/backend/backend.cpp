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

llvm::Value *LLCCEP_llvm::backend::generate(LLCCEP_llvm::instructionInfo_t instructionInfo)
{
	llvm::Value *(LLCCEP_llvm::backend:: *functions[])(LLCCEP_llvm::instructionInfo_t) = {
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

llvm::Value *LLCCEP_llvm::backend::generateMov(LLCCEP_llvm::instructionInfo_t instructionInfo)
{
	llvm::Value *cpy = get(instructionInfo.args[1]);
	llvm::Value *where = getPtr(instructionInfo.args[0]);

	builder.CreateStore(cpy, where);
}

llvm::Value *LLCCEP_llvm::backend::generateMva(LLCCEP_llvm::instructionInfo_t instructionInfo)
{
	llvm::Value *cpy = get(instructionInfo.args[1]);
	llvm::Value *where = get(instructionInfo.args[0]);

	builder.CreateStore(cpy, where);
}

llvm::Value *LLCCEP_llvm::backend::generatePush(LLCCEP_llvm::instructionInfo_t instructionInfo)
{
	llvm::Function *func = currentModule->getFunction(LLCCEP_llvm::PUSH_INTERNAL_CALLEE);
	if (!func) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Invalid callee for push"));
	}

	::std::vector<llvm::Value *> args;
	args.push_back(getValue(instructionInfo.args[0]));

	return builder.CreateCall(func, args, TEMP_INTERNAL_VAR);
}

llvm::Value *LLCCEP_llvm::backend::generatePop(LLCCEP_llvm::instructionInfo_t instructionInfo)
{
	llvm::Function *func = currentModule->getFunction(LLCCEP_llvm::POP_INTERNAL_CALLEE);
	if (!func) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Invalid callee for pop"));
	}

	::std::vector<llvm::Value *> args;
	return builder.CreateCall(func, args, TEMP_INTERNAL_VAR);
}

llvm::Value *LLCCEP_llvm::backend::generateTop(LLCCEP_llvm::instructionInfo_t instructionInfo)
{
	llvm::Function *func = currentModule->getFunction(LLCCEP_llvm::TOP_INTERNAL_CALLEE);
	if (!func) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Invalid callee for top"));
	}

	::std::vector<llvm::Value *> args;
	args.push_back(getPtr(instructionInfo.args[0]));

	return builder.CreateCall(func, args, TEMP_INTERNAL_VAR);
}

#define GENERATE_BINOP_MATH(info, inst) \
{ \
	llvm::Value *v0 = get(info.args[1]); \
	llvm::Value *v1 = get(info.args[2]); \
	llvm::Value *res = getPtr(info.args[0]); \
	\
	builder.CreateF##inst##(v0, v1, TEMP_INTERNAL_VAR); \
	builder.CreateLoad(res, TEMP_INTERNAL_VAR); \
	\
	return res; \
}

llvm::Value *LLCCEP_llvm::backend::generateAdd(LLCCEP_llvm::instructionInfo_t instructionInfo)
{
	GENERATE_BINOP_MATH(instructionInfo, Add);
}

llvm::Value *LLCCEP_llvm::backend::generateSub(LLCCEP_llvm::instructionInfo_t instructionInfo)
{
	GENERATE_BINOP_MATH(instructionInfo, Sub);
}

llvm::Value *LLCCEP_llvm::backend::generateMul(LLCCEP_llvm::instructionInfo_t instructionInfo)
{
	GENERATE_BINOP_MATH(instructionInfo, Mul);
}

llvm::Value *LLCCEP_llvm::backend::generateDiv(LLCCEP_llvm::instructionInfo_t instructionInfo)
{
	GENERATE_BINOP_MATH(instructionInfo, Div);
}

#define GENERATE_LOGIC(info, inst) \
{ \
	llvm::Value *v0 = get(info.args[1]); \
	llvm::Value *v1 = get(info.args[2]); \
	llvm::Value *res = getPtr(info.args[0]); \
	\
	builder.CreateFPToUI(v0, llvm::Type::getInt64Ty(), \
	                     TEMP_INTERNAL_VAR); \
	builder.CreateFPToUI(v1, llvm::Type::getInt64Ty(), \
	                     TEMP_INTERNAL_VAR_1); \
	\
	builder.CreateLoad(v0, TEMP_INTERNAL_VAR); \
	builder.CreateLoad(v1, TEMP_INTERNAL_VAR_1); \
	\
	builder.Create##inst##(v0, v1, TEMP_INTERNAL_VAR); \
	builder.CreateLoad(v0, TEMP_INTERNAL_VAR); \
	builder.CreateUIToFP(v0, llvm::Type::getDoubleTy(), \
	                     TEMP_INTERNAL_VAR); \
	builder.CreateLoad(res, TEMP_INTERNAL_VAR); \
	\
	return res; \
}

llvm::Value *LLCCEP_llvm::backend::generateAnd(LLCCEP_llvm::instructionInfo_t instructionInfo)
{
	GENERATE_LOGIC(instructionInfo, And);
}

llvm::Value *LLCCEP_llvm::backend::generateOr(LLCCEP_llvm::instructionInfo_t instructionInfo)
{
	GENERATE_LOGIC(instructionInfo, Or);
}

llvm::Value *LLCCEP_llvm::backend::generateXor(LLCCEP_llvm::instructionInfo_t instructionInfo)
{
	GENERATE_LOGIC(instructionInfo, Xor);
}

llvm::Value *LLCCEP_llvm::backend::generateOff(LLCCEP_llvm::instructionInfo_t instructionInfo)
{
	llvm::Value *v0 = get(instructionInfo.args[1]);
	llvm::Value *v1 = get(instructionInfo.args[2]);
	llvm::Value *res = getPtr(instructionInfo.args[0]);

	builder.CreateFPToUI(v0, llvm::Type::getInt64Ty(), TEMP_INTERNAL_VAR);
	builder.CreateLoad(v0, TEMP_INTERNAL_VAR);

	builder.CreateFPToUI(v1, llvm::Type::getInt64Ty(), TEMP_INTERNAL_VAR);
	builder.CreateLoad(v1, TEMP_INTERNAL_VAR);

	builder.CreateICmpSGE(v1, createConstantValue(0), TEMP_INTERNAL_VAR);
	builder.CreateLoad(res, TEMP_INTERNAL_VAR);
	builder.CreateShl(v0, v1, TEMP_INTERNAL_VAR);
	builder.CreateLoad(v0, TEMP_INTERNAL_VAR);
	builder.CreateShr(v0, v1, TEMP_INTERNAL_VAR);
	builder.CreateLoad(v1, TEMP_INTERNAL_VAR);
	builder.CreateSelect(res, v0, v1, TEMP_INTERNAL_VAR);
	builder.CreateLoad(res, TEMP_INTERNAL_VAR);

	return res;
}

llvm::Value *LLCCEP_llvm::backend::generateNop(LLCCEP_llvm::instructionInfo_t instructionInfo)
{
	return 0;
}

llvm::Value *LLCCEP_llvm::backend::generateSwi(LLCCEP_llvm::instructionInfo_t instructionInfo)
{
	llvm::Function *func = currentModule->getFunction(LLCCEP_llvm::SWI_INTERNAL_CALLEE);
	if (!func) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Invalid callee for swi"));
	}

	::std::vector<llvm::Value *> args;
	args.push_back(v0);

	builder.CreateCall(func, args, TMP_INTERNAL_VAR);
}
