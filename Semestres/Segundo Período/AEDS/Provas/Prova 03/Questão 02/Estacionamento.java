import java.util.*;

class Carro {
	String placa, modelo, tipo, chassi;

	public void ler(String linha) {
		String[] partes = linha.split(",");
		placa = partes[0];
		modelo = partes[1];
		tipo = partes[2];
		chassi = partes[3];
	}

	public void imprimir() {
		System.out.println(placa + " " + modelo + " " + tipo + " " + chassi);
	}
}

class Celula {
	int elemento;
	Carro veiculo;
	Celula prox;

	public Celula(int elemento, Carro v) {
		this.elemento = elemento;
		this.veiculo = v;
		prox = null;
	}
}

class Lista {
	Celula primeiro;
	Celula ultimo;

	public Lista() {
		Carro a = new Carro();
		Celula cabeca = new Celula(0, a);
		primeiro = cabeca;
		ultimo = cabeca;
	}
	
	public static boolean equals(String s1, String s2) {
                if(s1.length() != s2.length()) {
                        return false;
                }
                for(int i = 0; i < s1.length(); i++) {
                        if(s1.charAt(i) != s2.charAt(i)) {
                                return false;
                        }
                }
                return true;
        }

	public void inserir(int elemento, Carro veiculo) {
		Celula aux = new Celula(elemento, veiculo);
		if(primeiro == ultimo) {
			primeiro.prox = aux;
			ultimo = aux;
		} else {
			ultimo.prox = aux;
			ultimo = aux;
		}
	}

	public boolean buscar(String placa) {
		return buscar(placa, primeiro.prox);
	}
	public boolean buscar(String placa, Celula i) {
		if(i != null) {
			if(i.veiculo != null) {
				if(equals(i.veiculo.placa, placa)) {
					i.veiculo.imprimir();
					return true;
				}
			} else {
				return false;
			}
		} else {
			return false;
		}
		return false;
	}
}

class UnidadeTabela {
	int elemento;
	Carro veiculo;
	Lista lista;

	public UnidadeTabela() {
		this.elemento = -1;
		veiculo = null;
		lista = new Lista();
	}
}

public class Estacionamento {
	public static boolean equals(String s1, String s2) {
		if(s1.length() != s2.length()) {
			return false;
		}
		for(int i = 0; i < s1.length(); i++) {
			if(s1.charAt(i) != s2.charAt(i)) {
				return false;
			}
		}
		return true;
	}

	public static void main(String args[]) {
		int n = 0;
		Scanner sc = new Scanner(System.in);
		//PEGA O TAMANHO DA MINHA TABELA
		n = sc.nextInt();
		
		//CRIA A MINHA TABELA
		UnidadeTabela tabelaHash[] = new UnidadeTabela[n];

		String linha = "";

		int operacao = 0;
		// 1 = CADASTRO
		boolean status = true;
		while(sc.hasNextLine() && status) {
			linha = sc.nextLine();
			if(operacao == 1) {
				if(equals(linha, "FIM")) {
					operacao = 2;
				} else {
					Carro novo = new Carro();
					novo.ler(linha);

					//SOMAR OS CARACTERES
					int somaCaracteres = 0;
					for(int i=0; i<novo.placa.length(); i++) {
						somaCaracteres += novo.placa.charAt(i);
					}
					//System.out.println(somaCaracteres%n);
					//INSERE NA TABELA HASH
					int index = somaCaracteres%n;
					if(tabelaHash[index] == null) {
						tabelaHash[index] = new UnidadeTabela();
						tabelaHash[index].elemento = somaCaracteres;
						tabelaHash[index].veiculo = novo;
					} else {
						tabelaHash[index].lista.inserir(somaCaracteres, novo);
					}
				}
			}else if(operacao == 2 && !equals(linha, "FIM_CONSULTA")) {
				//OPERACAO PARA CONSULTAR
				int somaCaracteres2 = 0;
                                for(int i=0; i<linha.length(); i++) {
                                	somaCaracteres2 += linha.charAt(i);
                                }
				int index2 = somaCaracteres2%n;
				//VERIFICA SE A UNIDADE POSSUI A MESMA PLACA
				if(tabelaHash[index2] != null) {
					if(equals(tabelaHash[index2].veiculo.placa, linha)) {
						tabelaHash[index2].veiculo.imprimir();
					} else {
						if(!tabelaHash[index2].lista.buscar(linha)) {
							System.out.println("VEICULO NAO CADASTRADO");
						}
					}
				}
			} else if(operacao == 0) {
				operacao = 1;
			} else if(operacao == 2) {
				status = true;
			}
		}	

	}
}
