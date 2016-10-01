#include <context/context.hpp>

LLCCEP_SiHi::context::context():
	contextVariables()
{ }

LLCCEP_SiHi::context::~context()
{ }

void LLCCEP_SiHi::context::addVariable(::std::string name)
{
	auto goodVariableName = [](::std::string name) {
		if (!name.length() || (!isalpha(name[0]) && name[0] != '_'))
			return false;

		for (const auto &i: name)
			if (!isalnum(i) && i != '_')
				return false;

		return true;
	};

	if (variableDeclared(name)) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"%s variable was already declared at the [%p] context",
			name.c_str(), context));
	}

	if (!goodVariableName(name)) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"'%s' is bad variable name!",
			name.c_str()));
	}

	contextVariables.push_back(name);
}

void LLCCEP_SiHi::context::deleteVariable(::std::string name)
{
	if (!variableDeclared(name)) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"%s variable was not declared and cannot be deleted!",
			name.c_str()));
	}

	contextVariables.erase(vec_find(contextVariables, name));
}

bool LLCCEP_SiHi::context::variableDeclared(::std::string name) const
{
	return (vec_find(contextVariables, name) != contextVariables.end());
}

::std::string LLCCEP_SiHi::context::toString() const
{
	return "SiHiBackendContext" + to_string(this) + "OfVariables";
}
