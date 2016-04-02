#include <string>
#include <memory>
#include <vector>

#include "ast.hpp"

namespace LLCCEP_SiPy {	
	template <class TYPE, class... args>
	typename std::enable_if<!std::is_array<TYPE>::value, std::unique_ptr<TYPE>>::type make_unique(args &&... params)
	{
		return std::unique_ptr<TYPE>(new TYPE(std::forward<args>(params)...));
	}

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
