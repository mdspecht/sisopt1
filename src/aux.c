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
		printf("%s: entered;\n",__FUNCTION__);
        so_start = 1;
        if(createQueues()==0){
            printf("As filas foram criadas com sucesso.\n");
        }
        contextMain = allocContext();

		mainTCB= createTcb(contextMain, PRIO_MIN);
		mainTCB->state = PROCST_APTO;
		mainTCB->joined= NULL;
		runningTCB= mainTCB;
    }
    return 0;
}

void end(){
    printf("THREAD %d VAI TERMINAR SUA EXECUÇÃO\n",runningTCB->tid);
	runningTCB->state = PROCST_TERMINO;
    printf("THREAD %d ENTROU NA FILA DE FINALIZADOS\n",runningTCB->tid);
    AppendFila2(finished_queue,runningTCB);
	
	if(runningTCB->joined){
		TCB_t* tcb= runningTCB->joined;
		tcb->state= PROCST_APTO;
		AppendFila2(ready_queue[tcb->prio], tcb);
		printf("Liberando tid(%d) para aptos.\n", tcb->tid);
	}
    runningTCB = NULL;
    runNextThread();
    
}

void runThread(TCB_t* tcb){
    //REMOVE DA FILA DE APTOS
	removeTCBbyTid(ready_queue[tcb->prio],tcb->tid);

    //COLOCA EM EXECUCAO
    tcb->state=PROCST_EXEC;
    runningTCB = tcb;

    int ret = 0;
    //getcontext(contextMain);

    if(ret==0){
        ret=1;
        printf("THREAD %d VAI EXECUTAR\n",tcb->tid);
        setcontext(&runningTCB->context);
        printf("ESSE PRINTF NAO PODE EXECUTAR");
    }
    
    printf("PROGRAMA TERMINOU\n");
    
}

 void runNextThread(){
	int i;	
	for(i=0;i<NUM_PRIO;i++){
		if(!isFilaEmpty(ready_queue[i])){
			break;
		}
	}
	if(i==NUM_PRIO){
		printf("SEM THREADS NA FILA DE APTOS\n");
        //apenas retorna nesse mesmo contexto...
		//setcontext(contextMain);
        
	}else{
        FirstFila2(ready_queue[i]);
        runThread(ready_queue[i]->it->node);
    }
    
}


