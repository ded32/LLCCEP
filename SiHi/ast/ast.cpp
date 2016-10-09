#include <ast/ast.hpp>

#include <typeInfo/typeInfo.hpp>
#include <codeFragment/codeFragment.hpp>

#include "../lexem/lexem.hpp"

#include "ast.hpp"

LLCCEP_SiHi::typeInfo LLCCEP_SiHi::ast::getType() const
{
	LLCCEP_SiHi::typeInfo res;
	switch (lexemData.value().type) {
	case PRIMARY_EXPRESSION:
		
}
