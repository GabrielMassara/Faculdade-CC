#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void imprimeSemAspasDuplasString(char texto[]);

int comparacoes = 0;

typedef struct NoLista {
    struct Game *game;
    struct NoLista *prox;
} NoLista;

#define TAM_TABELA 21

typedef struct {
    NoLista *tabela[TAM_TABELA];
} HashIndireta;

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
    return atoi(texto);
}

int length(char texto[]) {
    return strlen(texto);
}

float stringParaFloat(char texto[]) {
    return atof(texto);
}

int stringCompare(char str1[], char str2[]) {
    return strcmp(str1, str2) == 0 ? 1 : 0;
}

Data textoParaDate(char texto[]) {
    char mes[4];
    int indexMes = 0;
    char dia[3];
    int indexDia = 0;
    char ano[5];
    int indexAno = 0;
    
    int tamanhoTexto = length(texto);
    int mesFinal;
    
    int start = 0;
    if(texto[0] == '"') start = 1;

    for(int i=start; texto[i] != '\0' && texto[i] != '"'; i++) {
        if(i - start <= 2) {
            mes[indexMes]=texto[i];
            indexMes++;
        } else if(strstr(texto, ",")) {
             if (texto[i] >= '0' && texto[i] <= '9') {
                 if (indexDia < 2 && indexAno == 0) {
                     dia[indexDia++] = texto[i];
                 } else {
                     ano[indexAno++] = texto[i];
                 }
             }
        } else {
             if (i > start + 3) {
                 ano[indexAno++] = texto[i];
             }
             dia[0] = '1'; dia[1] = '\0';
        }
    }

    mes[indexMes] = '\0';
    dia[indexDia] = '\0';
    ano[indexAno] = '\0';

    if(stringCompare(mes, "Jan")) mesFinal = 1;
    else if(stringCompare(mes, "Feb")) mesFinal = 2;
    else if(stringCompare(mes, "Mar")) mesFinal = 3;
    else if(stringCompare(mes, "Apr")) mesFinal = 4;
    else if(stringCompare(mes, "May")) mesFinal = 5;
    else if(stringCompare(mes, "Jun")) mesFinal = 6;
    else if(stringCompare(mes, "Jul")) mesFinal = 7;
    else if(stringCompare(mes, "Aug")) mesFinal = 8;
    else if(stringCompare(mes, "Sep")) mesFinal = 9;
    else if(stringCompare(mes, "Oct")) mesFinal = 10;
    else if(stringCompare(mes, "Nov")) mesFinal = 11;
    else if(stringCompare(mes, "Dec")) mesFinal = 12;
    else mesFinal = 1;

    Data data;
    data.dia = stringParaInteiro(dia);
    data.mes = mesFinal;
    data.ano = stringParaInteiro(ano);

    return data;
}

