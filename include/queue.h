#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include "../include/cdata.h"
#include "../include/support.h"
#include "../include/context.h"
#include "../include/aux.h"

//FILAS
PFILA2 ready_queue;
PFILA2 finished_queue;
PFILA2 blocked_queue;


int createQueues();
int appendFilaPrio(PFILA2 pfila, TCB_t* tcb);
void printFila2(PFILA2 fila);
int isFilaEmpty(PFILA2 pFILA2);


#endif 

