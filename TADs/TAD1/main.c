#include "Ponto.h"
#include <stdio.h>

int main(void) {
  Ponto *p1 = pto_cria(10.0, 20.0);
  Ponto *p2 = pto_cria(30.0, 40.0);
  pto_print(p1);
  putchar('\n');
  pto_print(p2);

  puts("");

  float x, y;
  pto_get_xy(p1, &x, &y);
  printf("p1 --> x = %0.2f, y = %0.2f\n", x, y);

  pto_set_x(p1, 5.1);
  pto_set_y(p2, 5.1);
  
  float distancia = pto_distancia(p1, p2);
  printf("distancia entre os pontos --> %0.2f\n", distancia);
  pto_libera(&p1);

  printf("p1 is null --> %d", p1 == NULL);
  return 0;
}