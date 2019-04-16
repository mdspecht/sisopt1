#ifndef CONTEXT_H_INCLUDED
#define CONTEXT_H_INCLUDED


#include "../include/cdata.h"
#include "../include/support.h"
#include "../include/queue.h"
#include "../include/context.h"


ucontext_t* contextMain;

ucontext_t* allocContext();
ucontext_t* createContext(void* (*start)(void*), void *arg,void* (*end)(void*));

#endif 

