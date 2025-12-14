import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

class Celula {
    public Game game;
    public Celula prox;

    public Celula(Game game) {
        this(game, null);
    }

    public Celula(Game game, Celula prox) {
        this.game = game;
        this.prox = prox;
    }
}

class Fila {
    public Celula primeiro;
    public Celula ultimo;

    //CRIA MINHA FILA FLEXIVEL COM NO CABECA
    public Fila() {
        Celula cabeca = new Celula(null);
        this.primeiro = this.ultimo = cabeca;
    }

    //METODO QUE INSERE
    public void inserir(Game game) {
        Celula nova = new Celula(game);
        if (primeiro == ultimo) {
            primeiro.prox = nova;
            ultimo = nova;
        } else {
            ultimo.prox = nova;
            ultimo = nova;
        }
    }

    //METODO QUE REMOVE O PRIMEIRO ELEMENTO DA FILA, AQUELE QUE O NO CABECA APONTA, POIS DEVE SER FIRST IN, FIRST OUT
    public String remover() {
        Celula aux = primeiro.prox;
        primeiro.prox = primeiro.prox.prox;
        aux.prox = null;
        String nome = aux.game.getNome();
        aux = null;
        return nome;
    }

    //IMPRIME TUDO QUE TEM NA FILA
    public void imprimir() {
        int index = 0;
        for (Celula i = primeiro.prox; i != null; i = i.prox) {
            System.out.println("[" + index + "] => " + i.game.getId() + " ## " +
                    (i.game.getNome() != null ? i.game.getNome() : " ") + " ## " +
                    (i.game.getReleaseDate() != null ? i.game.getReleaseDate().getData() : " ") + " ## " +
                    i.game.getEstimatedOwners() + " ## " +
                    i.game.getPrice() + " ## " +
                    i.game.listarArray(i.game.getSupportedLanguages()) + " ## " +
                    i.game.getMetacriticScore() + " ## " +
                    i.game.getUserScore() + " ## " +
                    i.game.getAchievements() + " ## " +
                    i.game.listarArray(i.game.getPublishers()) + " ## " +
                    i.game.listarArray(i.game.getDevelopers()) + " ## " +
                    i.game.listarArray(i.game.getCategories()) + " ## " +
                    i.game.listarArray(i.game.getGenre()) + " ## " +
                    i.game.listarArray(i.game.getTags()) + " ##");
            index++;
        }
    }
}

class Game {
    private int id;
    private String nome;
    private Data releaseDate;
    private int estimatedOwners;
    private float price;
    private String supportedLanguages[];
    private int metacriticScore;
    private float userScore;
    private int achievements;
    private String publishers[];
    private String developers[];
    private String categories[];
    private String genre[];
    private String tags[];

    public String listarArray(String array[]) {
        if (array == null) {
            return "[]";
        }
        String resposta = "[";
        for (int i = 0; i < array.length; i++) {
            resposta += array[i];
            if (i != (array.length - 1))
                resposta += ", ";
        }
        resposta += "]";
        return resposta;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public Data getReleaseDate() {
        return releaseDate;
    }

    public void setReleaseDate(Data releaseDate) {
        this.releaseDate = releaseDate;
    }

    public int getEstimatedOwners() {
        return estimatedOwners;
    }

    public void setEstimatedOwners(int estimatedOwners) {
        this.estimatedOwners = estimatedOwners;
    }

    public float getPrice() {
        return price;
    }

    public void setPrice(float price) {
        this.price = price;
    }

    public String[] getSupportedLanguages() {
        return supportedLanguages;
    }

    public void setSupportedLanguages(String[] supportedLanguages) {
        this.supportedLanguages = supportedLanguages;
    }

    public int getMetacriticScore() {
        return metacriticScore;
    }

    public void setMetacriticScore(int metacriticScore) {
        this.metacriticScore = metacriticScore;
    }

    public float getUserScore() {
        return userScore;
    }

    public void setUserScore(float userScore) {
        this.userScore = userScore;
    }

    public int getAchievements() {
        return achievements;
    }

    public void setAchievements(int achievements) {
        this.achievements = achievements;
    }

    public String[] getPublishers() {
        return publishers;
    }

    public void setPublishers(String[] publishers) {
        this.publishers = publishers;
    }

    public String[] getDevelopers() {
        return developers;
    }

    public void setDevelopers(String[] developers) {
        this.developers = developers;
    }

    public String[] getCategories() {
        return categories;
    }

    public void setCategories(String[] categories) {
        this.categories = categories;
    }

    public String[] getGenre() {
        return genre;
    }

    public void setGenre(String[] genre) {
        this.genre = genre;
    }

    public String[] getTags() {
        return tags;
    }

    public void setTags(String[] tags) {
        this.tags = tags;
    }

}

class Data {
    private int dia;
    private int mes;
    private int ano;

