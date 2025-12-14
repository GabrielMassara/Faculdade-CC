#include <stdio.h>
#include <string.h>

int verificaPalindromo(char *texto, int i, int f) {
    if(i>=f)
        return 1;
    if(texto[i] != texto[f])
        return 0;
    return verificaPalindromo(texto, i+1, f-1);
}

int main() {
    char linha[1000];

    while (fgets(linha, sizeof(linha), stdin)) {
        linha[strcspn(linha, "\n")] = '\0';

        if (strlen(linha) == 0) break;

        if (verificaPalindromo(linha, 0, strlen(linha)-1)) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
    }

    return 0;
}