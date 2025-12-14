import java.util.*;

class SomaDigitos {

    // FUNCAO PARA VERIFICAR SE AS STRINGS SAO IGUAIS (mesmo tamanho + mesmos chars)
    public static boolean equals(String a, String b) {
        if (a.length() != b.length())
            //TAMANHOS DIFERENTES RETORNA FALSO
            return false;
        
        //COMPARA CARACTERE POR CARACTERE
        for (int i = 0; i < a.length(); i++) {
            if (a.charAt(i) != b.charAt(i))
                return false;
        }
        return true;
    }

    public static int soma(String numero, int i) {
        if (i == numero.length()) {
            // SE ESTIVER NO FIM DA STRING RETORNA 0
            return 0;
        } else {
            // TRANSFORMA O STRING PARA INTEIRO
            // EM JAVA, POSSO FAZER OPERACOES COM CARACTERES, E O RETORNO É UM INTEIRO
            int digitoInt = numero.charAt(i) - '0';

            // SOMA O CARACTERE ATUAL COM O PROXIMO
            return soma(numero, ++i) + digitoInt;
        }
    }

    // SOBRECARGA DE FUNCAO, PARA CHAMAR ELA PASSANDO APENAS O NUMERO
    public static int soma(String numero) {
        return soma(numero, 0);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String numero;
        // LE ATÉ ENCONTRAR FIM
        while (sc.hasNext()) {
            numero = sc.nextLine();
            if(!equals(numero, "FIM"))
                System.out.println(soma(numero));
        }
    }
}