    public Data(int dia, int mes, int ano) {
        this.dia = dia;
        this.mes = mes;
        this.ano = ano;
    }

    public String getData() {
        return String.format("%02d/%02d/%d", dia, mes, ano);
    }

    public int getDia() {
        return dia;
    }

    public void setDia(int dia) {
        this.dia = dia;
    }

    public int getMes() {
        return mes;
    }

    public void setMes(int mes) {
        this.mes = mes;
    }

    public int getAno() {
        return ano;
    }

    public void setAno(int ano) {
        this.ano = ano;
    }
}

public class PrincipalGame {

    public static int stringParaInteiro(String texto) {
        int contador = 1;
        int resposta = 0;
        for (int i = texto.length() - 1; i >= 0; i--) {
            resposta += (texto.charAt(i) - '0') * contador;
            contador *= 10;
        }
        return resposta;
    }

    public static float stringParaFloat(String texto) {
        String inteira = "";
        String decimal = "";
        Boolean controle = true; // VERDADEIRO SALVA A PARTE INTEIRA E FALSO SALVA A PARTE DECIMAL

        int inteiroFinal = 0;
        float decimalFinal = 0;

        //DIVIDE ENTRE A PARTE INTEIRA E A DECIMAL
        for (int i = 0; i < texto.length(); i++) {
            if(texto.charAt(i) != '.') {
                if (controle) {
                    inteira += texto.charAt(i);
                } else if (!controle) {
                    decimal += texto.charAt(i);
                }
            } else {
                controle = false;
            }
        }

        // FAZ A PARTE DECIMAL
        int divisor = 10;
        for (int i = 0; i < decimal.length(); i++) {
            decimalFinal += (decimal.charAt(i) - '0') / (float) divisor;
            divisor *= 10;
        }

        //CONVERTE PARA INTEIRO
        inteiroFinal = stringParaInteiro(inteira);
        return inteiroFinal + decimalFinal;
    }

    public static Data textoParaDate(String texto) {
        // RECEBE UM TEXTO NESSE FORMATO: "Oct 18, 2018"
        String mes = "";
        String dia = "";
        String ano = "";

        int mesFinal;
        // COMECA DO 1 E TEMINA EM texto.length()-1 PARA REMOVER AS ASPAS DUPLAS DO
        // INICIO DE DO FIM
        for (int i = 1; i < texto.length()-1; i++) {
            if (i <= 3) {
                mes += texto.charAt(i);
            } else if (texto.length() == 14 && i > 4 && i <= 6) {
                dia += texto.charAt(i);
            } else if (texto.length() == 13 && i > 4 && i < 6) {
                dia += texto.charAt(i);
            } else if (texto.length() == 14 && i > 8) {
                ano += texto.charAt(i);
            } else if (texto.length() == 13 && i > 7) {
                ano += texto.charAt(i);
            }
        }

        // DEFINE O MES
        switch (mes) {
            case "Jan":
                mesFinal = 1;
                break;
            case "Feb":
                mesFinal = 2;
                break;
            case "Mar":
                mesFinal = 3;
                break;
            case "Apr":
                mesFinal = 4;
                break;
            case "May":
                mesFinal = 5;
                break;
            case "Jun":
                mesFinal = 6;
                break;
            case "Jul":
                mesFinal = 7;
                break;
            case "Aug":
                mesFinal = 8;
                break;
            case "Sep":
                mesFinal = 9;
                break;
            case "Oct":
                mesFinal = 10;
                break;
            case "Nov":
                mesFinal = 11;
                break;
            case "Dec":
                mesFinal = 12;
                break;
            default:
                mesFinal = 1;
                break;
        }
        Data data = new Data(stringParaInteiro(dia), mesFinal, stringParaInteiro(ano));
        return data;

    }

