import java.util.Scanner;

public class ContadorLetras {
	public static int contarMaiuscula(String texto) {
		int qtde = 0;
		for(int i=0; i<texto.length(); i++) {
			if(texto.charAt(i) >= 'A' &&  texto.charAt(i) <= 'Z') {
				qtde++;
			}
		}
		return qtde;
	}

        public static void main (String[] args) {
		String entrada;
		Scanner s = new Scanner(System.in);
		entrada = s.nextLine();
		System.out.println(contarMaiuscula(entrada));
		while(!entrada.equals("FIM")) {
			entrada=s.nextLine();
			System.out.println(contarMaiuscula(entrada));
		}
	}
}
