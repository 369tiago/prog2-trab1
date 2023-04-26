#include <stdio.h>
#include <stdlib.h>
#include "testa.h"

FILE *inicializaLeitura (char *arg){
    FILE *arq;
    if (!(arq = fopen (arg, "r"))){
        perror ("Arquivo inexistente!");
        exit(1);
    }
    return arq;
}

void testaParametro (int parametro, char opcao){
    if (parametro){
        fprintf (stderr, "Paramêtro -%c repetido, rode novamente", opcao);
        exit (1);
    }
}

FILE *inicializaEscrita (char *arg){
    FILE *arq;
    if ((arq = fopen (arg, "r"))){
        perror ("Arquivo já existe!");
        exit(1);
    }
    if (!(arq = fopen (arg, "w"))){
        perror ("Falha ao criar arquivo!");
        exit(1);
    }
    return arq;
}