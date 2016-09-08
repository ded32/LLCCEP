#include <utility>

#include <STDExtras.hpp>
#include <os-specific.hpp>
#include <convert.hpp>

#include "./../runtime/runtime.hpp"
#include "./../program/program.hpp"
#include "./../../exec/codeReader/codeReader.hpp"

#include "codegen.hpp"

#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunused-parameter"
#elif defined(__GNUC__)
#pragma GCC diagnostic ignored "-Wunused-parameter"
#endif

#define CODEGEN_BACKEND_OK DEFAULT_CHECK_BLOCK(this, ok(), true)

LLCCEP_JIT::codegenBackend::codegenBackend():
	globalRuntimeManager(),
	instructionPos()
{ }

void LLCCEP_JIT::codegenBackend::setRuntimeManager(LLCCEP_JIT::runtimeManager *newRuntimeManager)
{
	globalRuntimeManager = newRuntimeManager;

	CODEGEN_BACKEND_OK
}

size_t LLCCEP_JIT::codegenBackend::getInstructionPos(size_t id)
{
	CODEGEN_BACKEND_OK

	if (id >= instructionPos.size()) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"No instruction with " size_t_pf "id",
			id))
	}

	return instructionPos[id];

	CODEGEN_BACKEND_OK
}

void LLCCEP_JIT::codegenBackend::generateProgram()
{
	CODEGEN_BACKEND_OK

	LLCCEP_exec::instruction inst{};
	bool pass = true;

	do {
		if (!pass)
			generateMachineCode(inst);
		else
			pass = false;

		inst = globalRuntimeManager->getCodeReader()->getInstruction(instructionPos.size());
	} while (inst.opcode != INT8_MAX);

	CODEGEN_BACKEND_OK
}

void LLCCEP_JIT::codegenBackend::generateMachineCode(LLCCEP_exec::instruction data)
{
	CODEGEN_BACKEND_OK

	void (LLCCEP_JIT::codegenBackend:: *functions[])(LLCCEP_exec::instruction) = {
		&LLCCEP_JIT::codegenBackend::genMov,
		&LLCCEP_JIT::codegenBackend::genMva,
		&LLCCEP_JIT::codegenBackend::genPush,
		&LLCCEP_JIT::codegenBackend::genPop,
		&LLCCEP_JIT::codegenBackend::genTop,
		&LLCCEP_JIT::codegenBackend::genAdd,
		&LLCCEP_JIT::codegenBackend::genSub,
		&LLCCEP_JIT::codegenBackend::genMul,
		&LLCCEP_JIT::codegenBackend::genDiv,
		&LLCCEP_JIT::codegenBackend::genAnd,
		&LLCCEP_JIT::codegenBackend::genOr,
		&LLCCEP_JIT::codegenBackend::genXor,
		&LLCCEP_JIT::codegenBackend::genOff,
		&LLCCEP_JIT::codegenBackend::genNop,
		&LLCCEP_JIT::codegenBackend::genSwi,
		&LLCCEP_JIT::codegenBackend::genCmp,
		&LLCCEP_JIT::codegenBackend::genInc,
		&LLCCEP_JIT::codegenBackend::genDec,
		&LLCCEP_JIT::codegenBackend::genSqrt,
		&LLCCEP_JIT::codegenBackend::genSin,
		&LLCCEP_JIT::codegenBackend::genCos,
		&LLCCEP_JIT::codegenBackend::genPtan,
		&LLCCEP_JIT::codegenBackend::genPatan,
		&LLCCEP_JIT::codegenBackend::genLdc,
		&LLCCEP_JIT::codegenBackend::genCall,
		&LLCCEP_JIT::codegenBackend::genJmp,
		&LLCCEP_JIT::codegenBackend::genRet,
		&LLCCEP_JIT::codegenBackend::genStregs,
		&LLCCEP_JIT::codegenBackend::genLdregs
	};

	size_t old = size();                    // save old code size
	(this->*functions[data.opcode])(data);  // generate code
	instructionPos.push_back(size() - old); // new instruction size is difference

	CODEGEN_BACKEND_OK
}

