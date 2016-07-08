#ifndef AST_HPP
#define AST_HPP

#include <vector>
#include <string>
#include <initializer_list>

namespace LLCCEP_SiHi {
	class ast {
		::std::string __value__;
		::std::vector<ast *> children;
		ast *__ancestor__;
	protected:
		bool ok() const;
		void check() const;
	public:
		ast();
		ast(const ast &src);
		explicit ast(const ::std::string value);
		ast(::std::initializer_list<ast *>children)
		~ast();

		::std::string value() const;
		void value(::std::string)
		::std::vector<ast *> children() const;
		ast *ancestor() const;

		void insert_child(ast *new_child);
	}; 
}

#endif // AST_HPP
