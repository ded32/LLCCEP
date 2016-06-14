FLAGS:=-std=gnu++11 -g -O0
LIB:=./lib
BIN:=./bin
OBJ:=./obj

INC:=./../../include
SRC:=./../../lib

all: build

init:
	mkdir -p $(LIB) $(BIN) $(OBJ)

build_stdext: $(INC)/STDExtras.hpp $(SRC)/STDExtras.cpp
	c++ -c $(FLAGS) -I$(INC) -o $(OBJ)/STDExt.o $(SRC)/STDExtras.cpp
	ar rcs $(LIB)/libSTDExt.a $(OBJ)/STDExt.o

build_conf: ./conf.hpp ./conf.cpp
	c++ -c $(FLAGS) -I$(INC) -L$(LIB) -L/usr/lib -o $(OBJ)/conf.o ./conf.cpp -lSTDExt -lconfig++
	ar rcs $(LIB)/libconf.a $(OBJ)/conf.o

build_static: build_stdext build_conf

build: init build_static test.cpp
	c++ $(FLAGS) -L$(LIB) -o $(BIN)/test.out test.cpp -lconf -lSTDExt -lconfig++

clean:
	rm -rf $(LIB) $(BIN) $(OBJ)
