/*
 * cdata.h: arquivo de inclus�o de uso apenas na gera��o da libpithread
 *
 * VERS�O: 29/03/2019
 *
 */
#ifndef __cdata__
#define __cdata__

#include "ucontext.h"

typedef struct s_TCB { 
	/* OS CAMPOS ABAIXO N�O PODEM SER ALTERADOS OU REMOVIDOS
	*/
	int		tid; 		// identificador da thread
	int		state;		// estado em que a thread se encontra (CONFORME DEFINES ANTERIORES)
	int 		prio;		// Prioridade associada a thread
	ucontext_t 	context;	// contexto de execu��o da thread (SP, PC, GPRs e recursos) 
	
	/* A PARTIR DESSE PONTO PODEM SER ACRESCENTADOS CAMPOS NECESS�RIOS AO DESENVOLVIMENTO DA BIBLIOTECA
	*/
	struct s_TCB *joined;
	
} TCB_t; 


#include "../include/support.h"
#include "../include/queue.h"
#include "../include/context.h"


/* Estados das threads
*/
#define	PROCST_APTO	0		/* Processo em estado apto a ser escalonado */
#define	PROCST_EXEC	1		/* Processo em estado de execu��o */
#define	PROCST_BLOQ	2		/* Processo em estado bloqueado */
#define	PROCST_TERMINO	3	/* Processo em estado de terminado */

#define PRIO_MAX 0
#define PRIO_MED 1
#define PRIO_MIN 2

//static int tid_global;

//  TCB executando no momento
TCB_t* runningTCB;
TCB_t* mainTCB;


TCB_t* createTcb(ucontext_t* context,int prio);
TCB_t* findTCBbyTid(PFILA2 queue, int tid);
TCB_t* findTCBbyPrio(PFILA2 queue);
int removeTCBbyTid(PFILA2 queue, int tid);

int next_tid();

#endif
