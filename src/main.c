#include "../include/support.h"
#include "../include/cthread.h"
#include <stdio.h>

void* func0() {
	printf("Eu sou a thread ID0 imprimindo \n");
    cyield();
    printf("Eu sou a thread ID0 imprimindo FIM\n");
	
}

void* func1() {
	printf("Eu sou a thread ID1 imprimindo \n");
    cyield();
    printf("Eu sou a thread ID1 imprimindo FIM\n");
}


int main(int argc, char *argv[]) {

	int	id0, id1;
	int i;

	id0 = ccreate(func0, NULL, 2);
	id1 = ccreate(func1, NULL, 1);

	printf("Eu sou a main após a criação de ID0 e ID1\n");

	cjoin(id0);
	cjoin(id1);

	printf("Eu sou a main voltando para terminar o programa\n");
}
