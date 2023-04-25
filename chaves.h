#ifndef ___CHAVES___
#define ___CHAVES___

#include <stdio.h>
#include "liblde.h"

void criaListaLivro (FILE *livro, struct letras *letras);

void imprimeLetras (struct letras *letras, FILE *chaves);

void criaListaArquivo (FILE *chaves, struct letras *letras);

#endif //___CHAVES__