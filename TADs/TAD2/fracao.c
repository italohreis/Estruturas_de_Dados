#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "fracao.h"

struct _fracao {
    int num;
    int den;
};

Fracao *create(int x, int y) {
    Fracao *f = (Fracao *) malloc(sizeof(Fracao));

    if (f != NULL) {
        f->num = x;
        f->den = y;
    }
    return f;
}

Fracao *somaFracao(Fracao *f1, Fracao *f2) {
    int divisor = mmc(f1->den, f2->den);

    int numerador = (divisor / f1->den) * (f1->num) + (divisor / f2->den) * (f2->num);

    /* int divisor_mdc = mdc(numerador, divisor);  // Simplificando a fracao

    numerador /= divisor_mdc;   // Simplificando a fracao
    divisor /= divisor_mdc;     // Simplificando a fracao */

    return create(numerador, divisor);
}

Fracao *multiplicaFracao(Fracao *f1, Fracao *f2) {
    return create(f1->num * f2->num, f1->den * f2->den);
}

bool verificarIgualdade(Fracao *f1, Fracao *f2) {
    return (f1->num * f2->den) == (f1->den * f2->num);
}

int mmc(int a, int b){
    return a * (b / mdc(a, b));
}

int mdc(int a, int b){
    while(b != 0){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int getNumerador(Fracao *f) {
    return f->num;
}

int getDenominador(Fracao *f) {
    return f->den;
}

//funcao para simplificar fracao
void simplificar(Fracao *f){
    int divisor = mdc(f->num, f->den);
    f->num /= divisor;
    f->den /= divisor;
}



