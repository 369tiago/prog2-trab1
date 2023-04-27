#include <stdio.h>
#include <stdlib.h>
#include "testa.h"

FILE *inicializaLeitura (char *arg){
    FILE *arq;
    if (!(arq = fopen (arg, "r"))){
        fprintf (stderr, "Arquivo %s inexistente", arg)
        exit(1);
    }
    return arq;
}

void testaParametro (int parametro, char opcao){
    if (parametro){
        imprimeUsos();
        exit (1);
    }
}

FILE *inicializaEscrita (char *arg){
    FILE *arq;
    if ((arq = fopen (arg, "r"))){
        fprintf (stderr, "Arquivo %s já existe e não será sobreescrito", arg);
        exit(1);
    }
    if (!(arq = fopen (arg, "w"))){
        fprintf (stderr, "Falha ao abrir arquivo %s para escrita", arg);
        exit(1);
    }
    return arq;
}

void imprimeUsos (){
    fprintf (stderr, "Uso indevido, rode novamente respeitando as seguintes possibilidades:\n");
    fprintf (stderr, "./beale  -e  -b LivroCifra -m MensagemOriginal -o MensagemCodificada -c ArquivoDeChaves\n");
    fprintf (stderr, "./beale  -d  -i MensagemCodificada  -c ArquivoDeChaves  -o MensagemDecodificada\n");
    fprintf (stderr, "./beale -d -i MensagemCodificada -b LivroCifra -o MensagemDecodificada\n");
}
