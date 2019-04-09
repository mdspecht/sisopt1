#ifndef AUX_H_INCLUDED
#define AUX_H_INCLUDED

#include "../include/cdata.h"
#include "../include/support.h"

//FILAS
PFILA2 ready_queue;
PFILA2 finished_queue;
PFILA2 blocked_queue;

//	TCB executando no momento
TCB_t* runningTCB;


int init_cthread();
int create_queues();

TCB_t* create_tcb(ucontext_t* context, int state,int prio);
TCB_t* create_main_tcb(ucontext_t* context);
void reset_tid_global();
ucontext_t* create_context();
int next_tid();
int appendFilaPrio(PFILA2 pfila, TCB_t *tcb);
void printFila2(PFILA2 fila);

int IsFilaEmpty(PFILA2 pFILA2);

void even1(ucontext_t* cont1,ucontext_t* cont2) ;
void even2(ucontext_t* cont1,ucontext_t* cont2) ;
#endif // TESTE_H_INCLUDED

