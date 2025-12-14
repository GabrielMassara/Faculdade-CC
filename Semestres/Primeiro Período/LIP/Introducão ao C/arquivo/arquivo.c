#include<stdio.h>

void escrever(){
    FILE * arquivo;
    char nome [256];
    int n;
    printf("Quantidade de nomes para cadastrar: ");
    scanf("%d", &n);
    arquivo = fopen ("arquivo5.txt","a+");
    for(int i=0; i<n; i++) {
        getchar();
        printf ("Digite um nome: ");
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
        printf("%d - %s", i, nome);
    }
    fclose(arquivo);
}

int main() {
    int opt=0;
    while(opt != 3) {
        printf("+----------------------+\n");
        printf("| 1- Cadastrar n nomes |\n");
        printf("| 2- Ler nomes         |\n");
        printf("| 3- Sair              |\n");
        printf("+----------------------+\n");
        scanf("%d", &opt);
        switch(opt) {
            case 1:
                escrever();
                break;
            case 2:
                ler();
                break;
        }
    }
    return 0;
}