    //FUNCAO PARA CORTAR STRING RECEBIDA A PARTIR DE UM INICIO INCLUSIVO
    public static String cortarString(String texto, int inicio) {
        String resultado = "";
        for (int i = inicio; i < texto.length(); i++) {
            resultado += texto.charAt(i);
        }
        return resultado;
    }

    public static String[] separarArrayPais(String texto) {
        //CONTA QUANTOS ELEMENTOS TEM
        int n=1;
        for (int i = 1; i < texto.length()-1; i++) {
            if(texto.charAt(i) == ',')
                n++;
        }

        String aux = "";
        String novoArray[] = new String[n];
        int contador = 0;

        Boolean primeiroElemento = true;

        //COMECA EM 2 PARA REMOVER ABERTURA DE COLCHETE
        for (int i = 2; i < texto.length()-1; i++) {
            if(texto.charAt(i) == ',' || i == (texto.length()-2)) {
                //SE NAO FOR O PRIMEIRO ELEMENTO, RETIRA O SEGUINTE TEXTO DO INICIO: ", "
                if(!primeiroElemento) {
                    aux = cortarString(aux, 2);
                    
                } else {
                    primeiroElemento = false;
                }
                novoArray[contador] = aux;
                contador++;
                aux = "";
            }
            if(texto.charAt(i) != '\'') {
                aux+= texto.charAt(i);
            }
        }

        return novoArray;
    }

    public static String[] separarArrayPublisher(String texto) {
        //CONTA QUANTOS ELEMENTOS TEM
        int n=1;
        for (int i = 1; i < texto.length()-1; i++) {
            if(texto.charAt(i) == ',')
                n++;
        }

        String aux = "";
        String novoArray[] = new String[n];
        int contador = 0;

        Boolean primeiroElemento = true;

        int iInicial=0;
        int contadorAspasDuplas = 0;
        Boolean contemVirgula = false;
        for (int i = 0; i < texto.length()-1; i++) {
            if(texto.charAt(i) == '"')
                contadorAspasDuplas++;
            else if(texto.charAt(i) == ',')
                contemVirgula = true;
        }
        if(contadorAspasDuplas >= 2)
            iInicial = 1;

        if(contemVirgula) {
            for (int i = iInicial; i < texto.length()-1; i++) {
                if(texto.charAt(i) == ',' || i == (texto.length()-2)) {
                    //SE NAO FOR O PRIMEIRO ELEMENTO, RETIRA O SEGUINTE TEXTO DO INICIO: ", "
                    if(!primeiroElemento) {
                        aux = cortarString(aux, 1);
                        
                    } else {
                        primeiroElemento = false;
                    }
                    novoArray[contador] = aux;
                    contador++;
                    aux = "";
                }
                if(texto.charAt(i) != '\'') {
                    aux+= texto.charAt(i);
                }
            }
        } else {
            novoArray[0] = texto;
        }

        return novoArray;
    }

