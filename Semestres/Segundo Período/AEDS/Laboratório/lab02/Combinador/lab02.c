#include <stdio.h>
#include <string.h>
int main() {
	char string1[100];
	char string2[100];
	char stringFinal[200];

	while(scanf("%s", string1)!=EOF) {
		scanf("%s", string2);			

		int statusString1 = 1;
		int statusString2 = 1;

		int contador = 0;
		for(int i=0; i<100; i++) {
			if(string1[i] != '\0' && statusString1) {
				stringFinal[contador] = string1[i];
				contador++;
			} else {
				statusString1 = 0;
			}
			if(string2[i] != '\0' && statusString2) {
				stringFinal[contador] = string2[i];
				contador++;
			} else {
				statusString2 = 0;
			}
			if(!statusString1 && !statusString2){
				stringFinal[contador] = '\0';
				break;
			}
		}
		printf("%s\n", stringFinal);
	}
	return 0;
}
