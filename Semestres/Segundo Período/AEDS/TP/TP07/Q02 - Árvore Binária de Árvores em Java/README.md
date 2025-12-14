# TP07Q02 - Árvore Binária de Árvores em Java

## Enunciado

Refaça a questão anterior, agora considerando a **estrutura de árvore de árvore**.





Nessa estrutura, temos:

- Uma **árvore binária tradicional** (primeira árvore), em que **cada nó** possui um ponteiro para **outra árvore binária** (segunda árvore).
- Graficamente:
  - A primeira árvore está no **plano xy**.
  - A árvore associada a cada nó pode ser imaginada em um **espaço tridimensional**.





---





### 🧱 **Tipos de nós**

Temos **dois tipos de nós**:





1. **Primeiro tipo** (nós da primeira árvore):
   - Chave: um **inteiro**
   - Ponteiros: `esq` e `dir` (ambos para nós do **primeiro tipo**)
   - Um ponteiro para um nó do **segundo tipo** (raiz da segunda árvore associada)





2. **Segundo tipo** (nós das árvores associadas):
   - Chave: uma **String**
   - Ponteiros: `esq` e `dir` (ambos para nós do **segundo tipo**)





As chaves de pesquisa são:

- Na **primeira árvore**: atributo **`estimatedOwners mod 15`**
- Na **segunda árvore**: atributo **`Name`**

Conforme ilustrado na figura fornecida no enunciado.





---





### 🔍 **Estratégia de pesquisa**

Nossa pesquisa fará um **“mostrar”** na primeira árvore e um **“mostrar”** na segunda:

- Na **primeira árvore**, fazemos um **mostrar** porque ela é organizada pelo atributo  
  **`estimatedOwners mod 15`**, permitindo que o valor desejado esteja na segunda árvore de qualquer um de seus nós.
- Na **segunda árvore**, fazemos um **mostrar** porque ela é organizada pelo atributo  
  **`Name`**.





---





### 🌱 **Construção da primeira árvore**

Antes de inserir qualquer elemento nas árvores associadas (segunda árvore):

1. Crie a **primeira árvore** binária.
2. Insira **todos os nós** na seguinte ordem, respeitando a estrutura de árvore binária:

   ```text
   7, 3, 11, 1, 5, 9, 13, 0, 2, 4, 6, 8, 10, 12, 14  

## Arquivos de Teste

As entradas e saídas públicas do programa estão na pasta **pubs** (arquivo **pubs.zip**).

## Informações da Atividade

- **ID**: 7019
- **Linguagem**: JAVA
- **Formato**: .java
- **Limite**: -39 minutos
- **Close date**: 2025-11-29T02:59:00.000Z
