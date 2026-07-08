#include <stdio.h>

int binarioParaDecimal(int binario) {
    if (binario == 0 || binario == 1) {
        return binario;
    }
    
    int ultimoDigito = binario % 10;
    
    int resto = binario / 10;
    
    return 2 * binarioParaDecimal(resto) + ultimoDigito;
}

int main() {
    int binario;
    scanf("%d", &binario);
    
    printf("%d\n", binarioParaDecimal(binario));
    
    return 0;
}