void LLCCEP_JIT::codegenBackend::genMov(LLCCEP_exec::instruction data)
{
	CODEGEN_BACKEND_OK

	getImmediate(LLCCEP_JIT::RAX, data.args[1]);
	getPointer(LLCCEP_JIT::RBX, data.args[0]);

	emit_mov_reg_ptr_reg(LLCCEP_JIT::RBX, LLCCEP_JIT::RAX);

	CODEGEN_BACKEND_OK
}

void LLCCEP_JIT::codegenBackend::genMva(LLCCEP_exec::instruction data)
{
	CODEGEN_BACKEND_OK

	getImmediate(LLCCEP_JIT::RAX, data.args[1]);
	getMemPtrFromImmediate(LLCCEP_JIT::RBX, data.args[0]);

	emit_mov_reg_ptr_reg(LLCCEP_JIT::RBX, LLCCEP_JIT::RAX);

	CODEGEN_BACKEND_OK
}

void LLCCEP_JIT::codegenBackend::genPush(LLCCEP_exec::instruction data)
{
	CODEGEN_BACKEND_OK

	getImmediate(LLCCEP_JIT::RAX, data.args[0]);
	emit_push_reg(LLCCEP_JIT::RAX);

	CODEGEN_BACKEND_OK
}

void LLCCEP_JIT::codegenBackend::genPop(LLCCEP_exec::instruction data)
{
	CODEGEN_BACKEND_OK

	emit_pop_reg(LLCCEP_JIT::RAX);

	CODEGEN_BACKEND_OK
}

void LLCCEP_JIT::codegenBackend::genTop(LLCCEP_exec::instruction data)
{
	CODEGEN_BACKEND_OK

	getPointer(LLCCEP_JIT::RAX, data.args[0]);

	emit_pop_reg(LLCCEP_JIT::RBX);
	emit_push_reg(LLCCEP_JIT::RBX);
	emit_mov_reg_ptr_reg(LLCCEP_JIT::RAX, LLCCEP_JIT::RBX);

	CODEGEN_BACKEND_OK
}

#define FPU_BIOP_ARITHMETICS(data, op) \
({ \
	CODEGEN_BACKEND_OK \
 \
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
 \
	CODEGEN_BACKEND_OK \
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
	CODEGEN_BACKEND_OK \
 \
	emit_push_reg(LLCCEP_JIT::RDX); \
 \
	getImmediate(LLCCEP_JIT::RDX, arg); \
	emit_push_reg(LLCCEP_JIT::RDX); \
	emit_fld(LLCCEP_JIT::RSP); \
	emit_fistp(target); \
	\
	emit_pop_reg(LLCCEP_JIT::RDX); \
 \
	CODEGEN_BACKEND_OK \
});

