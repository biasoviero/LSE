#ifndef LSE_H_INCLUDED
#define LSE_H_INCLUDED

typedef struct tipoNo ptLSE;

struct tipoNo{
    int numero;
    ptLSE *prox;
};

//Fun��o que inicializa uma lista vazia
ptLSE* criaLista();

//Fun��o que imprime a lista
void imprime(ptLSE *lista);

//Fun��o que insere o n�mero dado na pr�xima posi��o vazia da lista
ptLSE* insereFim(ptLSE *lista, int num);

//Fun��o que insere o n�mero dado na primeira posi��o da lista
ptLSE* insereInicio(ptLSE *lista, int num);

//Fun��o que destr�i a lista dada
ptLSE* destroi(ptLSE *lista);

//Dados um n�mero e uma lista, retorna a posi��o desse n�mero na lista
void procuraNum(ptLSE *lista, int num);

/*
Dados um n�mero e uma lista, se a lista for vazia insere esse n�mero.
Sen�o, se o num estiver na lista, insere num - 1 na posi��o anterior e num + 1 na posi��o sucessora
Se o n�mero n�o estiver na lista, remove o primeiro e �ltimo elementos
*/
ptLSE* insere(ptLSE *lista, int num);

//Dados um n�mero e uma lista, remove esse n�mero da lista
ptLSE* removeNum(ptLSE *lista, int num);

#endif // LSE_H_INCLUDED

