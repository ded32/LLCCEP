#ifndef BACKEND_HPP
#define BACKEND_HPP

#include <iostream>
#include "./../ast/ast.hpp"

namespace LLCCEP_SiHi {
	class backend {
	public:
		backend();
		~backend();

		void generateCode(::std::ostream &out) const;

	private:
		void generateCode(::std::ostream &out, ast *ptr) const;
		
		ast *syntaxTree;
	};

#endif // BACKEND_HPP
