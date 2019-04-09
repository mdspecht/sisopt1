
#include <stdio.h>
#include <string.h>

#include "../include/aux.h"
#include "../include/queue.h"
#include "../include/support.h"
#include "../include/cdata.h"
#include "../include/cthread.h"



#include "../include/context.h"




int ccreate (void* (*start)(void*), void *arg, int prio) {
    init_cthread(); //CRIA AS FILAS E INDICA QUE SISTEMA COMECOU
    TCB_t* tcb = create_tcb(create_context(),prio);
    appendFilaPrio(ready_queue, tcb);
	return tcb->tid;
}

int csetprio(int tid, int prio) {
    //tid = NULL; //Na versão 2019/01, deixar sempre esse campo como NULL

	return -1;
}

int cyield(void) {

	return 0;
}

int cjoin(int tid) {
	return -1;
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


