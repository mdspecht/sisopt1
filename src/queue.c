#include <stdlib.h>
#include <string.h>
#include <ucontext.h>
#include <stdio.h>


#include "../include/cdata.h"
#include "../include/support.h"
#include "../include/queue.h"
#include "../include/context.h"

static int CreateFila2_ARRAY(PFILA2 fila[], int size){
	int i;
	for(i=0;i<size;i++){
		if(CreateFila2(fila[i])!=0){
			return -1;
		}
	}
	return 0;
}

/*
Aloca e cria as filas APTO,BLOQUEADO E TERMINADO
*/
int createQueues(){
	int i;
    //ALOCA NA MEMORIA AS FILAS
	for(i=0;i< NUM_PRIO;i++){
    	ready_queue[i] = malloc(sizeof(*ready_queue[0]));
	}
    finished_queue = malloc(sizeof(*finished_queue));
    blocked_queue = malloc(sizeof(*blocked_queue));

    if (ready_queue==NULL || finished_queue==NULL || blocked_queue==NULL){
            perror("Falha ao alocar memoria para as filas");
            exit(-1);
    }

    //CRIA AS FILAS
    if (CreateFila2_ARRAY(ready_queue, NUM_PRIO)!=0 || CreateFila2(finished_queue)!=0 || CreateFila2(blocked_queue)!=0){
            perror("Falha ao criar as filas");
            exit(-1);
    }

    return 0;
}

/*
Insere na fila de semaforo ordenada pela prioridade
*/
int appendFilaPrio(PFILA2 pfila, TCB_t* tcb){
    TCB_t* tcb_it;

    // pfile vazia?
    if (FirstFila2(pfila)==0) { //SETA O ITERADOR NO COMECO DA FILA
        do {
            tcb_it = (TCB_t *) GetAtIteratorFila2(pfila);
            if(tcb->prio < tcb_it->prio) {
                return InsertBeforeIteratorFila2(pfila, tcb);
            }
        } while (NextFila2(pfila)==0);
    }
    return AppendFila2(pfila, (void *)tcb);
 }


int isFilaEmpty(PFILA2 pFILA2){
    if (FirstFila2(pFILA2)==0)
        return 0;
    return 1;
}

/*
*DEBUG
Imprime TID das threads
*/
void printFila2(PFILA2 fila){
    
    if (isFilaEmpty(fila)==1){
        puts("FILA VAZIA");
    } 
    else{
        FirstFila2(fila);
        TCB_t* tcb =  fila->it->node;
        printf("tid = %d\n",tcb->tid );

        while (NextFila2(fila)==0){
            TCB_t* tcb =  fila->it->node;
            printf("tid = %d\n",tcb->tid );
        }
    }
    printf("FIM DA FILA\n\n");
}




