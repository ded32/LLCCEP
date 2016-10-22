#include <llvm/ADT/APFloat.h>
#include <llvm/ADT/STLExtras.h>
#include <llvm/ADT/SmallVector.h>
#include <llvm/Analysis/Passes.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/IR/Metadata.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/Verifier.h>
#include <llvm/Support/FileSystem.h>
#include <llvm/Support/TargetRegistry.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/Target/TargetMachine.h>
#include <llvm/Target/TargetOptions.h>
#include <llvm/Transforms/Scalar.h>

#include "reader/reader.hpp"
#include "codegen/codegen.hpp"

/**************************************************
 * Master
 *************************************************/
int main(int argn, char **argv)
{
	/* Handle all occured exceptions */
	try {
		/* Create reader object */
		LLCCEP_llvm::reader reader;
		/* Create generator object */
		LLCCEP_llvm::codegen generator;

		/* Initialize LLVM module and pass manager
		 * for code generation */
		llvm::InitializeModuleAndPassManager();
		/* Generate program, using the given
		   reader */
		generator.generateProgram(reader);

		/* Initialize LLVM backend */
		llvm::InitializeAllTargetInfos();
		llvm::InitializeAllTargets();
		llvm::InitializeAllTargetMCs();
		llvm::InitializeAllAsmParsers();
		llvm::InitializeAllAsmPrinters();

		/* Create LLVM target */
		::std::string llvmGeneratorError;
		auto llvmTargetTriple = llvm::sys::getDefaultTargetTriple();
		auto llvmTarget = llvm::TargetRegistry::lookupTarget(targetTriple, llvmGeneratorError);
		auto rm = llvm::Optional<Reloc::Model>();
		/* Create LLVM target machine */
		llvm::TargetOptions opt;
		const char *cpu = "generic";
		const char *features = "";
		auto llvmTargetMachine = target->createTargetMachine(llvmTargetTriple, cpu, features, opt, rm);
		/* Create LLVM pass manager */
		llvm::legacy::PassManager passMgr;
		/* Create llvm output type */
		auto llvmOutputType = llvm::TargetMachine::CGFT_ObjectFile;

		/* Change data layout */
		generator.module()->setDataLayout(llvmTargetMachine->createDataLayout());
		if (llvmTargetMachine->addPassesToEmitFile(passMgr, destination, llvmOutputType)) {
			/* If failed to add passes to emit file,
			   throw exception */
			throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
				"Can't emit file of the default type!"));
		}

		/* Run pass manager for generator
		   module */
		passMgr.run(*generator.module());
		/* Flush output file */
		destination.flush();
	} catch (::LLCCEP_exec::runtime_exception &exc) {
		/* Tell about default runtime
		   exception */
		QUITE_ERROR(yes, "%s", exc.msg());
	} catch (...) {
		/* Tell about unknown exception */
		QUITE_ERROR(yes, "Unknown exception");
	}

	return 0;
}
