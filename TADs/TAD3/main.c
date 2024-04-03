#include <stdio.h>
#include <stdlib.h>
#include "conjunto.h"

int main() {

    Conjunto *c1 = criarConjunto();

    /* inserirElemento(c1, 1);
    inserirElemento(c1, 2);
    inserirElemento(c1, 3);
    inserirElemento(c1, 4); */

    Conjunto *c2 = criarConjunto();

    inserirElemento(c2, 5);
    inserirElemento(c2, 3);
    inserirElemento(c2, 7);
    inserirElemento(c2, 4);

    //maior valor
    printf("O maior valor do conjunto c2 e: %d\n", maiorValor(c2));

    //menor valor
    printf("O menor valor do conjunto c2 e: %d\n", menorValor(c2));

    printf("O conjunto c1 e vazio ? --> %s", conjuntoVazio(c1) ? "Conjunto vazio" : "Conjunto nao vazio");

    printf("\nos conjuntos sao iguais ? --> %s", verificarIgualdade(c1, c2) ? "sao iguais" : "nao sao iguais");



    return 0;
}