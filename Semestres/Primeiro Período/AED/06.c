#include <stdio.h>

int fatorial(int n)
{
    int resultado = 1;
    for (int i = 1; i <= n; i++)
    {
        resultado *= i;
    }
    return resultado;
}

int comprimento_string(const char *str)
{
    int tamanho = 0;
    while (str[tamanho] != '\0')
    {
        tamanho++;
    }
    return tamanho;
}

int main()
{
    char acm[6];

    while (1)
    {
        scanf("%s", acm);
        if (acm[0] == '0' && acm[1] == '\0')
        {
            break;
        }

        int decimal = 0;
        int length = comprimento_string(acm);

        for (int i = 0; acm[i] != '\0'; i++)
        {
            int digito = acm[i] - '0';
            int pos = length - i;
            decimal += digito * fatorial(pos);
        }

        printf("%d\n", decimal);
    }

    return 0;
}