    public static String[] separarArrayCategories(String texto) {
        //CONTA QUANTOS ELEMENTOS TEM
        int n=1;
        for (int i = 1; i < texto.length()-1; i++) {
            if(texto.charAt(i) == ',')
                n++;
        }

        String aux = "";
        String novoArray[] = new String[n];
        int contador = 0;

        Boolean primeiroElemento = true;

        int iInicial=0;
        int contadorAspasDuplas = 0;
        Boolean contemVirgula = false;
        for (int i = 0; i < texto.length()-1; i++) {
            if(texto.charAt(i) == '"')
                contadorAspasDuplas++;
            else if(texto.charAt(i) == ',')
                contemVirgula = true;
        }
        if(contadorAspasDuplas >= 2)
            iInicial = 1;

        if(contemVirgula) {
            for (int i = 1; i < texto.length()-1; i++) {
                if(texto.charAt(i) == ',' || i == (texto.length()-2)) {
                    //NAO ADICIONA A VIRGULA MAS ADICIONA O ULTIMO CARACTERE DA ULTIMA PALAVRA
                    if(texto.charAt(i) != ',')
                        aux+= texto.charAt(i);
                    //SE NAO FOR O PRIMEIRO ELEMENTO, RETIRA O SEGUINTE TEXTO DO INICIO: ", "
                    if(!primeiroElemento) {
                        aux = cortarString(aux, 1);
                    } else {
                        primeiroElemento = false;
                    }
                    novoArray[contador] = aux;
                    contador++;
                    aux = "";
                }
                if(texto.charAt(i) != '\'') {
                    aux+= texto.charAt(i);
                }
            }
        } else {
            novoArray[0] = texto;
        }

        return novoArray;
    }

    public static String[] separarArray(String texto) {
        //CONTA QUANTOS ELEMENTOS TEM
        int n=1;
        for (int i = 1; i < texto.length()-1; i++) {
            if(texto.charAt(i) == ',')
                n++;
        }

        String aux = "";
        String novoArray[] = new String[n];
        int contador = 0;

        Boolean primeiroElemento = true;

        //COMECA EM 2 PARA REMOVER ABERTURA DE COLCHETE
        for (int i = 2; i < texto.length()-1; i++) {
            if(texto.charAt(i) == ',' || i == (texto.length()-2)) {
                //SE NAO FOR O PRIMEIRO ELEMENTO, RETIRA O SEGUINTE TEXTO DO INICIO: ", "
                if(!primeiroElemento) {
                    aux = cortarString(aux, 1);
                    
                } else {
                    primeiroElemento = false;
                }
                novoArray[contador] = aux;
                contador++;
                aux = "";
            }
            if(texto.charAt(i) != '\'') {
                aux+= texto.charAt(i);
            }
        }

        return novoArray;
    }

