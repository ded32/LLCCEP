#ifndef COMPILER_HPP
#define COMPILER_HPP

#include <vector>
#include <string>
#include <iostream>

LLCCEP_ASM::compiler::compiler()
{ }

LLCCEP_ASM::compiler::~compiler()
{ }

void LLCCEP_ASM::compiler::setProcessingFiles(::std::vector<::std::istream *> in,
                                              ::std::ostream *out)
{
	for (const auto &i: in) {
		if (!i) {
			throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
				"Met null input file for setProcessingFiles"))
		}

		_in.push_back(i);
	}

	_out = out;

	if (!_in.size())
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG("No input"))

	if (!_out)
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG("No output"))
}

void LLCCEP_ASM::compiler::compile()
{
	if (!_in.size() || !_out) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"No input or output"))
	}

	LLCCEP_ASM::lexer lex;
	LLCCEP_ASM::

	for (const auto &i: _in) {
		if (!i) {
			throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
				"Null input at compiling"))
		}


	}
}
