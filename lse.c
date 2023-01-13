#include "lse.h"
#include <stdio.h>
#include <stdlib.h>

ptLSE* criaLista(){
    return NULL;
}

void imprime(ptLSE *lista){

    ptLSE *aux = lista;

    printf("Imprimindo lista\n");

    //Caso em que a lista é vazia
    if(lista == NULL)
        printf("Lista vazia\n");

    else{

        //Percorre toda a lista
        while(aux != NULL){

            //Imprime o número
            printf("%d ", aux->numero);
            aux = aux->prox;
        }
        printf("\n");
    }
}

ptLSE* insereFim(ptLSE *lista, int num){
    ptLSE *aux = lista;
    ptLSE *novo;

    //Aloca novo nodo
    novo = (ptLSE*)malloc(sizeof(ptLSE));

    //Atualiza o número do novo nodo
    novo->numero = num;

    //Caso em que a lista é vazia o primeiro elemento é o novo nodo
    if (lista == NULL){
        novo->prox = lista;
        lista = novo;
    }

    //Caso não seja vazia
    else{

        //É percorrida a lista até o final
        while (aux->prox != NULL)
            aux = aux->prox;

        //Último nodo recebe o novo
        aux->prox = novo;
        novo->prox = NULL;
    }

    return lista;
}

ptLSE* insereInicio(ptLSE *lista, int num){
    ptLSE *novo = (ptLSE*)malloc(sizeof(ptLSE*));
    novo->numero = num;

    novo->prox = lista;
    lista = novo;

    return lista;
}

ptLSE* destroi(ptLSE *lista){
    ptLSE *aux;

    printf("Destruindo a lista\n");

    while (lista != NULL){
        aux = lista;
        lista = lista->prox;
        free(aux);
    }
    free(lista);
    return NULL;
}

void procuraNum(ptLSE *lista, int num){
    ptLSE *aux = lista; //ponteiro aux para percorrer a lista
    int p = 1; //contador de posições

    if(lista == NULL){
        printf("Lista vazia\n");
        return;
    }

    while (aux != NULL){
        if (aux->numero == num){
            printf("O numero %d se encontra na posicao %d da lista\n", num, p);
            return;
        }
        aux = aux->prox;
        p++;
    }

    printf("O numero %d nao esta na lista\n", num);
}

ptLSE* insere(ptLSE *lista, int num){

    ptLSE *aux = lista; //ponteiro auxiliar e também o último
    ptLSE *ant = NULL; //ponteiro que aponta para o elemento anterior ao aux
    ptLSE *novoA, *novoB, *novo;
    /*
    novo = nodo que será inserido quando a lista é vazia
    nodoA = num - 1
    nodoB = num + 1
    */

    //Aloca os novos nodos
    novo = (ptLSE*) malloc(sizeof(ptLSE));
    novo->numero = num;
    novoA = (ptLSE*) malloc(sizeof(ptLSE));
    novoA->numero = num - 1;
    novoB = (ptLSE*) malloc(sizeof(ptLSE));
    novoB->numero = num + 1;

    //Percorre toda a lista ou até encontrar o número dado
    while(aux != NULL){
        if (aux->numero == num){

            //Caso em que o número pedido é o primeiro elemento
            if (ant == NULL){

               //num + 1 é inserido antes do resto da lista
               novoB->prox = aux->prox;

               //num - 1 é inserido antes de num
               novoA->prox = aux;
               lista->prox = novoA;
               lista = lista->prox;

               //num + 1 é inserido após a posição atual da lista
               aux->prox = novoB;
            }

            else{
                //num + 1 é inserido antes do resto da lista
                novoB->prox = aux->prox;

                //num - 1 é inserido antes de num
                novoA->prox = aux;
                ant->prox = novoA;

                //num + 1 é inserido após a posição atual da lista
                aux->prox  = novoB;
            }
            return lista;
        }

            ant = aux;
            aux = aux->prox;
    }

    //Se o anterior é nulo, o num é inserido na primeira posição
    if (ant == NULL){
        novo->prox = lista;
        lista = novo;
    }



    //Caso em que o número não está na lista
    else{

        //Caso em que há apenas 2 elementos na lista
        if(lista->prox == ant){
            lista = NULL;
            return lista;
        }

        //Caso em que há só um elemento retorna a lista inalterada
        else if(lista == ant)
            return lista;

        //É removido o primeiro elemento da lista
        lista = lista->prox;

        //É removido o último elemento da lista
        aux = lista;
        ant = NULL;
        while(aux->prox != NULL){
            ant = aux;
            aux = aux->prox;
        }

        ant->prox = NULL;

    }

    return lista;
}

ptLSE* removeNum(ptLSE *lista, int num){
    ptLSE *novo = (ptLSE*)malloc(sizeof(ptLSE));
    novo->numero = num;
    ptLSE *aux = lista; //ponteiro que percorre a lista
    ptLSE *ant = NULL; // ponteiro anterior ao atual


    if(lista == NULL){
        printf("Lista vazia\n");
        return lista;
    }

    printf("Removendo o numero %d da lista...\n", num);

    while(aux != NULL){
        //Caso o número esteja na lista
        if (aux->numero == num){

            //Caso seja o primeiro da lista
            if(ant == NULL){
                lista = lista->prox;
            }

            else{
                ant->prox = aux->prox;
                aux->prox = ant;
            }
            return lista;
        }
        ant = aux;
        aux = aux->prox;
    }

    printf("O numero %d nao esta na lista\n", num);
    return lista;
}
