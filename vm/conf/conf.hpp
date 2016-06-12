#ifndef CONF_HPP
#define CONF_HPP

#include <string>
#include <vector>

namespace LLCCEP_vm {
	struct config {
		::std::vector<::std::string> dev;

		int displayW;
		int displayH;

		long long unsigned ramS;

		::std::string title;
	};

	config read_configuration_file(::std::string path);
}

#endif // CONF_HPP
