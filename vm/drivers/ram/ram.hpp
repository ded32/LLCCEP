#ifndef RAM_HPP
#define RAM_HPP

namespace LLCCEP_vm {
	void allocate_mem(size_t size_b);

	template<class T>
	T access_mem_data(size_t id);
	template<class T>
	void access_mem_data(size_t id, T val);

	void free_mem();
}

#endif // RAM_HPP
