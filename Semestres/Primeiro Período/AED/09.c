#include <stdio.h>

int main() {
    int posicao;
    scanf("%d", &posicao);
    
    int marcador[200000] = {0};
    int a = 1, b = 1;
    
    marcador[a] = 1;
    marcador[b] = 1;
    
    int c = a + b;
    while (c < 200000) {
        marcador[c] = 1;
        a = b;
        b = c;
        c = a + b;
    }
    
    int contador = 0;
    int numero = 1;
    int resultado = 0;
    
    while (numero < 200000 && contador < posicao) {
        if (marcador[numero] == 0) {
            contador++;
            resultado = numero;
        }
        numero++;
    }
    
    printf("%d\n", resultado);
    return 0;
}