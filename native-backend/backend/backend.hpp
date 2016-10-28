#ifndef LLCCEP_NATIVE_BACKEND_HPP
#define LLCCEP_NATIVE_BACKEND_HPP

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

#include <string>
#include <memory>
#include <map>

namespace LLCCEP {
	const ::std::string PUSH_INTERNAL_CALLEE = "__internal_push";
	const ::std::string POP_INTERNAL_CALLEE = "__internal_pop";
	const ::std::string TOP_INTERNAL_CALLEE = "__internal_top";
	const ::std::string POW_INTERNAL_CALLEE = "llvm.pow.f64";
	const ::std::string SIN_INTERNAL_CALLEE = "sin";
	const ::std::string COS_INTERNAL_CALLEE = "cos";
	const ::std::string SQRT_INTERNAL_CALLEE = "sqrt";
	const ::std::string PTAN_INTERNAL_CALLEE = "tan";
	const ::std::string PATAN_INTERNAL_CALLEE = "patan";
	const ::std::string LDC_INTERNAL_CALLEE = "getConstantToLoad";

	typedef llvm::ObjectLinkingLayer<> objLinkLayer;
	typedef llvm::IRCompileLayer<objLinkLayer> compileLayer;
	typedef compileLayer::ModuleSetHandleT moduleHandle;

	class nativeBackend {
		llvm::LLVMContext context;
		llvm::IRBuilder<> builder;
		
		::std::unique_ptr<llvm::TargetMachine> target;
		::std::unique_ptr<llvm::legacy::FunctionPassManager> fpm;
		const llvm::DataLayout layout;
		
		objLinkLayer oLayer;
		compileLayer cLayer;

		::std::unique_ptr<llvm::Module> currentModule;
		::std::map<::std::string, llvm::Value *> variables;

	public:
		nativeBackend(::std::string moduleName);
		~nativeBackend();

		void generateCode(instructionInfo_t info);

	private:
		void generateMov(instructionInfo_t info);
		void generateMva(instructionInfo_t info);
		void generatePush(instructionInfo_t info);
		void generatePop(instructionInfo_t info);
		void generateTop(instructionInfo_t info);
		void generateAdd(instructionInfo_t info);
		void generateSub(instructionInfo_t info);
		void generateMul(instructionInfo_t info);
		void generateDiv(instructionInfo_t info);
		void generateAnd(instructionInfo_t info);
		void generateOr(instructionInfo_t info);
		void generateXor(instructionInfo_t info);
		void generateOff(instructionInfo_t info);
		void generateNop(instructionInfo_t info);
		void generateSwi(instructionInfo_t info);
		void generateCmp(instructionInfo_t info);
		void generateInc(instructionInfo_t info);
		void generateDec(instructionInfo_t info);
		void generateSqrt(instructionInfo_t info);
		void generateSin(instructionInfo_t info);
		void generateCos(instructionInfo_t info);
		void generatePtan(instructionInfo_t info);
		void generatePatan(instructionInfo_t info);
		void generateLdc(instructionInfo_t info);
		void generateCall(instructionInfo_t info);
		void generateJmp(instructionInfo_t info);
		void generateRet(instructionInfo_t info);
		void generateStregs(instructionInfo_t info);
		void generateLdregs(instructionInfo_t info);
	};
}
#endif /* LLCCEP_NATIVE_BACKEND_HPP */
