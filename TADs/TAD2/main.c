#include <stdio.h>
#include "fracao.h"

int main() {

    Fracao *f1 = create(2, 4);
    Fracao *f2 = create(2, 4);

    Fracao *f3 = somaFracao(f1, f2);
    simplificar(f3);

    printf("\nResultado da soma: %d/%d\n", getNumerador(f3), getDenominador(f3));

    Fracao *resultado_multiplicacao = multiplicaFracao(f1, f2);
    simplificar(resultado_multiplicacao);

    printf("\nResultado da multiplicacao: %d/%d\n", getNumerador(resultado_multiplicacao), getDenominador(resultado_multiplicacao));

    printf("\nVerificar igualdade: %s\n", verificarIgualdade(f1, f2) ? "Sao Iguais" : "Nao sao iguais");


    return 0;
}