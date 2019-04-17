#
# Makefile para programas exemplo
# 

CC=gcc
LIB_DIR=../lib
C_FLAGS=-m32 -Wall

all: exemplo mandel teste_vetor series

exemplo: exemplo.c $(LIB_DIR)/libcthread.a
	$(CC) -o exemplo exemplo.c -L$(LIB_DIR) -lcthread $(C_FLAGS)

teste_vetor: teste_vetor.c $(LIB_DIR)/libcthread.a
	$(CC) -o teste_vetor teste_vetor.c -L$(LIB_DIR) -lcthread $(C_FLAGS)

mandel: mandel.c $(LIB_DIR)/libcthread.a
	$(CC) -o mandel mandel.c -L$(LIB_DIR) -lcthread -lm $(C_FLAGS)


series: series.c $(LIB_DIR)/libcthread.a
	$(CC) -o series series.c -L$(LIB_DIR) -lcthread -lm $(C_FLAGS)
	
clean:
	rm -rf exemplo mandel teste_vetor series *.o *~




