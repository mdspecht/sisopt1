#
# Makefile para programas exemplo
# 

CC=gcc
LIB_DIR=../lib
C_FLAGS=-m32 -Wall

all: main

main: main.c $(LIB_DIR)/libcthread.a
	$(CC) -o main main.c -L$(LIB_DIR) -lcthread $(C_FLAGS)
	
clean:
	rm -rf main *.o *~




