
#include <stdio.h>
#include <string.h>

#include "../include/aux.h"
#include "../include/queue.h"
#include "../include/support.h"
#include "../include/cdata.h"
#include "../include/cthread.h"



#include "../include/context.h"




int ccreate (void* (*start)(void*), void *arg, int prio) {

    init(); 
    ucontext_t* context = createContext(start,arg,(void*) &end);
    TCB_t* tcb = createTcb(context,prio); 
    tcb->state = PROCST_APTO;
	tcb->joined= NULL;

    if(AppendFila2(ready_queue[tcb->prio], tcb)!=0){
		return -1;
	}
	return tcb->tid;
}

int csetprio(int tid, int prio) {
    //tid = NULL; //Na versão 2019/01, deixar sempre esse campo como NULL
    runningTCB->prio=prio;
    if(runningTCB->prio==prio){
        return 0;
    }
    else{
        return -1;
    }
	
}


static int internal_yield( int block)
{
	
    //SALVA O CONTEXTO
    int ret=0;
    getcontext(&runningTCB->context);
    
    if(ret==0){
        printf("THREAD %d CEDEU A CPU\n",runningTCB->tid);
        ret=1;
		if(block){
			AppendFila2(blocked_queue, runningTCB);
			runningTCB->state = PROCST_BLOQ;
			printf("THREAD EXECUTANDO FOI PARA ESTADO BLOQUEADO\n");
		}else{
			//COLOCA THREAD NA FILA DE APTOS 
			AppendFila2(ready_queue[runningTCB->prio],runningTCB);
			runningTCB->state = PROCST_APTO;
		}
		runningTCB=NULL;

        runNextThread(); 
    }
    
	return 0;

}

int cyield(void) {
	return internal_yield(0);
}

int cjoin(int tid) {
    //BLOCK THREAD QUE ESTÁ EXECUTANDO

	TCB_t* tcb= NULL;
	int i;
	for(i=0;i<NUM_PRIO;i++){
		tcb = findTCBbyTid(ready_queue[i], tid);
		if(tcb!=NULL){
			break;
		}
	}
	if(tcb==NULL){
		printf("Valor de tid(%d) invalido.\n", tid);
		return -2;
	}

	if(tcb->joined){
		printf("Esse tid(%d) ja foi usado pela thread %d\n", tid, tcb->joined->tid);
		return -1;
	}
	tcb->joined= runningTCB;

	internal_yield(1);

	return 0;
}

int csem_init(csem_t *sem, int count) {
	return -1;
}

int cwait(csem_t *sem) {
	return -1;
}

int csignal(csem_t *sem) {
	return -1;
}

int cidentify (char *name, int size) {
    const char* names = "JESSICA - XXXXXX\nMARCELO - 230090\nRICARDO - 160542\n"; //porque o \0?
    if(strlen(names)<=size){
        strncpy(name,names,size);
        return 0;
    }
    else{
        return -1;
    }
}


