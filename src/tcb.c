#include <stdlib.h>
#include <string.h>
#include <ucontext.h>
#include <stdio.h>

#include "../include/aux.h"
#include "../include/cdata.h"
#include "../include/support.h"
#include "../include/queue.h"
#include "../include/context.h"


/*
*Não há necessidade de se preocupar com o reaproveitamento do identificador da
thread (tid), pois os testes não esgotarão essa capacidade.
*/
static int tid_global = 0;



/*
*Inicia o TCB com os valores de criacao de thread
*/
TCB_t* create_tcb(ucontext_t* context, int state,int prio){

    TCB_t* tcb = malloc(sizeof(*tcb));
    tcb->tid = tid_global++;
    tcb->state = state;
    tcb->prio = prio;   
    tcb->context = *context;
    
    return tcb;
}

TCB_t* create_main_tcb(ucontext_t* context){

    TCB_t* tcb = malloc(sizeof(*tcb));
    tcb->tid = 0;
    tcb->state = PROCST_EXEC;
    tcb->prio = PRIO_MIN;   
    tcb->context = *context;
    
    return tcb;
}


TCB_t* findTCBbyTid(PFILA2 queue, int tid){
    if (FirstFila2(queue)==0){
        do {
            TCB_t* tcb = queue->it->node;
            if (tcb->tid==tid)
                return tcb;
        } while (NextFila2(queue)==0);
    }
    return NULL;
}