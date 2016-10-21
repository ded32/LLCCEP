#ifndef LLCCEP_LLVM_BACKEND_HPP
#define LLCCEP_LLVM_BACKEND_HPP

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

#include <string>
#include <map>
#include <memory>

namespace LLCCEP_llvm {
	const ::std::string PUSH_INTERNAL_CALLEE = "__internal_push";
	const ::std::string POP_INTERNAL_CALLEE = "__internal_pop";
	const ::std::string TOP_INTERNAL_CALLEE = "__internal_top";

	class backend {
		llvm::LLVMContext context;
		llvm::IRBuilder<> builder;
		::std::unique_ptr<llvm::Module> currentModule;
		::std::map<::std::string, llvm::Value *> variables;

	public:
		backend();
		~backend();

		llvm::Value *generate(instructionInfo_t instructionInfo);

	private:
		llvm::Value *generateMov(instructionInfo_t instructionInfo);
		llvm::Value *generateMva(instructionInfo_t instructionInfo);
		llvm::Value *generatePush(instructionInfo_t instructionInfo);
		llvm::Value *generatePop(instructionInfo_t instructionInfo);
		llvm::Value *generateTop(instructionInfo_t instructionInfo);
		llvm::Value *generateAdd(instructionInfo_t instructionInfo);
		llvm::Value *generateSub(instructionInfo_t instructionInfo);
		llvm::Value *generateMul(instructionInfo_t instructionInfo);
		llvm::Value *generateDiv(instructionInfo_t instructionInfo);
		llvm::Value *generateAnd(instructionInfo_t instructionInfo);
		llvm::Value *generateOr(instructionInfo_t instructionInfo);
		llvm::Value *generateXor(instructionInfo_t instructionInfo);
		llvm::Value *generateOff(instructionInfo_t instructionInfo);
		llvm::Value *generateNop(instructionInfo_t instructionInfo);
		llvm::Value *generateSwi(instructionInfo_t instructionInfo);
		llvm::Value *generateCmp(instructionInfo_t instructionInfo);
		llvm::Value *generateInc(instructionInfo_t instructionInfo);
		llvm::Value *generateDec(instructionInfo_t instructionInfo);
		llvm::Value *generateSqrt(instructionInfo_t instructionInfo);
		llvm::Value *generateSin(instructionInfo_t instructionInfo);
		llvm::Value *generateCos(instructionInfo_t instructionInfo);
		llvm::Value *generatePtan(instructionInfo_t instructionInfo);
		llvm::Value *generatePatan(instructionInfo_t instructionInfo);
		llvm::Value *generateLdc(instructionInfo_t instructionInfo);
		llvm::Value *generateCall(instructionInfo_t instructionInfo);
		llvm::Value *generateJmp(instructionInfo_t instructionInfo);
		llvm::Value *generateRet(instructionInfo_t instructionInfo);
		llvm::Value *generateStregs(instructionInfo_t instructionInfo);
		llvm::Value *generateLdregs(instructionInfo_t instructionInfo);
	};
}

#endif /*LLCCEP_LLVM_BACKEND_HPP */
