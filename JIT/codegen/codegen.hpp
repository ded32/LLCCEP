#ifndef CODEGEN_HPP
#define CODEGEN_HPP

#include "../runtime/runtime.hpp"
#include "../program/program.hpp"

namespace LLCCEP_JIT {
	class codegenBackend: public program {
	public:
		codegenBackend();

		void genMov(LLCCEP_exec::instruction data);
		void genMva(LLCCEP_exec::instruction data);
		void genPush(LLCCEP_exec::instruction data);
		void genPop(LLCCEP_exec::instruction data);
		void genTop(LLCCEP_exec::instruction data);
		void genAdd(LLCCEP_exec::instruction data);
		void genSub(LLCCEP_exec::instruction data);
		void genMul(LLCCEP_exec::instruction data);
		void genDiv(LLCCEP_exec::instruction data);
		void genAnd(LLCCEP_exec::instruction data);
		void genOr(LLCCEP_exec::instruction data);
		void genXor(LLCCEP_exec::instruction data);
		void genOff(LLCCEP_exec::instruction data);
		void genNop(LLCCEP_exec::instruction data);
		void genSwi(LLCCEP_exec::instruction data);
		void genCmp(LLCCEP_exec::instruction data);
		void genInc(LLCCEP_exec::instruction data);
		void genDec(LLCCEP_exec::instruction data);
		void genSqrt(LLCCEP_exec::instruction data);
		void genSin(LLCCEP_exec::instruction data);
		void genCos(LLCCEP_exec::instruction data);
		void genPtan(LLCCEP_exec::instruction data);
		void genPatan(LLCCEP_exec::instruction data);
		void genLdc(LLCCEP_exec::instruction data);
		void genCall(LLCCEP_exec::instruction data);
		void genJmp(LLCCEP_exec::instruction data);
		void genRet(LLCCEP_exec::instruction data);

	protected:
		void getImmediate(regID reg, LLCCEP_exec::arg data);
		void getPointer(regID reg, LLCCEP_exec::arg data);

	private:
		runtimeManager *_runtimeManager;
	};
}

#endif // CODEvoid genHPP
