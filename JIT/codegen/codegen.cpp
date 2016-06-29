#include "codegen.hpp"

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
	//check it later
}

void gen_top(LLCCEP_JIT::codegen_backend &backend, instruction data)
{
	backend.emit_mov_reg_reg_ptr(LLCCEP_JIT::RAX, LLCCEP_JIT::RSP);
	backend.get_ptr(LLCCEP_JIT::RBX, data.args[0]);
	backend.emit_mov_reg_ptr_reg(LLCCEP_JIT::RBX, LLCCEP_JIT::RAX);
}

void gen_add(LLCCEP_JIT::codegen_backend &backend, instruction data)
{
	backend.emit_
}

namespace LLCCEP_JIT {
	
}
