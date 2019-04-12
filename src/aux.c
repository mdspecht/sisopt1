#include <stdlib.h>
#include <string.h>
#include <ucontext.h>
#include <stdio.h>

#include "../include/aux.h"
#include "../include/queue.h"
#include "../include/context.h"
#include "../include/cdata.h"
#include "../include/support.h"



int so_start = 0;

int init(){
    if(so_start==0){ 
        so_start = 1;
        if(createQueues()){
            printf("As filas foram criadas com sucesso.");
        }
    }
    return 0;
}

void endThread(){
	printf("MAIN THREAD");
}