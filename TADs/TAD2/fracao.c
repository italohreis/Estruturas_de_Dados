#include <stdlib.h>
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

float somaFracao(Fracao *f1, Fracao *f2) {
    int divisor = mmc(f1->den, f2->den);

    int numerador = (divisor / f1->den) * (f1->num) + (divisor / f2->den) * (f2->num);
    
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