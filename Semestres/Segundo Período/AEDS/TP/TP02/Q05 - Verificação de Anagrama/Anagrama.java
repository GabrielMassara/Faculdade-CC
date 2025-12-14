public class Anagrama {

   // FUNCAO PARA VERIFICAR SE AS STRINGS SAO IGUAIS (mesmo tamanho + mesmos chars)
   public static boolean equals(String a, String b) {
      if (a == null || b == null)
         return false;
      if (a.length() != b.length())
         return false;
      for (int i = 0; i < a.length(); i++) {
         if (a.charAt(i) != b.charAt(i))
            return false;
      }
      return true;
   }

   // BUSCA O INDICE DE UM CARACTERE EM UM VETOR (RETORNA -1 SE NAO ENCONTRAR)
   public static int buscaIndice(char vetor[], char c) {
      for (int i = 0; i < vetor.length; i++) {
         if (vetor[i] == c)
            return i;
      }
      return -1;
   }

   // REMOVE UM ELEMENTO ESPECIFICO DE UM VETOR A PARTIR DE SUA POSICAO
   public static char[] removerCaractere(char vetor[], int posicao) {
      // CRIA O VETOR PARA RESPOSTA
      char vetorFinal[] = new char[vetor.length - 1];
      int index = 0;

      // PARA CADA ELEMENTO DO VETOR DE ENTRADA
      for (int i = 0; i < vetor.length; i++) {
         if (i != posicao) {
            // SALVA NO VETOR DE RESPOSTA SE O INDEX FOR DIFERENTE DAQUELE QUE QUER SER
            // REMOVIDO
            vetorFinal[index] = vetor[i];
            index++;
         }
      }
      return vetorFinal;
   }

   // FUNCAO QUE VERIFICA O ANAGRAMA
   public static boolean verificaAnagrama(String texto1, String texto2) {
      // SE O TAMANHO FOR DIFERENTE NAO E ANAGRANMA
      if (texto1.length() != texto2.length()) {
         return false;
      }
      // CRIA UM VETOR COM OS CARACTERES DO TEXTO2
      char[] caracteresTexto2 = new char[texto2.length()];
      for (int i = 0; i < texto2.length(); i++) {
         caracteresTexto2[i] = texto2.charAt(i);
      }

      // PARA CADA CARACTERE DO TEXTO 1, BUSCA E REMOVE SE TIVER O CARACTERE CORRESPONDENTE DE TEXTO 2
      for (int i = 0; i < texto1.length(); i++) {
         char c = texto1.charAt(i);
         int pos = buscaIndice(caracteresTexto2, c);
         if (pos == -1) {
            //SE NAO ACHAR O CARACTERE, NAO É ANAGRAMA
            return false;
         }
         caracteresTexto2 = removerCaractere(caracteresTexto2, pos);
         //REMOVE O CARACTERE
      }

      // SE REMOVEU TUDO = ANAGRAMA
      return caracteresTexto2.length == 0;
   }

   // FUNCAO QUE SEPARA PELO SEPARADOR " - "
   public static String[] separaString(String texto) {
      int elemento = 0;
      // CRIA A VARIAVEL PARA A RESPOSTA
      String textosSeparados[] = { "", "" };
      for (int i = 0; i < texto.length(); i++) {
         // INCREMENTA NO PRIMEIRO ELEMENTO ATE ACHAR O PRIMEIR ESPACO DO SEPARADOR
         if (texto.charAt(i) != ' ') {
            textosSeparados[elemento] += texto.charAt(i);
         } else {
            // QUANDO ENCONTRA O PRIMEIRO ESPACO, AUMENTA ELEMENTO PARA PEGAR O SEGUNDO
            // PARAMETRO
            // INCREMENTA EM 2 O i PARA PULAR O caracteresTexto2 DO SEPARADOR "- "
            elemento++;
            i += 2;
         }
      }
      return textosSeparados;
   }

   // FUNCAO PARA CONVERTER STRING PARA TODOS OS CARACTERES MAIUSCULOS
   public static String toUpperCase(String texto) {
      String resultado = "";
      for (int i = 0; i < texto.length(); i++) {
         // SE FOR CARACTERE MINUSCULO
         if (texto.charAt(i) >= 'a' && texto.charAt(i) <= 'z') {
            // CONVERTE PARA MAIUSCULO
            resultado += (char) (texto.charAt(i) - ('a' - 'A'));
         } else {
            resultado += texto.charAt(i);
         }
      }
      return resultado;
   }

   public static void main(String[] args) {
      MyIO.setCharset("ISO-8859-1");
      String linha = MyIO.readLine();

      // REPETE ATE ENCONTRAR A PALAVRA FIM
      while (!equals(linha, "FIM")) {
         String parametros[] = separaString(linha);
         String a = toUpperCase(parametros[0]);
         String b = toUpperCase(parametros[1]);

         MyIO.println(verificaAnagrama(a, b) ? "SIM" : "NÃO");

         linha = MyIO.readLine();
      }
   }
}
