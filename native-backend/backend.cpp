#include <llvm/ADT/APFloat.h>
#include <llvm/ADT/STLExtras.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Constants.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/Verifier.h>

#include <core/reader.hpp>
#include <core/instruction.hpp>

#include "backend.hpp"

LLCCEP::nativeBackend::nativeBackend(::std::string moduleName):
	context(),
	builder(context),
	target(llvm::EngineBuilder().selectTarget()),
	layout(target->createDataLayout()),
	oLayer(),
	cLayer(oLayer, llvm::orc::SimpleCompiler(*target)),
	currentModule(0),
	variables()
{
	llvm::Context LLVMContext;
	currentModule = llvm::make_unique<llvm::Module>(moduleName.c_str(),
	                                                LLVMContext);
	currentModule->setDataLayout(layout);
	
	fpm = llvm::make_unique<llvm::legacy::FunctionPassManager>(currentModule.get());
	fpm->add(llvm::createInstructionCombiningPass());
	fpm->add(llvm::createReassociatePass());
	fpm->add(llvm::createGVNPass());
	fpm->add(llvm::createCFGSimplificationPass());

	fpm->doInitialization();
}

LLCCEP::nativeBackend::~nativeBackend()
{ }

void LLCCEP::nativeBackend::generateCode(LLCCEP::instructionInfo_t info)
{
	void (LLCCEP::nativeBackend:: *functions[])(LLCCEP::instructionInfo_t) = {
		&LLCCEP::nativeBackend::generateMov,
		&LLCCEP::nativeBackend::generateMva,
		&LLCCEP::nativeBackend::generatePush,
		&LLCCEP::nativeBackend::generatePop,
		&LLCCEP::nativeBackend::generateTop,
		&LLCCEP::nativeBackend::generateAdd,
		&LLCCEP::nativeBackend::generateSub,
		&LLCCEP::nativeBackend::generateMul,
		&LLCCEP::nativeBackend::generateDiv,
		&LLCCEP::nativeBackend::generateAnd,
		&LLCCEP::nativeBackend::generateOr,
		&LLCCEP::nativeBackend::generateXor,
		&LLCCEP::nativeBackend::generateOff,
		&LLCCEP::nativeBackend::generateNop,
		&LLCCEP::nativeBackend::generateSwi,
		&LLCCEP::nativeBackend::generateCmp,
		&LLCCEP::nativeBackend::generateInc,
		&LLCCEP::nativeBackend::generateDec,
		&LLCCEP::nativeBackend::generateSqrt,
		&LLCCEP::nativeBackend::generateSin,
		&LLCCEP::nativeBackend::generateCos,
		&LLCCEP::nativeBackend::generatePtan,
		&LLCCEP::nativeBackend::generatePatan,
		&LLCCEP::nativeBackend::generateLdc,
		&LLCCEP::nativeBackend::generateCall,
		&LLCCEP::nativeBackend::generateJmp,
		&LLCCEP::nativeBackend::generateRet,
		&LLCCEP::nativeBackend::generateStregs,
		&LLCCEP::nativeBackend::generateLdregs
	};

	if (info.opcode >= LLCCEP_ASM::INST_NUM) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Opcode overbound for codegenerator!"));
	}

	(this->*functions[info.opcode])(info);
}

void LLCCEP::nativeBackend::generateMov(LLCCEP::instructionInfo_t info)
{
	llvm::Value *copying = get(info.args[1]);
	llvm::Value *where = getPtr(info.args[0]);

	builder.CreateStore(copying, where);
}

void LLCCEP::nativeBackend::generateMva(LLCCEP::instructionInfo_t info)
{
	llvm::Value *copying = get(info.args[1]);
	llvm::Value *where = getPtrByVal(info.args[0]);

	builder.CreateStore(copying, where);
}

void LLCCEP::nativeBackend::generatePush(LLCCEP::instructionInfo_t info)
{
	auto callee = getModuleFunction(LLCCEP::PUSH_INTERNAL_CALLEE);
	LLCCEP::nativeBackend::functionArguments args;

	args.push_back(get(info.args[0]));
	builder.CreateCall(callee, args);
}

void LLCCEP::nativeBackend::generatePop(LLCCEP::instructionInfo_t info)
{
	auto callee = getModuleFunction(LLCCEP::POP_INTERNAL_CALLEE);
	LLCCEP::nativeBackend::functionArguments args;

	builder.CreateCall(callee, args);
}

void LLCCEP::nativeBackend::generateTop(LLCCEP::instructionInfo_t info)
{
	llvm::Value *res = getPtr(info.args[0]);
	auto callee = getModuleFunction(LLCCEP_llvm::TOP_INTERNAL_CALLEE);
	LLCCEP::nativeBackend::functionArguments args;

	builder.CreateCall(callee, args, LLCCEP::TEMP_INTERNAL_VAR);
	builder.CreateLoad(res, LLCCEP::TEMP_INTERNAL_VAR);	
}

#define SYNTHESE_ARITHMETICS(op) \
void LLCCEP::nativeBackend::generate##op##(LLCCEP::instructionInfo_t info) \
{ \
	llvm::Value *where = getPtr(info.args[0]); \
	llvm::Value *o[] = {get(info.args[1]), get(info.args[1])}; \
	\
	builder.CreateF##op##(o[0], o[1], LLCCEP::TEMP_INTERNAL_VAR); \
	builder.CreateLoad(where, LLCCEP::TEMP_INTERNAL_VAR); \
}

SYNTHESE_ARITHMETICS(Add);
SYNTHESE_ARITHMETICS(Sub);
SYNTHESE_ARITHMETICS(Mul);
SYNTHESE_ARITHMETICS(Div);

#undef SYNTHESE_ARITHMETICS

#define SYNTHESE_LOGIC(op) \
void LLCCEP::nativeBackend::generate##op##(LLCCEP::instructionInfo_t info) \
{ \
	llvm::Value *where = getPtr(info.args[0]); \
	llvm::Value *o[] = {get(info.args[1]), \
	                    get(info.args[2])}; \
	\
	for (unsigned i = 0; i < 2; i++) { \
		builder.createFPToUI(o[i], llvm::Type::getInt64Ty(), \
	                             LLCCEP::TEMP_INTERNAL_VAR); \
	\
		builder.CreateLoad(o[i], LLCCEP::TEMP_INTERNAL_VAR); \
	} \
	\
	builder.Create##op##(o[0], o[1], LLCCEP::TEMP_INTERNAL_VAR); \
	builder.CreateLoad(o[0], LLCCEP::TEMP_INTERNAL_VAR); \
	builder.CreateUIToFP(o[0], llvm::Type::getDoubleTy(), \
	                     LLCCEP::TEMP_INTERNAL_VAR); \
	builder.CreateLoad(where, LLCCEP::TEMP_INTERNAL_VAR); \
}

SYNTHESE_LOGIC(And);
SYNTHESE_LOGIC(Or);
SYNTHESE_LOGIC(Xor);
