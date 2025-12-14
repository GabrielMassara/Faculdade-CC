import java.util.Scanner;

class Pais {
	public String nome;
	public int ouro;
	public int prata;
	public int bronze;
}

class Medalhas {
	public static String pegarNome(String linha) {
		String resposta = "";
		for(int i = 0; i<linha.length() && linha.charAt(i) != ' '; i++) {
			resposta+=linha.charAt(i);
		}
		return resposta;
	}

	public static int pegarOuro(String linha) {
		String aux = "";
		int contadorEspacos = 0;
		for(int i = 0; i<linha.length() && contadorEspacos != 2; i++) {
			if(contadorEspacos==1 && linha.charAt(i) != ' ') {
				aux+=linha.charAt(i);
			}

			if(linha.charAt(i) == ' ') {
				contadorEspacos++;
			}
		}
		int digitoInt = 0;
		if(aux.length() == 1)
			digitoInt = aux.charAt(0) - '0';
		else {
			if(aux.length() > 1) {
			
				digitoInt = (aux.charAt(0) - '0') * 10;
				digitoInt += aux.charAt(1) - '0';
			}
		}
		return digitoInt;
	}

	public static int pegarPrata(String linha) {
                String aux = "";
                int contadorEspacos = 0;
                for(int i = 0; i<linha.length() && contadorEspacos != 3; i++) {
                        if(contadorEspacos==2 && linha.charAt(i) != ' ') {
                                aux+=linha.charAt(i);
                        }

                        if(linha.charAt(i) == ' ') {
                                contadorEspacos++;
                        }
                }
                int digitoInt = 0;
                if(aux.length() == 1)
                        digitoInt = aux.charAt(0) - '0';
                else {
                        if(aux.length() > 1) {

                                digitoInt = (aux.charAt(0) - '0') * 10;
                                digitoInt += aux.charAt(1) - '0';
                        }
                }
                return digitoInt;

        }

	public static int pegarBronze(String linha) {
                String aux = "";
                int contadorEspacos = 0;
                for(int i = 0; i<linha.length() && contadorEspacos != 4; i++) {
                        if(contadorEspacos==3 && linha.charAt(i) != ' ') {
                                aux+=linha.charAt(i);
                        }

                        if(linha.charAt(i) == ' ') {
                                contadorEspacos++;
                        }
                }
                int digitoInt = 0;
                if(aux.length() == 1)
                        digitoInt = aux.charAt(0) - '0';
                else {
                        if(aux.length() > 1) {

                                digitoInt = (aux.charAt(0) - '0') * 10;
                                digitoInt += aux.charAt(1) - '0';
                        }
                }
                return digitoInt;

        }


	public static void main(String[] args) {
		int n = 0;
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		boolean controle = true; //variavel para ele nao ler o primeiro enter
		if(controle) {
			Pais lista[] = new Pais[n];
			for(int i=0; i<n; i++) {
				String linha = sc.nextLine();
				Pais aux = new Pais();
				aux.nome = pegarNome(linha);
				aux.ouro = pegarOuro(linha);
				aux.prata = pegarPrata(linha);
				aux.bronze = pegarBronze(linha);
				lista[i] = aux;
			}

			//ORDENAR PELO OURO
			int maiorValor = 0;
			int indexMaior = 0;
			int contador = 0;
                	maiorValor = lista[0].ouro;
			Pais listaOrdenadaOuro[] = new Pais[n];
			while(contador < n) {
				for(int i=(indexMaior+1); i<n; i++) {
					if(lista[i].ouro > maiorValor) {
						maiorValor = lista[i].ouro;
						indexMaior = i;
					}
				}
				listaOrdenadaOuro[contador] = lista[indexMaior];
				contador++;
				maiorValor = 0;
			}


			for(int i=0; i<n; i++) {
				System.out.println(listaOrdenadaOuro[i].nome + " " + listaOrdenadaOuro[i].ouro + " " + listaOrdenadaOuro[i].prata + " " + listaOrdenadaOuro[i].bronze);
			}
		} else {
			controle = true;
		}
	}
}
