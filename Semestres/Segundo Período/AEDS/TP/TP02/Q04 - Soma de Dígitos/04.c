#include <stdio.h>
#include <string.h>

int soma(int n, int i) {
    char stringDoNumero[100];
    // TRANSFORMA O INTEIRO PAR STRING
    sprintf(stringDoNumero, "%d", n);
    
    char digito = stringDoNumero[i];
    
    //CONVERTO PARA UM NUMERO INTEIRO
    // EM C, POSSO FAZER OPERACOES COM CARACTERES, E O RETORNO É UM INTEIRO
    int digitoInt = digito - '0';
    
    if(stringDoNumero[i] == '\0') {
        //SE ESTIVER NO FIM DA STRING RETORNA 0
        return 0;
    } else {
        //SOMA O CARACTERE ATUAL COM O PROXIMO
        return soma(n, ++i) + digitoInt;
    }
}

//FUNCAO QUE CONVERTE UMA STRING EX "123" PARA 123
int stringParaInteiro(char texto[]) {
    //VERIFICACAO, SE ENTRAR A LETRA 'F' É PORQUE ESTA LENDO O FIM
    if(texto[0] == 'F') {
        return -1;
    }

    int valor = 0;

    for(int i=0; texto[i] != '\n'; i++) {
        //MULTIPLICA POR 10 PARA "ANDAR" A UNIDADE PARA A ESQUERDA, COLOCANDO O DIGITO NO FINAL
        // EM C, POSSO FAZER OPERACOES COM CARACTERES, E O RETORNO É UM INTEIRO, POR ISSO SUBTRAIO - '0'
        valor = valor * 10 + (texto[i] - '0');
    }
    
    return valor;
}

int main() {
    char texto[10000];
    fgets(texto, sizeof(texto), stdin);
    int numero = stringParaInteiro(texto);
    // LE ATÉ ENCONTRAR FIM
    while (numero != -1) {
        printf("%d\n", soma(numero, 0));

        //LE A PROXIMA LINHA
        fgets(texto, sizeof(texto), stdin);
        numero = stringParaInteiro(texto);
    }
    return 0;
}