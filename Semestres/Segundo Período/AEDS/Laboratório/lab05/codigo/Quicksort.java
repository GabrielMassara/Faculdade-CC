/**
 * Algoritmo de ordenacao Quicksort
 * 
 * @author Max do Val Machado
 * @version 3 08/2020
 */
class Quicksort extends Geracao {

   /**
    * Construtor.
    */
   public Quicksort() {
      super();
   }

   /**
    * Construtor.
    * 
    * @param int tamanho do array de numeros inteiros.
    */
   public Quicksort(int tamanho) {
      super(tamanho);
   }

   /**
    * Algoritmo de ordenacao Quicksort.
    */
   @Override
   public void sort() {
      quickSortMedianOfThree(0, n - 1);
   }

   /**
    * Algoritmo de ordenacao Quicksort.
    * 
    * @param int esq inicio do array a ser ordenado
    * @param int dir fim do array a ser ordenado
    */
   private void quickSortFirstPivot(int esq, int dir) {
      int i = esq, j = dir;
      int pivo = array[esq];
      while (i <= j) {
         while (array[i] < pivo)
            i++;
         while (array[j] > pivo)
            j--;
         if (i <= j) {
            swap(i, j);
            i++;
            j--;
         }
      }
      if (esq < j)
         quickSortFirstPivot(esq, j);
      if (i < dir)
         quickSortFirstPivot(i, dir);
   }

   private void quickSortLastPivot(int esq, int dir) {
      int i = esq, j = dir;
      int pivo = array[dir];
      while (i <= j) {
         while (array[i] < pivo)
            i++;
         while (array[j] > pivo)
            j--;
         if (i <= j) {
            swap(i, j);
            i++;
            j--;
         }
      }
      if (esq < j)
         quickSortLastPivot(esq, j);
      if (i < dir)
         quickSortLastPivot(i, dir);
   }

   private void quickSortRandomPivot(int esq, int dir) {
      int i = esq, j = dir;
      // NUMERO ALEATORIO ENTRE ESQUERDA E DIREITA
      int numeroAleatorio = esq + (int) (Math.random() * (dir - esq + 1));
      int pivo = array[numeroAleatorio];
      while (i <= j) {
         while (array[i] < pivo)
            i++;
         while (array[j] > pivo)
            j--;
         if (i <= j) {
            swap(i, j);
            i++;
            j--;
         }
      }
      if (esq < j)
         quickSortRandomPivot(esq, j);
      if (i < dir)
         quickSortRandomPivot(i, dir);
   }

   private void quickSortMediaOfThree(int esq, int dir) {
      int i = esq, j = dir;
      int pivo = medianOfThree(array[esq], array[(esq + dir) / 2], array[dir]);
      while (i <= j) {
         while (array[i] < pivo)
            i++;
         while (array[j] > pivo)
            j--;
         if (i <= j) {
            swap(i, j);
            i++;
            j--;
         }
      }
      if (esq < j)
         quickSortMediaOfThree(esq, j);
      if (i < dir)
         quickSortMediaOfThree(i, dir);
   }

   private void quickSortMedianOfThree(int esq, int dir) {
      int i = esq, j = dir;
      int pivo = medianOfThree(array[esq], array[(esq + dir) / 2], array[dir]);
      while (i <= j) {
         while (array[i] < pivo)
            i++;
         while (array[j] > pivo)
            j--;
         if (i <= j) {
            swap(i, j);
            i++;
            j--;
         }
      }
      if (esq < j)
         quickSortMedianOfThree(esq, j);
      if (i < dir)
         quickSortMedianOfThree(i, dir);
   }

   private int medianOfThree(int a, int b, int c) {
      if ((a <= b && b <= c) || (c <= b && b <= a))
         return b;
      else if ((b <= a && a <= c) || (c <= a && a <= b))
         return a;
      else
         return c;
   }
}
