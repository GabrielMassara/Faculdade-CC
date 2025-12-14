# TP01Q04 - Alteração Aleatória

## Enunciado

Crie um método iterativo que recebe uma string, sorteia duas letras minúsculas aleatórias (código ASCII >= 'a' e <= 'z'), substitui todas as ocorrências da primeira letra na string pela segunda e retorna a string com as alterações efetuadas.





Na saída padrão, para cada linha de entrada, execute o método desenvolvido nesta questão e mostre a string retornada como uma linha de saída.





Abaixo, observamos um exemplo de entrada supondo que para a primeira linha as letras sorteadas foram o a e o q. Para a segunda linha, foram o e e o k.





### Exemplo de Entrada → Saída


 

**Entrada:**
```
o rato roeu a roupa do rei de roma
e qwe qwe qwe ewq ewq ewq
FIM
```




**Saída**
```
o rqto roeu q roupq do rei de romq
k qwk qwk qwk kwq kwq kwq
```





A classe `Random` do Java gera números (ou letras) aleatórios e o exemplo abaixo mostra uma letra minúscula na tela.  



Em especial, destacamos que:  
1. *seed* é a semente para geração de números aleatórios.  
2. Nesta questão, por causa da correção automática, a *seed* será `4`.  
3. A disciplina de Estatística e Probabilidade faz uma discussão sobre "aleatório".  





```java
Random gerador = new Random();
gerador.setSeed(4);
System.out.println((char)('a' + (Math.abs(gerador.nextInt()) % 26)));
```  

## Arquivos de Teste

As entradas e saídas públicas do programa estão na pasta **pubs** (arquivo **pubs.zip**).

## Informações da Atividade

- **ID**: 5970
- **Linguagem**: JAVA
- **Formato**: .java
- **Limite**: -39 minutos
- **Close date**: 2025-08-29T02:59:00.000Z
