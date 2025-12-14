class Principal {
	
   //ESSE ALGORITMO CRIA UM ARRAY ORDENADO E FAZ 10% DE TROCAS PARA DESORDENA-LO
   //SENDO ASSIM, TEMOS UM ARRAY QUASE ORDENADO
	public static void quaseOrdenado(Geracao algoritmo) {
		algoritmo.crescente();
		
		int n = algoritmo.array.length;
		int trocas = n / 10;
		java.util.Random rand = new java.util.Random();
		
		for (int i = 0; i < trocas; i++) {
			int pos1 = rand.nextInt(n);
			int pos2 = rand.nextInt(n);
			algoritmo.swap(pos1, pos2);
		}
	}
	
	public static void main(String[] args) {
		
		int[] tamanhos = {100, 1000, 10000, 100000, 1000000};
		int repeticoes = 10;
		String[] tiposArray = {"ORDENADO", "QUASE ORDENADO", "ALEATÓRIO"};
		double somaGeralTempo = 0.0;
		int totalTestes = 0;
		
		System.out.println("=== ANÁLISE DE PERFORMANCE - QUICKSORT ===\n");
		
		System.out.println("Escolha o tipo de array para testar:");
		System.out.println("1 - Arrays ORDENADOS (crescente)");
		System.out.println("2 - Arrays QUASE ORDENADOS (90% ordenados)");
		System.out.println("3 - Arrays ALEATÓRIOS");
		System.out.print("Digite sua opção (1-3): ");
		
		int opcao = MyIO.readInt();
		int tipoIndex = opcao - 1;
		
		if (tipoIndex < 0 || tipoIndex >= tiposArray.length) {
			System.out.println("Opção inválida! Usando arrays ALEATÓRIOS por padrão.");
			tipoIndex = 2;
		}
		
		System.out.println("\n╔" + "═".repeat(60) + "╗");
		System.out.printf("║ %-58s ║%n", "            TESTE COM ARRAYS " + tiposArray[tipoIndex]);
		System.out.println("╚" + "═".repeat(60) + "╝");
		System.out.println();
		
		for (int tamanho : tamanhos) {
			System.out.println("TABELA - TAMANHO: " + String.format("%,d", tamanho) + " elementos (" + tiposArray[tipoIndex] + ")");
			System.out.println("╔" + "═".repeat(58) + "╗");
			
			System.out.printf("║ %-10s │ %-22s │ %-18s ║%n", "Repetição", "Quantidade de elementos", "Tempo execução (s)");
			System.out.println("╠" + "═".repeat(12) + "┼" + "═".repeat(24) + "┼" + "═".repeat(20) + "╣");
			
			double somaTempo = 0.0;
			
			for (int i = 1; i <= repeticoes; i++) {
				Geracao algoritmo = new Quicksort(tamanho);
				
				switch (tipoIndex) {
					case 0: // ORDENADO
						algoritmo.crescente();
						break;
					case 1: // QUASE ORDENADO
						quaseOrdenado(algoritmo);
						break;
					case 2: // ALEATÓRIO
						algoritmo.aleatorio();
						break;
				}
				
				double inicio = algoritmo.now();
				algoritmo.sort();
				double fim = algoritmo.now();
				
				double tempoExecucao = (fim - inicio) / 1000.0;
				somaTempo += tempoExecucao;
				
				System.out.printf("║ %-10d │ %-22s │ %18s ║%n", i, String.format("%,d", tamanho), String.format("%18.6f", tempoExecucao));
				
				if (!algoritmo.isOrdenado()) {
					System.out.println("ERRO: Array não foi ordenado corretamente!");
				}
			}
			
			// ESSA PARTE DO CÓDIGO ESTÁ RESPONSÁVEL PELO CALCULO DA MÉDIA
			double mediaTempo = somaTempo / repeticoes;
			System.out.println("╠" + "═".repeat(58) + "╣");
			System.out.printf("║ %-35s │ %18s ║%n", "MÉDIA PARA " + String.format("%,d", tamanho) + " ELEMENTOS:", String.format("%18.6f", mediaTempo));
			System.out.println("╚" + "═".repeat(58) + "╝");
			System.out.println();
			
			somaGeralTempo += somaTempo;
			totalTestes += repeticoes;
		}
		
		// EXIBICAO DA MEDIA GERAL
		double mediaGeral = somaGeralTempo / totalTestes;
		System.out.println("╔" + "═".repeat(60) + "╗");
		System.out.printf("║ %-58s ║%n", "                    RESUMO GERAL");
		System.out.println("╠" + "═".repeat(60) + "╣");
		System.out.printf("║ %-40s: %15d ║%n", "Total de testes executados", totalTestes);
		System.out.printf("║ %-40s: %15s ║%n", "Tipo de array testado", tiposArray[tipoIndex]);
		System.out.printf("║ %-40s: %15d ║%n", "Tamanhos de arrays testados", tamanhos.length);
		System.out.printf("║ %-40s: %15d ║%n", "Repetições por configuração", repeticoes);
		System.out.printf("║ %-40s: %15.6f ║%n", "Média geral de execução (s)", mediaGeral);
		System.out.println("╚" + "═".repeat(60) + "╝");
	}
}
