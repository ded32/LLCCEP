#include <initializer_list>
#include <vector>
#include <string>
#include <cassert>
#include <memory>

#include <STLExtras.hpp>

#include "ast.hpp"

#define PANIC(type, fmt, ...) {fprintf(stderr, fmt, ##__VA_ARGS__); return type();}
#define CHECK_ME(type) if (!OK()) PANIC(type, "Tree's not ok. It's located here: [%p]!\n", this);

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
			PANIC(bool, "Ancestor at %p has no child with %p address!\n", __ancestor__, this)

		for (const auto &child: __children__)
			if (child && !child->OK())
				PANIC(bool, "My child at %p isn't ok!", child)

		return true;
	}

	void ast::insert_child(ast *src)
	{
		CHECK_ME(void)

		assert(src);
		__children__.push_back(src);

		CHECK_ME(void)
	}

	::std::vector<ast *> ast::get_children() const
	{
		CHECK_ME(::std::vector<ast *>)
		return __children__;
	}

	::std::auto_ptr<ast> ast::get_ancestor() const
	{
		CHECK_ME(::std::auto_ptr<ast>)
		return ::std::auto_ptr<ast>(__ancestor__);
	}

	int ast::get_type() const
	{
		CHECK_ME(int)
		return __lex_data__.__type__;
	}

	::std::string ast::get_val() const
	{
		CHECK_ME(::std::string)
		return __lex_data__.__val__;
	}
}
