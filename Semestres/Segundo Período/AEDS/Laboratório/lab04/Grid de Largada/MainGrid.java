// Arquivo gerado automaticamente, Feito por MergeJava


//===== INÍCIO DOS IMPORTS =====
import java.util.Scanner;
import java.util.Arrays;
//===== FIM DOS IMPORTS =====

//===== INICIO DO ARQUIVO: MainGrid.java =====

public class MainGrid {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (sc.hasNextInt()) {
            int n = sc.nextInt();
            int[] largada = new int[n];
            int[] chegada = new int[n];

            for (int i = 0; i < n; i++) {
                largada[i] = sc.nextInt();
            }
            for (int i = 0; i < n; i++) {
                chegada[i] = sc.nextInt();
            }

            Grid grid = new Grid(largada);
            int contador = grid.countOvertakes(chegada);
            System.out.println(contador);
        }

        sc.close();
    }
}
//===== FIM DO ARQUIVO: MainGrid.java =====

//===== INICIO DO ARQUIVO: Grid.java =====

class Grid {
	/*
	 * Classe responsável por manter o array de largada e
	 * executar operações de movimentação para contar ultrapassagens.
	 * Complexidade: O(N^2) no pior caso (busca linear + deslocamento por elemento).
	 */
	private int[] largada;

	public Grid(int[] largada) {
		// copia para evitar efeitos colaterais externos
		this.largada = Arrays.copyOf(largada, largada.length);
	}

	// Retorna a posição (index) do elemento no array de largada, ou -1 se não encontrado
	public int posicaoArray(int elemento) {
		for (int i = 0; i < largada.length; i++) {
			if (largada[i] == elemento) return i;
		}
		return -1;
	}

	// Move o carro de indexCarro para novaPosicao (novaPosicao < indexCarro), deslocando o bloco apropriado
	public void sobePosicao(int indexCarro, int novaPosicao) {
		if (indexCarro <= novaPosicao) return; // nada a fazer
		int carro = largada[indexCarro];
		for (int i = indexCarro; i > novaPosicao; i--) {
			largada[i] = largada[i - 1];
		}
		largada[novaPosicao] = carro;
	}

	// Conta quantas ultrapassagens ocorreram para chegar na ordem "chegada"
	public int countOvertakes(int[] chegada) {
		int contador = 0;
		for (int i = 0; i < chegada.length; i++) {
			int origIndex = posicaoArray(chegada[i]);
			if (origIndex == -1) continue; // elemento não encontrado — ignora
			int ganho = origIndex - i; // quantas posições subiu
			if (ganho > 0) {
				contador += ganho;
				sobePosicao(origIndex, i);
			}
		}
		return contador;
	}

	public int[] getLargada() {
		return Arrays.copyOf(largada, largada.length);
	}

}
//===== FIM DO ARQUIVO: Grid.java =====

