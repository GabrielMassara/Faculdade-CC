#include <stdio.h>

int soma(int numerto) {
    if (numerto == 1) return 1;
    int soma = 1 + numerto;
    for (int i = 2; i * i <= numerto; i++) {
        if (numerto % i == 0) {
            if (i * i == numerto) {
                soma += i;
            } else {
                soma += i + (numerto / i);
            }
        }
    }
    return soma;
}

int main() {
    int N, matricula;
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &matricula);
        printf("%d\n", soma(matricula));
    }
    
    return 0;
}