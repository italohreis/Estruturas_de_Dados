#ifndef FRACAO_H
#define FRACAO_H

typedef struct _fracao Fracao;

Fracao *create(int num, int den);

float somaFracao(Fracao *f1, Fracao *f2);

float multiplicaFracao(Fracao *f1, Fracao *f2);

void verificarIgualdade(Fracao *f1, Fracao *f2);

#endif
