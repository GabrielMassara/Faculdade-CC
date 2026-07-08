/*
ATIVIDADE: Ex05. Soma de Conjunto
AUTOR: GABRIEL EVANGELISTA MASSARA
*/

#include <stdio.h>

int main()
{
    int n = 0, soma=0;

    while (1)
    {
        printf("Digite um numero (-1) para ternimar:\n");
        scanf("%d", &n);
        if(n != -1) {
            soma+=n;
        } else {
            printf("A soma dos numeros fornecidos = %d\n", soma);
            return 0;
        }
    }
}