#ifndef CONF_HPP
#define CONF_HPP

#include <string>
#include <vector>

#include <stdint.h>

#include <libconfig.h++>

namespace LLCCEP_vm {
	struct config {
		::std::vector<::std::string> dev;

		uint16_t displayW;
		uint16_t displayH;

		size_t ramS;
	};

	config read_configuration_file(::std::string path);
}

#endif // CONF_HPP
