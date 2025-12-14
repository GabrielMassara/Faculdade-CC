import java.util.Scanner;

//CLASSE UTILIZADA PARA ORGANIZAR OS VALORES REFERENTES A DETERMINADA LETRA NO INPUT
class Parametros {
    private char letra;
    private int valor;

    public Parametros(char letra, int valor) {
        this.letra = letra;
        this.valor = valor;
    }

    public char getLetra() {
        return letra;
    }

    public int getValor() {
        return valor;
    }
}

// CLASSE PARA ORGANIZAR OS DADOS DA PILHA EM UM ÚNICO OBJETO
class ElementoPilha {
    private String condicional;
    private int indiceResultado;
    private int tamanhoParametros;
    private String operador;
    private int estado; // 0=inicio, 1=aguardando resultados, 2=finalizado

    public ElementoPilha() {
        this.condicional = "";
        this.indiceResultado = 0;
        this.tamanhoParametros = 0;
        this.operador = "";
        this.estado = 0;
    }

    public String getCondicional() {
        return condicional;
    }

    public void setCondicional(String condicional) {
        this.condicional = condicional;
    }

    public int getIndiceResultado() {
        return indiceResultado;
    }

    public void setIndiceResultado(int indiceResultado) {
        this.indiceResultado = indiceResultado;
    }

    public int getTamanhoParametros() {
        return tamanhoParametros;
    }

    public void setTamanhoParametros(int tamanhoParametros) {
        this.tamanhoParametros = tamanhoParametros;
    }

    public String getOperador() {
        return operador;
    }

    public void setOperador(String operador) {
        this.operador = operador;
    }

    public int getEstado() {
        return estado;
    }

    public void setEstado(int estado) {
        this.estado = estado;
    }
}

public class Algebra {

    public static String removerEspacosAntesDepois(String texto) {
        Boolean status1 = false;
        Boolean status2 = false;
        String textoAntes = "";
        String textoFinal = "";

        // REMOVE OS ESPACOS ANTES DE COMECAR O TEXTO
        for (int i = 0; i < texto.length(); i++) {
            if (texto.charAt(i) != ' ' && !status1) {
                status1 = true;
                textoAntes += texto.charAt(i);
            } else if (status1) {
                // DEPOIS QUE ENCONTRA TEXTO ADICIONA ELE ADICIONA A STRING FINAL E PARA DE
                // REMOVER ESPACOS
                textoAntes += texto.charAt(i);
            }
        }

        // REMOVE OS ESPACOES DO FINAL DO TEXTO
        // PERCORRE DE TRAS PARA FRENTE
        for (int i = textoAntes.length() - 1; i >= 0; i--) {
            if (textoAntes.charAt(i) != ' ' && !status2) {
                status2 = true;
                textoFinal = textoAntes.charAt(i) + textoFinal;
            } else if (status2) {
                // DEPOIS QUE ENCONTRA TEXTO ADICIONA ELE ADICIONA A STRING FINAL E PARA DE
                // REMOVER ESPACOS
                textoFinal = textoAntes.charAt(i) + textoFinal;
            }
        }
        return textoFinal;
    }

    // FUNCAO PARA CORTAR STRING RECEBIDA A PARTIR DE UM INICIO INCLUSIVO E FIM
    // EXCLUSIVO
    public static String cortarString(String texto, int inicio, int fim) {
        String resultado = "";
        for (int i = inicio; i < fim; i++) {
            resultado += texto.charAt(i);
        }
        return resultado;
    }

    // FUNCAO PARA CORTAR STRING RECEBIDA A PARTIR DE UM INICIO INCLUSIVO
    public static String cortarString(String texto, int inicio) {
        String resultado = "";
        for (int i = inicio; i < texto.length(); i++) {
            resultado += texto.charAt(i);
        }
        return resultado;
    }

    // COMPARAR IGUALDADE ENTRE DUAS STRINGS
    public static Boolean equals(String texto1, String texto2) {
        for (int i = 0; i < texto1.length(); i++) {
            if (texto1.charAt(i) != texto2.charAt(i)) {
                return false;
            }
        }
        return true;
    }

    // PEGA OS VALORES DOS PARAMETROS REFERENTE A LETRA
    public static int getValorParametro(Parametros[] parametros, char letra) {
        for (Parametros p : parametros) {
            if (p.getLetra() == letra) {
                return p.getValor();
            }
        }
        return -1;
    }

