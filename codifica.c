#include "codifica.h"
#include <stdlib.h>
#include <ctype.h>

/*A função abaixo recebe uma mensagem que deve ser codificada, e, a partir da lista, realiza a codificação através da seleção de chaves aleatórias
correspondentes a letra desejada. Caso a letra seja um espaço, é codificada como -1, caso não exista na lista, é codificada como -2, e caso seja uma
quebra de linha, é codificada como -3*/
void codifica (struct letras *letras,  FILE *original, FILE *codificada){
    int pos, flag = 0;
    char letra = tolower (fgetc (original));
    while (!feof(original)){
        if (letra == ' ')
            fprintf (codificada, "-1");
        else if (letra == '\n')
            fprintf (codificada, "-3");
        else{
            struct nol *aux = letras->inicio;
            while (aux->prox && aux->letra < letra)
                aux = aux->prox;
            if (aux->letra != letra){
                fprintf (codificada, "-2");
                flag = 1;
            }
            else{
                pos = rand()%(aux->chaves->tam);
                struct noc *aux1 = aux->chaves->inicio;
                for (int k=0; k<pos; k++)
                    aux1 = aux1->prox;
                fprintf (codificada, "%d", aux1->pos);
            }
        }
        if (!feof(original))
            fprintf (codificada, " ");
        letra = tolower (fgetc (original));
    }
    if (flag)
        fprintf (stderr, "Há caracteres que não estão no arquivo de chaves. A codificação dessa mensagem não sera tão precisa quanto o ideal");
}
