#include <stdlib.h>
#include <string.h>
#include <ucontext.h>
#include <stdio.h>

#include "../include/aux.h"
#include "../include/queue.h"
#include "../include/context.h"
#include "../include/cdata.h"
#include "../include/support.h"






int so_start = 0;

int init_cthread(){
    if(so_start==0){ 
        createQueues(); //CRIA AS FILAS: APTO,BLOQUEADO E FINALIZADO      
        printf("JK");
        so_start = 1;




    }
   
    return 0;
}


TCB_t* createMainThread(void* main){
    //CRIA UMA THREAD COM CONTEXTO VAZIO
    ccreate(main,NULL,0); //THREAD MAIN COM CONTEXT MAIN SEM UC_LINK
    printFila2(ready_queue);// TESTA SE THREAD MAIN ESTA NA FILA

    //PROCURA THREAD MAIN - TID = 0 pois foi a primeira a ser criada.
    //COLOCAR EM EXECUCAO A THREAD MAIN
    TCB_t* tcb_main = findTCBbyTid(ready_queue,MAIN_TID);
    //getcontext(&tcb_main->context);
    //makecontext(&tcb_main->context,main,0);
    printf("tid: %d\n",tcb_main->tid); //TESTA SE A THREAD MAIN ESTA EXECUTANDO
    return tcb_main;
}


/*
Busca na fila de aptos a thread com maior prioridade e coloca em execução
*/

void dispatch(){
    TCB_t* tcb = findTCBbyPrio(ready_queue);
    runningTCB = tcb;
}

void* dispacher(){

    mainThread = createMainThread(dispacher);
        



    int tid1 = ccreate(f1,NULL,0);
    
    //DEBUG
    TCB_t* tcb1 = findTCBbyTid(ready_queue,tid1);       
    printFila2(ready_queue);
    //DEBUG

    int ret=0;
    //SALVA O CONTEXTO DA MAIN
    getcontext(&mainThread->context);
    
    
    if(ret==0){
        ret=1;
        runningTCB = tcb1;
        setcontext(&tcb1->context);
    }
    
    printf("ACABOU\n\n");
}




void* f1(){
    printf("F1\n\n");

}

void* f2(){
    printf("F2\n\n");
}

