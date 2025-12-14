#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool confereVogais(char texto[]) {
    for (int i = 0; texto[i] != '\n'; i++) {
        //SE ACHAR ALGUM CARACTERE QUE NAO SEJA VOGAL ELE RETORNA FALSE
        if(texto[i] != 'a' && texto[i] != 'e' && texto[i] != 'i' && texto[i] != 'o' && texto[i] != 'u' &&
           texto[i] != 'A' && texto[i] != 'E' && texto[i] != 'I' && texto[i] != 'O' && texto[i] != 'U') {
            return false;
        }
    }
    return true;
}

bool confereConsoantes(char texto[]) {
    for (int i = 0; texto[i] != '\n'; i++) {
        // SE ACHAR ALGUM CARACTERE QUE SEJA VOGAL RETORNA FALSE
        if(texto[i] == 'a' || texto[i] == 'e' || texto[i] == 'i' || texto[i] == 'o' || texto[i] == 'u' ||
           texto[i] == 'A' || texto[i] == 'E' || texto[i] == 'I' || texto[i] == 'O' || texto[i] == 'U' || texto[i] >=0 || texto[i] <=9) {
            return false;
        }
    }
    return true;
}

bool confereInteiros(char texto[]) {
    for (int i = 0; texto[i] != '\n'; i++) {
        //SE TIVER ALGUM CARACTERE QUE NAO SEJA NUMERO, ELE NÃO É INTEIRO
        if(texto[i] < '0' || texto[i] > '9') {
            return false;
        }
    }
    return true;
}

bool confereReais(char texto[]) {
    int contadorPonto = 0;
    int contadorVirgula = 0;
    for (int i = 0; texto[i] != '\n'; i++) {
        //SE ACHAR UM CARACTERE QUE NAO SEJA UM PONTO OU UMA VIRGULA
        if(texto[i] != '.' && texto[i] != ',') {
            //SE ESSE CARACTERE NAO FOR UM NUMERO ENTAO ELE NAO PODE SER REAL
            if(texto[i] < '0' || texto[i] > '9') {
                return false;
            }
        } else {
            //QUANDO ACHA UM PONTO OU UMA VIRGULA ELE INCREMENTA OS RESPECTIVOS CONTADORES
            if(texto[i] == '.') {
                contadorPonto ++;
            } else {
                contadorVirgula ++;
            }
        }
        
    }

    //SE O CONTADOR FOR MAIOR QUE 1 É PORQUE TEM MAIS DE UM PONTO OU MAIS DE UMA VIRGULA, OU SEJA NAO É NUMERO REAL
    if(contadorPonto > 1 || contadorVirgula > 1) {
        return false;
    } else {
        return true;
    }
}

int main() {
    char texto[10000];
    fgets(texto, sizeof(texto), stdin);
    char fim[] = "FIM\n";

    // LE ATÉ ENCONTRAR FIM
    while (strcmp(texto, fim)) {

        //VERIFICA VOGAIS
        if (confereVogais(texto)) {
            printf("SIM ");
        } else {
            printf("NAO ");
        }

        //VERIFICA CONSOANTES
        if (confereConsoantes(texto)) {
            printf("SIM ");
        } else {
            printf("NAO ");
        }

        //VERIFICA INTEIROS
        if (confereInteiros(texto)) {
            printf("SIM ");
        } else {
            printf("NAO ");
        }

        //VERIFICA REAIS
        if (confereReais(texto)) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }

        //LE A PROXIMA LINHA
        fgets(texto, sizeof(texto), stdin);
    }
    return 0;
}