int main(int argn, char **argv)
{
	try {
		LLCCEP_llvm::codegen generator;

		llvm::InitializeModuleAndPassManager();
		generator.generateProgram(program);

		llvm::InitializeAllTargetInfos();
		llvm::InitializeAllTargets();
		llvm::InitializeAllTargetMCs();
		llvm::InitializeAllAsmParsers();
		llvm::InitializeAllAsmPrinters();

		::std::string llvmGeneratorError;
		auto llvmTargetTriple = llvm::sys::getDefaultTargetTriple();
		auto llvmTarget = llvm::TargetRegistry::lookupTarget(targetTriple, llvmGeneratorError);
		auto rm = llvm::Optional<Reloc::Model>();
		llvm::TargetOptions opt;
		const char *cpu = "generic";
		const char *features = "";
		auto llvmTargetMachine = target->createTargetMachine(llvmTargetTriple, cpu, features, opt, rm);
		llvm::legacy::PassManager passMgr;
		auto llvmOutputType = llvm::TargetMachine::CGFT_ObjectFile;

		generator.module()->setDataLayout(llvmTargetMachine->createDataLayout());
		if (llvmTargetMachine->addPassesToEmitFile(passMgr, destination, llvmOutputType)) {
			throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
				"Can't emit file of the default type!"));
		}

		passMgr.run(*generator.module());
		destination.flush();
	} catch (::LLCCEP_exec::runtime_exception &exc) {
		QUITE_ERROR(yes, "%s", exc.msg());
	} catch (...) {
		QUITE_ERROR(yes, "Unknown exception");
	}

	return 0;
}
