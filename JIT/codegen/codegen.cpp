#include <STDExtras.hpp>

#include "../runtime/runtime.hpp"
#include "../program/program.hpp"
#include "../../exec/program/program.hpp"

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
	(void)data;
	emit_pop_reg(LLCCEP_JIT::RAX);
}

void LLCCEP_JIT::codegenBackend::genTop(LLCCEP_exec::instruction data)
{
	getPointer(LLCCEP_JIT::RAX, data.args[0]);

	emit_pop_reg(LLCCEP_JIT::RBX);
	emit_push_reg(LLCCEP_JIT::RBX);

	emit_mov_reg_ptr_reg(LLCCEP_JIT::RBX, LLCCEP_JIT::RAX);
}

#define FPU_BIOP_ARITHMETICS(data, op) \
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
	emit_f##op(); \
 \
	getPointer(LLCCEP_JIT::RCX, data.args[0]); \
	emit_fstp_reg_ptr(LLCCEP_JIT::RCX); \
});

void LLCCEP_JIT::codegenBackend::genAdd(LLCCEP_exec::instruction data)
{
	FPU_BIOP_ARITHMETICS(data, add)
}

void LLCCEP_JIT::codegenBackend::genSub(LLCCEP_exec::instruction data)
{
	FPU_BIOP_ARITHMETICS(data, sub)
}

void LLCCEP_JIT::codegenBackend::genMul(LLCCEP_exec::instruction data)
{
	FPU_BIOP_ARITHMETICS(data, mul)
}

void LLCCEP_JIT::codegenBackend::genDiv(LLCCEP_exec::instruction data)
{
	FPU_BIOP_ARITHMETICS(data, div)
}

#undef FPU_BIOP_ARITHMETICS

#define CAST(target, arg) \
({ \
	emit_push_reg(LLCCEP_JIT::RDX); \
 \
	getImmediate(LLCCEP_JIT::RDX, arg); \
	emit_push_reg(LLCCEP_JIT::RDX); \
	emit_fld(LLCCEP_JIT::RSP); \
	emit_fistp(target); \
	\
	emit_pop_reg(LLCCEP_JIT::RDX); \
});

#define LOGIC(data, name) \
({ \
	getPointer(LLCCEP_JIT::RCX, data.args[0]); \
 \
	CAST(LLCCEP_JIT::RAX, data.args[1]) \
	CAST(LLCCEP_JIT::RBX, data.args[2]) \
 \
	emit_##name##_reg_reg(LLCCEP_JIT::RAX, LLCCEP_JIT::RBX); \
	emit_mov_reg_ptr_reg(LLCCEP_JIT::RAX, LLCCEP_JIT::RCX); \
});


void LLCCEP_JIT::codegenBackend::genAnd(LLCCEP_exec::instruction data)
{
	LOGIC(data, and)
}

void LLCCEP_JIT::codegenBackend::genOr(LLCCEP_exec::instruction data)
{
	LOGIC(data, and)
}

void LLCCEP_JIT::codegenBackend::genXor(LLCCEP_exec::instruction data)
{
	LOGIC(data, and)
}

#undef LOGIC

void LLCCEP_JIT::codegenBackend::genOff(LLCCEP_exec::instruction data)
{
	getPointer(LLCCEP_JIT::RCX, data.args[0]);

	CAST(LLCCEP_JIT::RAX, data.args[1])
	CAST(LLCCEP_JIT::RBX, data.args[2])
}

void LLCCEP_JIT::codegenBackend::genNop(LLCCEP_exec::instruction data)
{
	(void)data;
	// Do nothing, to increase speed...
}

void LLCCEP_JIT::codegenBackend::genSwi(LLCCEP_exec::instruction data)
{
	for (size_t i = 0; i < sizeof(data) / 8; i++) {
		long long unsigned v_push = (reinterpret_cast<long long unsigned *>(&data))[i];
		emit_push_imm(v_push);
	}

	void *ptr = _runtimeManager->getSwiEmulatePtr();
	emit_mov_reg_imm(LLCCEP_JIT::RAX, reinterpret_cast<uint64_t>(ptr));
	emit_call_reg(LLCCEP_JIT::RAX);
}

void LLCCEP_JIT::codegenBackend::genCmp(LLCCEP_exec::instruction data)
{
	(void)data;
}

#define INCDEC(data, op) \
({ \
	getPointer(LLCCEP_JIT::RAX, data.args[0]); \
	emit_mov_reg_reg_ptr(LLCCEP_JIT::RAX, LLCCEP_JIT::RBX); \
	emit_##op##_reg(LLCCEP_JIT::RBX); \
	emit_mov_reg_ptr_reg(LLCCEP_JIT::RBX, LLCCEP_JIT::RAX); \
});

void LLCCEP_JIT::codegenBackend::genInc(LLCCEP_exec::instruction data)
{
//	INCDEC(data, inc)
}

void LLCCEP_JIT::codegenBackend::genDec(LLCCEP_exec::instruction data)
{
//	INCDEC(data, inc)
}

#undef INCDEC

