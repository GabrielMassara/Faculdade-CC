import java.util.Scanner;

public class Sort {
    //FUNCAO SWAP PADRAO
    public static void swap(int[] array, int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    //FUNCAO ORDENAR (MODIFICADO DO ALGORITMO DE ORDENACAO POR SELECAO)
    public static void ordenar(int array[], int m) {
        for (int i = 0; i < array.length-1; i++) {
            int menor = i;
            for (int j = i + 1; j < array.length; j++) {
                if ((array[menor] % m) == (array[j] % m)) {
                    // EMPATE
                    if ((array[menor] % 2) != (array[j] % 2)) {
                        // UM PAR E OUTRO IMPAR
                        if (array[j] % 2 != 0) {
                            // SE O SEGUNDO FOR IMPAR
                            menor = j;
                        }
                    } else if (array[menor] % 2 != 0) {
                        // OS DOIS SAO IMPARES
                        if (array[menor] < array[j]) {
                            // O MAIOR IMPAR PRECEDE
                            menor = j;
                        }
                    } else {
                        // EMPATE DOIS PARES
                        if (array[menor] > array[j]) {
                            // O MENOR PAR PRECEDE
                            menor = j;
                        }
                    }
                } else if ((array[menor] % m) > (array[j] % m)) {
                    // O MENOR PRECEDE
                    menor = j;
                }
            }
            swap(array, menor, i);
        }

        //IMPRIME O VETOR ORDENADO
        for (int i = 0; i < array.length; i++) {
            System.out.println(array[i]);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        //EXECUTA ATE ENTRADA DO USUARIO SER 0 0
        while (n != 0 && m != 0) {
            System.out.println(n + " " + m);
            int[] array = new int[n];
            for (int i = 0; i < n; i++) {
                array[i] = sc.nextInt();
            }
            ordenar(array, m);
            m = sc.nextInt();
            n = sc.nextInt();
        }
        System.out.println(n + " " + m);
    }
}