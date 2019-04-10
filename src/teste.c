#include "../include/teste.h"

void testa_cidentify(void){
    char name[40];
    int a = cidentify(name,sizeof(name));
    puts(name);
}
