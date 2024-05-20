#include <stdio.h>
#include "linked_list.h"

/* Desenvolva um programa que utilize uma lista encadeada para calcular a média ponderada de um
conjunto de notas. Cada nó da lista deve armazenar uma nota e seu respectivo peso. A entrada
será uma série de pares nota-peso até que seja inserido um par com nota zero, que indica o fim da
entrada. A saída deve ser a média ponderada calculada. A lista encadeada deve ser utilizada para
armazenar cada nota e seu peso, e para realizar o cálculo da média. */

int main() {

    int num, peso;
    LinkedList *list = LinkedList_create();

    while(1){ 
        scanf("%d %d", &num, &peso);
        if (num == 0 && peso == 0) 
            break;
        
        LinkedList_insert_end(list, num, peso);
    }

    LinkedList_print(list);

    printf("Media Ponderada = %.2f\n", calcular_media(list));
    

    return 0;
}