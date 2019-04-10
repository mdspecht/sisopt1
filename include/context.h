#ifndef CONTEXT_H_INCLUDED
#define CONTEXT_H_INCLUDED

typedef struct s_swapContexts { 
    
    
    ucontext_t context1;    
    ucontext_t context2;
   
    
} swapContexts_t; 

#include "../include/cdata.h"
#include "../include/support.h"
#include "../include/queue.h"
#include "../include/context.h"


ucontext_t* createContext(void* start);
ucontext_t* createContext1(void* func);
void* even1(ucontext_t* cont1,ucontext_t* cont2) ;
void* even2(ucontext_t* cont1,ucontext_t* cont2) ;
void set_uc_link(TCB_t* tcb);

#endif // TESTE_H_INCLUDED

