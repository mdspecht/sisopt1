
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
    appendFilaPrio(ready_queue, tcb);
	return tcb->tid;
}

int csetprio(int tid, int prio) {
    //tid = NULL; //Na versão 2019/01, deixar sempre esse campo como NULL

	return -1;
}

int cyield(void) {
    appendFilaPrio(ready_queue,runningTCB);
    runningTCB->state = PROCST_APTO;
    runningTCB=NULL;
	return 0;
}

int cjoin(int tid) {
    //BLOCK THREAD QUE ESTÁ EXECUTANDO
    //*********
    if(runningTCB!=NULL){
        AppendFila2(blocked_queue,runningTCB);
        printf("THREAD EXECUTANDO FOI PARA ESTADO BLOQUEADO\n");
    }
    else{
        printf("SEM THREAD EXECUTANDO\n");
    }
    //RUN THREAD
	TCB_t* tcb = findTCBbyTid(ready_queue, tid);
    printf("PROXIMA TCB A EXECUTAR: %d \n",tcb->tid);
    runThread(tcb);

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
    const char* names = "MARCELO - 230090\0\n";
    if(strlen(names)<=size){
        strncpy(name,names,size);
        return 0;
    }
    else{
        return -1;
    }
}


