#include<stdio.h>
#include<string.h>

int main() {
	char entrada[255];
	char fim[] = "FIM";
	int contador = 0;
	scanf("%s", entrada);
	while(strcmp(entrada, fim) != 0) {
		contador = 0;
		for (int i=0; entrada[i] != '\0'; i++) {
			if (entrada[i]>='A'&&entrada[i]<='Z') {
				contador++;
			}
		}
		printf("%d\n", contador);
		scanf("%s", entrada);
	}
	return 0;
}
