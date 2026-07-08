/*
ATIVIDADE: Ex09. Padrão de Triângulo de Estrelas
AUTOR: GABRIEL EVANGELISTA MASSARA
*/

#include <stdio.h>

int main() {
    int altura;
    
    printf("Digite a altura do triangulo de estrelas:\n");
    scanf("%d", &altura);
    
    for (int i = 1; i <= altura; i++) {
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
    
    return 0;
}