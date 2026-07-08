/*
Autor: Gabriel Evangelista Massara
Atividade: L04P_Ex02
*/

#include <stdio.h>

void procedimento(int n) {
    int soma = 0;

    printf("Estou no procedimento!\n");

    for (int i = 1; i <= n; i++) {
        soma += i;
    }

    printf("Soma de 1 ate %d = %d\n", n, soma);
    printf("saindo do procedimento!\n");
}

int main() {
    int qtd, valor;

    printf("Quantos numeros voce deseja?:\n");
    scanf("%d", &qtd);

    for (int i = 0; i < qtd; i++) {
        printf("Digite o %d valor:\n", i + 1);
        scanf("%d", &valor);

        printf("Chamando o procedimento!\n");
        procedimento(valor);
        printf("Voltou do procedimento!\n");
    }

    return 0;
}
