#include <stdlib.h>
#include <string.h>
#include <ucontext.h>
#include <stdio.h>


#include "../include/cdata.h"
#include "../include/support.h"
#include "../include/queue.h"
#include "../include/context.h"



/*
*Aloca um contexto.
*/

ucontext_t* createContext(void* func){
    
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

    //getcontext(context);
    //makecontext(context,(void (*)(void)) func, 0);

    return context;

}


//THREADS CRIADAS APONTAM PARA O THREAD MAIN QUE VAI DECIDIR QUAL O PROXIMA THREAD A USAR A CPU
void set_uc_link(TCB_t* tcb){
    getcontext(&tcb->context);
    tcb->context.uc_link = &mainThread->context;
    makecontext(&tcb->context,(void (*)(void))f1,0);
}


void *even2(ucontext_t* cont1,ucontext_t* cont2) {
    int i;

     for (i =0; i <=10; i=i+2 )
         printf("BBB%3d\n\n", i);

     

     /* A função even ao terminar vai para a função indicada por:
      * "setcontext(&even_context->uc_link);", ou seja, a main,
      *  no retorno da chamada "getcontext(&main_context)" */ 
} 


void *even1(ucontext_t* cont1,ucontext_t* cont2) {
    int i;

     for (i =0; i <=10; i=i+2 ){

         printf("AAA%3d\n\n", i);
     }

        swapcontext(cont1,cont2);

     

     /* A função even ao terminar vai para a função indicada por:
      * "setcontext(&even_context->uc_link);", ou seja, a main,
      *  no retorno da chamada "getcontext(&main_context)" */ 
} 