/*
Autor: Gabriel Evangelista Massara
Atividade: L04P_Ex01
*/

#include <stdio.h>

void procedimento() {
    int n, soma = 0;

    printf("Estou no procedimento!\n");
    printf("Digite um valor:\n");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        soma += i;
    }

    printf("Soma de 1 ate %d = %d\n", n, soma);
    printf("saindo do procedimento!\n");
}

int main() {
    int qtd;

    printf("Quantos numeros voce deseja?:\n");
    scanf("%d", &qtd);

    for (int i = 0; i < qtd; i++) {
        printf("Chamando o procedimento!\n");
        procedimento();
        printf("Voltou do procedimento!\n");
    }

    return 0;
}
