#include "listas.h"
#include <ctype.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

/*A função abaixo retorna um nó para a lista de letras, preenchido com um caractere passado como paramêtro. Caso a alocação falhe, retorna NULL*/
struct nol *criaNol (char letra){
    struct nol *l;
    l = malloc(sizeof (struct nol));
    if (!l)
        return NULL;
    l->letra = letra;
    l->prox = NULL;
    return l;
}

/*A função abaixo retorna um nó para a lista de cahves, preenchido com uma chave passado como paramêtro. Caso a alocação falhe, retorna NULL*/
struct noc *criaNoc (int dado){
    struct noc *c;
    c = malloc(sizeof (struct noc));
    if (!c)
        return NULL;
    c->pos = dado;
    c->prox = NULL;
    return c;
}

/*A função abaixo recebe um caractere e a sua chave, e faz a inserção ordenada. Caso o caractere já exista na lista, somente sua chave é adicionada através
da função adicionaChaveCabeca. Caso contrário, o caractere é adicionado na lista em ordem crescente, e a função adicionaChaveCabeca é chamada para sua chave*/
void adicionaCaracterOrdenado (struct letras *letras, char letra, int dado){
    struct nol *aux, *novo;
    novo = criaNol(letra);
    if (!novo){
        fprintf (stderr, "Falha ao alocar novo nó (liblde.c)\n");
        exit (1);
    }
    else{
        if (estaVazia(letras)){ //Caso em que a lista está vazia
            letras->inicio = novo;
            letras->inicio->chaves = inicializaChaves (letras->inicio->chaves);
            adicionaChaveCabeca (letras->inicio->chaves, dado);
        }
        else if (novo->letra < letras->inicio->letra){ //Caso em que o caractere a ser adicionado é "menor" que o primeiro da lista
            novo->prox = letras->inicio;
            letras->inicio = novo;
            letras->inicio->chaves = inicializaChaves (letras->inicio->chaves);
            adicionaChaveCabeca (letras->inicio->chaves, dado); 
        }
        else{ //Demais casos
            aux = letras->inicio;
            while (aux->prox && aux->prox->letra < novo->letra)
                aux = aux->prox;
            novo->prox = aux->prox;
            aux->prox = novo;
            novo->chaves = inicializaChaves (novo->chaves);
            adicionaChaveCabeca (novo->chaves, dado);
        }
        letras->tam++;
    }
}

/*A função abaixo é chamada pela adicionaCaracterOrdenado para que a chave seja adicionada na lista de chaves correspondente ao seu caractere. A função, como
o próprio nome diz, sempre insere a chave no começo da lista*/
void adicionaChaveCabeca (struct chaves *chaves, int dado){
    struct noc* novo;
    novo = criaNoc(dado);
    if (!novo){
        fprintf (stderr, "Falha ao alocar novo nó (liblde.c)\n");
        exit (1);
    }
    else{
        if (!chaves->tam){
            chaves->inicio = novo;
        }
        else{
            novo->prox = chaves->inicio;
            chaves->inicio = novo;
        }
        chaves->tam++;
    }
}

void adicionaChave (struct letras *letras, char letra, int dado){
    struct nol *aux = letras->inicio;
    letra = tolower (letra);
    while (aux && aux->letra < letra)
        aux = aux->prox;
    if (!aux || aux->letra != letra)
        adicionaCaracterOrdenado (letras, letra, dado);
    else
        adicionaChaveCabeca (aux->chaves, dado);
}

/*Verifica se a lista está vazia e retorna 1 caso esteja, e 0 em caso contrário*/
int estaVazia (struct letras *letras){
    if (!letras->tam)
        return 1;
    return 0;
}

/*Realiza o malloc e inicializa as váriaveis da struct. Caso o malloc falhe, o programa sai com código de erro*/
struct letras *inicializaLetras (struct letras *letras){
    struct letras *letras_aux;
    letras_aux = malloc (sizeof (struct letras));
    if (!letras_aux){
        fprintf (stderr, "Falha ao inicializar lista de caracteres (liblde.c)\n");
        exit (1);
    }
    letras_aux->tam = 0;
    letras_aux->inicio = NULL;
    return letras_aux;
}

struct chaves *inicializaChaves (struct chaves *chaves){
    struct chaves *chaves_aux;
    chaves_aux = malloc (sizeof (struct chaves));
    if (!chaves_aux){
        fprintf (stderr, "Falha ao inicializar lista de chaves (liblde.c)\n");
        exit (1);
    }
    chaves_aux->tam = 0;
    chaves_aux->inicio = NULL;
    return chaves_aux;
}

/*A função abaixo itera através da lista de caracteres, destruindo cada nó e sua respectiva lista de chaves e variáveis, através da função destroiChaves*/
struct letras *destroiLetras (struct letras *letras){
    struct nol *aux;
    while (letras->inicio){
        aux = letras->inicio;
        aux->chaves = destroiChaves (aux->chaves);
        letras->inicio = letras->inicio->prox;
        aux->letra = '\0';
        free (aux);
        aux = NULL;
    }
    letras->tam = 0;
    free (letras);
    return NULL;
}

/*A função abaixo itera através da lista de chaves, destruindo cada nó e resetando suas variáveis*/
struct chaves *destroiChaves (struct chaves *chaves){
    struct noc *aux;
    while (chaves->inicio){
        aux = chaves->inicio;
        chaves->inicio = chaves->inicio->prox;
        aux->pos = 0;
        free (aux);
        aux = NULL;
    }
    chaves->tam = 0;
    free (chaves);
    return NULL;
}
