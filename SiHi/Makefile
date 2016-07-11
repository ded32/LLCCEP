DEBUG:=-g -O0
RELEASE:=-O2

FLAGS:=-std=gnu11
MODE:=$(DEBUG)

FLEX_BISON_LIBS:=-ll -ly

all: build_lexer

build_lexer: build_parser SiHi.l
	lex -o SiHi_lexer.c SiHi.l
	cc $(FLAGS) $(MODE) -o SiHi_lexer.o SiHi_lexer.c $(FLEX_BISON_LIBS)

build_parser: SiHi.y
	yacc -o SiHi_parser.h SiHi.y

clean:
	rm -rf SiHi_lexer.c SiHi_parser.h SiHi_lexer.o
