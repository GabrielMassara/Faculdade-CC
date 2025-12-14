#include <stdio.h>

void identificarImpares(int *n, int parImpar)
{
    int comparacao = 11;
    if (parImpar) {
        printf("%d,", *n);
        comparacao = 10;
    }

    for (int i = 1; i < comparacao; i++)
    {
        *n += 2;
        printf("%d,", *n);
    }
}

int main()
{
    int n;

    printf("Digite o valor inicial:\n");
    scanf("%d", &n);

    if (n % 2 == 0)
    {
        n--;
        identificarImpares(&n, 0);
    } else {
        identificarImpares(&n, 1);
    }

    return 0;
}
