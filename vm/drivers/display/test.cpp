#include "display.hpp"

int main()
{
	LLCCEP_vm::init_display("test", 800, 640);

	LLCCEP_vm::set_clr(RGB(0xFF, 0xFF, 0xFF));
	LLCCEP_vm::set_pix(0, 0);

	while (LLCCEP_vm::handle_msg());

	LLCCEP_vm::kill_display();
}
