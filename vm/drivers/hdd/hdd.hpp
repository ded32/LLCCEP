#ifndef HDD_HPP
#define HDD_HPP

#include <cstdint>

namespace LLCCEP_vm {
	inline void set_byte(size_t devID, size_t byteID, uint8_t byteV);
	inline uint8_t get_byte(size_t devID, size_t byteID);
}

#endif // HDD_HPP
