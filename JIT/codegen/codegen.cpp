//#include "../runtime/runtime_data.hpp"
#include "../program/program.hpp"

#include "codegen.hpp"

LLCCEP_JIT::codegenBackend::codegenBackend()
{ }

void LLCCEP_JIT::codegenBackend::genMov(LLCCEP_exec::instruction data)
{
	getImmediate(LLCCEP_JIT::RAX, data.args[1]);
	getPointer(LLCCEP_JIT::RBX, data.args[0]);

	emit_mov_reg_reg_ptr(LLCCEP_JIT::RAX, LLCCEP_JIT::RBX);
}

void LLCCEP_JIT::codegenBackend::genMva(LLCCEP_exec::instruction data)
{
	getImmediate(LLCCEP_JIT::RAX, data.args[1]);
	getImmediate(LLCCEP_JIT::RBX, data.args[0]);

	emit_mov_reg_reg_ptr(LLCCEP_JIT::RAX, LLCCEP_JIT::RBX);
}

void LLCCEP_JIT::codegenBackend::genPush(LLCCEP_exec::instruction data)
{
	getImmediate(LLCCEP_JIT::RAX, data.args[0]);

	emit_push_reg(LLCCEP_JIT::RAX);
}

void LLCCEP_JIT::codegenBackend::genPop(LLCCEP_exec::instruction data)
{
	emit_pop_reg(LLCCEP_JIT::RAX);
}

void LLCCEP_JIT::codegenBackend::genTop(LLCCEP_exec::instruction data)
{
	getAddress(LLCCEP_JIT::RAX, data.args[0]);

	emit_pop_reg(LLCCEP_JIT::RBX);
	emit_push_imm(LLCCEP_JIT::RBX);

	emit_mov_reg_ptr_reg(LLCCEP_JIT::RBX, LLCCEP_JIT::RAX);
}

#define FPU_BIOP_ARITHMETICS(data, function) \
({ \
	getImmediate(LLCCEP_JIT::RAX, data.args[1]); \
	getImmediate(LLCCEP_JIT::RBX, data.args[2]); \
 \
	emit_push_reg(LLCCEP_JIT::RBX); \
	emit_push_reg(LLCCEP_JIT::RAX); \
 \
	emit_fld(LLCCEP_JIT::RSP); \
	emit_pop_reg(LLCCEP_JIT::RAX); \
	emit_fld(LLCCEP_JIT::RSP); \
	emit_pop_reg(LLCCEP_JIT::RBX); \
	function; \
 \
	getPointer(LLCCEP_JIT::RCX, data.args[0]); \
	emit_fstp_reg_ptr(LLCCEP_JIT::RCX); \
	emit_pop_reg(LLCCEP_JIT::RAX); \
});

void LLCCEP_JIT::codegenBackend::genAdd(LLCCEP_exec::instruction data)
{
	FPU_BIOP_ARITHMETICS(data, emit_fadd())
}

void LLCCEP_JIT::codegenBackend::genSub(LLCCEP_exec::instruction data)
{
	FPU_BIOP_ARITHMETICS(data, emit_fsub())
}

void LLCCEP_JIT::codegenBackend::genMul(LLCCEP_exec::instruction data)
{
	FPU_BIOP_ARITHMETICS(data, emit_fmul())
}

void LLCCEP_JIT::codegenBackend::genDiv(LLCCEP_exec::instruction data)
{
	FPU_BIOP_ARITHMETICS(data, emit_fdiv())
}

#undef FPU_BIOP_ARITHMETICS

#define FPU_UNIOP_ARITHMETICS(data, function) \
({ \
	getImmediate(LLCCEP_JIT::RAX, data.args[1]); \
	emit_push_reg(LLCCEP_JIT::RAX); \
 \
	emit_fld(LLCCEP_JIT::RSP); \
	emit_pop_reg(LLCCEP_JIT::RAX); \
	function; \
 \
	getPointer(LLCCEP_JIT::RBX, data.args[0]); \
	emit_fstp_reg_ptr(LLCCEP_JIT::RBX); \
	emit_pop_reg(LLCCEP_JIT::RAX); \
});

