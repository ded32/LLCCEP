#ifndef RM_FIELD_HPP
#define RM_FIELD_HPP

#include <cstdint>

namespace LLCCEP_JIT {
	class rm_field {
		uint8_t modrm;
	public:
		rm_field();
		rm_field(uint8_t selector, uint8_t op0, uint8_t op1);
		~rm_field();

		uint8_t get_val() const;
	};
}

#endif // RM_FIELD_HPP
