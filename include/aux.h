#ifndef AUX_H_INCLUDED
#define AUX_H_INCLUDED

#include "../include/cdata.h"
#include "../include/support.h"
#include "../include/queue.h"
#include "../include/context.h"
#include "../include/cthread.h"


#define MAIN_TID 0
int so_start;
TCB_t* mainThread;

int init_cthread();
TCB_t* createMainThread(void* main);

void* f0();
void* f1();
void* f2();
void* dispacher();

void dispatch();
#endif 