#define LOAD_AND_CAST(target, arg) \
({ \
	emit_push_reg(LLCCEP_JIT::RDX);\
 \
	getImmediate(target, data.args[1]); \
	emit_cvtsd2si(LLCCEP_JIT::RDX, target); \
	emit_mov_reg_reg(target, LLCCEP_JIT::RDX); \
 \
	emit_pop_reg(LLCCEP_JIT::RDX); \
});

void LLCCEP_JIT::codegenBackend::genAnd(LLCCEP_exec::instruction data)
{
	getPointer(LLCCEP_JIT::RCX, data.args[0]);

	LOAD_AND_CAST(LLCCEP_JIT::RAX, data.args[1])
	LOAD_AND_CAST(LLCCEP_JIT::RBX, data.args[2])

	emit_and_reg_reg(LLCCEP_JIT::RAX, LLCCEP_JIT::RBX);
}

void LLCCEP_JIT::codegenBackend::genOr(LLCCEP_exec::instruction data)
{
	getPointer(LLCCEP_JIT::RCX, data.args[0]);

	LOAD_AND_CAST(LLCCEP_JIT::RAX, data.args[1])
	LOAD_AND_CAST(LLCCEP_JIT::RBX, data.args[2])

	emit_mov_reg_reg_ptr(LLCCEP_JIT::RBX, LLCCEP_JIT::RCX);
	emit_or_reg_ptr_reg(LLCCEP_JIT::RCX, LLCCEP_JIT::RBX);
}

void LLCCEP_JIT::codegenBackend::genXor(LLCCEP_exec::instruction data)
{
	getPointer(LLCCEP_JIT::RCX, data.args[0]);

	LOAD_AND_CAST(LLCCEP_JIT::RAX, data.args[1])
	LOAD_AND_CAST(LLCCEP_JIT::RBX, data.args[2])

	emit_mov_reg_reg_ptr(LLCCEP_JIT::RBX, LLCCEP_JIT::RCX);
	emit_xor_reg_ptr_reg(LLCCEP_JIT::RCX, LLCCEP_JIT::RBX);
}

void LLCCEP_JIT::codegenBackend::genOff(LLCCEP_exec::instruction data)
{
	getPointer(LLCCEP_JIT::RCX, data.args[0]);

	LOAD_AND_CAST(LLCCEP_JIT::RAX, data.args[1])
	LOAD_AND_CAST(LLCCEP_JIT::RBX, data.args[2])

	emit_mov_reg_imm(LLCCEP_JIT::RDX, 0);
	emit_cmp_reg_ptr_reg(LLCCEP_JIT::RCX, LLCCEP_JIT::RBX);
}

void LLCCEP_JIT::codegenBackend::genNop(LLCCEP_exec::instruction data);
void LLCCEP_JIT::codegenBackend::genSwi(LLCCEP_exec::instruction data);
void LLCCEP_JIT::codegenBackend::genCmp(LLCCEP_exec::instruction data);
void LLCCEP_JIT::codegenBackend::genInc(LLCCEP_exec::instruction data);
void LLCCEP_JIT::codegenBackend::genDec(LLCCEP_exec::instruction data);
void LLCCEP_JIT::codegenBackend::genSqrt(LLCCEP_exec::instruction data);
void LLCCEP_JIT::codegenBackend::genSin(LLCCEP_exec::instruction data);
void LLCCEP_JIT::codegenBackend::genCos(LLCCEP_exec::instruction data);
void LLCCEP_JIT::codegenBackend::genPtan(LLCCEP_exec::instruction data);
void LLCCEP_JIT::codegenBackend::genPatan(LLCCEP_exec::instruction data);
void LLCCEP_JIT::codegenBackend::genLdc(LLCCEP_exec::instruction data);
void LLCCEP_JIT::codegenBackend::genCall(LLCCEP_exec::instruction data);
void LLCCEP_JIT::codegenBackend::genJmp(LLCCEP_exec::instruction data);
void LLCCEP_JIT::codegenBackend::genRet(LLCCEP_exec::instruction data);
