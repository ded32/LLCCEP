#ifndef RAM_HPP
#define RAM_HPP

#include <cstring>
#include <cstddef>
#include <string>

namespace LLCCEP_vm {
	void allocate_mem(size_t size_b);
	
	uint8_t *get_mem(size_t offset);
	size_t get_mem_size();

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

	void free_mem();

	::std::string get_string(size_t pos);
	void write_string(size_t addr, ::std::string str);
}

#endif // RAM_HPP
