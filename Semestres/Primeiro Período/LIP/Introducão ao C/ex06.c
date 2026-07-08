/*
ATIVIDADE: Ex06. Média de Conjunto
AUTOR: GABRIEL EVANGELISTA MASSARA
*/

#include <stdio.h>

int main()
{
    double n = 0, soma=0, media = 0;

    for(int i=0; i>=0; i++) {
        printf("Digite um numero (-1 para terminar):\n");
        scanf("%lf", &n);
        if(n != -1) {
            soma+=n;
        } else {
            media = soma/i;
            printf("A media dos numeros fornecidos = %.2lf\n", media);
            return 0;
        }
    }
}