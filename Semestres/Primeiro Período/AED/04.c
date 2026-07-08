#include <stdio.h>

int main() {
    int idade, gostou;
    char genero;
    int masc_gostou = 0, fem_gostou = 0;
    int masc_mais_velho = -1;
    int fem_mais_nova_nao_gostou = -1;
    int total_pessoas = 0, nao_gostaram = 0;

    while(1) {
        scanf("%d", &idade);
        if(idade < 0) break;
        
        scanf(" %c %d", &genero, &gostou);
        
        total_pessoas++;
        
        if(gostou == 1) {
            if(genero == 'M') {
                masc_gostou++;
                if(idade > masc_mais_velho) {
                    masc_mais_velho = idade;
                }
            } else if(genero == 'F') {
                fem_gostou++;
            }
        } else {
            nao_gostaram++;
            if(genero == 'F') {
                if(fem_mais_nova_nao_gostou == -1 || idade < fem_mais_nova_nao_gostou) {
                    fem_mais_nova_nao_gostou = idade;
                }
            }
        }
    }

    printf("Masculino: %d\n", masc_gostou);
    printf("Feminino: %d\n", fem_gostou);
    
    if(masc_mais_velho != -1) {
        printf("%d anos\n", masc_mais_velho);
    }
    
    if(fem_mais_nova_nao_gostou != -1) {
        printf("%d anos\n", fem_mais_nova_nao_gostou);
    }
    
    float percentual_nao_gostou = 0.0;
    if(total_pessoas > 0) {
        percentual_nao_gostou = (nao_gostaram * 100.0) / total_pessoas;
    }
    printf("%.2f%%\n", percentual_nao_gostou);

    return 0;
}