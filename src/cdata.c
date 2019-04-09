#include <stdlib.h>
#include <string.h>
#include <ucontext.h>
#include <stdio.h>

#include "../include/queue.h"
#include "../include/support.h"
#include "../include/cdata.h"
#include "../include/context.h"


/*
*Não há necessidade de se preocupar com o reaproveitamento do identificador da
thread (tid), pois os testes não esgotarão essa capacidade.
*/

/*
Variavel com numero da nova thread
Vai ser incrementado com cada criação de threads - ccreate()
*/
static int tid_global = 0;


/*
Procura TCB na FILA DE APTOS pelo TID
*/
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

/*
Inicia o TCB com os valores de criacao de thread
Quando criada, uma thread nova sempre vai para a FILA DE APTOS
*/
TCB_t* create_tcb(ucontext_t* context, int prio){

    TCB_t* tcb = malloc(sizeof(*tcb));
    tcb->tid = tid_global++;
    tcb->state = PROCST_APTO;
    tcb->prio = prio;   
    tcb->context = *context;
    
    return tcb;
}


int next_tid(){
    //printf("tid: %d\n",tid_global );
    return tid_global++;

}