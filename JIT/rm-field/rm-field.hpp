#ifndef RM_FIELD_HPP
#define RM_FIELD_HPP

#include <cstdint>

namespace LLCCEP_JIT {
	class rmField {
		uint8_t modrm;
	public:
		rmField();
		rmField(uint8_t selector, uint8_t op0, uint8_t op1);
		~rmField();

		void value(uint8_t selector, uint8_t op0, uint8_t op1);
		uint8_t value() const;
	};

#define rmFieldRegReg rmField(0b11, 0, 0)
}

#endif // RM_FIELD_HPP
