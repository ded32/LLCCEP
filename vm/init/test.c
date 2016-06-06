#include "./init.h"
#include "./../conf/reader.h"

int main(void)
{
	struct unidirected_list *data = read_vm_configuration_file(stdin);
	process_configuration(data);

	return 0;
}
