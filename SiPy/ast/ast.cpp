#include <string>
#include <memory>
#include <vector>

#include <STLExtras.hpp>

#include "ast.hpp"

namespace LLCCEP_SiPy {	
	astNode::~astNode()
	{}

	astNumberNode::astNumberNode(double val):
		value(val)
	{}

	astVariableNode(const std::string& str):
		name(str)
	{}

	astBinaryExprNode::astBinaryExprNode(char op_, std::unique_ptr<astNode> pL, std::unique_ptr<astNode> pR):
		left(std::move(pL)),
		right(std::move(pR)),
		op(op_)
	{}

	astInvokeExprNode::astInvokeExprNode(const std::string& str, std::vector<std::unique_ptr<astNode> > args):
		name(str),
		params(std::move(args))
	{}

	astProto::astProto(const std::string &str, std::vector<std::string> args):
		name(str),
		params(std::move(args))
	{}

	astFunc::astFunc(std::unique_ptr<astProto> prototype, std::unique_ptr<astNode> Body):
		proto(std::move(prototype)),
		Body(std::move(Body))
	{}	
}
