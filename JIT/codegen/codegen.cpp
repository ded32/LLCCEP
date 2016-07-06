#include "codegen.hpp"
#include "../rex/rex.hpp"
#include "../runtime/runtime.hpp"

#define EMIT_CONDITION_CHECK(data, size_b) \
({\
	backend.emit_mov_reg_imm(LLCCEP_JIT::RAX, data.cond); /*RAX := condition*/\
	backend.get_cmp(LLCCEP_JIT::RBX));                    /*RBX := compare flag*/\
	backend.emit_and(LLCCEP_JIT::RAX, LLCCEP_JIT::RBX);   /*Look for matching bits*/\
	backend.emit_mov(LLCCEP_JIT::RBX, 0);\
	backend.emit_cmp(LLCCEP_JIT::RAX, LLCCEP_JIT::RBX);\
	backend.emit_je(size_b);                              /*If there are no, skip function*/\
});

static inline void __gen_read_nums(LLCCEP_JIT:::codegen_backend &backend, instruction data, int num)
{
	for (int i = 0; i < num; i++) {
		backend.get_imm(LLCCEP_JIT::RAX, data.args[i + 1]);
		backend.emit_push(LLCCEP_JIT::RAX);
		backend.emit_fld(LLCCEP_JIT::RSP);
		backend.emit_pop_reg(LLCCEP_JIT::RAX);
	}
}

void gen_mov(LLCCEP_JIT::codegen_backend &backend, instruction data)
{
	EMIT_CONDITION_CHECK(data, 0/*TODO: insert size in bytes*/)

	backend.get_ptr(LLCCEP_JIT::RAX, data.args[0]);
	backend.get_imm(LLCCEP_JIT::RBX, data.args[1]);
	backend.emit_mov_reg_ptr_reg(LLCCEP_JIT::RAX,
				     LLCCEP_JIT::RBX);

	/* TODO: insert here code, for the jumps by mov into r14 */
}

void gen_mva(LLCCEP_JIT::codegen_backend &backend, instruction data)
{
	EMIT_CONDITION_CHECK(data, 0/*TODO: insert size in bytes*/)

	backend.get_mem_addr(LLCCEP_JIT::RAX, data.args[0]);
	backend.get_imm(LLCCEP_JIT::RBX, data.args[1]);
	backend.emit_mov_reg_ptr_reg(LLCCEP_JIT::RAX,
				     LLCCEP_JIT::RBX);
}

void gen_push(LLCCEP_JIT::codegen_backend &backend, instruction data)
{	
	EMIT_CONDITION_CHECK(data, 0/*TODO: insert size in bytes*/)

	backend.get_imm(LLCCEP_JIT::RAX, data.args[0]);
	backend.emit_push_reg(LLCCEP_JIT::RAX);
	backend.emit_fld();
}

void gen_pop(LLCCEP_JIT::codegen_backend &backend, instruction data)
{
	EMIT_CONDITION_CHECK(data, 1/*TODO: insert size in bytes*/)

	backend.emit_pop_reg(LLCCEP_JIT::RDX);
}

void gen_top(LLCCEP_JIT::codegen_backend &backend, instruction data)
{
	EMIT_CONDITION_CHECK(data, 0/*TODO: insert size in bytes*/)

	backend.emit_mov_reg_reg_ptr(LLCCEP_JIT::RAX, LLCCEP_JIT::RSP);
	backend.get_ptr(LLCCEP_JIT::RBX, data.args[0]);
	backend.emit_mov_reg_ptr_reg(LLCCEP_JIT::RBX, LLCCEP_JIT::RAX);
}

void gen_add(LLCCEP_JIT::codegen_backend &backend, instruction data)
{
	EMIT_CONDITION_CHECK(data, 0/*TODO: insert size in bytes*/)

	__gen_read_nums(backend, data, 2);
	backend.emit_fadd();
	backend.get_ptr(LLCCEP_JIT::RAX, data.args[0]);
	backend.emit_fstp_reg_ptr(LLCCEP_JIT::RAX);
}

void gen_sub(LLCCEP_JIT::codegen_backend &backend, instruction data)
{
	EMIT_CONDITION_CHECK(data, 0/*TODO: insert size in bytes*/)

	__gen_read_nums(backend, data, 2);
	backend.emit_fsub();
	backend.get_ptr(LLCCEP_JIT::RAX, data.args[0]);
	backend.emit_fstp_reg_ptr(LLCCEP_JIT::RAX);
}

