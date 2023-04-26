#include "decodifica.h"
#include <stdlib.h>

/*A função abaixo utiliza a lista para decodificar uma mensagem. Essa função itera através da lista em busca do número presente na mensagem codificada.
Caso o encontre, substitui pelo caracter correspondente, senão, pula o caractere*/
void decodifica (struct letras *letras, FILE *codificada, FILE *decodificada){
    struct nol *aux;
    struct noc *aux1;
    int valor;
    aux = letras->inicio;
    if (fscanf (codificada, "%d", &valor) == EOF)
        return;
    while (aux && valor){
        switch (valor){
            case -1:
                fprintf (decodificada," ");
                if (fscanf (codificada, "%d", &valor) == EOF)
                    return;
            break;
            case -2:
                fprintf (decodificada, "?");
                if (fscanf (codificada, "%d", &valor) == EOF)
                    return;
            break;
            case -3:
                fprintf (decodificada, "\n");
                if (fscanf (codificada, "%d", &valor) == EOF)
                    return;
            break;
            default:
                aux1 = aux->chaves->inicio;
                while (aux1->prox && aux1->pos != valor){
                    aux1 = aux1->prox;
                }
                if (aux1->pos == valor){
                    fprintf (decodificada, "%c", aux->letra);
                    aux = letras->inicio;
                    if (fscanf (codificada, "%d", &valor) == EOF)
                        return;
                }
                else
                    aux = aux->prox;
            break;
        }
    }
}