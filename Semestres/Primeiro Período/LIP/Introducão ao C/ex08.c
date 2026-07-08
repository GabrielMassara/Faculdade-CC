/*
ATIVIDADE: EX08. Tabuada de Multiplicação
AUTOR: GABRIEL EVANGELISTA MASSARA
*/

#include <stdio.h>

int main() {
    int numero;
    
    printf("Digite um numero para ver sua tabuada:\n");
    scanf("%d", &numero);
    
    for (int i = 1; i <= 10; i++) {
        printf("%d x %2d = %3d\n", numero, i, numero * i);
    }
    
    return 0;
}

