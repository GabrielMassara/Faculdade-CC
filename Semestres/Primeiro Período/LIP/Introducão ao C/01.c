#include <stdio.h>

int main()
{
    int n;

    for (int i = 1; i <= 5; i++) {
        printf("Digite um numero:\n");
        scanf("%d", &n);
        printf("O tripo de %d = %d\n", n, n*3);
    }

    return 0;
}
