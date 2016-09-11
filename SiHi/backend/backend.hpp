#ifndef BACKEND_HPP
#define BACKEND_HPP

#include <iostream>
#include "./../ast/ast.hpp"

namespace LLCCEP_SiHi {
	class backend {
		struct functionArgument {
			::std::string type_name;
			::std::string name;
		};
		
		struct functionProto {
			::std::string ret_t;
			::std::string name;
			::std::vector<functionArgument> args;
		};

	public:
		backend();
		~backend();

		void generateCode(::std::ostream &out) const;

	private:
		void generateCode(::std::ostream &out, ast *root) const;
		
		ast *syntaxTree;
	};

#endif // BACKEND_HPP