void gen_mul(LLCCEP_JIT::codegen_backend &backend, instruction data)
{
	EMIT_CONDITION_CHECK(data, 0/*TODO: insert size in bytes*/)

	__gen_read_nums(backend, data, 2);
	backend.emit_fmul();
	backend.get_ptr(LLCCEP_JIT::RAX, data.args[0]);
	backend.emit_fstp_reg_ptr(LLCCEP_JIT::RAX);
}

void gen_div(LLCCEP_JIT::codegen_backend &backend, instruction data)
{
	EMIT_CONDITION_CHECK(data, 0/*TODO: insert size in bytes*/)

	__gen_read_nums(backend, data, 2);
	backend.emit_fdiv();
	backend.get_ptr(LLCCEP_JIT::RAX, data.args[0]);
	backend.emit_fstp_reg_ptr(LLCCEP_JIT::RAX);
}

void gen_and(LLCCEP_JIT::codegen_backend &backend, instruction data)
{
	EMIT_CONDITION_CHECK(data, 0/*TODO: insert size in bytes*/)

	backend.get_ptr(LLCCEP_JIT::RAX, data.args[1]);
	backend.get_ptr(LLCCEP_JIT::RBX, data.args[2]);

	backend.emit_cvtsd2si(LLCCEP_JIT::RCX, LLCCEP_JIT::RAX);
	backend.emit_cvtsd2si(LLCCEP_JIT::RDX, LLCCEP_JIT::RBX);

	backend.emit_and(LLCCEP_JIT::RCX, LLCCEP_JIT::RDX);
	backend.get_ptr(LLCCEP_JIT::RBX, data.args[0]);
	backend.emit_mov_reg_ptr_reg(LLCCEP_JIT::RBX, LLCCEP_JIT::RCX);
}

void gen_or(LLCCEP_JIT::codegen_backend &backend, instruction data)
{
	EMIT_CONDITION_CHECK(data, 0/*TODO: insert size in bytes*/)

	backend.get_ptr(LLCCEP_JIT::RAX, data.args[1]);
	backend.get_ptr(LLCCEP_JIT::RBX, data.args[2]);

	backend.emit_cvtsd2si(LLCCEP_JIT::RCX, LLCCEP_JIT::RAX);
	backend.emit_cvtsd2si(LLCCEP_JIT::RDX, LLCCEP_JIT::RBX);

	backend.emit_or(LLCCEP_JIT::RCX, LLCCEP_JIT::RDX);
	backend.get_ptr(LLCCEP_JIT::RBX, data.args[0]);
	backend.emit_mov_reg_ptr_reg(LLCCEP_JIT::RBX, LLCCEP_JIT::RCX);
}

void gen_xor(LLCCEP_JIT::codegen_backend &backend, instruction data)
{
	EMIT_CONDITION_CHECK(data, 0/*TODO: insert size in bytes*/)

	backend.get_ptr(LLCCEP_JIT::RAX, data.args[1]);
	backend.get_ptr(LLCCEP_JIT::RBX, data.args[2]);

	backend.emit_cvtsd2si(LLCCEP_JIT::RCX, LLCCEP_JIT::RAX);
	backend.emit_cvtsd2si(LLCCEP_JIT::RDX, LLCCEP_JIT::RBX);

	backend.emit_xor(LLCCEP_JIT::RCX, LLCCEP_JIT::RDX);
	backend.get_ptr(LLCCEP_JIT::RBX, data.args[0]);
	backend.emit_mov_reg_ptr_reg(LLCCEP_JIT::RBX, LLCCEP_JIT::RCX);
}

void gen_off(LLCCEP_JIT::codegen_backend &backend, instruction data)
{
	EMIT_CONDITION_CHECK(data, 0/*TODO: insert size in bytes*/)
	
	backend.get_imm(LLCCEP_JIT::RAX, data.args[2]);
	backend.emit_mov(LLCCEP_JIT::RBX, 0);
	backend.emit_cmp(LLCCEP_JIT::RAX, LLCCEP_JIT::RBX);
	backend.emit_jl(/*TODO: insert size of right offset function*/);

	// Right offset
	backend.emit_mov(LLCCEP_JIT::RCX, LLCCEP_JIT::RAX);
	backend.get_imm(LLCCEP_JIT::RAX, data.args[1]);
	backend.emit_shr_cl(LLCCEP_JIT::RAX);
	backend.emit_jmp(/*TODO: insert size of left offset function*/);

	// Left offset
	backend.emit_mov(LLCCEP_JIT::RCX, LLCCEP_JIT::RAX);
	backend.get_imm(LLCCEP_JIT::RAX, data.args[1]);
	backend.emit_shr_cl(LLCCEP_JIT::RAX);
}

