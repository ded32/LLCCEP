#include <iostream>
#include <string>
#include <DotViz++.hpp>

#include "ast.hpp"

void __dump_node(DotViz::DVGraph &graph, LLCCEP_SiHi::ast &tree,
		 long long unsigned id) 
{
	graph.node(++id - 1, tree.get_val());

	for (size_t i = 0; i < tree.get_children().size(); i++) {
		if (tree.get_children()[i]) {
			__dump_node(graph, *(tree.get_children()[i]), id + i);
			graph.link(id - 1, id + i);
		}
	}
}

namespace LLCCEP_SiHi {
	void dump_ast(::std::string path, ::std::string name,
		      ast &tree)
	{
		DotViz::DVGraph graph;
		graph.begin(path, name);

		__dump_node(graph, tree, 0);
		
		graph.end();
	}
}
