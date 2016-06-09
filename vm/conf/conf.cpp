#include <string>
#include <vector>
#include <map>

#include <stdint.h>

#include <libconfig.h++>
#include <STDExtras.hpp>

namespace LLCCEP_vm {
	config read_configuration_file(::std::string path)
	{
		::libconfig::Config data;
		const ::libconfig::Setting &root;
		config conf = {
			.displayW = 800,
			.displayH = 640,
			.ramS = 1024 * 1024 * 512
		};

		try {
			data.readFile(path);
		} catch (const ::libconfig::FileIOException &exc) {
			throw RUNTIME_EXCEPTION(exc.what());
		} catch (const ::libconfig::ParseException &exc) {
			throw RUNTIME_EXCEPTION(exc.what());
		} DEFAULT_HANDLING

		root = data.getRoot();

		try {
			const ::libconfig::Setting &sc  = root["config"]["screen"],
			                           &ram = root["config"]["ram"],
			                           &dev = root["config"]["devices"];

			sc.lookupValue("width",  conf.displayW);
			sc.lookupValue("height", conf.displayH);
			ram.lookupValue("size",  conf.ramS);
			dev.lookupValue("dev",   conf.dev);
		} catch (::libconfig::SettingNotFoundException &nf) {

		} DEFAULT_HANDLING

		return conf;
	}
}
