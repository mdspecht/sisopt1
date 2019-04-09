#ifndef AUX_H_INCLUDED
#define AUX_H_INCLUDED

#include "../include/cdata.h"
#include "../include/support.h"
#include "../include/queue.h"
#include "../include/context.h"



#define MAIN_TID 0

int init_cthread();
int run_main_thread(PFILA2 ready_queue);

#endif 

