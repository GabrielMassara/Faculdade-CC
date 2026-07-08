/*
Autor: Gabriel Evangelista Massara
Atividade: L04P_Ex05
*/

#include <stdio.h>

void procedimento() {
    int termos;

    printf("Chamando o procedimento!\n");
    printf("Estou no procedimento!\n");

    printf("Digite quantos termos da serie:\n");
    scanf("%d", &termos);

    if (termos <= 0) {
        printf("Voce escolheu um numero invalido!\n");
    } else {
        int a = 1, b = 1, temp;

        for (int i = 0; i < termos; i++) {
            if (i == 0)
                printf("%d", a);
            else if (i == 1)
                printf(",%d", b);
            else {
                temp = a + b;
                printf(",%d", temp);
                a = b;
                b = temp;
            }
        }
        printf("\n");
    }

    printf("saindo do procedimento!\n");
    printf("Voltou do procedimento!\n");
}

int main() {
    int qtd;

    printf("Quantos numeros voce deseja?:\n");
    scanf("%d", &qtd);

    for (int i = 0; i < qtd; i++) {
        procedimento();
    }

    return 0;
}
