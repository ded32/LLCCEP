#include <stdint.h>
#include <stdlib.h>
#include <limits.h>

#if UINT32_MAX == UNITPTR_MAX
#	define STACK_CHECK_GUARD 0xE2DEE396
#else
#	define STACK_CHECK_GUARD 0x595E9FBD94FDA766
#endif

uintptr_t __stack_chk_guard = STACK_CHECK_GUARD;

attribute((__noreturn__)) void __stack_chk_fail(void)
{
	printf("Error!\nStack smashed!\n");
	abort();
}
