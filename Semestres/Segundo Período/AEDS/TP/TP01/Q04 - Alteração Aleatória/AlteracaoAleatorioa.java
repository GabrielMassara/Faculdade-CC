import java.util.Random;
import java.util.Scanner;

class AlteracaoAleatorioa {

    private static Random gerador = new Random();
    
    static {
        gerador.setSeed(4);
    }

    public static String alterarTexto(String texto) {
        char letra1 = (char) ('a' + (Math.abs(gerador.nextInt()) % 26));
        char letra2 = (char) ('a' + (Math.abs(gerador.nextInt()) % 26));
        String textoFinal = "";
        for (int i = 0; i < texto.length(); i++) {
            if (texto.charAt(i) == letra1) {
                textoFinal += letra2;
            } else {
                textoFinal += texto.charAt(i);
            }
        }
        return textoFinal;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String linha;
        linha = scanner.nextLine();
        while (!linha.equals("FIM")) {
            System.out.println(alterarTexto(linha));
            linha = scanner.nextLine();
        }

        scanner.close();
    }
}