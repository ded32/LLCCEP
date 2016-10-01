#include <ast/ast.hpp>
#include <context/context.hpp>

#include <string>

#include <backend/variableDeclaration/variableDeclaration.hpp>

LLCCEP_SiHi::variableDeclaration::variableDeclaration():
	declarationInfo(),
	wasDeclared(false)
{ }

LLCCEP_SiHi::variableDeclaration::~variableDeclaration()
{
	release();
}

void LLCCEP_SiHi::variableDeclaration::data(LLCCEP_SiHi::variable data)
{
	declarationInfo = data;
}

LLCCEP_SiHi::variable LLCCEP_SiHi::variableDeclaration::data() const
{
	return declarationInfo;
}

void LLCCEP_SiHi::variableDeclaration::declare() const
{
	if (!declarationInfo.cxt.out) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"No output for codegenerator!"));
	}

	if (wasDeclared) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Codegenerator failure: attempt of variable "
			"re-declaration at the same context!"));
	}

	auto out = *declarationInfo.cxt.out;
	auto varname = "__user_var_" + declarationInfo.cxt.toString() + "_" + 
	               declarationInfo.type.toString() + "_" + 
		       declarationInfo.name;
	
	out << "var " << varname << "\n";
	    << "__operator_alloc_init_" << declarationInfo.type.toString() 
	    << "__ " << varname << "\n";

	wasDeclared = true;
}

void LLCCEP_SiHi::variableDeclaration::release() const
{
	if (!declarationInfo.cxt.out) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"No output for codegenerator!"));
	}

	if (wasDeclared) {
		auto out = *declarationInfo.cxt.out;
		auto varname = "__user_var_" + declarationInfo.cxt.toString() + "_" +
		               declarationInfo.type.toString() + "_" + 
			       declarationInfo.name;

		out << "var " << varname << "\n"
		    << "__operator_release_delete_" << declarationInfo.type.toString()
		    << "__ " << varname << "\n";

		wasDeclared = false;
	}
}
