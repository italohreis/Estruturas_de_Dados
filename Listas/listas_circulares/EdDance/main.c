#include "TCircList.h"
#include <stdio.h>

int main(void) {
  TCircList *list = TCircList_create();
  TCircList *sec = TCircList_create();

  int cadeira, time;
  scanf("%d %d", &cadeira, &time);

  int i;
  for (i = 0; i < cadeira; i++) {
    TCircList_insert(list, (i+1));
  }


  int segs;
  for (i = 0; i < time; i++) {
    scanf("%d", &segs);
    TCircList_insert(sec, segs);
  }

  printf("%d\n", Ed_Dance(list, sec));


  return 0;
}