    public static String[] divideCondicional(String condicional) {
        int nivel = 0;

        // INDEX DA PRIMEIRA VIRGULA -1 E PADRÃO CASO NAO ENCONTRE
        int indexPrimeiraVirgula = -1;
        int indexSegundaVirgula = -1;
        int indexTerceiraVirgula = -1;

        // PERCORRE TODOS OS CARACTERES
        for (int i = 0; i < condicional.length(); i++) {
            if (condicional.charAt(i) == '(') {
                nivel++;
            } else if (condicional.charAt(i) == ')') {
                nivel--;
            }
            // QUANDO TODAS OS PARENTESES ABERTOS FOREM FECHADOS
            if (nivel == 0 && condicional.charAt(i) == ',') {
                if (indexPrimeiraVirgula == -1) {
                    indexPrimeiraVirgula = i;
                } else if (indexSegundaVirgula == -1) {
                    indexSegundaVirgula = i;
                } else if (indexTerceiraVirgula == -1) {
                    indexTerceiraVirgula = i;
                }
            }
        }
        // SE A SEGUNDA VIRGULA FOR -1 ISSO SIGNIFICA QUE SO TEM DOIS PARAMETROS
        if (indexSegundaVirgula == -1) {
            String p1 = removerEspacosAntesDepois(cortarString(condicional, 0, indexPrimeiraVirgula));
            String p2 = removerEspacosAntesDepois(cortarString(condicional, indexPrimeiraVirgula + 1));
            return new String[] { p1, p2 };
        } else if (indexTerceiraVirgula == -1) {
            // CASO CONTRARIO TEM 3 PARAMETROS
            String p1 = removerEspacosAntesDepois(cortarString(condicional, 0, indexPrimeiraVirgula));
            String p2 = removerEspacosAntesDepois(
                    cortarString(condicional, indexPrimeiraVirgula + 1, indexSegundaVirgula));
            String p3 = removerEspacosAntesDepois(cortarString(condicional, indexSegundaVirgula + 1));
            return new String[] { p1, p2, p3 };
        } else {
            // CASO CONTRARIO TEM 4 PARAMETROS
            String p1 = removerEspacosAntesDepois(cortarString(condicional, 0, indexPrimeiraVirgula));
            String p2 = removerEspacosAntesDepois(
                    cortarString(condicional, indexPrimeiraVirgula + 1, indexSegundaVirgula));
            String p3 = removerEspacosAntesDepois(
                    cortarString(condicional, indexSegundaVirgula + 1, indexTerceiraVirgula));
            String p4 = removerEspacosAntesDepois(cortarString(condicional, indexTerceiraVirgula + 1));
            return new String[] { p1, p2, p3, p4 };
        }
    }

    // POS ABRE É A POSICAO DO CARACTERE ( QUE EU QUERO FECHAR
    private static int acharFecha(String condicional, int posAbre) {
        int nivel = 1;
        for (int i = posAbre + 1; i < condicional.length(); i++) {
            char caractere = condicional.charAt(i);
            if (caractere == '(')
                nivel++;
            else if (caractere == ')') {
                nivel--;
                if (nivel == 0)
                    return i;
            }
        }
        return -1; // CASO NÃO ENCONTRE
    }

