#include <stdlib.h>
#include <string.h>
#include <ucontext.h>
#include <stdio.h>


#include "../include/cdata.h"
#include "../include/support.h"
#include "../include/queue.h"
#include "../include/context.h"


ucontext_t* allocContext(){
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

/*
CRIA UM CONTEXTO ASSOCIADO A FUNCAO START E APONTA O UC_LINK AO CONTEXTO DA FUNCAO END
CRIA UM CONTEXTO ASSOCIADO A FUNCAO END E APONTA O UC_LINK PARA NULL, POIS A THREAD TERMINOU

A FUNCÃO END RODARÁ QUANDO A FUNCAO START TERMINAR
A FUNCAO END LEVARÁ A THREAD EM EXECUÇÃO PARA O ESTADO DE TERMINO
*/

ucontext_t* createContext(void* (*start)(void*), void *arg,void* (*end)(void*)){
    
    ucontext_t* context = allocContext();
    ucontext_t* endContext = allocContext();

    context->uc_link = endContext;
    endContext->uc_link = NULL;

    makecontext(endContext,(void*) end, 1, arg);
    makecontext(context,(void*) start, 1, arg);

    return context;
}

