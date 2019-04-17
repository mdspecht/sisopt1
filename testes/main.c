#include "../include/support.h"
#include "../include/cthread.h"
#include <stdio.h>

void* func0(void *arg) {
	printf("Eu sou a thread ID0 imprimindo \n");
    cyield();
    printf("Eu sou a thread ID0 imprimindo FIM\n");
	return NULL;
	
}

void* func1(void *arg) {
	printf("Eu sou a thread ID1 imprimindo \n");
    cyield();
    printf("Eu sou a thread ID1 imprimindo FIM\n");
	return NULL;
}


int main(int argc, char *argv[]) {

	int	id0, id1;

	id0 = ccreate(func0, NULL, 2);
	id1 = ccreate(func1, NULL, 1);

	printf("Eu sou a main após a criação de ID0(id=%d) e ID1(id=%d)\n", id0, id1);

	cjoin(id1);
	cjoin(id0);

	printf("Eu sou a main voltando para terminar o programa\n");
	char str[256];	
	if(cidentify (str, sizeof(str))==0){
		printf("%s", str);
	}
}
