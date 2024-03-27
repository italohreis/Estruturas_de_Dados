#include "Ponto.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct _ponto {
  float x, y;
};

Ponto *pto_cria(float x, float y) {
  Ponto *p = (Ponto *)malloc(sizeof(Ponto));
  if (p != NULL) {
    p->x = x;
    p->y = y;
  }
  return p;
}
/**
 * Libera a memória de um Ponto.
 * @param p Ponto* a ser liberado.
 */
// void pto_libera(Ponto *p);
/**
 * Imprime o ponto formatado em 2 casas.
 * @param p Ponto* a ser impresso.
 */
void pto_print(Ponto *p) { printf("(%0.2f, %0.2f)", p->x, p->y); }

/**
*  Sobescreve a variavel do ponto
  @param p Ponto* a ser modificado
  @param x novo valor da coordenada x
*/

void pto_get_x(Ponto *p, float *val) { 
  *val = p->x;
}

void pto_get_xy(Ponto *p, float *x, float *y) {
  *x = p->x;
  *y = p->y;
}

void pto_set_x(Ponto *p, float x) { 
  p->x = x; 
}

void pto_set_y(Ponto *p, float y) { 
  p->y = y; 
}

void pto_libera(Ponto **p) { 
  free(*p);
  *p = NULL;
}

float pto_distancia(Ponto *p1, Ponto *p2) {
  return sqrtf(pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2));
}