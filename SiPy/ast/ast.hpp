#ifndef SIPY_AST_HPP
#define SIPY_AST_HPP

#include <string>
#include <memory>
#include <vector>

namespace LLCCEP_SiPy {	
	class astNode {
	public:
		virtual ~astNode();
	};

	class astNumberNode: public astNode {
		double value;
	public:
		astNumberNode(double val);
	};

	class astVariableNode: public astNode {
		std::string name;
	public:
		astVariableNode(const std::string &str);;
	};

	class astBinaryExprNode: public astNode {
		std::unique_ptr<astNode> left, right;
		char op;
	public:
		astBinaryExprNode(char op_, std::unique_ptr<astNode> pL, std::unique_ptr<astNode> pR);
	};

	class astInvokeExprNode: public astNode {
		std::string name;
		std::vector<std::unique_ptr<astNode> > params;
	public:
		astInvokeExprNode(const std::string &str, std::vector<std::unique_ptr<astNode> > args);
	};

	class astProto {
		std::string name;
		std::vector<std::string> params;
	public:
		astProto(const std::string &str, std::vector<std::string> args);
	};

	class astFunc {
		std::unique_ptr<astProto> proto;
		std::unique_ptr<astNode> body;
	public:
		astFunc(std::unique_ptr<astProto> prototype, std::unique_ptr<astNode> Body);
	};
}

#endif // SIPY_AST_HPP
