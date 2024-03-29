#include <stdbool.h>
#ifndef FRACAO_H
#define FRACAO_H

typedef struct _fracao Fracao;

Fracao *create(int num, int den);

Fracao *somaFracao(Fracao *f1, Fracao *f2);

Fracao *multiplicaFracao(Fracao *f1, Fracao *f2);

bool verificarIgualdade(Fracao *f1, Fracao *f2);

int mmc(int a, int b);

int mdc(int a, int b);

int getNumerador(Fracao *f);

int getDenominador(Fracao *f);

void simplificar(Fracao *f);

#endif
