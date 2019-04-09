#ifndef TCB_H_INCLUDED
#define TCB_H_INCLUDED

#include "../include/cdata.h"
#include "../include/support.h"
#include "../include/queue.h"
#include "../include/context.h"
#include "../include/tcb.h"

//	TCB executando no momento
TCB_t* runningTCB;


TCB_t* create_tcb(ucontext_t* context, int state,int prio);
TCB_t* create_main_tcb(ucontext_t* context);
TCB_t* findTCBbyTid(PFILA2 queue, int tid);

#endif 

