#include <initializer_list>
#include <vector>
#include <string>
#include <cassert>

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
		std::vector<ast *>::const_iterator node = std::vector<ast *>::const_iterator();

		for (const auto &child: __children__)
			if (child)
				child->~ast();

		if (__ancestor__ && (node = vec_find(__ancestor__->__children__, this)) != __ancestor__->__children__.end())
			__ancestor__->__children__.erase(node);
	}

	inline bool ast::OK() const
	{
		if (__ancestor__ && vec_find(__ancestor__->__children__, (ast *)this) == __ancestor__->__children__.end()) 
			PANIC(bool, "Ancestor at %p has no child with %p address!\n", __ancestor__, this);

		for (const auto &child: __children__)
			if (child && !child->OK())
				PANIC(bool, "My child at %p isn't ok!", child);

		return true;
	}

	void ast::insert_child(ast *src)
	{
		assert(src);
		__children__.push_back(src);
	}

	::std::vector<ast *> ast::get_children() const
	{
		return __children__;
	}

	ast *ast::get_ancestor() const
	{
		return __ancestor__;
	}
}
