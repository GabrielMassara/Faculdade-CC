#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Data
{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct Game
{
    int id;
    char *nome;
    Data releaseDate;
    int estimatedOwners;
    float price;
    char **supportedLanguages;
    int numSupportedLanguages;
    int metacriticScore;
    float userScore;
    int achievements;
    char **publishers;
    int numPublishers;
    char **developers;
    int numDevelopers;
    char **categories;
    int numCategories;
    char **genre;
    int numGenre;
    char **tags;
    int numTags;
} Game;

int stringParaInteiro(char texto[]) {
    int qtdCaracteres;
    for(qtdCaracteres=0; texto[qtdCaracteres] != '\0' && texto[qtdCaracteres] != '\n'; qtdCaracteres++);

    int contador = 1;
    int resposta = 0;
    for(int i=qtdCaracteres-1; i>=0; i--) {
        resposta += (texto[i] - '0') * contador;
        contador *= 10;
    }
    return resposta;
}

int length(char texto[]) {
    int contador;
    for(contador=0; texto[contador] != '\0'; contador++);
    return contador;
}

float stringParaFloat(char texto[]) {
    char inteira[100];
    int indexInteira = 0;
    char decimal[100];
    int indexDecimal = 0;
    int controle = 1; // 1 SALVA A PARTE INTEIRA E 0 SALVA A PARTE DECIMAL

    int inteiroFinal = 0;
    float decimalFinal = 0;

    //DIVIDE ENTRE A PARTE INTEIRA E A DECIMAL
    for(int i=0; i<length(texto); i++) {
        if(texto[i] != '.') {
            if(controle) {
                inteira[indexInteira] = texto[i];
                indexInteira++;
            } else {
                decimal[indexDecimal] = texto[i];
                indexDecimal++;
            }
        } else {
            controle = 0;
        }
    }
    
    decimal[indexDecimal] = '\0';
    inteira[indexInteira] = '\0';

    //FAZ A PARTE DECIMAL
    float divisor = 10.0;
    for(int i=0; i < length(decimal); i++) {
        decimalFinal += (decimal[i] - '0') / divisor;
        divisor *= 10;
    }

    //CONVERTE PARA INTEIRO
    inteiroFinal = stringParaInteiro(inteira);
    return inteiroFinal + decimalFinal;

}

int stringCompare(char str1[], char str2[]) {
    //0 = DIFERENTES
    //1 = IGUAIS
    if(length(str1) != length(str2))
        return 0;
    for(int i=0; str1[i] != '\0'; i++) {
        //SE TIVER ALGO DIFERENTE RETORNA 0
        if(str1[i] != str2[i])
            return 0;
    }
    return 1;
}

Data textoParaDate(char texto[]) {
    // RECEBE UM TEXTO NESSE FORMATO: "Oct 18, 2018"
    char mes[4];
    int indexMes = 0;

    char dia[3];
    int indexDia = 0;
    
    char ano[5];
    int indexAno = 0;
    

    int mesFinal;
    for(int i=1; texto[i+1] != '\0' && texto[i] != '"'; i++) {
        if(i<=3) {
            mes[indexMes]=texto[i];
            indexMes++;
        } else if(length(texto) == 14 && i > 4 && i <= 6) {
            dia[indexDia] = texto[i];
            indexDia++;
        } else if(length(texto) == 13 && i > 4 && i < 6) {
            dia[indexDia] = texto[i];
            indexDia++;
        } else if(length(texto) == 14 && i > 8) {
            ano[indexAno] = texto[i];
            indexAno++;
        } else if(length(texto) == 13 && i > 7) {
            ano[indexAno] = texto[i];
            indexAno++;
        }
    }

    mes[indexMes] = '\0';
    dia[indexDia] = '\0';
    ano[indexAno] = '\0';

    if(stringCompare(mes, "Jan"))
        mesFinal = 1;
    else if(stringCompare(mes, "Feb"))
        mesFinal = 2;
    else if(stringCompare(mes, "Mar"))
        mesFinal = 3;
    else if(stringCompare(mes, "Apr"))
        mesFinal = 4;
    else if(stringCompare(mes, "May"))
        mesFinal = 5;
    else if(stringCompare(mes, "Jun"))
        mesFinal = 6;
    else if(stringCompare(mes, "Jul"))
        mesFinal = 7;
    else if(stringCompare(mes, "Aug"))
        mesFinal = 8;
    else if(stringCompare(mes, "Sep"))
        mesFinal = 9;
    else if(stringCompare(mes, "Oct"))
        mesFinal = 10;
    else if(stringCompare(mes, "Nov"))
        mesFinal = 11;
    else if(stringCompare(mes, "Dec"))
        mesFinal = 12;
    else
        mesFinal = 1;

    Data data;
    data.dia = stringParaInteiro(dia);
    data.mes = mesFinal;
    data.ano = stringParaInteiro(ano);

    return data;
}

char* cortarString(char texto[], int inicio) {
    int tamanho = length(texto) - inicio;
    char *resultado = (char*)malloc((tamanho + 1) * sizeof(char));
    int indexResultado = 0;

    for(int i = inicio; i < length(texto); i++) {
        resultado[indexResultado] = texto[i];
        indexResultado++;
    }
    resultado[indexResultado] = '\0';

    return resultado;
}

void separarArray(Game *game, char valor[], int tipo) {
    //TIPO = 1 -> supportedLanguages
    //TIPO = 2 -> publishers
    //TIPO = 3 -> developers
    //TIPO = 4 -> categories
    //TIPO = 5 -> genre
    //TIPO = 6 -> tags


    //CONTA QUANTOS ELEMENTOS TEM
    int n = 1;
    for (int i = 1; i < length(valor) - 1; i++) {
        if (valor[i] == ',')
            n++;
    }

    // ALOCA O VETOR DE PONTEIROS
    if(tipo == 1) {
        game->supportedLanguages = (char **)malloc(n * sizeof(char *));
        game->numSupportedLanguages = n;
    } else if(tipo == 2) {
        game->publishers = (char **)malloc(n * sizeof(char *));
        game->numPublishers = n;
    } else if(tipo == 3) {
        game->developers = (char **)malloc(n * sizeof(char *));
        game->numDevelopers = n;
    } else if(tipo == 4) {
        game->categories = (char **)malloc(n * sizeof(char *));
        game->numCategories = n;
    } else if(tipo == 5) {
        game->genre = (char **)malloc(n * sizeof(char *));
        game->numGenre = n;
    } else if(tipo == 6) {
        game->tags = (char **)malloc(n * sizeof(char *));
        game->numTags = n;
    }

    char aux[255];
    int indexAux = 0;

    int contador = 0;

    int primeiroElemento = 1;

    //COMECA EM 2 PARA REMOVER ABERTURA DE COLCHETE
    for (int i = 2; i < length(valor) - 1; i++) {
        if (valor[i] == ',' || i == (length(valor) - 2)) {
            aux[indexAux] = '\0';
            indexAux = 0;
            //SE NAO FOR O PRIMEIRO ELEMENTO, RETIRA O SEGUINTE TEXTO DO INICIO: ", "
            if (!primeiroElemento)
                strcpy(aux, cortarString(aux, 2));
            else
                primeiroElemento = 0;

            if(tipo == 1) {
                game->supportedLanguages[contador] = (char *)malloc(length(aux) + 1);
                strcpy(game->supportedLanguages[contador], aux);
            } else if (tipo == 2) {
               game->publishers[contador] = (char *)malloc(length(aux) + 1);
                strcpy(game->publishers[contador], aux); 
            } else if (tipo == 3) {
               game->developers[contador] = (char *)malloc(length(aux) + 1);
                strcpy(game->developers[contador], aux); 
            } else if (tipo == 4) {
               game->categories[contador] = (char *)malloc(length(aux) + 1);
                strcpy(game->categories[contador], aux); 
            } else if (tipo == 5) {
               game->genre[contador] = (char *)malloc(length(aux) + 1);
                strcpy(game->genre[contador], aux); 
            } else if (tipo == 6) {
               game->tags[contador] = (char *)malloc(length(aux) + 1);
                strcpy(game->tags[contador], aux); 
            }
            contador++;
        }
        if (valor[i] != '\'') {
            aux[indexAux] = valor[i];
            indexAux++;
        }
    }
}

void separarArrayPublisher(Game *game, char valor[], int tipo) {
    //TIPO = 1 -> supportedLanguages
    //TIPO = 2 -> publishers
    //TIPO = 3 -> developers
    //TIPO = 4 -> categories
    //TIPO = 5 -> genre
    //TIPO = 6 -> tags

    //CONTA QUANTOS ELEMENTOS TEM
    int n = 1;
    for (int i = 1; i < length(valor) - 1; i++) {
        if (valor[i] == ',')
            n++;
    }

    char aux[1000] = "";
    int indexAux = 0;
    int contador = 0;
    int primeiroElemento = 1;

    int iInicial = 0;
    int contadorAspasDuplas = 0;
    int contemVirgula = 0;
    
    // CONTA AS ASPAS DUPLAS E VE SE TEM VIRGULA
    for (int i = 0; i < length(valor) - 1; i++) {
        if (valor[i] == '"')
            contadorAspasDuplas++;
        else if (valor[i] == ',')
            contemVirgula = 1;
    }
    
    if (contadorAspasDuplas >= 2)
        iInicial = 1;

    // ALOCA O VETOR DE PONTEIROS
    if(tipo == 1) {
        game->supportedLanguages = (char **)malloc(n * sizeof(char *));
        game->numSupportedLanguages = n;
    } else if(tipo == 2) {
        game->publishers = (char **)malloc(n * sizeof(char *));
        game->numPublishers = n;
    } else if(tipo == 3) {
        game->developers = (char **)malloc(n * sizeof(char *));
        game->numDevelopers = n;
    } else if(tipo == 4) {
        game->categories = (char **)malloc(n * sizeof(char *));
        game->numCategories = n;
    } else if(tipo == 5) {
        game->genre = (char **)malloc(n * sizeof(char *));
        game->numGenre = n;
    } else if(tipo == 6) {
        game->tags = (char **)malloc(n * sizeof(char *));
        game->numTags = n;
    }

    if (contemVirgula) {
        for (int i = iInicial; i < length(valor) - 1; i++) {
            if (valor[i] == ',' || i == (length(valor) - 2)) {
                aux[indexAux] = '\0';
                //SE NAO FOR O PRIMEIRO ELEMENTO, RETIRA O SEGUINTE TEXTO DO INICIO: " "
                if (!primeiroElemento) {
                    strcpy(aux, cortarString(aux, 1));
                } else {
                    primeiroElemento = 0;
                }

                if(tipo == 1) {
                    game->supportedLanguages[contador] = (char *)malloc(length(aux) + 1);
                    strcpy(game->supportedLanguages[contador], aux);
                } else if (tipo == 2) {
                   game->publishers[contador] = (char *)malloc(length(aux) + 1);
                    strcpy(game->publishers[contador], aux); 
                } else if (tipo == 3) {
                   game->developers[contador] = (char *)malloc(length(aux) + 1);
                    strcpy(game->developers[contador], aux); 
                } else if (tipo == 4) {
                   game->categories[contador] = (char *)malloc(length(aux) + 1);
                    strcpy(game->categories[contador], aux); 
                } else if (tipo == 5) {
                   game->genre[contador] = (char *)malloc(length(aux) + 1);
                    strcpy(game->genre[contador], aux); 
                } else if (tipo == 6) {
                   game->tags[contador] = (char *)malloc(length(aux) + 1);
                    strcpy(game->tags[contador], aux); 
                }
                contador++;
                indexAux = 0;
            }
            if (valor[i] != '\'') {
                aux[indexAux] = valor[i];
                indexAux++;
            }
        }
    } else {
        // SE NAO TIVER VIRGULA, COLOCA NO PRIMEIRO ELEMENTO POIS SÓ TEM 1 ELEMENTO
        if(tipo == 1) {
            game->supportedLanguages[0] = (char *)malloc(length(valor) + 1);
            strcpy(game->supportedLanguages[0], valor);
        } else if (tipo == 2) {
           game->publishers[0] = (char *)malloc(length(valor) + 1);
            strcpy(game->publishers[0], valor); 
        } else if (tipo == 3) {
           game->developers[0] = (char *)malloc(length(valor) + 1);
            strcpy(game->developers[0], valor); 
        } else if (tipo == 4) {
           game->categories[0] = (char *)malloc(length(valor) + 1);
            strcpy(game->categories[0], valor); 
        } else if (tipo == 5) {
           game->genre[0] = (char *)malloc(length(valor) + 1);
            strcpy(game->genre[0], valor); 
        } else if (tipo == 6) {
           game->tags[0] = (char *)malloc(length(valor) + 1);
            strcpy(game->tags[0], valor); 
        }
    }
}

void separarArrayDevelopers(Game *game, char valor[], int tipo) {
    //TIPO = 1 -> supportedLanguages
    //TIPO = 2 -> publishers
    //TIPO = 3 -> developers
    //TIPO = 4 -> categories
    //TIPO = 5 -> genre
    //TIPO = 6 -> tags

    //CONTA QUANTOS ELEMENTOS TEM
    int n = 1;
    for (int i = 1; i < length(valor) - 1; i++) {
        if (valor[i] == ',')
            n++;
    }

    char aux[1000] = "";
    int indexAux = 0;
    int contador = 0;
    int primeiroElemento = 1;

    int iInicial = 0;
    int contadorAspasDuplas = 0;
    int contemVirgula = 0;
    
    // CONTA AS ASPAS DUPLAS E VE SE TEM VIRGULA
    for (int i = 0; i < length(valor) - 1; i++) {
        if (valor[i] == '"')
            contadorAspasDuplas++;
        else if (valor[i] == ',')
            contemVirgula = 1;
    }
    
    if (contadorAspasDuplas >= 2)
        iInicial = 1;

    // ALOCA O VETOR DE PONTEIROS
    if(tipo == 1) {
        game->supportedLanguages = (char **)malloc(n * sizeof(char *));
        game->numSupportedLanguages = n;
    } else if(tipo == 2) {
        game->publishers = (char **)malloc(n * sizeof(char *));
        game->numPublishers = n;
    } else if(tipo == 3) {
        game->developers = (char **)malloc(n * sizeof(char *));
        game->numDevelopers = n;
    } else if(tipo == 4) {
        game->categories = (char **)malloc(n * sizeof(char *));
        game->numCategories = n;
    } else if(tipo == 5) {
        game->genre = (char **)malloc(n * sizeof(char *));
        game->numGenre = n;
    } else if(tipo == 6) {
        game->tags = (char **)malloc(n * sizeof(char *));
        game->numTags = n;
    }

    if (contemVirgula) {
        for (int i = iInicial; i < length(valor) - 1; i++) {
            if (valor[i] == ',' || i == (length(valor) - 2)) {
                // NAO ADICIONA A VIRGULA MAS ADICIONA O ULTIMO CARACTERE DA ULTIMA PALAVRA
                if (valor[i] != ',')
                    aux[indexAux++] = valor[i];
                
                aux[indexAux] = '\0';
                //SE NAO FOR O PRIMEIRO ELEMENTO, RETIRA O SEGUINTE TEXTO DO INICIO: " "
                if (!primeiroElemento) {
                    strcpy(aux, cortarString(aux, 1));
                } else {
                    primeiroElemento = 0;
                }

                if(tipo == 1) {
                    game->supportedLanguages[contador] = (char *)malloc(length(aux) + 1);
                    strcpy(game->supportedLanguages[contador], aux);
                } else if (tipo == 2) {
                   game->publishers[contador] = (char *)malloc(length(aux) + 1);
                    strcpy(game->publishers[contador], aux); 
                } else if (tipo == 3) {
                   game->developers[contador] = (char *)malloc(length(aux) + 1);
                    strcpy(game->developers[contador], aux); 
                } else if (tipo == 4) {
                   game->categories[contador] = (char *)malloc(length(aux) + 1);
                    strcpy(game->categories[contador], aux); 
                } else if (tipo == 5) {
                   game->genre[contador] = (char *)malloc(length(aux) + 1);
                    strcpy(game->genre[contador], aux); 
                } else if (tipo == 6) {
                   game->tags[contador] = (char *)malloc(length(aux) + 1);
                    strcpy(game->tags[contador], aux); 
                }
                contador++;
                indexAux = 0;
            }
            if (valor[i] != '\'') {
                aux[indexAux] = valor[i];
                indexAux++;
            }
        }
    } else {
        // SE NAO TIVER VIRGULA, COLOCA NO PRIMEIRO ELEMENTO POIS SÓ TEM 1 ELEMENTO
        if(tipo == 1) {
            game->supportedLanguages[0] = (char *)malloc(length(valor) + 1);
            strcpy(game->supportedLanguages[0], valor);
        } else if (tipo == 2) {
           game->publishers[0] = (char *)malloc(length(valor) + 1);
            strcpy(game->publishers[0], valor); 
        } else if (tipo == 3) {
           game->developers[0] = (char *)malloc(length(valor) + 1);
            strcpy(game->developers[0], valor); 
        } else if (tipo == 4) {
           game->categories[0] = (char *)malloc(length(valor) + 1);
            strcpy(game->categories[0], valor); 
        } else if (tipo == 5) {
           game->genre[0] = (char *)malloc(length(valor) + 1);
            strcpy(game->genre[0], valor); 
        } else if (tipo == 6) {
           game->tags[0] = (char *)malloc(length(valor) + 1);
            strcpy(game->tags[0], valor); 
        }
    }
}

void separarArrayCategories(Game *game, char valor[], int tipo) {
    //TIPO = 1 -> supportedLanguages
    //TIPO = 2 -> publishers
    //TIPO = 3 -> developers
    //TIPO = 4 -> categories
    //TIPO = 5 -> genre
    //TIPO = 6 -> tags

    //CONTA QUANTOS ELEMENTOS TEM
    int n = 1;
    for (int i = 1; i < length(valor) - 1; i++) {
        if (valor[i] == ',')
            n++;
    }

    char aux[1000] = "";
    int indexAux = 0;
    int contador = 0;
    int primeiroElemento = 1;

    int iInicial = 0;
    int contadorAspasDuplas = 0;
    int contemVirgula = 0;
    
    // CONTA AS ASPAS DUPLAS E VE SE TEM VIRGULA
    for (int i = 0; i < length(valor) - 1; i++) {
        if (valor[i] == '"')
            contadorAspasDuplas++;
        else if (valor[i] == ',')
            contemVirgula = 1;
    }
    
    if (contadorAspasDuplas >= 2)
        iInicial = 1;

    // ALOCA O VETOR DE PONTEIROS
    if(tipo == 1) {
        game->supportedLanguages = (char **)malloc(n * sizeof(char *));
        game->numSupportedLanguages = n;
    } else if(tipo == 2) {
        game->publishers = (char **)malloc(n * sizeof(char *));
        game->numPublishers = n;
    } else if(tipo == 3) {
        game->developers = (char **)malloc(n * sizeof(char *));
        game->numDevelopers = n;
    } else if(tipo == 4) {
        game->categories = (char **)malloc(n * sizeof(char *));
        game->numCategories = n;
    } else if(tipo == 5) {
        game->genre = (char **)malloc(n * sizeof(char *));
        game->numGenre = n;
    } else if(tipo == 6) {
        game->tags = (char **)malloc(n * sizeof(char *));
        game->numTags = n;
    }

    if (contemVirgula) {
        for (int i = 1; i < length(valor) - 1; i++) {
            if (valor[i] == ',' || i == (length(valor) - 2)) {
                if (valor[i] != ',')
                    aux[indexAux++] = valor[i];
                
                aux[indexAux] = '\0';
                
                //SE NAO FOR O PRIMEIRO ELEMENTO, RETIRA O SEGUINTE TEXTO DO INICIO: " "
                if (!primeiroElemento) {
                    strcpy(aux, cortarString(aux, 1));
                } else {
                    primeiroElemento = 0;
                }

                if(tipo == 1) {
                    game->supportedLanguages[contador] = (char *)malloc(length(aux) + 1);
                    strcpy(game->supportedLanguages[contador], aux);
                } else if (tipo == 2) {
                   game->publishers[contador] = (char *)malloc(length(aux) + 1);
                    strcpy(game->publishers[contador], aux); 
                } else if (tipo == 3) {
                   game->developers[contador] = (char *)malloc(length(aux) + 1);
                    strcpy(game->developers[contador], aux); 
                } else if (tipo == 4) {
                   game->categories[contador] = (char *)malloc(length(aux) + 1);
                    strcpy(game->categories[contador], aux); 
                } else if (tipo == 5) {
                   game->genre[contador] = (char *)malloc(length(aux) + 1);
                    strcpy(game->genre[contador], aux); 
                } else if (tipo == 6) {
                   game->tags[contador] = (char *)malloc(length(aux) + 1);
                    strcpy(game->tags[contador], aux); 
                }
                contador++;
                indexAux = 0;
            }
            if (valor[i] != '\'') {
                aux[indexAux] = valor[i];
                indexAux++;
            }
        }
    } else {
        // SE NAO TIVER VIRGULA, COLOCA NO PRIMEIRO ELEMENTO POIS SÓ TEM 1 ELEMENTO
        if(tipo == 1) {
            game->supportedLanguages[0] = (char *)malloc(length(valor) + 1);
            strcpy(game->supportedLanguages[0], valor);
        } else if (tipo == 2) {
           game->publishers[0] = (char *)malloc(length(valor) + 1);
            strcpy(game->publishers[0], valor); 
        } else if (tipo == 3) {
           game->developers[0] = (char *)malloc(length(valor) + 1);
            strcpy(game->developers[0], valor); 
        } else if (tipo == 4) {
           game->categories[0] = (char *)malloc(length(valor) + 1);
            strcpy(game->categories[0], valor); 
        } else if (tipo == 5) {
           game->genre[0] = (char *)malloc(length(valor) + 1);
            strcpy(game->genre[0], valor); 
        } else if (tipo == 6) {
           game->tags[0] = (char *)malloc(length(valor) + 1);
            strcpy(game->tags[0], valor); 
        }
    }
}

void separarArrayGenre(Game *game, char valor[], int tipo) {
    //TIPO = 1 -> supportedLanguages
    //TIPO = 2 -> publishers
    //TIPO = 3 -> developers
    //TIPO = 4 -> categories
    //TIPO = 5 -> genre
    //TIPO = 6 -> tags

    //CONTA QUANTOS ELEMENTOS TEM
    int n = 1;
    for (int i = 1; i < length(valor) - 1; i++) {
        if (valor[i] == ',')
            n++;
    }

    char aux[1000] = "";
    int indexAux = 0;
    int contador = 0;
    int primeiroElemento = 1;

    int iInicial = 0;
    int contadorAspasDuplas = 0;
    int contemVirgula = 0;
    
    // CONTA AS ASPAS DUPLAS E VE SE TEM VIRGULA
    for (int i = 0; i < length(valor) - 1; i++) {
        if (valor[i] == '"')
            contadorAspasDuplas++;
        else if (valor[i] == ',')
            contemVirgula = 1;
    }
    
    if (contadorAspasDuplas >= 2)
        iInicial = 1;

    // ALOCA O VETOR DE PONTEIROS
    if(tipo == 1) {
        game->supportedLanguages = (char **)malloc(n * sizeof(char *));
        game->numSupportedLanguages = n;
    } else if(tipo == 2) {
        game->publishers = (char **)malloc(n * sizeof(char *));
        game->numPublishers = n;
    } else if(tipo == 3) {
        game->developers = (char **)malloc(n * sizeof(char *));
        game->numDevelopers = n;
    } else if(tipo == 4) {
        game->categories = (char **)malloc(n * sizeof(char *));
        game->numCategories = n;
    } else if(tipo == 5) {
        game->genre = (char **)malloc(n * sizeof(char *));
        game->numGenre = n;
    } else if(tipo == 6) {
        game->tags = (char **)malloc(n * sizeof(char *));
        game->numTags = n;
    }

    if (contemVirgula) {
        for (int i = 1; i < length(valor); i++) {
            if (valor[i] == ',' || i == (length(valor) - 2)) {
                if (valor[i] != ',')
                    aux[indexAux++] = valor[i];
                
                aux[indexAux] = '\0';
                
                //SE NAO FOR O PRIMEIRO ELEMENTO, RETIRA O SEGUINTE TEXTO DO INICIO: " "
                if (!primeiroElemento) {
                    strcpy(aux, cortarString(aux, 1));
                } else {
                    primeiroElemento = 0;
                }

                if(tipo == 1) {
                    game->supportedLanguages[contador] = (char *)malloc(length(aux) + 1);
                    strcpy(game->supportedLanguages[contador], aux);
                } else if (tipo == 2) {
                   game->publishers[contador] = (char *)malloc(length(aux) + 1);
                    strcpy(game->publishers[contador], aux); 
                } else if (tipo == 3) {
                   game->developers[contador] = (char *)malloc(length(aux) + 1);
                    strcpy(game->developers[contador], aux); 
                } else if (tipo == 4) {
                   game->categories[contador] = (char *)malloc(length(aux) + 1);
                    strcpy(game->categories[contador], aux); 
                } else if (tipo == 5) {
                   game->genre[contador] = (char *)malloc(length(aux) + 1);
                    strcpy(game->genre[contador], aux); 
                } else if (tipo == 6) {
                   game->tags[contador] = (char *)malloc(length(aux) + 1);
                    strcpy(game->tags[contador], aux); 
                }
                contador++;
                indexAux = 0;
            }
            if (valor[i] != '\'') {
                aux[indexAux] = valor[i];
                indexAux++;
            }
        }
    } else {
        // SE NAO TIVER VIRGULA, COLOCA NO PRIMEIRO ELEMENTO POIS SÓ TEM 1 ELEMENTO
        if(tipo == 1) {
            game->supportedLanguages[0] = (char *)malloc(length(valor) + 1);
            strcpy(game->supportedLanguages[0], valor);
        } else if (tipo == 2) {
           game->publishers[0] = (char *)malloc(length(valor) + 1);
            strcpy(game->publishers[0], valor); 
        } else if (tipo == 3) {
           game->developers[0] = (char *)malloc(length(valor) + 1);
            strcpy(game->developers[0], valor); 
        } else if (tipo == 4) {
           game->categories[0] = (char *)malloc(length(valor) + 1);
            strcpy(game->categories[0], valor); 
        } else if (tipo == 5) {
           game->genre[0] = (char *)malloc(length(valor) + 1);
            strcpy(game->genre[0], valor); 
        } else if (tipo == 6) {
           game->tags[0] = (char *)malloc(length(valor) + 1);
            strcpy(game->tags[0], valor); 
        }
    }
}

//RECEBE A LINHA E EXTRAI OS PARAMETROS A CADA VIRGULA
Game criaGame(char linha[]) {
    Game game;
    char valor[10000] = "";
    int indexValor = 0;

    int parametro = 0;
    int aspasAbertas = 0;

    //printf("LINHA: %s\n\n", linha);
    for (int i = 0; linha[i] != '\0'; i++) {
        if(linha[i] == '"') {
            if(aspasAbertas == 0)
                aspasAbertas = 1;
            else
                aspasAbertas = 0;
        }

        if(linha[i] != ',') {
            valor[indexValor] = linha[i];
            indexValor++;
        } else if(aspasAbertas == 1) {
            valor[indexValor] = linha[i];
            indexValor++;
        } else {
            valor[indexValor] = '\0';
            //printf("PARAMETRO = %d | VALOR = %s\n\n", parametro, valor);

            //SWITCH PARA SABER O PARAMETRO QUE ELE ESTA TRATANDO
            switch (parametro)
            {
                case 0:
                    game.id = stringParaInteiro(valor);
                    break;
                case 1:
                    game.nome = malloc(length(valor) + 1);
                    strcpy(game.nome, valor);
                    break;

                case 2:
                    game.releaseDate = textoParaDate(valor);
                    break;

                case 3:
                    game.estimatedOwners = stringParaInteiro(valor);
                    break;

                case 4:
                    game.price = stringParaFloat(valor);
                    break;

                case 5:
                    separarArray(&game, valor, 1);
                    break;

                case 6:
                    game.metacriticScore = stringParaInteiro(valor);
                    break;
                
                case 7:
                    game.userScore = stringParaFloat(valor);
                    break;

                case 8:
                    game.achievements = stringParaInteiro(valor);
                    break;

                //TEM DIFERENTES SEPARAR ARRAY POIS TENTEI TRATAR INUMEROS CASOS QUE TINHA, E REAPROVEITEI ALGUNS PARA M,AIS DE UM PARAMETRO
                case 9:
                    separarArrayDevelopers(&game, valor, 2);
                    break;
                case 10:
                    separarArrayDevelopers(&game, valor, 3);
                    break;
                case 11:
                    separarArrayCategories(&game, valor, 4);
                    break;
                case 12:
                    separarArrayGenre(&game, valor, 5);
                    break;
                case 13:
                    separarArrayPublisher(&game, valor, 6);
                    break;
            }
            parametro++;
            indexValor = 0;
        }
    }
    //printf("---------------------\n\n\n\n\n");
    return game;
}

void listarArray(Game game, int tipo) {
    //REECEBE UM TIPO PARA SABER QUAL ARRAY ELE VAI IMPRIMIR
    //CHAMA IMPRIMESEMASPASDUPLAS PARA TRATAR UM ERRO QUE ESTAVA DANDO

    //TIPO = 1 -> supportedLanguages
    //TIPO = 2 -> publishers
    //TIPO = 3 -> developers
    //TIPO = 4 -> categories
    //TIPO = 5 -> genre
    //TIPO = 6 -> tags

    printf("[");
    if(tipo == 1) {
        for(int i=0; i < game.numSupportedLanguages; i++) {
            imprimeSemAspasDuplasString(game.supportedLanguages[i]);
            if(i != game.numSupportedLanguages-1)
                printf(", ");
        }
    } else if(tipo == 2) {
        for(int i=0; i < game.numPublishers; i++) {
            imprimeSemAspasDuplasString(game.publishers[i]);
            if(i != game.numPublishers-1)
                printf(", ");
        }
    } else if(tipo == 3) {
        for(int i=0; i < game.numDevelopers; i++) {
            imprimeSemAspasDuplasString(game.developers[i]);
            if(i != game.numDevelopers-1)
                printf(", ");
        }
    } else if(tipo == 4) {
        for(int i=0; i < game.numCategories; i++) {
            printf("%s", game.categories[i]);
            if(i != game.numCategories-1)
                printf(", ");
        }
    } else if(tipo == 5) {
        for(int i=0; i < game.numGenre; i++) {
            imprimeSemAspasDuplasString(game.genre[i]);
            if(i != game.numGenre-1)
                printf(", ");
        }
    } else if(tipo == 6) {
        for(int i=0; i < game.numTags; i++) {
            imprimeSemAspasDuplasString(game.tags[i]);
            if(i != game.numTags-1)
                printf(", ");
        }
    }
    printf("]");
}

void imprimeSemAspasDuplasString(char texto[]) {
    for(int i=0; texto[i] != '\0'; i++) {
        if(texto[i] != '"') {
            printf("%c", texto[i]);
        }
    }
}

int main()
{
    //FLUXO PRINCIPAL QUE PERCORRE LINHA POR LINHA E PREENCHE O VETOR DE Game
    //TEM ALGUNS PRINTS AO LONGO DO C'ODIGO QUE AJUDA A VISUALIZAR A EXECUCAO
    FILE *p = fopen("/tmp/games.csv", "r");
    char linha[50000];

    Game listaGames[5000];
    int indexListaGames = 0;

    int contadorLinha = 0;

    if (p != NULL)
    {
        while (fgets(linha, sizeof(linha), p) != NULL)
        {
            if(contadorLinha > 0) {
                //ADICIONA UMA VIRGULA AO FINAL DA LINHA PARA FACILIAR IDENTIFICAR OS PARAMETROS
                int len = length(linha);
                if(len > 0 && linha[len-1] == '\n') {
                    linha[len-1] = ',';
                    linha[len] = '\0';
                } else {
                    linha[len] = ',';
                    linha[len+1] = '\0';
                }
                listaGames[indexListaGames] = criaGame(linha);
                indexListaGames++;
            }
            contadorLinha++;
        }
        fclose(p);
    }
    //printf("PRIMEIRO ID: %d -> %s | %d/%d/%d   |   %d -> %f | supportedLanguage = %s | publisher = %s", listaGames[0].id, listaGames[0].nome, listaGames[0].releaseDate.dia, listaGames[0].releaseDate.mes, listaGames[0].releaseDate.ano, listaGames[0].estimatedOwners, listaGames[0].price, listaGames[0].supportedLanguages[10], listaGames[0].publishers[0]);
    
    char texto[10000];
    fgets(texto, sizeof(texto), stdin);
    char fim[] = "FIM\n";

    // LE ATÉ ENCONTRAR FIM E FAZ A CONSULTA PELO ID
    while (strcmp(texto, fim))
    {
        int id = stringParaInteiro(texto);
        for(int i=0; i < 5000; i++) {
            //FAZ A CONSULKTA PELO ID
            if(listaGames[i].id == id) {
                if(listaGames[i].price == 0.0) {
                    printf("=> %d ## %s ## %02d/%02d/%d ## %d ## %.1f ## ", listaGames[i].id, listaGames[i].nome, listaGames[i].releaseDate.dia, listaGames[i].releaseDate.mes, listaGames[i].releaseDate.ano, listaGames[i].estimatedOwners, listaGames[i].price);
                } else {
                    printf("=> %d ## %s ## %02d/%02d/%d ## %d ## %.2f ## ", listaGames[i].id, listaGames[i].nome, listaGames[i].releaseDate.dia, listaGames[i].releaseDate.mes, listaGames[i].releaseDate.ano, listaGames[i].estimatedOwners, listaGames[i].price);
                }
                listarArray(listaGames[i], 1);
                printf(" ## %d ## %.1f ## %d ## ", listaGames[i].metacriticScore, listaGames[i].userScore, listaGames[i].achievements);
                listarArray(listaGames[i], 2);
                printf(" ## ");
                listarArray(listaGames[i], 3);
                printf(" ## ");
                listarArray(listaGames[i], 4);
                printf(" ## ");
                listarArray(listaGames[i], 5);
                printf(" ## ");
                listarArray(listaGames[i], 6);
                printf(" ##\n");
            }
        }
        fgets(texto, sizeof(texto), stdin);
    }

    return 0;
}
