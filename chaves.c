#include "chaves.h"
#include <stdlib.h>
#include <ctype.h>


/*A função abaixo recebe um livro-cifra e a partir dele gera as cifras. A função pega cada palavra do livro através do fscanf,
e manda a primeira letra da palavra junto com um contador para a função responsável por adicionar elementos na lista. Caso a primeira letra
da palavra não seja ASCII, é ignorada*/
void criaListaLivro (FILE *livro, struct letras *letras){
    char *palavra = malloc (sizeof(char) * BUFFER);
    int pos = 0;
    while (fscanf (livro, "%s", palavra) == 1){
        if (palavra[0] > 0)
            insereLista (letras, palavra[0], pos++);
    }
    free (palavra);
}

/*A função abaixo itera pela lista uma vez, imprimindo as letras e suas respectivas chaves na ordem em que estão inseridas.*/
void imprimeLetras (struct letras *letras, FILE *chaves){
    struct nol *aux;
    struct noc *aux1;
    aux = letras->inicio;
    while (aux){
        fprintf (chaves, "%c:", aux->letra);
        aux1 = aux->chaves->inicio;
        while (aux1){
            fprintf (chaves, " %d", aux1->pos);
            aux1 = aux1->prox;
        }
        fprintf (chaves, "\n");
        aux = aux->prox;
    }
}

/*A função abaixo recebe um arquivo de chaves pré-existente, e extrai suas informações para dentro da lista, tornando-as mais fáceis
de manipular para as funções de codificar e decodificar.*/
void criaListaArquivo (FILE *chaves, struct letras *letras){
    int chave;
    char letra, aux;
    while(fscanf(chaves, "%c:", &letra) != EOF){
        aux = fgetc (chaves); //Pega os espaços entre as chaves, e na troca de letras, pega a quebra de linha
        while (aux != '\n'){
            fscanf (chaves, "%d", &chave);
            aux = fgetc(chaves);
            insereLista(letras, letra, chave);
        }
    }
}