#define FPU_UNIOP_MATH(data, op) \
({ \
	getImmediate(LLCCEP_JIT::RAX, data.args[1]); \
	emit_push_reg(LLCCEP_JIT::RAX); \
 \
	emit_fld(LLCCEP_JIT::RSP); \
	emit_pop_reg(LLCCEP_JIT::RAX); \
	emit_f##op(); \
 \
	getPointer(LLCCEP_JIT::RCX, data.args[0]); \
	emit_fstp_reg_ptr(LLCCEP_JIT::RCX); \
});

void LLCCEP_JIT::codegenBackend::genSqrt(LLCCEP_exec::instruction data)
{
	FPU_UNIOP_MATH(data, sqrt)
}

void LLCCEP_JIT::codegenBackend::genSin(LLCCEP_exec::instruction data)
{
	FPU_UNIOP_MATH(data, sin)
}

void LLCCEP_JIT::codegenBackend::genCos(LLCCEP_exec::instruction data)
{
	FPU_UNIOP_MATH(data, cos)
}

void LLCCEP_JIT::codegenBackend::genPtan(LLCCEP_exec::instruction data)
{
	FPU_UNIOP_MATH(data, ptan)
}

void LLCCEP_JIT::codegenBackend::genPatan(LLCCEP_exec::instruction data)
{
	FPU_UNIOP_MATH(data, patan)
}

#undef FPU_UNIOP_MATH

void LLCCEP_JIT::codegenBackend::genLdc(LLCCEP_exec::instruction data)
{
	getImmediate(LLCCEP_JIT::RAX, data.args[1]);
	getPointer(LLCCEP_JIT::RBX, data.args[0]);

	emit_mov_reg_ptr_reg(LLCCEP_JIT::RAX, LLCCEP_JIT::RBX);
}

void LLCCEP_JIT::codegenBackend::genCall(LLCCEP_exec::instruction data)
{
	/* TODO:
	 * By call to reg
	 */
}

void LLCCEP_JIT::codegenBackend::genJmp(LLCCEP_exec::instruction data)
{
	/* TODO:
	 * By jmp to reg
	 */
}

void LLCCEP_JIT::codegenBackend::genRet(LLCCEP_exec::instruction data)
{
	(void)data;
	emit_ret();
}

void LLCCEP_JIT::codegenBackend::getImmediate(regID reg, LLCCEP_exec::arg data)
{
	auto getTmpRegister = [reg] {
		return (reg == LLCCEP_JIT::RAX)?(LLCCEP_JIT::RBX):(LLCCEP_JIT::RAX);
	};

	switch (data.type) {
	case LLCCEP_exec::ARG_T_REG: {
		if (static_cast<size_t>(data.val) > 32) {
			throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
				"Error!\n"
				"Overbounding while reading from register"))
		}

		void *ptr = _runtimeManager->getRegPtr(static_cast<size_t>(data.val));
		regID tmp = getTmpRegister();

		emit_push_reg(tmp);

		emit_mov_reg_imm(tmp, reinterpret_cast<uint64_t>(ptr));
		emit_mov_reg_reg_ptr(tmp, reg);

		emit_pop_reg(tmp);
		break;
	}

	case LLCCEP_exec::ARG_T_MEM: {
		regID tmp = getTmpRegister();
		emit_push_reg(tmp);

		void *mem = reinterpret_cast<void *>(
				    reinterpret_cast<uint64_t>(_runtimeManager->getMemoryBeginning()) +
				    static_cast<uint64_t>(static_cast<size_t>(data.val) *
							       sizeof(double)));

		emit_mov_reg_imm(tmp, reinterpret_cast<uint64_t>(mem));
		emit_mov_reg_reg_ptr(tmp, reg);

		emit_pop_reg(tmp);
		break;
	}

	case LLCCEP_exec::ARG_T_VAL: {
		uint64_t val = *reinterpret_cast<uint64_t *>(&data.val);
		emit_mov_reg_imm(reg, val); // copy the bits, not the casted value
		break;
	}

	default: {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Error!\n"
			"Invalid reading of immediate data!\n"))
	}
	}
}

void LLCCEP_JIT::codegenBackend::getPointer(regID reg, LLCCEP_exec::arg data)
{
	switch (data.type) {
	case LLCCEP_exec::ARG_T_REG: {
		if (static_cast<size_t>(data.val) > 32) {
			throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
				"Error!\n"
				"Overbounding while reading from register"))
		}

		void *ptr = _runtimeManager->getRegPtr(static_cast<size_t>(data.val));
		emit_mov_reg_imm(reg, reinterpret_cast<uint64_t>(ptr));

		break;
	}

	case LLCCEP_exec::ARG_T_MEM: {
		void *mem = reinterpret_cast<void *>(
				    reinterpret_cast<uint64_t>(_runtimeManager->getMemoryBeginning()) +
				    static_cast<uint64_t>(static_cast<size_t>(data.val) *
							  sizeof(double)));
		emit_mov_reg_imm(reg, reinterpret_cast<uint64_t>(mem));

		break;
	}

	default: {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Error!\n"
			"Invalid reading of pointer data!\n"))
	}
	}
}
