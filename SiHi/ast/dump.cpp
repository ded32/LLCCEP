#include <iostream>
#include <string>
#include <DotViz++.hpp>

#include "ast.hpp"

static void __dump_node(DotViz::DVGraph &graph, 
			LLCCEP_SiHi::ast *tree, 
			size_t par_id)
{
	if (!tree)
		return;

	static size_t id = 0;
	id++;

	graph.node(id, tree->get_val());
	graph.link(par_id, id);

	for (size_t i = 0; i < tree->get_children().size(); i++) {
		__dump_node(graph, (tree->get_children()[i]),
			    id);
	}
}

namespace LLCCEP_SiHi {
	void dump_ast(::std::string path, ::std::string name,
		      ast *tree)
	{
		DotViz::DVGraph graph;
		graph.begin(path, name);

		if (tree) {
			graph.node(0, tree->get_val());

			for (size_t i = 0; i < tree->get_children().size(); i++)
				__dump_node(graph, tree->get_children()[i], 0);
		}

		graph.end();
	}
}
