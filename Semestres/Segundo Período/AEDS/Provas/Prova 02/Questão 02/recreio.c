#include <stdio.h>

int main() {
	//LE QUANTOS CASOS DE TESTE TEM
	int n = 0;
	scanf("%d", &n);

	int m = 0;
	//PARA CADA CASO DE TESTE
	for(int i=0; i<n; i++){
		scanf("%d", &m);

		int alunos[m];
		int indexAlunos= 0;
		//LE AS NOTAS DOS M ALUNOS
		for(int j=0; j<m; j++){
			int aux;
			scanf("%d", &aux);
			alunos[indexAlunos] = aux;
			indexAlunos++;
		}

		//CRIA UM NOVO ARRAY ORDENADO
		int alunosOrdenados[m];
		int indexAlunosOrdenados = 0;

		//ORDENA
		int menor = alunos[0];
		int parametro = -1;
		for(int j=0; j<m; j++){
			menor = 1001;
			for(int k=0; k<m; k++) {
				if(alunos[k] <= menor && alunos[k] > parametro){
					menor = alunos[k];	
				}
			}
			parametro = menor;
			alunosOrdenados[j] = menor;
		}

		//COMPARA OS ELEMENTOS QUE SE MANTIVERAM DOS DOIS ARRAYS
		int contador = 0;
		for(int j=0; j<m; j++){
			//printf("%d  -  %d\n", alunos[j], alunosOrdenados[(m-1)-j]);
			if(alunos[j] == alunosOrdenados[(m-1)-j]) {
				contador++;
			}
		}

		printf("%d\n", contador);
	}
	return 0;
}