#define LOGIC(data, name) \
({ \
	CODEGEN_BACKEND_OK \
 \
	getPointer(LLCCEP_JIT::RCX, data.args[0]); \
 \
	CAST(LLCCEP_JIT::RAX, data.args[1]) \
	CAST(LLCCEP_JIT::RBX, data.args[2]) \
 \
	emit_##name##_reg_reg(LLCCEP_JIT::RAX, LLCCEP_JIT::RBX); \
	emit_mov_reg_ptr_reg(LLCCEP_JIT::RAX, LLCCEP_JIT::RCX); \
 \
	CODEGEN_BACKEND_OK \
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
	CODEGEN_BACKEND_OK
}

void LLCCEP_JIT::codegenBackend::genSwi(LLCCEP_exec::instruction data)
{
	CODEGEN_BACKEND_OK

	genRuntimeFallback(globalRuntimeManager->getSwiEmulatePtr(), data);

	CODEGEN_BACKEND_OK
}

void LLCCEP_JIT::codegenBackend::genCmp(LLCCEP_exec::instruction data)
{
	CODEGEN_BACKEND_OK
}

#define INCDEC(data, op) \
({ \
	CODEGEN_BACKEND_OK \
 \
	getImmediate(LLCCEP_JIT::RAX, data.args[0]); \
	emit_push_reg(LLCCEP_JIT::RAX); \
 \
	emit_fld(LLCCEP_JIT::RSP); \
	emit_pop_reg(LLCCEP_JIT::RAX); \
	emit_f##op##stp(); \
 \
	getPointer(LLCCEP_JIT::RAX, data.args[0]); \
	emit_fstp_reg_ptr(LLCCEP_JIT::RAX); \
 \
	CODEGEN_BACKEND_OK \
});

void LLCCEP_JIT::codegenBackend::genInc(LLCCEP_exec::instruction data)
{
	INCDEC(data, inc)
}

void LLCCEP_JIT::codegenBackend::genDec(LLCCEP_exec::instruction data)
{
	INCDEC(data, inc)
}

#undef INCDEC

#define FPU_UNIOP_MATH(data, op) \
({ \
	CODEGEN_BACKEND_OK \
 \
	getImmediate(LLCCEP_JIT::RAX, data.args[1]); \
	emit_push_reg(LLCCEP_JIT::RAX); \
 \
	emit_fld(LLCCEP_JIT::RSP); \
	emit_pop_reg(LLCCEP_JIT::RAX); \
	emit_f##op(); \
 \
	getPointer(LLCCEP_JIT::RCX, data.args[0]); \
	emit_fstp_reg_ptr(LLCCEP_JIT::RCX); \
 \
	CODEGEN_BACKEND_OK \
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
	CODEGEN_BACKEND_OK

	getPointer(LLCCEP_JIT::RBX, data.args[0]);
	emit_mov_reg_ptr_reg(LLCCEP_JIT::RAX, LLCCEP_JIT::RBX);

	CODEGEN_BACKEND_OK
}

void LLCCEP_JIT::codegenBackend::genCall(LLCCEP_exec::instruction data)
{
	CODEGEN_BACKEND_OK

	/* TODO:
	 * Implement this, using conditional calls due to data.args[0]
	 * value
	 */

	CODEGEN_BACKEND_OK
}

void LLCCEP_JIT::codegenBackend::genJmp(LLCCEP_exec::instruction data)
{
	CODEGEN_BACKEND_OK

	/* TODO:
	 * Implement this, using conditional jumps due to data.args[0]
	 * value
	 */

	CODEGEN_BACKEND_OK
}

void LLCCEP_JIT::codegenBackend::genRet(LLCCEP_exec::instruction data)
{
	CODEGEN_BACKEND_OK

	emit_ret();

	CODEGEN_BACKEND_OK
}

void LLCCEP_JIT::codegenBackend::genStregs(LLCCEP_exec::instruction data)
{
	CODEGEN_BACKEND_OK

	genRuntimeFallback(globalRuntimeManager->getStregsEmulatePtr(), data);

	CODEGEN_BACKEND_OK
}

void LLCCEP_JIT::codegenBackend::genLdregs(LLCCEP_exec::instruction data)
{
	CODEGEN_BACKEND_OK

	genRuntimeFallback(globalRuntimeManager->getLdregsEmulatePtr(), data);

	CODEGEN_BACKEND_OK
}

void LLCCEP_JIT::codegenBackend::getImmediate(regID reg, LLCCEP_exec::arg data)
{
	CODEGEN_BACKEND_OK

	auto getTmpRegister = [reg] {
		return (reg == LLCCEP_JIT::RAX)?(LLCCEP_JIT::RBX):(LLCCEP_JIT::RAX);
	};

	switch (data.type) {
	case LLCCEP_ASM::LEX_T_REG: {
		if (static_cast<size_t>(data.val) > 32) {
			throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
				"Error!\n"
				"Overbounding while reading from register"))
		}

		void *ptr = globalRuntimeManager->getRegPtr(static_cast<size_t>(data.val));
		regID tmp = getTmpRegister();

		emit_push_reg(tmp);

		emit_mov_reg_imm(tmp, reinterpret_cast<uint64_t>(ptr));
		emit_mov_reg_reg_ptr(tmp, reg);

		emit_pop_reg(tmp);
		break;
	}

	case LLCCEP_ASM::LEX_T_MEM: {
		regID tmp = getTmpRegister();
		emit_push_reg(tmp);

		void *mem = reinterpret_cast<void *>(
				    reinterpret_cast<uint64_t>(globalRuntimeManager->getMemoryBeginning()) +
				    static_cast<uint64_t>(static_cast<size_t>(data.val) *
							       sizeof(double)));

		emit_mov_reg_imm(tmp, reinterpret_cast<uint64_t>(mem));
		emit_mov_reg_reg_ptr(tmp, reg);

		emit_pop_reg(tmp);
		break;
	}

	case LLCCEP_ASM::LEX_T_VAL: {
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

	CODEGEN_BACKEND_OK
}

void LLCCEP_JIT::codegenBackend::getPointer(LLCCEP_JIT::regID reg, LLCCEP_exec::arg data)
{
	CODEGEN_BACKEND_OK

	switch (data.type) {
	case LLCCEP_ASM::LEX_T_REG: {
		if (static_cast<size_t>(data.val) > 32) {
			throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
				"Error!\n"
				"Overbounding while reading from register"))
		}

		void *ptr = globalRuntimeManager->getRegPtr(static_cast<size_t>(data.val));
		emit_mov_reg_imm(reg, reinterpret_cast<uint64_t>(ptr));

		break;
	}

	case LLCCEP_ASM::LEX_T_MEM: {
		uint64_t mem = reinterpret_cast<uint64_t>(globalRuntimeManager->getMemoryBeginning()) +
			       static_cast<uint64_t>(static_cast<size_t>(data.val) * sizeof(double));
		emit_mov_reg_imm(reg, mem);

		break;
	}

	default: {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Error!\n"
			"Invalid reading of pointer data!\n"))
	}
	}

	CODEGEN_BACKEND_OK
}

