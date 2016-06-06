#include <convert.h>

#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <assert.h>

#define DEFAULT_CONVERT_BLOCK(str, type, fmt) \
({ \
	assert(str); \
	\
	type res = 0; \
	sscanf(str, fmt, &res); \
	res;\
})

uint16_t str2uint16_t(char const *str)
{
	return DEFAULT_CONVERT_BLOCK(str, uint16_t, "%hu");
}

size_t str2size_t(char const *str)
{
	return DEFAULT_CONVERT_BLOCK(str, size_t, "%zd");
}

#undef DEFAULT_CONVERT_BLOCK
