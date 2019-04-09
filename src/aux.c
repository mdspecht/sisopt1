#include <stdlib.h>
#include <string.h>
#include <ucontext.h>
#include <stdio.h>

#include "../include/aux.h"
#include "../include/cdata.h"
#include "../include/support.h"


/*
*Não há necessidade de se preocupar com o reaproveitamento do identificador da
thread (tid), pois os testes não esgotarão essa capacidade.
*/
static int tid_global = 1;



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
int create_queues(){

    //ALOCA NA MEMORIA AS FILAS
    ready_queue = malloc(sizeof(*ready_queue));
    finished_queue = malloc(sizeof(*finished_queue));
    blocked_queue = malloc(sizeof(*blocked_queue));

    if (ready_queue==NULL || finished_queue==NULL || blocked_queue==NULL){
			perror("Falha ao alocar memoria para as filas");
			exit(-1);
		}

    //CRIA AS FILAS
    if (CreateFila2(ready_queue)!=0 || CreateFila2(finished_queue)!=0 || CreateFila2(blocked_queue)!=0){
            perror("Falha ao criar as filas");
            exit(-1);
        }

    return 0;
}

int IsFilaEmpty(PFILA2 pFILA2){
    if (FirstFila2(pFILA2)==0)
        return 0;
    return 1;
}

void printFila2(PFILA2 fila){
    
    if (IsFilaEmpty(fila)==1){
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
    
}

int appendFilaPrio(PFILA2 pfila, TCB_t *tcb) {
    TCB_t *tcb_it;

    // pfile vazia?
    if (FirstFila2(pfila)==0) { //SETA O ITERADOR NO COMECO DA FILA
        do {
            tcb_it = (TCB_t *) GetAtIteratorFila2(pfila);
            if (tcb->prio < tcb_it->prio) {
                return InsertBeforeIteratorFila2(pfila, tcb);
            }
        } while (NextFila2(pfila)==0);
    }
    return AppendFila2(pfila, (void *)tcb);
}




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

void reset_tid_global(){
    tid_global = 1;
}

int next_tid(){
    //printf("tid: %d\n",tid_global );
    return tid_global++;

}


/*
*Aloca um contexto.
*/

ucontext_t* create_context(){
    
    ucontext_t* context = malloc(sizeof(*context));
    if (context==NULL){
        perror("Erro ao alocar o contexto!");
        exit(-1);
    }

    if(getcontext(context)!=0){
        perror("Erro ao pegar o contexto!");
        exit(-1);
    }

    
    context->uc_stack.ss_sp = malloc(SIGSTKSZ);
    context->uc_stack.ss_size = SIGSTKSZ;

    if (context->uc_stack.ss_sp==NULL){
        printf("ERRO AO ALOCAR A STACK!!");
        exit(-1);
    }

    return context;

}


void even2(ucontext_t* cont1,ucontext_t* cont2) {
    int i;

     for (i =0; i <=10; i=i+2 )
         printf("BBB%3d\n\n", i);

     return;

     /* A função even ao terminar vai para a função indicada por:
      * "setcontext(&even_context->uc_link);", ou seja, a main,
      *  no retorno da chamada "getcontext(&main_context)" */ 
} 


void even1(ucontext_t* cont1,ucontext_t* cont2) {
    int i;

     for (i =0; i <=10; i=i+2 ){

         printf("AAA%3d\n\n", i);
     }

        swapcontext(cont1,cont2);

     return;

     /* A função even ao terminar vai para a função indicada por:
      * "setcontext(&even_context->uc_link);", ou seja, a main,
      *  no retorno da chamada "getcontext(&main_context)" */ 
} 