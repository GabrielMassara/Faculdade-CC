import java.util.Scanner;

public class Inversao {
    //FUNCAO PARA INVERTER A STRING
    public static String inverter(String texto) {
        //VARIAVEL PARA GUARDAR O TEXTO INVERTIDO
        String textoReverso = "";
        for (int i = 0; i < texto.length(); i++) {
            //CONCATENA, COLOCANDO O ULTIMO CARACTERE NO INICIO DA STRING
            textoReverso = texto.charAt(i) + textoReverso;
        }
        return textoReverso;
    }

    //FUNCAO PARA VERIFICAR SE A STRING E IGUAL A OUTRA
    public static boolean equals(String a, String b) {
        for (int i = 0; i < a.length(); i++) {
            //SE ALGUM CARACTERE FOR DIFERENTE, RETORNA FALSE
            if (a.charAt(i) != b.charAt(i)) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String texto = sc.nextLine();

        //LE ATE ENCONTRAR "FIM"
        while(!equals(texto, "FIM")) {
            System.out.println(inverter(texto));
            texto = sc.nextLine();
        }
    }
}