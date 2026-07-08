#include <stdio.h>

void contarDigitosSimples(int inicio, int fim, int contador[10]) {
    for (int i = 0; i < 10; i++) contador[i] = 0;
    
    for (int numero = inicio; numero <= fim; numero++) {
        int temp = numero;
        while (temp > 0) {
            contador[temp % 10]++;
            temp /= 10;
        }
    }
}

void contarDigitosAvancado(int numero, int contador[10], int fator) {
    while (numero > 0) {
        contador[numero % 10] += fator;
        numero /= 10;
    }
}

void contarDigitosOtimizado(int inicio, int fim, int contador[10]) {
    for (int i = 0; i < 10; i++) contador[i] = 0;
    
    int fatorMultiplicador = 1;
    
    while (inicio <= fim) {
        while (inicio % 10 != 0 && inicio <= fim) {
            contarDigitosAvancado(inicio, contador, 1);
            inicio++;
        }
        
        while (fim % 10 != 9 && inicio <= fim) {
            contarDigitosAvancado(fim, contador, 1);
            fim--;
        }
        
        if (inicio <= fim) {
            int intervalo = (fim / 10 - inicio / 10 + 1);
            for (int d = 0; d < 10; d++) {
                contador[d] += intervalo * fatorMultiplicador;
            }
            
            fatorMultiplicador *= 10;
            inicio /= 10;
            fim /= 10;
        }
    }
}

int main() {
    int inicio, fim;
    int contador[10];
    int continuar = 1;
    
    while (continuar) {

        scanf("%d %d", &inicio, &fim);
        continuar = !(inicio == 0 && fim == 0);
        
        if (continuar) {
            if (fim - inicio < 1000) {
                contarDigitosSimples(inicio, fim, contador);
            } else {
                contarDigitosOtimizado(inicio, fim, contador);
            }
            
            for (int i = 0; i < 10; i++) {
                printf("%d", contador[i]);
                if (i < 9) printf(" ");
            }
            printf("\n");
        }
    }
    
    return 0;
}
