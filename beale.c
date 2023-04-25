#include "liblde.h"
#include "codifica.h"
#include "decodifica.h"
#include "chaves.h"
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <getopt.h>
#include <stdlib.h>

FILE *inicializaLeitura (FILE *arquivo, char *arg){
    FILE *arq;
    if (!(arq = fopen (arg, "r"))){
        perror ("Arquivo inexistente!");
        exit(1);
    }
    return arq;
}

FILE *inicializaEscrita (FILE *arquivo, char *arg){
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

int main(int argc, char *argv[]){
    char *argi, *argb, *arg_c, *argm, *argo;
    int comando, cmde, cmdb, cmdd;
    srand(time(NULL));
    while ((comando = getopt(argc, argv, "edi:b:m:o:c:")) != -1)
        switch (comando){
            case 'e':
                cmde = 1;
            break;
            case 'd':
                cmdd= 1;
            break;
            case 'i':
                argi = optarg;
            break;
            case 'b':
                cmdb= 1;
                argb = optarg;
            break;
            case 'm':
                argm = optarg;
            break;
            case 'o':
                argo = optarg;
            break;
            case 'c':
                arg_c = optarg;
            break;
            default:
                perror ("Uso indevido!");
                exit(1);
        }
    struct letras *letras = NULL;
    letras = inicializaLetras (letras);
    if (cmde == 1){
        FILE *livro = NULL, *original = NULL, *codificada = NULL, *chaves = NULL;
        livro = inicializaLeitura (livro, argb);
        original = inicializaLeitura (original, argm);
        codificada = inicializaEscrita (codificada, argo);
        chaves = inicializaEscrita (chaves, arg_c);
        criaListaLivro (livro, letras);
        codifica (letras, original, codificada);
        imprimeLetras (letras, chaves);
        fclose (livro);
        fclose (original);
        fclose (codificada);
        fclose (chaves);
    }
    else if (cmdd == 1){
        if (cmdb == 1){
            FILE *livro = NULL, *codificada = NULL, *decodificada = NULL;
            livro = inicializaLeitura (livro, argb);
            codificada = inicializaLeitura (codificada, argi);
            decodificada = inicializaEscrita (decodificada, argo);
            criaListaLivro (livro, letras);
            decodifica (letras, codificada, decodificada);
            fclose (livro);
            fclose (codificada);
            fclose (decodificada);
        }
        else{
            FILE *chaves = NULL, *codificada = NULL, *decodificada = NULL;
            chaves = inicializaLeitura (chaves, arg_c);
            codificada = inicializaLeitura (codificada, argi);
            decodificada = inicializaEscrita (decodificada, argo);
            criaListaArquivo (chaves, letras);
            decodifica (letras, codificada, decodificada);
            fclose (chaves);
            fclose (codificada);
            fclose (decodificada);
        }
    }
    letras = destroiLetras (letras);
    return 0;
}
