#include <stdio.h>

int main() {
    int votos[7];
    int voto;
    int total_votos = 0;
    
    for(int i = 0; i < 7; i++) {
        votos[i] = 0;
    }

    while(1) {
        scanf("%d", &voto);
        if(voto == 0) break;
        if(voto >= 1 && voto <= 6) {
            votos[voto]++;
            total_votos++;
        }
    }

    for(int i = 1; i <= 4; i++) {
        printf("Candidato %d: %d voto(s)\n", i, votos[i]);
    }
    printf("Votos nulos: %d\n", votos[5]);
    
    float percent_branco = 0.0;
    if(total_votos > 0) {
        percent_branco = (votos[6] * 100.0) / total_votos;
    }
    printf("Porcentagem de votos em branco: %.2f%%\n", percent_branco);

    return 0;
}