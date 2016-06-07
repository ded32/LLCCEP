#include "./init.h"
#include "./../conf/reader.h"

int main(void)
{
	struct unidirected_list *data = read_vm_configuration_file(stdin);
	struct init_data res = process_configuration(data);

	printf("I need %zd memory to be allocated!\n"
	       "The display is %hux%hu!\n"
	       "Devices list:\n", res.ramS, res.dispW, res.dispH);

	return 0;
}
