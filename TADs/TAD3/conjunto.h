#ifndef CONJUNTO_H
#define CONJUNTO_H
#include <stdbool.h>

typedef struct _conjunto Conjunto;

Conjunto *criarConjunto();

void inserirElemento(Conjunto *c, int elemento);

void removerElemento(Conjunto *c, int elemento);

Conjunto *intersecao(Conjunto *c1, Conjunto *c2);

Conjunto *diferenca(Conjunto *c1, Conjunto *c2);

Conjunto *uniao(Conjunto *c1, Conjunto *c2);

int maiorValor(Conjunto *c);

int menorValor(Conjunto *c);

bool verificarIgualdade(Conjunto *c1, Conjunto *c2);

int tamanhoConjunto(Conjunto *c);

bool conjuntoVazio(Conjunto *c);

void printConjunto(Conjunto *c);

#endif