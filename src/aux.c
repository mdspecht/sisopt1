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


int init(){
    if(so_start==0){ 
        so_start = 1;
        if(createQueues()){
            printf("As filas foram criadas com sucesso.");
        }
        contextMain = allocContext();
    }
    return 0;
}

void end(){
    printf("THREAD %d VAI TERMINAR SUA EXECUÇÃO\n",runningTCB->tid);
	runningTCB->state = PROCST_TERMINO;
    printf("THREAD %d ENTROU NA FILA DE FINALIZADOS\n",runningTCB->tid);
    AppendFila2(finished_queue,runningTCB);
    runningTCB = NULL;
    runNextThread();
    
}

void runThread(TCB_t* tcb){
    
    removeTCBbyTid(ready_queue,tcb->tid);
    tcb->state=PROCST_EXEC;
    runningTCB = tcb;

    int ret = 0;
    getcontext(contextMain);

    if(ret==0){
        ret=1;
        printf("THREAD %d VAI EXECUTAR\n",tcb->tid);
        setcontext(&runningTCB->context);
        printf("ESSE PRINTF NAO PODE EXECUTAR");
    }
    printf("THREAD %d TERMINOU SUA EXECUÇÂO\n",tcb->tid);
}

 void runNextThread(){
	
	if(isFilaEmpty(ready_queue)==1){
		printf("SEM THREADS NA FILA DE APTOS\n");
	}
    else{
        FirstFila2(ready_queue);
        runThread(ready_queue->it->node);
    }
    
    
}   


