# TP04Q01 - Classe em Java

## Enunciado

- Implemente a classe `Game` em Java tomando como referência o conjunto de dados `games.csv` (Steam).  
  A classe deve modelar um jogo com os seguintes atributos (nomes sugeridos entre parênteses), tipos e regras de normalização:

  - **Identificador único do jogo (`id`)**: inteiro.  
  - **Nome do jogo (`name`)**: string.  
  - **Data de lançamento (`releaseDate`)**: string no formato `dd/mm/aaaa`.  
    Caso a data esteja incompleta, utilize `01` para dia ou mês faltantes.  
    Exemplo: `01/05/2010` ou `15/01/2005`.  
  - **Estimativa do número de jogadores (`estimatedOwners`)**: inteiro.  
    Remova quaisquer caracteres não numéricos (ex.: vírgulas).  
  - **Preço do jogo (`price`)**: float.  
    Caso o preço seja *Free to Play*, atribua `0.0`.  
  - **Idiomas suportados (`supportedLanguages`)**: array de strings.  
    Extraia os idiomas listados entre colchetes e separados por vírgulas.  
  - **Nota da crítica especializada (`metacriticScore`)**: inteiro.  
    Caso o campo esteja vazio, atribua `-1`.  
  - **Nota dos usuários (`userScore`)**: float.  
    Caso o campo esteja vazio ou contenha *tbd*, atribua `-1.0`.  
  - **Quantidade de conquistas disponíveis (`achievements`)**: inteiro.  
    Caso o campo esteja vazio, atribua `0`.  
  - **Empresa(s) responsável(is) pela publicação (`publishers`)**: array de strings.  
    Separe múltiplas empresas por vírgulas.  
  - **Empresa(s) ou estúdio(s) responsável(is) pelo desenvolvimento (`developers`)**: array de strings.  
    Separe múltiplas empresas por vírgulas.  
  - **Categorias associadas ao jogo (`categories`)**: array de strings.  
    Extraia as categorias listadas entre colchetes e separadas por vírgulas.  
  - **Gêneros do jogo (`genres`)**: array de strings.  
    Extraia os gêneros listados entre colchetes e separados por vírgulas.  
  - **Conjunto de palavras-chave atribuídas pelos usuários (`tags`)**: array de strings.  
    Extraia as tags listadas entre colchetes e separadas por vírgulas.  

## Arquivos de Teste

As entradas e saídas públicas do programa estão na pasta **pubs** (arquivo **pubs.zip**).

## Informações da Atividade

- **ID**: 6413
- **Linguagem**: JAVA
- **Formato**: .java
- **Limite**: -39 minutos
- **Close date**: 2025-10-14T02:59:00.000Z
