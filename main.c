#include "lse.h"
#include <stdlib.h>
#include <stdio.h>

int main(){

    ptLSE *l;
    l = criaLista();

    int n, r;
    imprime(l);

    do{
        printf("Lista Simples Encadeada\n");

        printf("0 - Encerrar o programa\n");
        printf("1 - Inserir numero no inicio da lista\n");
        printf("2 - Inserir numero no fim da lista\n");
        printf("3 - Procurar numero na lista\n");
        printf("4 - Remover numero da lista\n");
        printf("5 - Funcaoo insere() na lista\n");
        printf("6 - Imprime lista\n");
        printf("Escolha a opcao desejada:\n");
        scanf("%d", &r);

        switch(r){
        case 1:
            printf("Informe um numero: ");
            scanf("%d", &n);
            l = insereInicio(l, n);
            imprime(l);
            break;
        case 2:
            printf("Informe um numero: ");
            scanf("%d", &n);
            l = insereFim(l, n);
            imprime(l);
            break;
        case 3:
            printf("Informe um numero: ");
            scanf("%d", &n);
            procuraNum(l, n);
            break;
        case 4:
            printf("Informe um numero: ");
            scanf("%d", &n);
            l = removeNum(l, n);
            imprime(l);
            break;
        case 5:
            printf("Informe um numero: ");
            scanf("%d", &n);
            l = insere(l, n);
            imprime(l);
            break;
        case 6:
            imprime(l);
            break;
        }

    }while (r != 0);
    l = destroi(l);
    imprime(l);

    return 0;
}
