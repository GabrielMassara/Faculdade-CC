/*
Autor: Gabriel Evangelista Massara
Atividade: L04P_Ex04
*/

#include <stdio.h>

int fatorial(int n) {
    int fatorial = 1;

    printf("Estou no procedimento!\n");

    for (int i = 1; i <= n; i++) {
        fatorial *= i;
    }

    printf("saindo do procedimento!\n");

    return fatorial;
}

int main() {
    int qtd, valor, resultado;

    printf("Quantos numeros voce deseja?:\n");
    scanf("%d", &qtd);

    for (int i = 0; i < qtd; i++) {
        printf("Digite o %d valor:\n", i + 1);
        scanf("%d", &valor);

        printf("Chamando o procedimento!\n");
        resultado = fatorial(valor);
        printf("Voltou do procedimento!\n");

        printf("O fatorial de %d = %d\n", valor, resultado);
    }

    return 0;
}
