import java.util.Scanner;

public class ContadorLetrasRecursivo {
	public static void contarMaiuscula(String texto, int i, int qtde) {
		if(i==texto.length()) {
			System.out.println(qtde);	
		} else {
			if(texto.charAt(i) >= 'A' &&  texto.charAt(i) <= 'Z') {
                        	qtde++;
                	}
                	contarMaiuscula(texto, i+1, qtde);
		}
	}

        public static void main (String[] args) {
		String entrada;
		Scanner s = new Scanner(System.in);
		entrada = s.nextLine();
		contarMaiuscula(entrada, 0, 0);
		while(!entrada.equals("FIM")) {
			entrada=s.nextLine();
			contarMaiuscula(entrada, 0, 0);
		}
	}
}
