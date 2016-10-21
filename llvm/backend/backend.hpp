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
	class backend {
		llvm::LLVMContext context;
		llvm::IRBuilder<> builder;
		::std::unique_ptr<llvm::Module> currentModule;
		::std::map<::std::string, llvm::Value *> variables;

	public:
		backend();
		~backend();

		void generate(instructionInfo_t instructionInfo);

	private:
		void generateMov(instructionInfo_t instructionInfo);
		void generateMva(instructionInfo_t instructionInfo);
		void generatePush(instructionInfo_t instructionInfo);
		void generatePop(instructionInfo_t instructionInfo);
		void generateTop(instructionInfo_t instructionInfo);
		void generateAdd(instructionInfo_t instructionInfo);
		void generateSub(instructionInfo_t instructionInfo);
		void generateMul(instructionInfo_t instructionInfo);
		void generateDiv(instructionInfo_t instructionInfo);
		void generateAnd(instructionInfo_t instructionInfo);
		void generateOr(instructionInfo_t instructionInfo);
		void generateXor(instructionInfo_t instructionInfo);
		void generateOff(instructionInfo_t instructionInfo);
		void generateNop(instructionInfo_t instructionInfo);
		void generateSwi(instructionInfo_t instructionInfo);
		void generateCmp(instructionInfo_t instructionInfo);
		void generateInc(instructionInfo_t instructionInfo);
		void generateDec(instructionInfo_t instructionInfo);
		void generateSqrt(instructionInfo_t instructionInfo);
		void generateSin(instructionInfo_t instructionInfo);
		void generateCos(instructionInfo_t instructionInfo);
		void generatePtan(instructionInfo_t instructionInfo);
		void generatePatan(instructionInfo_t instructionInfo);
		void generateLdc(instructionInfo_t instructionInfo);
		void generateCall(instructionInfo_t instructionInfo);
		void generateJmp(instructionInfo_t instructionInfo);
		void generateRet(instructionInfo_t instructionInfo);
		void generateStregs(instructionInfo_t instructionInfo);
		void generateLdregs(instructionInfo_t instructionInfo);
	};
}

#endif /* LLCCEP_LLVM_BACKEND_HPP */
