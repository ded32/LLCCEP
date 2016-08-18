#include <initializer_list>
#include <vector>
#include <string>
#include <cassert>
#include <memory>

#include <STDExtras.hpp>
#include <STLExtras.hpp>

#include "ast.hpp"

ast::ast():
	_children(),
	_parent(0),
	_val(0)
{ }

ast::ast(const ast &from):
	_children(),
	_parent(0),
	_val(from.getValue())
{
	for (const auto &i: from.getChildren()) {
		if (i) {
			ast *ch = new ast(*i);
			_children.push_back(ch);
		}
	}
}

ast::ast(::std::string val):
	_children(),
	_parent(0),
	_val(val)
{ }

ast::~ast()
{
	
}