#include <stdio.h>
#include <stdlib.h>
#include "conjunto.h"

int main() {

    Conjunto *c1 = criarConjunto();

    inserirElemento(c1, 1);
    inserirElemento(c1, 2);
    inserirElemento(c1, 3);
    inserirElemento(c1, 4);

    Conjunto *c2 = criarConjunto();

    inserirElemento(c2, 3);
    inserirElemento(c2, 4);
    inserirElemento(c2, 5);
    inserirElemento(c2, 6);

    Conjunto *c3 = diferenca(c1, c2);

    printConjunto(c3);


    return 0;
}