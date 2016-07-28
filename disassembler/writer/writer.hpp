#ifndef WRITER_HPP
#define WRITER_HPP

#include <iostream>
#include "../reader/reader.hpp"

::std::ostream &operator>>(::std::ostream &out, LLCCEP_DisASM::instruction inst);

#endif // WRITER_HPP
