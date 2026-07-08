/*
Autor: Gabriel Evangelista Massara
Atividade: L04P_Ex07
*/


#include <stdio.h>

void verificarPrimo(int n) {
    int i, primo = 1;

    printf("Estou no procedimento!\n");

    if (n <= 1) {
        primo = 0;
    } else {
        for (i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                primo = 0;
                break;
            }
        }
    }

    if (primo == 1) {
        printf("Numero %d eh primo!\n", n);
    } else {
        printf("Numero %d nao eh primo!\n", n);
    }

    printf("saindo do procedimento!\n");
}

int main() {
    int qtd, numero;

    printf("Quantos numero voce deseja verificar?:\n");
    scanf("%d", &qtd);

    for (int i = 0; i < qtd; i++) {
        printf("Digite o %d numero a ser verificado:\n", i + 1);
        scanf("%d", &numero);

        printf("Chamando o procedimento!\n");
        verificarPrimo(numero);
        printf("Voltou do procedimento!\n");
    }

    return 0;
}
