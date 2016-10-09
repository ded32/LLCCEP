#include <stdio.h>
#include <errno.h>
#include <yyext.h>

int readfile(FILE *in, char **buf)
{
#define CHECKED_FILEOP(f, op) \
	{ \
		int stat; \
		op; \
		if (stat = ferror(f)) \
			return -stat; \
	}

	size_t len;
	char *buffer;

	if (!in)
		return -EBADF;
       	
	CHECKED_FILEOP(in, fseek(in, 0, SEEK_END));
	len = ftell(in);
	CHECKED_FILEOP(in, fseek(in, 0, SEEK_SET));
	buffer = (char *)calloc(length + 1, sizeof(char));
	CHECKED_FILEOP(in, fread(buffer, length, 1, in));

	*buf = buffer;
#undef CHECKED_FILEOP
}
