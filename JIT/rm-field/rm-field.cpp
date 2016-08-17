#include <STDExtras.hpp>
#include "rm-field.hpp"

LLCCEP_JIT::rm_field::rm_field():
	modrm(0)
{ }

LLCCEP_JIT::rm_field::rm_field(uint8_t selector, uint8_t op0, uint8_t op1):
	modrm(((selector & 0b011) << 6) |
	      ((op0      & 0b111) << 3) |
	      ((op1      & 0b111) << 0))
{ }

LLCCEP_JIT::rm_field::~rm_field()
{ }

uint8_t LLCCEP_JIT::rm_field::get_val() const
{
	return modrm;
}
