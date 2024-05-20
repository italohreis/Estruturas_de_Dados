#include <stdio.h>
#include "linked_list.h"

/* Neste exercício, você deverá decompor um número inteiro em seus componentes primários usando
listas encadeadas. Por exemplo, para o número 360, os componentes são 2, 2, 2, 3, 3 e 5. O
programa deve utilizar uma lista encadeada para armazenar cada fator primário à medida que é
encontrado. A entrada será um número inteiro e a saída deve listar os fatores primários separados
por ' -> '. Use a decomposição em fatores primos como base para o processamento. */

int fatorPrimario(int a);

int main() {

    LinkedList *list = LinkedList_create();

    int num = 0;
    scanf("%d", &num);

    while (num != 1) {
        LinkedList_insert_end(list, fatorPrimario(num));
        num = num / fatorPrimario(num);
    }
    
    LinkedList_print(list);
    return 0;
}

int fatorPrimario(int a) {
    int i = 2;
    while (a % i != 0) {
        i++;
    }
    return i;
}