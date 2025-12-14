import java.util.Scanner;

public class Cesar {

    public static String codificar(String texto) {
        String textoFinal = "";
        for (int i = 0; i < texto.length(); i++) {
            char c = texto.charAt(i);
            if (c != '\uFFFD') {
                textoFinal += (char) (c + 3);
            } else {
                textoFinal += c;
            }
        }
        return textoFinal;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String texto = sc.nextLine();
        while (!texto.equals("FIM")) {
            String textoFinal = codificar(texto);
            System.out.println(textoFinal);
            texto = sc.nextLine();
        }
    }
}
