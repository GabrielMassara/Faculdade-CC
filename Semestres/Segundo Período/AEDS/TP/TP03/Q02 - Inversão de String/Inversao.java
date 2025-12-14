import java.util.Scanner;

public class Inversao {

    //RECEBE APENAS O TEXTO E CHAMA A FUNCAO COM O INDEX 0 E O TEXTO FINAL VAZIO
    public static String inverter(String texto) {
        return inverter(texto, 0, "");
    }
    public static String inverter(String texto, int i, String textoFinal) {
        //SE TIVER CHEGADO AO FINAL DA STRING RETORNA
        if(i==texto.length())
            return textoFinal;
        //RETORNA AS CHAMADAS, CONCATENANDO O ULTIMO CARACTERE NO INICIO DA STRING FINAL
        return inverter(texto, i+1, (texto.charAt(i) + textoFinal));
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