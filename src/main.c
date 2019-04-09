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

void conte(){
	ucontext_t* cont_main = create_context();
	ucontext_t* cont1 = create_context();
	ucontext_t* cont2 = create_context();
	int ret_code;

	cont1->uc_link = cont_main;
	cont2->uc_link = cont1;

    /* O typecast (void (*)(void)) é só para evitar warnings na
     * compilação e não afeta o comportamento da função */

	makecontext(cont1, (void (*)(void)) even1, 2, cont1,cont2) ;
	makecontext(cont2, (void (*)(void)) even2, 2, cont1,cont2);

	ret_code = 0;
	getcontext(cont_main);	//SALVA O CONTEXTO ATUAL EM CONT1

	if(ret_code==0){
		ret_code = 1;
		setcontext(cont1);
	}
}

int main(){

	ccreate(test_ccreate_func,NULL,0); //THREAD MAIN
	printFila2(ready_queue);// TESTA SE THREAD MAIN ESTA NA FILA

	//PROCURA THREAD MAIN - TID = 0 pois foi a primeira a ser criada.
	//COLOCAR EM EXECUCAO A THREAD MAIN
	runningTCB = findTCBbyTid(ready_queue,MAIN_TID);
	printf("running tid: %d\n",runningTCB->tid); //TESTA SE A THREAD MAIN ESTA EXECUTANDO
	

	

	
		
		
	

}


/*

getcontext(&main_context);
SALVA O CONTEXTO


*/