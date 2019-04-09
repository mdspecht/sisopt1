#include <stdlib.h>
#include <string.h>
#include <ucontext.h>
#include <stdio.h>

#include "../include/aux.h"
#include "../include/queue.h"
#include "../include/context.h"
#include "../include/tcb.h"
#include "../include/cdata.h"
#include "../include/support.h"


/*
*Não há necessidade de se preocupar com o reaproveitamento do identificador da
thread (tid), pois os testes não esgotarão essa capacidade.
*/
static int tid_global = 0;



int so_start = 0;

int init_cthread(){
    if(so_start==0){ 
        create_queues(); //CRIA AS FILAS: APTO,BLOQUEADO E FINALIZADO      
                
        so_start = 1;
    }
   
    return 0;
}

/*
*Cria as filas
*/




int run_main_thread(PFILA2 ready_queue){
    //PROCURA A THREAD COM MAIS PRIORIDADE NA FILA
    runningTCB = findTCBbyTid(ready_queue,0);
    return 1;
}





void reset_tid_global(){
    tid_global = 1;
}

int next_tid(){
    //printf("tid: %d\n",tid_global );
    return tid_global++;

}



