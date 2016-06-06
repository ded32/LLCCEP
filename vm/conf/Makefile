OBJ:=./obj
BIN:=./bin
LIB:=./lib
SYNTH:=./synthesis

INC:=./../../include/
SRC:=./../../lib

FLAGS:=-std=gnu99 -I$(INC) -g -O0

all: build

init:
	mkdir -p $(OBJ) $(BIN) $(LIB) $(SYNTH)

synthesis: init ./vm_conf.l ./vm_conf.y
	lex -o $(SYNTH)/lexer.h ./vm_conf.l
	yacc -o $(SYNTH)/parser.h ./vm_conf.y

build_section: ./section.c ./section.h
	cc -c $(FLAGS) -o $(OBJ)/section.o ./section.c
	ar rcs $(LIB)/libsection.a $(OBJ)/section.o

build_list: ./../../lib/list.c ./../../include/list.h
	cc -c $(FLAGS) -o $(OBJ)/list.o $(SRC)/list.c
	ar rcs $(LIB)/liblist.a $(OBJ)/list.o

build_reader: ./reader.c ./reader.h
	cc -c $(FLAGS) -o $(OBJ)/reader.o ./reader.c
	ar rcs $(LIB)/libreader.a $(OBJ)/reader.o

build_static: synthesis build_section build_list build_reader

build: build_static test.c
	cc $(FLAGS) -L$(LIB) -o $(BIN)/test.out ./test.c -lreader -ly -ll -lsection -llist

clean:
	rm -rf $(OBJ) $(BIN) $(LIB) $(SYNTH)