void LLCCEP_JIT::codegenBackend::getMemPtrFromImmediate(LLCCEP_JIT::regID reg, LLCCEP_exec::arg data)
{
	CODEGEN_BACKEND_OK

	switch (data.type) {
	case LLCCEP_ASM::LEX_T_VAL: {
		uint64_t tmpPtr = reinterpret_cast<uint64_t>(globalRuntimeManager->getMemoryBeginning()) +
				  static_cast<uint64_t>(static_cast<size_t>(data.val) * sizeof(double));
		emit_mov_reg_imm(reg, tmpPtr);

		break;
	}

	case LLCCEP_ASM::LEX_T_MEM: {
		void *tmpPtr = reinterpret_cast<void *>(reinterpret_cast<uint64_t>(globalRuntimeManager->getMemoryBeginning()) +
							 static_cast<uint64_t>(static_cast<size_t>(data.val) * sizeof(double)));
		emit_mov_reg_imm(reg, static_cast<uint64_t>(*reinterpret_cast<double *>(tmpPtr)));

		break;
	}

	case LLCCEP_ASM::LEX_T_REG: {
		void *regPtr = reinterpret_cast<void *>(reinterpret_cast<uint64_t>(globalRuntimeManager->getRegPtr(data.val)));
		emit_mov_reg_imm(reg, static_cast<uint64_t>(*reinterpret_cast<double *>(regPtr)));

		break;
	}

	default: {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Error!\n"
			"Invalid reading of pointer data!\n"))
	}
	}

	CODEGEN_BACKEND_OK
}

bool LLCCEP_JIT::codegenBackend::ok() const
{
	return globalRuntimeManager && globalRuntimeManager->OK();
}

void LLCCEP_JIT::codegenBackend::genRuntimeFallback(void *funcPtr, LLCCEP_exec::instruction data)
{
	CODEGEN_BACKEND_OK

#ifdef _MSC_VER
	emit_mov_reg_imm(LLCCEP_JIT::RCX, reinterpret_cast<uint64_t>(globalRuntimeManager->getSoftcorePtr()));
#else
	emit_mov_reg_imm(LLCCEP_JIT::RDI, reinterpret_cast<uint64_t>(globalRuntimeManager->getSoftcorePtr()));
#endif // save this

	for (int i = 0; i < 7; i++) {
		uint64_t imm = reinterpret_cast<uint64_t *>(&data)[6 - i];
		emit_mov_reg_imm(LLCCEP_JIT::RAX, imm);
		emit_push_reg(LLCCEP_JIT::RAX);
	}

	emit_mov_reg_imm(LLCCEP_JIT::RAX, reinterpret_cast<uint64_t>(funcPtr));
	emit_call_reg(LLCCEP_JIT::RAX);

	for (int i = 0; i < 7; i++)
		emit_pop_reg(LLCCEP_JIT::RAX);

	CODEGEN_BACKEND_OK
}

#undef CODEGEN_BACKEND_OK
