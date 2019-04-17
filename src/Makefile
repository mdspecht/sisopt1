CC=gcc
LIB_DIR=./lib
INC_DIR=./include
BIN_DIR=./bin
SRC_DIR=./src
C_FLAGS=-Wall -m32
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

all: $(OBJ)
	$(CC) $(OBJ) ../bin/support.o -o main $(C_FLAGS)

%.o: %.c
	$(CC) -c $< $(C_FLAGS)

clean:
	rm *.o

.PHONY: clean all

