#ifndef PONTO_H
#define PONTO_H
typedef struct _ponto Ponto;
/**
 * Cria instância de Ponto.
 * @param x Valor da coordenada x.
 * @param y Valor da coordenada y.
 * @return Ponto* uma instância de Ponto.
 */
Ponto *pto_cria(float x, float y);
/**
 * Libera a memória de um Ponto.
 * @param p Ponto* a ser liberado.
 */
void pto_libera(Ponto **p);
/**
 * Imprime o ponto formatado em 2 casas.
 * @param p Ponto* a ser impresso.
 */
void pto_print(Ponto *);

void pto_get_x(Ponto *p, float *val);

void pto_get_xy(Ponto *p, float *x, float *y);
  
void pto_set_x(Ponto *p, float x);

void pto_set_y(Ponto *p, float y);

float pto_distancia(Ponto *p1, Ponto *p2);

#endif
