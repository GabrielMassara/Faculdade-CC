# TP06Q01 - Lista com Alocação Sequencial em Java

## Enunciado

Crie uma **Lista de registros** baseada na de inteiros vista em sala de aula.  
Sua lista deve conter **todos os atributos e métodos** existentes na lista de inteiros, contudo, adaptados para a classe `Shows`.





Lembre-se de que, na verdade, temos uma **lista de ponteiros (ou referências)**, e cada um deles aponta para um registro.  
Neste exercício, faremos **inserções**, **remoções** e exibiremos os elementos da lista.






---




#### Especificações dos métodos


Os métodos de inserir e remover devem operar conforme descrito a seguir, respeitando parâmetros e retornos:



- `void inserirInicio(Game game)`: insere um registro na primeira posição da lista e remaneja os demais.  
- `void inserir(Game game, int posicao)`: insere um registro na posição `p` da lista, onde `p < n` e `n` é o número de registros cadastrados.  
  Em seguida, o método deve remanejar os demais registros.  
- `void inserirFim(Game game)`: insere um registro na última posição da lista.  
- `Game removerInicio()`: remove e retorna o primeiro registro cadastrado na lista e remaneja os demais.  
- `Game remover(int posicao)`: remove e retorna o registro cadastrado na `p`-ésima posição da lista e remaneja os demais.  
- `Game removerFim()`: remove e retorna o último registro cadastrado na lista.






---




#### Formato da entrada

A entrada padrão é composta por **duas partes**:

1. **Primeira parte:** igual à entrada da primeira questão do **TP04**.  
2. **Segunda parte:** contém os comandos de inserção e remoção.

A primeira linha da segunda parte contém um número inteiro `n`, indicando a quantidade de registros a serem processados.  
Nas próximas `n` linhas, há `n` comandos de **inserção** ou **remoção**, seguindo o formato abaixo:





| Comando | Ação |
|----------|------|
| `II` | Inserir no início |
| `I*` | Inserir em qualquer posição |
| `IF` | Inserir no fim |
| `RI` | Remover do início |
| `R*` | Remover de qualquer posição |
| `RF` | Remover do fim |



 

Nos comandos de **inserir**, também é informado o **nome do arquivo** que contém o registro a ser inserido.  
Nos comandos de inserção em posição específica (`I*`), a posição é informada logo após a palavra de comando.






---




#### Formato da saída



A saída padrão deve conter:

- Uma linha para **cada registro removido**, no formato:  
(R) \<Name>




 
- Ao final, devem ser exibidos os atributos relativos a **cada registro ainda presente na lista**, após todas as operações de inserção e remoção.  

## Arquivos de Teste

As entradas e saídas públicas do programa estão na pasta **pubs** (arquivo **pubs.zip**).

## Informações da Atividade

- **ID**: 6663
- **Linguagem**: JAVA
- **Formato**: .java
- **Limite**: -39 minutos
- **Close date**: 2025-11-22T02:59:00.000Z
