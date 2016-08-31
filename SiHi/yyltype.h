#ifndef YYLTYPE_H
#define YYLTYPE_H

typedef struct YYLTYPE {
	int line;
	int first_column;
	int last_column;
	int next_tok_first_column;
	int posbuf;
	char *buf;
} YYLTYPE;

#define YYLTYPE_IS_DECLARED

#endif
