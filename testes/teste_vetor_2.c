/* 
 * test_vetor.c: realiza a criação de 10 threads, cada uma delas escreve uma
 * sequencia de 20 letras iguais e passa a vez para outra thread. Repete até
 * preencher um vetor de 250 caracteres.
 */

#include	"../include/support.h"
#include	"../include/cthread.h"
#include	<stdio.h>
#include	<stdlib.h>

#define		MAX_SIZE	50
#define		MAX_THR		10

int vetor[MAX_SIZE];
int  inc = 0;

csem_t *sem;

void *func(void *arg){

   while ( inc < MAX_SIZE ) {
	   printf("T%d: loop inc=%d\n", 1+(int)arg -'A', inc);
	   cwait(sem);
	   if(inc>= MAX_SIZE){
		   csignal(sem);
		   break;
	   }
	   printf("*T%d: vector[%d]=%d\n", 1+(int)arg -'A', inc, (int)arg);
       vetor[inc] = (int)arg;
       inc++;
       if ( (inc % 5) == 0 ){
		   printf("%s: will call yield.\n",__FUNCTION__);
           cyield();
	   }
	   csignal(sem);
   }

   return (NULL);
}


int main(int argc, char *argv[]) {
    int i, pid[MAX_THR];

	sem=  malloc(sizeof(*sem));
	if(csem_init(sem,  1)==0){
		printf("semaforo inicializado.\n");
	}
  
    for (i = 0; i < MAX_THR; i++) {
        pid[i] = ccreate(func, (void *)('A'+i), 0);
       if ( pid[i] == -1) {
          printf("ERRO: criação de thread!\n");
          exit(-1);
       }
     }

    for (i = 0; i < MAX_THR; i++) 
         cjoin(pid[i]);

    for (i = 0; i < MAX_SIZE; i++) {    
        if ( (i % 5) == 0 )
           printf("\n");
        printf("%c", (char)vetor[i]);
    }
      
    printf("\nConcluido vetor de letras...\n");
    exit(0);
}

