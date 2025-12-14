import java.util.Scanner;
public class Espelho {

	public static String reverse(String valor) {
		String stringFinal = "";
		for(int i=valor.length()-1; i>=0; i--) {
			stringFinal+=valor.charAt(i);
		}
		return stringFinal;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		do {
			String texto = sc.nextLine();
			String valores[] = texto.split(" ");
			int n1 = Integer.parseInt(valores[0]);
			int n2 = Integer.parseInt(valores[1]);
			for(int i=n1; i<=n2; i++) {
				System.out.print(i);
			}
			for(int i=n2; i>=n1; i--) {
				System.out.print(reverse(String.valueOf(i)));
            }
			System.out.print("\n");
		} while(sc.hasNextLine());
	}
}