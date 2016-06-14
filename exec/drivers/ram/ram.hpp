#ifndef RAM_HPP
#define RAM_HPP

#include <cstring>

namespace LLCCEP_vm {
	inline void allocate_mem(size_t size_b);

	inline uint8_t *get_mem(size_t offset);

	template<class T>
	inline T access_mem_data(size_t id)
	{
		uint8_t *mem = get_mem(id);
		union {
			uint8_t data[sizeof(T)];
			T val;
		} conv;

		::std::memcpy(conv.data, mem, sizeof(T));

		return conv.val;
	}

	template<class T>
	inline void access_mem_data(size_t id, T val)
	{
		::std::memcpy(get_mem(id), &val, sizeof(T));
	}

	inline void free_mem();
}

#endif // RAM_HPP
