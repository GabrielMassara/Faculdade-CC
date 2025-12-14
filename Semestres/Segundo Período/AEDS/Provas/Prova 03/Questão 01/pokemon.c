#include <stdio.h>
#include <string.h>

int compararString(char texto1[255], char texto2[255]) {
	for(int i=0; i<255; i++) {
		if(texto1[i] == '\0' && texto2[i] != '\0') {
			return 0;
		} else if(texto1[i] != '\0' && texto2[i] == '\0') {
			return 0;
		} else if(texto1[i] == '\0' && texto2[i] == '\0') {
			return 1;
		}
		if(texto1[i] != texto2[i]) {
			return 0;
		}
	}
	return 1;
}

int main() {
	int n = 0;
	scanf("%d", &n);
	
	int contador = 0;

	char pokemon[255];
	char lista[n][255];
	int index = 0;
	for(int i = 0; i<n; i++) {
		scanf("%s", pokemon);
		int status = 0;
		for(int j = 0; j<(index-1); j++) {
			if(compararString(pokemon, lista[j]))
				status = 1;
		}
		if(!status) {
			//for(int j = 0; j < 255; j++) {}
			strcpy(lista[index], pokemon);
			index++;
			contador++;
		}
	}
	int faltantes = 152 - contador;
	printf("Falta(m) %d pomekon(s).", faltantes);	

	return 0;
}
