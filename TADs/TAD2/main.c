#include <stdio.h>
#include "fracao.h"

int main() {

    Fracao *f1 = create(1, 2);
    Fracao *f2 = create(1, 2);

    Fracao *f3 = somaFracao(f1, f2);

    printf("\nResultado da soma: %d/%d\n", getNumerador(f3), getDenominador(f3));

    Fracao *resultado_multiplicacao = multiplicaFracao(f1, f2);

    printf("\nResultado da multiplicacao: %d/%d\n", getNumerador(resultado_multiplicacao), getDenominador(resultado_multiplicacao));

    printf("\nVerificar igualdade: %s\n", verificarIgualdade(f1, f2) ? "Sao Iguais" : "Nao sao iguais");


    return 0;
}