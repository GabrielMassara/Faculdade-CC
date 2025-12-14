import java.util.*;

public class Teclado {

	public static boolean equals(String a, String b) {
		if(a.length() != b.length()) {
			return false;
		}
		for(int i=0; i<a.length(); i++) {
			if(a.charAt(i) != b.charAt(i))
				return false;
		}
		return true;
	}

	public static String textoSemColchete(String texto) {
		boolean abriu = false;
		String resposta = "";
		for(int i=0; i<texto.length(); i++) {
			if(texto.charAt(i) == '[' || texto.charAt(i) == ']'){
				abriu = !abriu;
			} else if(!abriu) {
				resposta+=texto.charAt(i);
			}
		}
		return resposta;
	}
	public static String textoDoColchete(String texto) {
		boolean abriu = false;
		String resposta = "";
		for(int i=0; i<texto.length(); i++) {
			if(texto.charAt(i) == '[' || texto.charAt(i) == ']') {
				abriu = !abriu;
			} else if(abriu) {
				resposta += texto.charAt(i);
			}
		}
		return resposta;
	}

	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);

		while(sc.hasNextLine()) {
			String linha = sc.nextLine();
			if(!equals(linha, "")){
				System.out.println(textoDoColchete(linha)+textoSemColchete(linha));
			}
		}
	}
}
