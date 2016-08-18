#ifndef AST_HPP
#define AST_HPP

#include <string>
#include <vector>

namespace LLCCEP_SiHi {
	class ast {
		ast();
		ast(const ast &from);
		explicit ast(::std::string val);
		~ast();
		
		void dumpPlain(::std::string outPath) const;
		void dumpImage(::std::string outPath) const;
		
		::std::string getValue();
		::std::vector<ast *> getChildren();
		
		bool OK();
		
	private:
		::std::vector<ast *> _children;
		ast *_parent;
		::std::string _val;
	};
}

#endif // AST_HPP
