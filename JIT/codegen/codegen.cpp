#include "codegen.hpp"

static inline void __gen_read_nums(LLCCEP_JIT:::codegen_backend &backend, instruction data)
{
	for (int i = 0; i < 2; i++) {
		backend.get_imm(LLCCEP_JIT::RAX, data.args[i + 1]);
		backend.emit_push(LLCCEP_JIT::RAX);
		backend.emit_fld(LLCCEP_JIT::RSP);
		backend.emit_pop_reg(LLCCEP_JIT::RAX);
	}
}

void gen_mov(LLCCEP_JIT::codegen_backend &backend, instruction data)
{
	backend.get_ptr(LLCCEP_JIT::RAX, data.args[0]);
	backend.get_imm(LLCCEP_JIT::RBX, data.args[1]);
	backend.emit_mov_reg_ptr_reg(LLCCEP_JIT::RAX,
				     LLCCEP_JIT::RBX);
}

void gen_mva(LLCCEP_JIT::codegen_backend &backend, instruction data)
{
	backend.get_mem_addr(LLCCEP_JIT::RAX, data.args[0]);
	backend.get_imm(LLCCEP_JIT::RBX, data.args[1]);
	backend.emit_mov_reg_ptr_reg(LLCCEP_JIT::RAX,
				     LLCCEP_JIT::RBX);
}

void gen_push(LLCCEP_JIT::codegen_backend &backend, instruction data)
{
	backend.get_imm(LLCCEP_JIT::RAX, data.args[0]);
	backend.emit_push_reg(LLCCEP_JIT::RAX);
	backend.emit_fld();
}

void gen_pop(LLCCEP_JIT::codegen_backend &backend, instruction data)
{
	backend.emit_pop_reg(LLCCEP_JIT::RDX);
}

void gen_top(LLCCEP_JIT::codegen_backend &backend, instruction data)
{
	backend.emit_mov_reg_reg_ptr(LLCCEP_JIT::RAX, LLCCEP_JIT::RSP);
	backend.get_ptr(LLCCEP_JIT::RBX, data.args[0]);
	backend.emit_mov_reg_ptr_reg(LLCCEP_JIT::RBX, LLCCEP_JIT::RAX);
}

void gen_add(LLCCEP_JIT::codegen_backend &backend, instruction data)
{
	__gen_read_nums(backend, data);
	backend.emit_fadd();
	backend.get_ptr(LLCCEP_JIT::RAX, data.args[0]);
	backend.emit_fstp_reg_ptr(LLCCEP_JIT::RAX);
}

void gen_sub(LLCCEP_JIT::codegen_backend &backend, instruction data)
{
	__gen_read_nums(backend, data);
	backend.emit_fsub();
	backend.get_ptr(LLCCEP_JIT::RAX, data.args[0]);
	backend.emit_fstp_reg_ptr(LLCCEP_JIT::RAX);
}

void gen_mul(LLCCEP_JIT::codegen_backend &backend, instruction data)
{
	__gen_read_nums(backend, data);
	backend.emit_fmul();
	backend.get_ptr(LLCCEP_JIT::RAX, data.args[0]);
	backend.emit_fstp_reg_ptr(LLCCEP_JIT::RAX);
}

void gen_div(LLCCEP_JIT::codegen_backend &backend, instruction data)
{
	__gen_read_nums(backend, data);
	backend.emit_fdiv();
	backend.get_ptr(LLCCEP_JIT::RAX, data.args[0]);
	backend.emit_fstp_reg_ptr(LLCCEP_JIT::RAX);
}

void gen_and(LLCCEP_JIT::codegen_backend &backend, instruction data)
{

}

void gen_or(LLCCEP_JIT::codegen_backend &backend, instruction data)
{
}

void gen_xor(LLCCEP_JIT::codegen_backend &backend, instruction data)
{
}

void gen_off(LLCCEP_JIT::codegen_backend &backend, instruction data)
{
}

void gen_nop(LLCCEP_JIT::codegen_backend &backend, instruction data)
{
}

void gen_swi(LLCCEP_JIT::codegen_backend &backend, instruction data)
{
	//runtime
}

void gen_cmp(LLCCEP_JIT::codegen_backend &backend, instruction data)
{
}

void gen_inc(LLCCEP_JIT::codegen_backend &backend, instruction data)
{
}

void gen_dec(LLCCEP_JIT::codegen_backend &backend, instruction data)
{
}

void gen_sqrt(LLCCEP_JIT::codegen_backend &backend, instruction data)
{
}

void gen_sin(LLCCEP_JIT::codegen_backend &backend, instruction data)
{
}

void gen_cos(LLCCEP_JIT::codegen_backend &backend, instruction data)
{
}

void gen_ptan(LLCCEP_JIT::codegen_backend &backend, instruction data)
{
}

void gen_patan(LLCCEP_JIT::codegen_backend &backend, instruction data)
{
}

void gen_ldc(LLCCEP_JIT::codegen_backend &backend, instruction data)
{
}

void gen_outp(LLCCEP_JIT::codegen_backend &backend, instruction data)
{
	//runtime
}

void gen_inp(LLCCEP_JIT::codegen_backend &backend, instruction data)
{
	//runtime
}

namespace LLCCEP_JIT {
	
}
