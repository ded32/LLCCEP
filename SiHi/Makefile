DEBUG:=-g -O0
RELEASE:=-O2

FLAGS:=-std=gnu++11
MODE:=$(DEBUG)

FLEX_BISON_LIBS:=-ll -ly

all: build_lexer

build_lexer: build_parser SiHi.l
	lex -o SiHi_lexer.cpp SiHi.l
	c++ $(FLAGS) $(MODE) -o SiHi_lexer.o SiHi_lexer.cpp $(FLEX_BISON_LIBS)

build_parser: SiHi.y
	yacc -o SiHi_parser.hpp SiHi.y

clean:
	rm -rf SiHi_lexer.cpp SiHi_parser.hpp SiHi_lexer.o
