#include <stdio.h>

int calcularF(int n) {
    if (n == 0) {
        return 1;
    } else {
        return 2 * calcularF(n - 1);
    }
}

int main() {
    int numero;

    scanf("%d", &numero);

    int resultado = calcularF(numero);
    printf("%d\n", numero, resultado);

    return 0;
}