    public static int processarCondicional(String condicional, Parametros[] parametros) {
        // ARRAY DE OBJETOS PARA SIMULAR PILHA
        ElementoPilha[] pilha = new ElementoPilha[1000];
        for (int i = 0; i < 1000; i++) {
            pilha[i] = new ElementoPilha();
        }

        int[] pilhaResultados = new int[1000]; // ARRAY SEPARADO PARA ARMAZENAR RESULTADOS DOS PARAMETROS
        int topoPilha = 0;
        int indiceResultados = 0; // INDICE PARA ARMAZENAR RESULTADOS

        // EMPILHA A CONDICIONAL INICIAL
        pilha[topoPilha].setCondicional(condicional);
        pilha[topoPilha].setEstado(0);
        topoPilha++;

        while (topoPilha > 0) {
            topoPilha--; // DESEMPILHA
            String condicionalAtual = pilha[topoPilha].getCondicional();
            int estadoAtual = pilha[topoPilha].getEstado();

            if (estadoAtual == 0) { // INICIO, PROCESSA A CONDICIONAL
                Boolean statusParenteses = false;
                for (int posCaracter = 0; posCaracter < condicionalAtual.length() && !statusParenteses; posCaracter++) {
                    // VERIFICA SE ABRIU UMA CONDICAO POR MEIO DO CARACTERE (
                    if (condicionalAtual.charAt(posCaracter) == '(') {
                        statusParenteses = true;
                        String operador = "";
                        String[] parametroStrings = null;
                        String textoComParametros = "";

                        // LE O OPERADOR
                        for (int i = posCaracter - 1; condicionalAtual.charAt(i) != ' '
                                && condicionalAtual.charAt(i) != '('; i--) {
                            operador = condicionalAtual.charAt(i) + operador;
                        }

                        if (equals(operador, "and") || equals(operador, "or")) {
                            // REMOVE O OPERADOR ANTES E PEGA O CONTEUDO ENTRE PARENTESES

                            // ENCONTRA A POSICAO DO CARACTERE ) QUE FECHA O COLCHETES QUE ESTA NA POSICAO
                            // posCaracter
                            int fecha = acharFecha(condicionalAtual, posCaracter);
                            textoComParametros = cortarString(condicionalAtual, posCaracter + 1, fecha);

                            // DIVIDE A CONDICIONAL, SEPARANDO OS PARAMETROS
                            parametroStrings = divideCondicional(textoComParametros);

                            // CONFIGURA ESTA OPERACAO PARA AGUARDAR RESULTADOS
                            pilha[topoPilha].setOperador(operador);
                            pilha[topoPilha].setIndiceResultado(indiceResultados);
                            pilha[topoPilha].setTamanhoParametros(parametroStrings.length);
                            pilha[topoPilha].setEstado(1);
                            topoPilha++;

                            // EMPILHA OS PARAMETROS NA ORDEM REVERSA
                            for (int i = parametroStrings.length - 1; i >= 0; i--) {
                                if (parametroStrings[i].length() > 1) {
                                    // TEM MAIS CONDICOES DENTRO, EMPILHA PARA PROCESSAR
                                    pilha[topoPilha].setCondicional(" " + parametroStrings[i]);
                                    pilha[topoPilha].setEstado(0);
                                    topoPilha++;
                                } else {
                                    // É UM PARÂMETRO SIMPLES, CALCULA DIRETAMENTE E ARMAZENA O RESULTADO
                                    int valor = getValorParametro(parametros, parametroStrings[i].charAt(0));
                                    pilhaResultados[indiceResultados] = valor;
                                    indiceResultados++;
                                }
                            }

                        } else if (equals(operador, "not")) {
                            // REMOVE O OPERADOR ANTES E PEGA O CONTEUDO ENTRE PARENTESES
                            int fecha = acharFecha(condicionalAtual, posCaracter);
                            textoComParametros = cortarString(condicionalAtual, posCaracter + 1, fecha);

                            // CONFIGURA ESTA OPERACAO PARA AGUARDAR RESULTADO
                            pilha[topoPilha].setOperador(operador);
                            pilha[topoPilha].setIndiceResultado(indiceResultados);
                            pilha[topoPilha].setTamanhoParametros(1);
                            pilha[topoPilha].setEstado(1);
                            topoPilha++;

                            if (textoComParametros.length() > 1) {
                                // TEM SUBCONDIÇÕES, EMPILHA PARA PROCESSAR
                                pilha[topoPilha].setCondicional(" " + textoComParametros);
                                pilha[topoPilha].setEstado(0);
                                topoPilha++;
                            } else {
                                // É UM PARÂMETRO SIMPLES, CALCULA DIRETAMENTE E ARMAZENA
                                int valor = getValorParametro(parametros, textoComParametros.charAt(0));
                                pilhaResultados[indiceResultados] = valor;
                                indiceResultados++;
                            }
                        }
                    }
                }

            } else if (estadoAtual == 1) { // PROCESSAMENTO, COLETA RESULTADOS E CALCULA
                String operador = pilha[topoPilha].getOperador();
                int inicioResultados = pilha[topoPilha].getIndiceResultado();
                int tamanhoParametros = pilha[topoPilha].getTamanhoParametros();
                int resultado = 0;

                if (equals(operador, "and")) {
                    resultado = 1;
                    // COLETA TODOS OS RESULTADOS DOS PARÂMETROS
                    for (int i = 0; i < tamanhoParametros; i++) {
                        resultado = resultado & pilhaResultados[inicioResultados + i];
                    }

                } else if (equals(operador, "or")) {
                    resultado = 0;
                    // COLETA TODOS OS RESULTADOS DOS PARÂMETROS
                    for (int i = 0; i < tamanhoParametros; i++) {
                        resultado = resultado | pilhaResultados[inicioResultados + i];
                    }

                } else if (equals(operador, "not")) {
                    // PEGA O RESULTADO DO ÚNICO PARÂMETRO
                    int valor = pilhaResultados[inicioResultados];
                    resultado = (valor == 1) ? 0 : 1;
                }

                // ARMAZENA O RESULTADO DESTA OPERAÇÃO
                pilhaResultados[inicioResultados] = resultado;
                // AJUSTA O INDICE PARA SOBRESCREVER OS RESULTADOS INTERMEDIARIOS
                indiceResultados = inicioResultados + 1;
            }
        }

        // O RESULTADO FINAL DEVE ESTAR NO INDICE 0
        return pilhaResultados[0];
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int qtdParametros = sc.nextInt();

        // CONDICAO PARA EXECUCAO DO PROGRAMA
        while (qtdParametros > 0) {
            // VETOR DE PARAMETROS
            Parametros[] parametros = new Parametros[qtdParametros];
            for (int i = 0; i < qtdParametros; i++) {
                int valor = sc.nextInt();
                parametros[i] = new Parametros((char) ('A' + i), valor);
            }

            // ARMAZENA A CONDICIONAL COMPLETA, EX: and(A , and(A, B))
            String condicional = sc.nextLine();

            System.out.println(processarCondicional(condicional, parametros));

            qtdParametros = sc.nextInt();
        }

        sc.close();
    }
}