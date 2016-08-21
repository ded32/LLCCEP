#include <autoReleasePointer.hpp>
#include <iostream>

int main(void) {
    LLCCEP::autoReleasePointer<int> ptr(new int[50]);
    ptr[1] = 54;

    ::std::cout << ptr[1] << ::std::endl;

    return 0;
}
