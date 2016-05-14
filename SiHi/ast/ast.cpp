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
		for (const auto &child: children)
			if (child)
				child->~ast();

		if (__ancestor__ && LLCCEP::vec_find(__ancestor__->children, ))
	}

	inline bool ast::OK() const
	{
		if (ancestor && !LLCCEP::vec_find(__ancestor__->__children__, this)) 
			PANIC(bool, "Ancestor at %p has no child with %p address!\n", ancestor, this);

		for (const auto &child: __children__)
			if (child && !child->OK())
				PANIC(bool, "My child at %p isn't ok!", child);

		return true;
	}
}
