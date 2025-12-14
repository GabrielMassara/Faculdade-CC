import java.util.Scanner;
public class Palindromo {

	public static Boolean verificaPalindromo(String texto) {
		if(texto.equals(reverse(texto))) {
			return true;
		}
		return false;
	}

	public static String reverse(String valor) {
		String stringFinal = "";
		for(int i=valor.length()-1; i>=0; i--) {
			stringFinal+=valor.charAt(i);
		}
		return stringFinal;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		String texto = sc.nextLine();
		
		while(!texto.equals("FIM")) {
			if(verificaPalindromo(texto)) {
				System.out.print("SIM\n");
			} else {
				System.out.print("NAO\n");
			}
			texto = sc.nextLine();
		}
	}
}