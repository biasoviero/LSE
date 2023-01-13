#ifndef LSE_H_INCLUDED
#define LSE_H_INCLUDED

typedef struct tipoNo ptLSE;

struct tipoNo{
    int numero;
    ptLSE *prox;
};

//Função que inicializa uma lista vazia
ptLSE* criaLista();

//Função que imprime a lista
void imprime(ptLSE *lista);

//Função que insere o número dado na próxima posição vazia da lista
ptLSE* insereFim(ptLSE *lista, int num);

//Função que insere o número dado na primeira posição da lista
ptLSE* insereInicio(ptLSE *lista, int num);

//Função que destrói a lista dada
ptLSE* destroi(ptLSE *lista);

//Dados um número e uma lista, retorna a posição desse número na lista
void procuraNum(ptLSE *lista, int num);

/*
Dados um número e uma lista, se a lista for vazia insere esse número.
Senão, se o num estiver na lista, insere num - 1 na posição anterior e num + 1 na posição sucessora
Se o número não estiver na lista, remove o primeiro e último elementos
*/
ptLSE* insere(ptLSE *lista, int num);

//Dados um número e uma lista, remove esse número da lista
ptLSE* removeNum(ptLSE *lista, int num);

#endif // LSE_H_INCLUDED

