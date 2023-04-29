#ifndef ___LISTAS___
#define ___LISTAS___

#include <stdio.h>

#define BUFFER 256

struct nol{
   char letra;
   struct chaves *chaves;
   struct nol *prox;
};

struct letras{
   int tam;
   struct nol *inicio;
};

struct noc{
   int pos;
   struct noc *prox;
};

struct chaves{
   int tam;
   struct noc *inicio;
};

struct nol *criaNol (char letra);

struct noc *criaNoc (int dado);

void adicionaCaracterOrdenado (struct letras *letras, char letra, int dado);

void adicionaChaveCabeca (struct chaves *chaves, int dado);

void adicionaChave (struct letras *letras, char letra, int dado);

int estaVazia (struct letras *letras);

struct letras *inicializaLetras (struct letras *letras);

struct chaves *inicializaChaves (struct chaves *chaves);

struct letras *destroiLetras (struct letras *letras);

struct chaves *destroiChaves (struct chaves *chaves);

int busca (struct letras *letras, char letra);

#endif //___LISTAS___