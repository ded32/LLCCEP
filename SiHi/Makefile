DEBUG:=-g -O0
RELEASE:=-O2

FLAGS:=-std=gnu++11 -I./../include/
MODE:=$(DEBUG)

FLEX_BISON_LIBS:=-ll -ly

all: build_lexer

build_lexer: build_parser build_ast SiHi.l
	lex -o SiHi_lexer.cpp SiHi.l
	c++ $(FLAGS) $(MODE) -o SiHi_lexer.o SiHi_lexer.cpp $(FLEX_BISON_LIBS) -last -lSTDExtras

build_ast: build_extras ast/ast.hpp ast/ast.cpp
	c++ -c $(FLAGS) $(MODE) -o libast.o ast/ast.cpp -lSTDExtras
	libtool -static -o libast.a libast.o

build_extras: ./../include/STDExtras.hpp ./../lib/STDExtras.cpp
	c++ -c $(FLAGS) $(MODE) -o libSTDExtras.o ./../lib/STDExtras.cpp
	libtool -static -o libSTDExtras.a libSTDExtras.o

build_parser: SiHi.y
	yacc -o SiHi_parser.hpp SiHi.y

clean:
	rm -rf *.cpp *.hpp *.o *.a
