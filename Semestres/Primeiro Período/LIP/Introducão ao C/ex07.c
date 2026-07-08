/*
ATIVIDADE: Ex07. Sequência de Fibonacci
AUTOR: GABRIEL EVANGELISTA MASSARA
*/

#include <stdio.h>

int main() {
    int entrada, result=0, termo1, termo2, proximoTermo, status=1;
    while(status) {
        printf("Digite um numero maior que 2:\n");
        scanf("%d", &entrada);
        if(entrada > 2) {
            termo1= 1;
            termo2= 1;
            printf("A sequencia de Fibonaacci ate o %d termo: 1,1", entrada);
            for(int i=0; i<(entrada-2); i++) {
                printf(",");
                proximoTermo = termo1+termo2;
                printf("%d", proximoTermo);
                termo1=termo2;
                termo2 = proximoTermo;
            }
            status=0;
        } else {
            printf("Numero invalido! Deve ser maior que 2.\n");
        }
    }
    return 0;
}