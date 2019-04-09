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
        create_queues(); //CRIA AS FILAS: APTO,BLOQUEADO E FINALIZADO      
                
        so_start = 1;
    }
   
    return 0;
}


int run_main_thread(PFILA2 ready_queue){
    //PROCURA A THREAD COM MAIS PRIORIDADE NA FILA
    runningTCB = findTCBbyTid(ready_queue,0);
    return 1;
}








