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