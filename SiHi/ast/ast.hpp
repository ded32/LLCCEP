#ifndef AST_HPP
#define AST_HPP

#include <initializer_list>
#include <vector>
#include <string>

namespace LLCCEP_SiHi {
	class ast {
		::std::vector<ast *> __children__;
		ast *__ancestor__;

		struct {
			int __type__;
			::std::string __val__;
		} __lex_data__;
	public:
		ast();
		ast(const ast &src);
		ast(::std::initializer_list<ast *> children, int lex_t, ::std::string lex_val);
		~ast();

		inline bool OK() const;

		void insert_child(ast *src);
		::std::vector<ast *> get_children() const;
		ast *get_ancestor() const; 
	};
}

#endif // AST_HPP
