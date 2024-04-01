#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "conjunto.h"

#define MAX_SIZE 100

typedef struct _conjunto{
    int elementos[MAX_SIZE];
    int size;
} Conjunto;

Conjunto *criarConjunto() {
    Conjunto *c = (Conjunto *) malloc(sizeof(Conjunto));
    c->size = 0;
    return c;
}

void inserirElemento(Conjunto *c, int elemento) {
    int i;
    for (i = 0; i < c->size; i++) {
        if (c->elementos[i] == elemento) {
            printf("\nElemento [%d] ja existente no conjunto!\n", elemento);
            return;
        }
    }

    c->elementos[c->size++] = elemento;
}

void removerElemento(Conjunto *c, int elemento) {
    int i;
    for (i = 0; i < c->size; i++) {
        if (c->elementos[i] == elemento) {
            c->elementos[i] = c->elementos[c->size - 1];    // Substitui o elemento a ser removido pelo ultimo elemento do conjunto
            c->size--;  //remove um elemento do conjunto
            printf("\nElemento Removido!\n");
            return;
        }
    }

    printf("\nElemento nao encontrado no conjunto!\n"); //caso o elemento nao seja encontrado no laço de repetição
}

Conjunto *intersecao(Conjunto *c1, Conjunto *c2) {
    Conjunto *c = criarConjunto();
    int i, j;

    for (i = 0; i < c1->size; i++) {
        for (j = 0; j < c2->size; j++) {
            if (c1->elementos[i] == c2->elementos[j]) {     //verifica se o elemento do conjunto 1 é igual ao elemento do conjunto 2 (interseção)
                inserirElemento(c, c1->elementos[i]);
            }
        }
    }

    return c;
}

Conjunto *diferenca(Conjunto *c1, Conjunto *c2) {
    Conjunto *c = criarConjunto();
    int i, j;

    for (i = 0; i < c1->size; i++) {
        for (j = 0; j < c2->size; j++) {
            if (c1->elementos[i] == c2->elementos[j]) {
                break;
            }
        }

        if (j == c2->size) {        //se o elemento do conjunto 1 não estiver presente no conjunto 2, ele é adicionado ao conjunto c
            inserirElemento(c, c1->elementos[i]);   //adiciona o elemento que está presente em c1 e não em c2
        }
    } 

    return c;
}

Conjunto *uniao(Conjunto *c1, Conjunto *c2) {
    Conjunto *c = criarConjunto();

    int i;
    for (i = 0; i < c1->size; i++) {
        inserirElemento(c, c1->elementos[i]);   //adiciona todos os elementos do conjunto 1 ao conjunto c
    }

    for (i = 0; i < c2->size; i++) {
        inserirElemento(c, c2->elementos[i]);   //adiciona todos os elementos do conjunto 2 ao conjunto c
    }
   

    return c;
}

int maiorValor(Conjunto *c) {
    int maior = 0;
    int i;
    for (i = 0; i < c->size; i++) {
        if (c->elementos[i] > maior) {
            maior = c->elementos[i];
        }
    }

    return maior;
}

int menorValor(Conjunto *c) {
    int menor = c->elementos[0];
    int i;

    for (i = 1; i < c->size; i++) {
        if (c->elementos[i] < menor) {
            menor = c->elementos[i];
        }
    }
    
    return menor;
}

bool verificarIgualdade(Conjunto *c1, Conjunto *c2) {
    if (c1->size != c2->size) {
        return false;
    }

    bool igualdade = false;
    int i, j;

    for (i = 0; i < c1->size; i++) {
        for (j = 0; j < c2->size; j++) {

            if (c1->elementos[i] == c2->elementos[j]) {
                igualdade = true;
                break;
            } else {
                igualdade = false;
            }

        }
        if (igualdade == false) {
            return false;
        }
    }

    return true;
}

int tamanhoConjunto(Conjunto *c) {
    return c->size;
}

bool conjuntoVazio(Conjunto *c) {
    return c->size == 0;    //retorna verdadeiro se o conjunto estiver vazio, caso contrario retorna falso
}

void printConjunto(Conjunto *c) {
    int i;
    printf("\nConjunto: {");
    for (i = 0; i < c->size; i++) {
        printf("%d", c->elementos[i]);
        if (i < c->size - 1) {
            printf(", ");
        }
    }
    printf("}\n");
}

