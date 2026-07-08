/*
Autor: Gabriel Evangelista Massara
Atividade: L04P_Ex03
*/

#include <stdio.h>

int procedimento(int n) {
    int soma = 0;

    printf("Estou no procedimento!\n");

    for (int i = 1; i <= n; i++) {
        soma += i;
    }

    printf("saindo do procedimento!\n");

    return soma;
}

int main() {
    int qtd, valor, resultado;

    printf("Quantos numeros voce deseja?:\n");
    scanf("%d", &qtd);

    for (int i = 0; i < qtd; i++) {
        printf("Digite o %d valor:\n", i + 1);
        scanf("%d", &valor);

        printf("Chamando o procedimento!\n");
        resultado = procedimento(valor);
        printf("Voltou do procedimento!\n");

        printf("Soma de 1 ate %d = %d\n", valor, resultado);
    }

    return 0;
}
