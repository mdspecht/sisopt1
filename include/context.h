#ifndef CONTEXT_H_INCLUDED
#define CONTEXT_H_INCLUDED

#include "../include/cdata.h"
#include "../include/support.h"
#include "../include/queue.h"
#include "../include/context.h"


ucontext_t* create_context(void* start);
void even1(ucontext_t* cont1,ucontext_t* cont2) ;
void even2(ucontext_t* cont1,ucontext_t* cont2) ;


#endif // TESTE_H_INCLUDED

