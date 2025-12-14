#include<stdio.h>
#include <string.h>
#include <stdlib.h>

void escrever(){
    FILE * arquivo;
    char nome [256];
    int n;
    printf("Quantidade de nomes para cadastrar: ");
    scanf("%d", &n);
    getchar(); //pega caracter aleatorio para n incluir espaco
    arquivo = fopen ("arquivo5.txt","a+");
    for(int i=0; i<n; i++) {
        printf ("Digite um aluno: ");
        fgets (nome,sizeof(nome),stdin);
        fputs (nome,arquivo);
    }
    fclose (arquivo);
}

void ler() {
    FILE *arquivo;
    arquivo = fopen("arquivo5.txt", "r");
    char nome[256];
    for(int i=1; fgets (nome,sizeof(nome),arquivo)!=NULL; i++) {
        char * pch;

        pch = strtok (nome,";");
        printf("%d - %s\n", i, pch);

    }
    fclose(arquivo);
}

int main() {
    escrever();
    ler();
    return 0;
}

