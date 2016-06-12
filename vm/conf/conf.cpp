#include <string>
#include <vector>
#include <map>

#include <cstdint>
#include <cstring>
#include <cerrno>

#include <libconfig.h++>
#include <STDExtras.hpp>

#include "conf.hpp"

namespace LLCCEP_vm {
	config read_configuration_file(::std::string path)
	{
		::libconfig::Config data;
		config conf = { };
		conf.displayW = 800;
		conf.displayH = 640;
		conf.ramS = 1024 * 1024 * 512;
		conf.title = "LLCCEP VM";

		try {
			data.readFile(path.c_str());
		} catch (const ::libconfig::FileIOException &exc) {
			throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
				"FileIOException: reading file %s failed: %s!\n",
				path.c_str(), strerror(errno)));
		} catch (const ::libconfig::ParseException &exc) {
			throw RUNTIME_EXCEPTION(exc.what());
		} DEFAULT_HANDLING

		const ::libconfig::Setting &root = data.getRoot();

		try {
			const ::libconfig::Setting &sc  = root["config"]["screen"],
			                           &ram = root["config"]["ram"],
			                           &dev = root["config"]["devices"]["dev"];

			sc.lookupValue("width", conf.displayW);
			sc.lookupValue("height", conf.displayH);
			ram.lookupValue("size",  conf.ramS);
			root.lookupValue("title", conf.title);

			for (size_t i = 0; i < dev.getLength(); i++) {
				::std::string val = "";
				dev.lookupValue("path", val);
				conf.dev.push_back(val);
			}
		} catch (::libconfig::SettingNotFoundException &nf) {

		} DEFAULT_HANDLING

		return conf;
	}
}