void gen_nop(LLCCEP_JIT::codegen_backend &backend, instruction data)
{
	EMIT_CONDITION_CHECK(data, 1)

	backend.emit_nop();
}

void gen_swi(LLCCEP_JIT::codegen_backend &backend, instruction data)
{
	EMIT_CONDITION_CHECK(data, 0/*TODO: insert size in bytes*/)

	// runtime
}

void gen_cmp(LLCCEP_JIT::codegen_backend &backend, instruction data)
{
	EMIT_CONDITION_CHECK(data, 0/*TODO: insert size in bytes*/)

	// TODO: insert cmp code from first test
}

void gen_inc(LLCCEP_JIT::codegen_backend &backend, instruction data)
{
	EMIT_CONDITION_CHECK(data, 0/*TODO: insert size in bytes*/)

	data.args[1] = { 
		.type = ARG_T_VAL,
		.val = 1
	};

	gen_add(backend, data);
}

void gen_dec(LLCCEP_JIT::codegen_backend &backend, instruction data)
{
	EMIT_CONDITION_CHECK(data, 0/*TODO: insert size in bytes*/)

	data.args[1] = {
		.type = ARG_T_VAL,
		.val = 1
	};

	gen_sub(backend, data);
}

#define GEN_FPU_MATH(inst_name) \
({\
	instruction copy = data;\
	copy.args[0] = copy.args[1];\
	\
	gen_push(backend, copy);\
	backend.emit_ ##inst_name();\
	gen_pop(backend, data);\
})

void gen_sqrt(LLCCEP_JIT::codegen_backend &backend, instruction data)
{
	GEN_FPU_MATH(fsqrt);
}

void gen_sin(LLCCEP_JIT::codegen_backend &backend, instruction data)
{
	GEN_FPU_MATH(fsin);
}

void gen_cos(LLCCEP_JIT::codegen_backend &backend, instruction data)
{
	GEN_FPU_MATH(fcos);
}

void gen_ptan(LLCCEP_JIT::codegen_backend &backend, instruction data)
{
	GEN_FPU_MATH(fptan);
}

void gen_patan(LLCCEP_JIT::codegen_backend &backend, instruction data)
{
	GEN_FPU_MATH(fpatan);
}

void gen_ldc(LLCCEP_JIT::codegen_backend &backend, instruction data)
{
	backend.get_ptr(LLCCEP_JIT::RAX, data.args[0]); // RAX is ptr to res
	backend.get_imm(LLCCEP_JIT::RBX, data.args[1]);
	backend.emit_fld_const_reg(LLCCEP_JIT::RBX);
	backend.emit_fst_reg_ptr(LLCCEP_JIT::RAX);
}

#undef GEN_FPU_MATH

void gen_outp(LLCCEP_JIT::codegen_backend &backend, instruction data)
{ }

void gen_inp(LLCCEP_JIT::codegen_backend &backend, instruction data)
{ }

static auto __codegen_functions[] = {
	gen_mov,
	gen_mva,
	gen_push,
	gen_pop,
	gen_top,
	gen_add,
	gen_sub,
	gen_mul,
	gen_div,
	gen_and,
	gen_or,
	gen_xor,
	gen_off,
	gen_nop,
	gen_swi,
	gen_cmp,
	gen_inc,
	gen_dec,
	gen_sqrt,
	gen_sin,
	gen_cos,
	gen_ptan,
	gen_patan,
	gen_ldc,
	gen_outp,
	gen_inp
};

namespace LLCCEP_JIT {
	void codegen_backend::get_cmp(regID reg)
	{
		emit_mov_reg_imm(reg, &cmp);
		emit_mov_reg_reg_ptr(reg, reg);
	}

	void codegen_backend::get_imm(regID reg, arg data)
	{
		
	}
}
