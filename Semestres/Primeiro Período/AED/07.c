#include <stdio.h>

int contar_digitos(int numero) {
    if (numero == 0) {
        return 1;
    }
    
    int contador = 0;
    while (numero != 0) {
        numero /= 10;
        contador++;
    }
    return contador;
}

int main() {
    int N;
    scanf("%d", &N);
    
    printf("%d\n", contar_digitos(N));
    
    return 0;
}