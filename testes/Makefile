#
# Makefile para programas de teste
# 

CC=gcc
LIB_DIR=../lib
CFLAGS=-lcthread -Wall -m32

all: teste_vetor_2

teste_vetor_2: teste_vetor_2.c $(LIB_DIR)/libcthread.a
	$(CC) -o teste_vetor_2 teste_vetor_2.c -L$(LIB_DIR) $(CFLAGS)

.PHONY: all clean teste_vetor_2
	
clean:
	rm -rf teste_vetor_2 *.o *~