char* cortarString(char texto[], int inicio) {
    int tamanhoTexto = length(texto);
    int tamanho = tamanhoTexto - inicio;
    char *resultado = (char*)malloc((tamanho + 1) * sizeof(char));
    int indexResultado = 0;

    for(int i = inicio; i < tamanhoTexto; i++) {
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
    int tamanhoValor = length(valor);
    for (int i = 1; i < tamanhoValor - 1; i++) {
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
    for (int i = 2; i < tamanhoValor - 1; i++) {
        if (valor[i] == ',' || i == (tamanhoValor - 2)) {
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
    int tamanhoValor = length(valor);
    for (int i = 1; i < tamanhoValor - 1; i++) {
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
    for (int i = 0; i < tamanhoValor - 1; i++) {
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
        for (int i = iInicial; i < tamanhoValor - 1; i++) {
            if (valor[i] == ',' || i == (tamanhoValor - 2)) {
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
    int tamanhoValor = length(valor);
    for (int i = 1; i < tamanhoValor - 1; i++) {
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
    for (int i = 0; i < tamanhoValor - 1; i++) {
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
        for (int i = iInicial; i < tamanhoValor - 1; i++) {
            if (valor[i] == ',' || i == (tamanhoValor - 2)) {
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
    int tamanhoValor = length(valor);
    for (int i = 1; i < tamanhoValor - 1; i++) {
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
    for (int i = 0; i < tamanhoValor - 1; i++) {
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
        for (int i = 1; i < tamanhoValor - 1; i++) {
            if (valor[i] == ',' || i == (tamanhoValor - 2)) {
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
    int tamanhoValor = length(valor);
    for (int i = 1; i < tamanhoValor - 1; i++) {
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
    for (int i = 0; i < tamanhoValor - 1; i++) {
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
        for (int i = 1; i < tamanhoValor; i++) {
            if (valor[i] == ',' || i == (tamanhoValor - 2)) {
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

Game criaGame(char linha[]) {
    Game game;

    game.nome = NULL;
    game.numSupportedLanguages = 0;
    game.numPublishers = 0;
    game.numDevelopers = 0;
    game.numCategories = 0;
    game.numGenre = 0;
    game.numTags = 0;

    char buffer[2048];
    int idxBuffer = 0;
    int coluna = 0;
    int inQuotes = 0;
    int len = strlen(linha);

    for (int i = 0; i <= len; i++) {
        char c = linha[i];
        
        if (c == '"' && (i == 0 || linha[i-1] != '\\')) {
            inQuotes = !inQuotes;
        } else if ((c == ',' && !inQuotes) || c == '\0' || c == '\n') {
            buffer[idxBuffer] = '\0';
            
            // REMOVE AS ASPAS QUE ENVOLVEM
            if (buffer[0] == '"' && buffer[strlen(buffer)-1] == '"') {
                memmove(buffer, buffer + 1, strlen(buffer) - 2);
                buffer[strlen(buffer) - 2] = '\0';
            }

            switch (coluna) {
                case 0:
                    game.id = atoi(buffer);
                    break;
                case 1:
                    game.nome = (char*)malloc(strlen(buffer) + 1);
                    strcpy(game.nome, buffer);
                    break;
                case 2:
                    game.releaseDate = textoParaDate(buffer);
                    break;
                case 3:
                    game.estimatedOwners = atoi(buffer);
                    break;
                case 4:
                    game.price = atof(buffer);
                    break;
                case 6:
                    game.metacriticScore = atoi(buffer);
                    break;
                case 7:
                    game.userScore = atof(buffer);
                    break;
                case 8:
                    game.achievements = atoi(buffer);
                    break;
            }
            
            coluna++;
            idxBuffer = 0;
            if (coluna > 8) break; 
        } else {
            buffer[idxBuffer++] = c;
        }
    }
    
    return game;
}

void imprimeSemAspasDuplasString(char texto[]) {
    for(int i=0; texto[i] != '\0'; i++) {
        if(texto[i] != '"') {
            printf("%c", texto[i]);
        }
    }
}

int calcularHash(char *nome) {
    int soma = 0;
    for (int i = 0; nome[i] != '\0'; i++) {
        soma += nome[i];
    }
    return soma % TAM_TABELA;
}

void inicializarHash(HashIndireta *hash) {
    for (int i = 0; i < TAM_TABELA; i++) {
        hash->tabela[i] = NULL;
    }
}

NoLista* criarNoLista(Game *game) {
    NoLista *novo = (NoLista*)malloc(sizeof(NoLista));
    novo->game = game;
    novo->prox = NULL;
    return novo;
}

void inserirHash(HashIndireta *hash, Game *game) {
    int posicao = calcularHash(game->nome);
    NoLista *novo = criarNoLista(game);
    
    novo->prox = hash->tabela[posicao];
    hash->tabela[posicao] = novo;
}

int pesquisarHash(HashIndireta *hash, char *nome, int *posicao) {
    *posicao = calcularHash(nome);
    NoLista *atual = hash->tabela[*posicao];
    
    while (atual != NULL) {
        if (strcmp(nome, atual->game->nome) == 0) {
            return 1;
        }
        atual = atual->prox;
    }
    return 0;
}

void liberarHash(HashIndireta *hash) {
    for (int i = 0; i < TAM_TABELA; i++) {
        NoLista *atual = hash->tabela[i];
        while (atual != NULL) {
            NoLista *temp = atual;
            atual = atual->prox;
            free(temp);
        }
    }
}

int compareGamesID(const void *a, const void *b) {
    return ((Game*)a)->id - ((Game*)b)->id;
}

Game* buscaBinaria(Game vetor[], int n, int id) {
    int inicio = 0, fim = n - 1;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        comparacoes++;
        if (vetor[meio].id == id) {
            return &vetor[meio];
        } else if (vetor[meio].id < id) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return NULL;
}

int main()
{
    FILE *p = fopen("/tmp/games.csv", "r");
    char linha[50000];

    Game listaGames[5000];
    int indexListaGames = 0;

    if (p != NULL)
    {
        fgets(linha, sizeof(linha), p);
        
        while (fgets(linha, sizeof(linha), p) != NULL && indexListaGames < 5000)
        {
            linha[strcspn(linha, "\n")] = '\0';
            listaGames[indexListaGames] = criaGame(linha);
            indexListaGames++;
        }
        fclose(p);
    }
    
    // ORDENAR PARA PERMITIR BUSCA BINARIA
    qsort(listaGames, indexListaGames, sizeof(Game), compareGamesID);

    HashIndireta hash;
    inicializarHash(&hash);
    
    char texto[10000];
    fgets(texto, sizeof(texto), stdin);
    char fim[] = "FIM\n";
    char fim2[] = "FIM";

    clock_t inicio = clock();
    while (strcmp(texto, fim) != 0 && strcmp(texto, fim2) != 0)
    {
        int id = stringParaInteiro(texto);

        Game *g = buscaBinaria(listaGames, indexListaGames, id);
        if (g != NULL) {
            inserirHash(&hash, g);
        }

        fgets(texto, sizeof(texto), stdin);
    }
    
    fgets(texto, sizeof(texto), stdin);
    while (strcmp(texto, fim) != 0 && strcmp(texto, fim2) != 0)
    {
        int len = length(texto);
        if(len > 0 && texto[len-1] == '\n') {
            texto[len-1] = '\0';
        }
        
        int posicao;
        int encontrou = pesquisarHash(&hash, texto, &posicao);
        
        if (encontrou) {
            printf("%s: (Posicao: %d) SIM\n", texto, posicao);
        } else {
            printf("%s: (Posicao: %d) NAO\n", texto, posicao);
        }
        
        if(fgets(texto, sizeof(texto), stdin) == NULL) break;
    }
    
    clock_t fimTempo = clock();
    double tempoExecucao = ((double)(fimTempo - inicio)) / CLOCKS_PER_SEC;

    FILE *logFile = fopen("885810_hashIndireta.txt", "w");
    if (logFile != NULL) {
        fprintf(logFile, "885810\t%d\t%f\n", comparacoes, tempoExecucao);
        fclose(logFile);
    }
    
    liberarHash(&hash);

    return 0;
}