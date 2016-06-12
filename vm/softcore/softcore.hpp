#ifndef SOFTCORE_HPP
#define SOFTCORE_HPP

#include "./../program.hpp"

inline void emulated_mov(LLCCEP_vm::instruction &data);
inline void emulated_mva(LLCCEP_vm::instruction &data);
inline void emulated_push(LLCCEP_vm::instruction &data);
inline void emulated_pop(LLCCEP_vm::instruction &data);
inline void emulated_top(LLCCEP_vm::instruction &data);
inline void emulated_add(LLCCEP_vm::instruction &data);
inline void emulated_sub(LLCCEP_vm::instruction &data);
inline void emulated_mul(LLCCEP_vm::instruction &data);
inline void emulated_dev(LLCCEP_vm::instruction &data);
inline void emulated_and(LLCCEP_vm::instruction &data);
inline void emulated_or(LLCCEP_vm::instruction &data);
inline void emulated_xor(LLCCEP_vm::instruction &data);
inline void emulated_off(LLCCEP_vm::instruction &data);
inline void emulated_nop(LLCCEP_vm::instruction &data);
inline void emulated_swi(LLCCEP_vm::instruction &data);
inline void emulated_cmp(LLCCEP_vm::instruction &data);
inline void emulated_inc(LLCCEP_vm::instruction &data);
inline void emulated_dec(LLCCEP_vm::instruction &data);
inline void emulated_sqrt(LLCCEP_vm::instruction &data);
inline void emulated_sin(LLCCEP_vm::instruction &data);
inline void emulated_cos(LLCCEP_vm::instruction &data);
inline void emulated_ptan(LLCCEP_vm::instruction &data);
inline void emulated_patan(LLCCEP_vm::instruction &data);
inline void emulated_ldc(LLCCEP_vm::instruction &data);
inline void emulated_outp(LLCCEP_vm::instruction &data);

namespace LLCCEP_vm {
	void (*funcs[])(instruction &data) = {
		emulated_mov,
		emulated_mva,
		emulated_push,
		emulated_pop,
		emulated_top,
		emulated_add,
		emulated_sub,
		emulated_mul,
		emulated_dev,
		emulated_and,
		emulated_or,
		emulated_xor,
		emulated_off,
		emulated_nop,
		emulated_swi,
		emulated_cmp,
		emulated_inc,
		emulated_dec,
		emulated_sqrt,
		emulated_sin,
		emulated_cos,
		emulated_ptan,
		emulated_patan,
		emulated_ldc,
		emulated_outp
	};
}

#endif // SOFT_CORE_HPP
