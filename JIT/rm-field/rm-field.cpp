#include <STDExtras.hpp>
#include "rm-field.hpp"

namespace LLCCEP_JIT {
	rm_field::rm_field():
		modrm(0)
	{
		DECL_INVALID("rm_field", "in current context")
	}

	rm_field::rm_field(uint8_t selector, uint8_t op0, uint8_t op1):
		modrm(((selector & 0b011) << 6) |
		      ((op0      & 0b111) << 3) |
		      ((op1      & 0b111) << 0))
	{
		// modrm:[0-1] = selector
		// modrm:[2-4] = op0
		// modrm:[5-7] = op1
	}

	rm_field::~rm_field()
	{
		modrm = 0;
	}

	uint8_t get_val() const
	{
		return modrm;
	}
}
