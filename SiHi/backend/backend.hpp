#ifndef BACKEND_HPP
#define BACKEND_HPP

#include "./../ast/ast.hpp"

namespace LLCCEP_SiHi {
	class backend {
	public:
		backend();
		~backend();

		void generateCode() const;

	private:
		void generateCode(ast *ptr, bool inclass) const;

		ast *syntaxTree;
	};

#endif // BACKEND_HPP
