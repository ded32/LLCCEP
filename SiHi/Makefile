DEBUG:=-g -O0
RELEASE:=-O2

FLAGS:=-std=gnu11
MODE:=$(DEBUG)

all: build_lexer

build_lexer: SiHi.l
	lex -o SiHi_lexer.c SiHi.l
	cc $(FLAGS) $(MODE) -o SiHi_lexer.o SiHi_lexer.c -ll -ly

clean:
	rm -rf SiHi_lexer.c SiHi_lexer.o
