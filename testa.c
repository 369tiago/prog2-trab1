#include <stdio.h>
#include <stdlib.h>
#include "testa.h"


/*Tenta abrir o arquivo passado como argumento para leitura. Caso falhe, o programa sai com código 1 e avisa ao usuário*/
FILE *inicializaLeitura (char *arg){
    FILE *arq;
    if (!(arq = fopen (arg, "r"))){
        fprintf (stderr, "Arquivo %s inexistente\n", arg);
        exit(1);
    }
    return arq;
}

/*Tenta abrir o arquivo passado como argumento para escrita. Caso o arquivo já exista ou a abertura falhe, o programa
sai com código 1 e avisa ao usuário*/
FILE *inicializaEscrita (char *arg){
    FILE *arq;
    if ((arq = fopen (arg, "r"))){
        fprintf (stderr, "Arquivo %s já existe e não será sobreescrito\n", arg);
        exit(1);
    }
    if (!(arq = fopen (arg, "w"))){
        fprintf (stderr, "Falha ao abrir arquivo %s para escrita\n", arg);
        exit(1);
    }
    return arq;
}

/*Testa se o paramêtro já foi passado. Em caso afirmativo, imprime os usos corretos do programa e sai com código 1*/
void testaParametro (int parametro, char opcao){
    if (parametro){
        imprimeUsos();
        exit (1);
    }
}

/*Imprime os usos corretos do programa*/
void imprimeUsos (){
    fprintf (stderr, "Uso indevido, rode novamente respeitando as seguintes possibilidades:\n");
    fprintf (stderr, "./beale  -e  -b LivroCifra -m MensagemOriginal -o MensagemCodificada -c ArquivoDeChaves\n");
    fprintf (stderr, "./beale  -d  -i MensagemCodificada  -c ArquivoDeChaves  -o MensagemDecodificada\n");
    fprintf (stderr, "./beale -d -i MensagemCodificada -b LivroCifra -o MensagemDecodificada\n");
}
