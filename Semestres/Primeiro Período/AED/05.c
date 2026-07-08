#include <stdio.h>

int main() {
    int N, X;
    scanf("%d", &N);
    
    for(int i = 0; i < N; i++) {
        scanf("%d", &X);
        
        if(X == 1) {
            printf("1 nao eh perfeito\n");
            continue;
        }
        
        int soma = 1;
        for(int divisor = 2; divisor * divisor <= X; divisor++) {
            if(X % divisor == 0) {
                soma += divisor;
                if(divisor != X / divisor) {
                    soma += X / divisor;
                }
            }
        }
        
        if(soma == X) {
            printf("%d eh perfeito\n", X);
        } else {
            printf("%d nao eh perfeito\n", X);
        }
    }
    
    return 0;
}