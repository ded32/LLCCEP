#ifndef PROGRAM_MANAGER_HPP
#define PROGRAM_MANAGER_HPP

#include <initializer_list>
#include <cstdint>
#include "../emitter/emitter.hpp"

namespace LLCCEP_JIT {
	enum fld_const: uint8_t {
		FLD_1        = 0,
		FLD_LOG_2_10 = 1,
		FLD_LOG_2_E  = 2,
		FLD_PI       = 3,
		FLD_LOG_10_2 = 4,
		FLD_LOG_N_2  = 5,
		FLD_ZERO     = 6
	};

	class program: public emitter {
	public:
		program();
		program(const program &src);

		void emit_ret();
		void emit_nop();
		
		void emit_mov_reg_reg(regID dst, regID src);
		void emit_mov_reg_ptr_reg(regID src, regID dst);
		void emit_mov_reg_reg_ptr(regID src, regID dst);
		void emit_mov_reg_imm(regID dst, uint64_t src);

		void emit_push_reg(regID src);
		void emit_push_imm(uint64_t src);
		void emit_pop_reg(regID dst);
		void emit_pop_reg_ptr(regID src);

		void emit_finit();
		void emit_fclex();

		void emit_fld(regID src);
		void emit_fld_const(fld_const val);

		void emit_fabs();

		void emit_fadd();
		void emit_fsub();
		void emit_fmul();
		void emit_fdiv();
		void emit_fsqrt();

		void emit_fsin();
		void emit_fcos();
		void emit_fptan();
		void emit_fpatan();

		void emit_fstp_reg_ptr(regID dest);

		void emit_call_reg(regID id);
	};
}

#endif // PROGRAM_MANAGER_HPP
