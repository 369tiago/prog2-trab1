# prog2-trab1

Nome: Tiago Mendes Bottamedi GRR 20220068

Estruturas de dados utilizadas: 
  A estrutura utilizada foi uma lista de listas, em que cada nodo lista de caracteres contém a cabeça de uma lista de posições. As cabeças das listas contêm o tamanho da lista e um ponteiro para o primeiro nodo. Os nodos contêm o elemento (a letra ou a posição) e um ponteiro para o próximo nodo.


Módulos e algoritmos:
  As funções foram divididos em 5 bibliotecas:
    - listas.h: Contém as funções que manipulam as listas de maneira geral, ou seja, contém as funções de inicialização das listas, de criação de nodos, de destruição das listas e os algoritmos de inserção ordenada e na cabeça. Caso haja alguma falha de alocação de memória dentro das funções, o programa sai com código 1 e avisa ao usuário que houve falha na alocação dentro dessa biblioteca. Como essa biblioteca também contém as estruturas que sâo utilizadas no resto do programa, ela é incluída nos demais .h.
    - chaves.h: Contém as funções que manipulam as listas de maneira específica, dependendo de outros arquivos. Contém duas funções que geram a lista de chaves (usando como base as funções da listas.h), uma a partir de um livro cifra, e outra a partir de um arquivo de chaves. Além disso, possui uma função que imprime a lista formatada dentro de um arquivo de chaves.
     -codifica.h: Contém a função que codifica uma mensagem recebida através de um arquivo, utilizando a lista criada por uma das funções da chaves.h. A função verifica, caracter por caracter, se ele existe na lista de chaves. Caso exista, uma posição aleatória pertencente a esse caracter é escolhida e inserida no arquivo da mensagem codificada. Caso seja um espaço é inserido -1, se for uma quebra de linha é inserido -3. Caso não exista, é inserido -2 e uma mensagem aparece para o usuário avisando que havia caracteres que não estavam na lista.
     -decodifica.h: Contém a função que decodifica uma mensagem recebida através de um arquivo, utilizando a lista criada por uma das funções da chaves.h. A função verifica, número por número, a qual caracter ele pertence, e então insere o caracter correspondente no arquivo da mensagem decodificada. Nos casos -1 e -3, são inseridos um espaço e uma quebra de linha, respectivamente. No caso -2, é inserido um ponto de interrogação(?) e o usuário é avisado de que certos caracteres não estavam na lista.
     -testa.h: Contém as funções que lidam com erros que podem acontecer no main. As funções testam a abertura de arquivos, tanto para leitura quanto para escrita, e também se um paramêtro já foi passado na execução do programa. Em qualquer caso de falha, o programa sai com código 1 e avisa o usuário sobre o problema ocorrido.
