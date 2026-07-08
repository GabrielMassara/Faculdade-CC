/*
ATIVIDADE: Ex03. Soma Progressiva
AUTOR: GABRIEL EVANGELISTA MASSARA
*/

#include <stdio.h>

int main() {
    int n, soma;

    printf("Digite um numero:\n");
    scanf("%d", &n);

    for(int i=1; i<=n; i++) {
        soma+=i;
    }

    printf("A soma de todos os numeros de 1 ate 5 = %d\n", soma);

    return 0;
}