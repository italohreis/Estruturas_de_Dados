#include <stdbool.h>
#ifndef FRACAO_H
#define FRACAO_H

typedef struct _fracao Fracao;

/**
 * Cria instância de Fracao.
 * @param num Numerador da fracao.
 * @param den Denominador da fracao.
 * @return Fracao* uma instância de Fracao.
*/

Fracao *create(int num, int den);

/**
 * Soma duas fracoes e retorna uma instância de fracao.
 * @param f1 Fracao* a ser somada.
 * @param f2 Fracao* a ser somada.
 * @return Fracao* uma nova instância de fracao com a soma
 * 
*/

Fracao *somaFracao(Fracao *f1, Fracao *f2);

/**
 * Multiplica duas fracoes e retorna uma instância de fracao.
 * @param f1 Fracao* a ser multiplicada.
 * @param f2 Fracao* a ser multiplicada.
 * @return Fracao* uma nova instância de fracao com a multiplicacao
*/

Fracao *multiplicaFracao(Fracao *f1, Fracao *f2);

/**
 * Verifica se duas fracoes sao iguais.
 * @param f1 Fracao* a ser comparada.
 * @param f2 Fracao* a ser comparada.
 * @return bool true se as fracoes sao iguais, false caso contrario.
*/

bool verificarIgualdade(Fracao *f1, Fracao *f2);

/**
 * Calcula o minimo multiplo comum entre dois numeros.
 * @param a Primeiro numero.
 * @param b Segundo numero.
 * @return int o minimo multiplo comum entre a e b.
*/

int mmc(int a, int b);

/**
 * Calcula o maximo divisor comum entre dois numeros.
 * @param a Primeiro numero.
 * @param b Segundo numero.
 * @return int o maximo divisor comum entre a e b.
*/

int mdc(int a, int b);

/**
 * Retorna o numerador de uma fracao.
 * @param f Fracao* a ser consultada.
 * @return int o numerador da fracao.
*/

int getNumerador(Fracao *f);

/**
 * Retorna o denominador de uma fracao.
 * @param f Fracao* a ser consultada.
 * @return int o denominador da fracao.
*/

int getDenominador(Fracao *f);

/**
 * Simplifica uma fracao.
 * @param f Fracao* a ser simplificada.
*/

void simplificar(Fracao *f);

#endif
