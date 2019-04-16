#ifndef AUX_H_INCLUDED
#define AUX_H_INCLUDED

#include "../include/cdata.h"
#include "../include/support.h"
#include "../include/queue.h"
#include "../include/context.h"
#include "../include/cthread.h"


#define MAIN_TID 0
int so_start;

int init();
void end();
void runThread(TCB_t* tcb);
void runNextThread();

#endif 

