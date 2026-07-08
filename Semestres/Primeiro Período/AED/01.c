#include <stdio.h>

int main()
{
    int casos;
    scanf("%d", &casos);

    for (int valor = 0; valor < casos; valor++)
    {
        double C, i;
        int n;

        scanf("%lf %lf %d", &C, &i, &n);

        double juros_simples, juros_composto, diferenca;

        juros_simples = C * i * n;
        double montante_composto = C;
        for (int j = 0; j < n; j++)
        {
            montante_composto *= (1 + i);
        }
        juros_composto = montante_composto - C;

        if (juros_simples > juros_composto)
        {
            diferenca = juros_simples - juros_composto;
        }
        else
        {
            diferenca = juros_composto - juros_simples;
        }

        printf("DIFERENCA DE VALOR = %.2lf\n", diferenca);
        printf("JUROS SIMPLES = %.2lf\n", juros_simples);
        printf("JUROS COMPOSTO = %.2lf\n", juros_composto);
        printf("\n");
    }

    return 0;
}