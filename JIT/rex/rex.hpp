#ifndef REX_HPP
#define REX_HPP

namespace LLCCEP_JIT {
	enum REX: uint8_t {
		REX_W = 0x48,
		REX_R = 0x44,
		REX_X = 0x42,
		REX_B = 0x41
	};	
}

#endif // REX_HPP
