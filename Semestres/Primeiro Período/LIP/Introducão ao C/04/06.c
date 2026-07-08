/*
Autor: Gabriel Evangelista Massara
Atividade: L04P_Ex06
*/


#include <stdio.h>

float calcularMedia() {
    int valor, soma = 0, count = 0;

    printf("Estou no procedimento!\n");

    while (1) {
        printf("Digite um valor (FLAG valor negativo)\n");
        scanf("%d", &valor);

        if (valor < 0)
            break;

        soma += valor;
        count++;
    }

    printf("saindo do procedimento!\n");

    if (count == 0)
        return 0.0;

    return (float)soma / count;
}

int main() {
    int qtd;
    float media;

    printf("Quantos conjuntos voce deseja?:\n");
    scanf("%d", &qtd);

    for (int i = 0; i < qtd; i++) {
        printf("Chamando o procedimento!\n");
        media = calcularMedia();
        printf("Voltou do procedimento!\n");
        printf("A media do %d conjunto foi:%.3f\n", i + 1, media);
    }

    return 0;
}
