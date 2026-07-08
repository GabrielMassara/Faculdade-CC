/*
ATIVIDADE: EX10. Quadrado de Caracteres
AUTOR: GABRIEL EVANGELISTA MASSARA
*/

#include <stdio.h>

int main() {
    int tamanho;
    char caractere;
    
    printf("Digite o tamanho do lado do quadrado:\n");
    scanf("%d", &tamanho);
    
    printf("Digite um caractere para formar o quadrado:\n");
    scanf(" %c", &caractere);
    
    for (int i = 3; i < 3 + tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            printf("%c ", caractere);
        }
        printf("\n");
    }
    
    return 0;
}
