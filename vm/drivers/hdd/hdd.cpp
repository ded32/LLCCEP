#include <cstdint>
#include <cstdio>
#include "./../../setup/setup.hpp"

namespace LLCCEP_vm {
	void set_byte(size_t devID, size_t byteID, uint8_t byteV)
	{
		::std::fseek(dev[devID], byteID, SEEK_SET);
		::std::fwrite(&byteV, sizeof(byteV), 1, dev[devID]);
		::std::fseek(dev[devID], 0, SEEK_SET);
	}

	uint8_t get_byte(size_t devID, size_t byteID)
	{
		uint8_t res = 0;

		::std::fseek(dev[devID], byteID, SEEK_SET);
		::std::fread(&res, sizeof(res), 1, dev[devID]);
		::std::fseek(dev[devID], 0, SEEK_SET);

		return res;
	}
}
