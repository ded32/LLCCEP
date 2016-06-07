#include <convert.h>

#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

#define DEFAULT_CONVERT_BLOCK(str, type) \
({ \
	assert(str); \
	\
	type res = 0; \
	size_t len = strlen(str); \
	\
	for (unsigned i = 0; i < len; i++) { \
		if (!isdigit(str[i])) \
			break; \
		else \
			res = res * 10 + str[i] - '0'; \
	} \
	res; \
})

uint16_t str2uint16_t(char const *str)
{
	return DEFAULT_CONVERT_BLOCK(str, uint16_t);
}

size_t str2size_t(char const *str)
{
	return DEFAULT_CONVERT_BLOCK(str, size_t);
}

#undef DEFAULT_CONVERT_BLOCK
