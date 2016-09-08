#include <convert.hpp>
#include <iostream>

int main(void) {
	::std::cout << reinterpret_value<uint64_t, void *>(0xff) << ::std::endl;
	return 0;
}
