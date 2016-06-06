OBJ:=./obj
BIN:=./bin
LIB:=./lib

INC:=./../../include
SRC:=./../../lib

FLAGS:=-std=gnu99 -I$(INC) -g -O0

all: build

init:
	mkdir -p $(OBJ) $(BIN) $(LIB)

build_config_reader:
	$(MAKE) -C ./../conf/ build_static

build_init: ./init.c ./init.h
	cc -c $(FLAGS) -o $(OBJ)/init.o ./init.c
	ar rcs $(LIB)/libinit.a $(OBJ)/init.o

build_convert: $(SRC)/convert.c $(INC)/convert.h
	cc -c $(FLAGS) -o $(OBJ)/convert.o $(SRC)/convert.c
	ar rcs $(LIB)/libconvert.a $(OBJ)/convert.o

build_static: build_init build_convert

build: init build_config_reader build_static
	cc $(FLAGS) -L$(LIB) -L./../conf/lib/ -L$(LIB) -o $(BIN)/test.out ./test.c -lreader -ly -ll -lsection -llist -linit -lconvert
	
clean:
	$(MAKE) -C ./../conf/ clean
	rm -rf $(OBJ) $(BIN) $(LIB)
