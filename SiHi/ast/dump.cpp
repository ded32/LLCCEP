#include <iostream>
#include <string>
#include <DotViz/DotViz++.hpp>

#include "ast.hpp"

void __dump_lib_static_only_dump_node(const LLCCEP_SiHi::ast &node, long long unsigned begin)
{
	static long long unsigned count = begin + 1;

	DotViz::dvNode(begin, node.get_val());

	for (size_t i = 0; i < node.get_children().size(); i++) {
		if (node.get_children()[i]) {
			__dump_lib_static_only_dump_node(*(node.get_children()[i]), count + i);
			DotViz::dvLink(begin, count + i);
		}
	}
}

namespace LLCCEP_SiHi {
	void dump_tree(::std::string title, const ast &root)
	{
		DotViz::dvBegin(title, "AST_dump");

		__dump_lib_static_only_dump_node(root, 0);

		DotViz::dvEnd();
	}
}
