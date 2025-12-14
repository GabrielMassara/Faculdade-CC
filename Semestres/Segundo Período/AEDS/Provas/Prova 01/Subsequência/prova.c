#include<stdio.h>

int main() {
	int a, b;
	scanf("%d", &a);
	scanf("%d", &b);
	int lista1[a];
	int lista2[b];
	for(int i=0; i<a; i++) {
		int aux = 0;
		scanf("%d", &aux);
		lista1[i] = aux;
	}

	for(int i=0; i<b; i++) {
                int aux = 0;
                scanf("%d", &aux);
                lista2[i] = aux;
        }

	int contador = 0;
	for(int i = 0; i<a; i++) {
		if(lista1[i] == lista2[contador]) {
			contador++;
		}
	}
	
	if(contador != b) {
		printf("N\n");
	} else {
		printf("S\n");
	}

	return 0;
}
