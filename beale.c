#include "liblde.h"
#include "codifica.h"
#include "decodifica.h"
#include "chaves.h"
#include "testa.h"
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <getopt.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    char *msgCod, *livroCifra, *arquivoChaves, *msgOrig, *msgDecod;
    int comando = 0, codificar = 0, argLivro = 0, argChaves = 0, decodificar = 0, argOrig = 0, argCod = 0, argDecod = 0;
    srand(time(NULL));

    while ((comando = getopt(argc, argv, "edi:b:m:o:c:")) != -1)
        switch (comando){
            case 'e':
                testaParametro (codificar, 'e');
                codificar = 1;
            break;
            case 'd':
                testaParametro (decodificar, 'd');
                decodificar = 1;
            break;
            case 'i':
                testaParametro (argCod, 'i');
                argCod = 1;
                msgCod = optarg;
            break;
            case 'b':
                testaParametro (argLivro, 'b');
                argLivro = 1;
                livroCifra = optarg;
            break;
            case 'm':
                testaParametro (argOrig, 'm');
                argOrig = 1;
                msgOrig = optarg;
            break;
            case 'o':
                testaParametro (argDecod, 'o');
                argDecod = 1;
                msgDecod = optarg;
            break;
            case 'c':
                if (argChaves){
                    perror ("Paramêtro -o repetido, rode novamente");
                    exit (1);
                }
                argChaves = 1;
                arquivoChaves = optarg;
            break;
            default:
                perror ("Uso indevido!");
                exit(1);
        }

    struct letras *letras = NULL;
    letras = inicializaLetras (letras);

    if (codificar == decodificar){
        perror ("Argumentos inválidos, uso indevido!");
        exit (1);
    }
    else if (codificar){
        FILE *livro = NULL, *original = NULL, *codificada = NULL, *chaves = NULL;
        livro = inicializaLeitura (livroCifra);
        original = inicializaLeitura (msgOrig);
        codificada = inicializaEscrita (msgDecod);
        chaves = inicializaEscrita (arquivoChaves);
        criaListaLivro (livro, letras);
        codifica (letras, original, codificada);
        imprimeLetras (letras, chaves);
        fclose (livro);
        fclose (original);
        fclose (codificada);
        fclose (chaves);
    }
    else if (decodificar){
        if (argLivro){
            FILE *livro = NULL, *codificada = NULL, *decodificada = NULL;
            livro = inicializaLeitura (livroCifra);
            codificada = inicializaLeitura (msgCod);
            decodificada = inicializaEscrita (msgDecod);
            criaListaLivro (livro, letras);
            decodifica (letras, codificada, decodificada);
            fclose (livro);
            fclose (codificada);
            fclose (decodificada);
        }
        else if (argChaves){
            FILE *chaves = NULL, *codificada = NULL, *decodificada = NULL;
            chaves = inicializaLeitura (arquivoChaves);
            codificada = inicializaLeitura (msgCod);
            decodificada = inicializaEscrita (msgDecod);
            criaListaArquivo (chaves, letras);
            decodifica (letras, codificada, decodificada);
            fclose (chaves);
            fclose (codificada);
            fclose (decodificada);
        }
        else{
            perror ("Algo deu errado");
            exit (1);
        }
    }
    letras = destroiLetras (letras);
    return 0;
}