    public static Game lerGame(String linha) {
        Game game = new Game();

        String valor = "";
        int parametro = 0;

        Boolean aspasAbertas = false;

        for (int i = 0; i < linha.length(); i++) {
            if(linha.charAt(i) == '"') {
                aspasAbertas = !aspasAbertas;
            }
            if (linha.charAt(i) != ',') {
                valor += linha.charAt(i);
            } else if (aspasAbertas) {
                valor += linha.charAt(i);
            } else {
                switch (parametro) {
                    case 0:
                        game.setId(stringParaInteiro(valor));
                        break;

                    case 1:
                        game.setNome(valor);
                        break;

                    case 2:
                        game.setReleaseDate(textoParaDate(valor));
                        break;

                    case 3:
                        game.setEstimatedOwners(stringParaInteiro(valor));
                        break;

                    case 4:
                        game.setPrice(stringParaFloat(valor));
                        break;

                    case 5:
                        game.setSupportedLanguages(separarArrayPais(valor));
                        break;

                    case 6:
                        game.setMetacriticScore(stringParaInteiro(valor));
                        break;

                    case 7:
                        game.setUserScore(stringParaFloat(valor));
                        break;

                    case 8:
                        game.setAchievements(stringParaInteiro(valor));
                        break;

                    case 9:
                        game.setPublishers(separarArrayPublisher(valor));
                        break;

                    case 10:
                        game.setDevelopers(separarArrayPublisher(valor));
                        break;

                    case 11:
                        game.setCategories(separarArrayCategories(valor));
                        break;

                    case 12:
                        game.setGenre(separarArrayPublisher(valor));
                        break;

                    case 13:
                        game.setTags(separarArrayPublisher(valor));
                        break;

                    default:
                        break;
                }
                parametro++;
                valor = "";
            }
        }

        return game;
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

    //ESSA FUNCAO INSERE O JOGO NA FILA
    public static void inserirTudoFila(int id, Game arrayGames[], Fila fila) {
        for (Game game : arrayGames) {
            if (game != null && game.getId() == id) {
                fila.inserir(game);
            }
        }
    }

    public static Game buscarPorId(int id, Game arrayGames[]) {
        for (Game game : arrayGames) {
            if (game != null && game.getId() == id) {
                return game;
            }
        }
        Game jogoErro = new Game();
        jogoErro.setId(-1);
        return jogoErro;
    }

    //RECEBE UM COMANDO EXEMPLO: I 40930 E RETORNA O VALOR DO ID
    public static int pegarValorOperacao(String comando) {
        String resultado = "";
        for(int i = 2; i < comando.length(); i++) {
            if(comando.charAt(i) != ' ')
                resultado += comando.charAt(i);
        }
        return stringParaInteiro(resultado);
    }

    //RECEBE UM COMANDO EXEMPLO: I* 40 589780 E RETORNA UM ARRAY COM OS DOIS INTEIROS
    public static int[] pegarValorOperacaoDupla(String comando) {
        String valor1 = "";
        String valor2 = "";
        int i = 3;
        for(; i < comando.length() && comando.charAt(i) != ' '; i++) {
            valor1 += comando.charAt(i);
        }

        for(i++; i < comando.length(); i++) {
            if(comando.charAt(i) != ' ') {
                valor2 += comando.charAt(i);
            }
        }
        int resposta[] = new int[2];
        resposta[0] = stringParaInteiro(valor1);
        resposta[1] = stringParaInteiro(valor2);
        return resposta;
    }

    public static void main(String args[]) throws IOException {
        BufferedReader buffRead = new BufferedReader(new FileReader("/tmp/games.csv"));
        String linha = "";
        Boolean status = true;
        int contadorLinha = 0;

        Game arrayGames[] = new Game[10000];
        int index = 0;
        while (status) {
            if (linha != null) {
                if (contadorLinha > 1) {
                    //ADICIONA A VIRGULA NO FINAL PARA A FUNCAO LERGAME IDENTIFICAR O FIM DO PARAMETRO
                    linha = linha+=" , ";
                    Game tmp = lerGame(linha);
                    arrayGames[index] = tmp;
                    index++;
                }
            } else {
                status = false;
            }
            try {
                linha = buffRead.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            contadorLinha++;
        }
        buffRead.close();

        //CRIA A LISTA TAD
        Fila fila = new Fila();

        //FAZ AS BUSCAS
        Scanner sc = new Scanner(System.in);
        String id = sc.nextLine();

        //LE ATE ENCONTRAR "FIM"
        while (!equals(id, "FIM")) {
            inserirTudoFila(stringParaInteiro(id), arrayGames, fila);
            id = sc.nextLine();
        }

        //LE O VALOR N PARA A QUANTIDADE DE COMANDOS
        int n = 0;
        if (sc.hasNextInt()) {
            n = sc.nextInt();
            sc.nextLine();
        }

        for (int i = 0; i < n; i++) {
            String comando = sc.nextLine();
            String operacao = "";
            
            operacao += comando.charAt(0);

            switch (operacao) {
                case "I":
                    fila.inserir(buscarPorId(pegarValorOperacao(comando), arrayGames));
                    break;

                case "R":
                    System.out.println("(R) "+fila.remover());
                    break;
            }
        }

        fila.imprimir();
    }
}

