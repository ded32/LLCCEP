#include <initializer_list>
#include <vector>
#include <string>

#include <STLExtras.hpp>

#include "ast.hpp"

#define PANIC(type, fmt, ...) {fprintf(stderr, fmt, ##__VA_ARGS__); return type();}

namespace LLCCEP_SiHi {
	ast::ast():
		__children__(),
		__ancestor__(0),
		__lex_data__()
	{ }

	ast::ast(const ast &src):
		__children__(src.__children__),
		__ancestor__(0),
		__lex_data__(src.__lex_data__)
	{ }
	
	ast::ast(std::initializer_list<ast *> children, int lex_t, ::std::string lex_val):
		__children__(children),
		__ancestor__(0),
		__lex_data__({lex_t, lex_val})
	{ }

	ast::~ast()
	{
		if (__ancestor__)
			for (size_t i = 0; i < __ancestor__->__children__.size(); i++)
				if (__ancestor__->__children__[i] == this)
					__ancestor__->__children__.erase(__ancestor__->__children__.begin() + i);
	}

	inline bool ast::OK() const
	{
		if (ancestor && !LLCCEP::vec_find(ancestor->children, this)) 
			PANIC("Ancestor at %p has no child with %p address!\n", );
	}
}
