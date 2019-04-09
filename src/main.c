#include <stdio.h>
#include <string.h>
#include <ucontext.h>


#include "../include/cthread.h"
#include "../include/aux.h"
#include "../include/queue.h"
#include "../include/context.h"
#include "../include/cdata.h"


void testa_cidentify(void){
    char name[40];
    int a = cidentify(name,sizeof(name));
    puts(name);
}

void* test_ccreate_func(void* arg){

}

void createMainThread(void* main){
	//CRIA UMA THREAD COM CONTEXTO VAZIO
	ccreate(main,NULL,0); //THREAD MAIN COM CONTEXT MAIN
	printFila2(ready_queue);// TESTA SE THREAD MAIN ESTA NA FILA

	//PROCURA THREAD MAIN - TID = 0 pois foi a primeira a ser criada.
	//COLOCAR EM EXECUCAO A THREAD MAIN
	TCB_t* tcb = findTCBbyTid(ready_queue,MAIN_TID);
	printf("tid: %d\n",tcb->tid); //TESTA SE A THREAD MAIN ESTA EXECUTANDO
}


void* main(){

	
	createMainThread(main);

	

	
		
		
	

}


/*

getcontext(&main_context);
SALVA O CONTEXTO


*/