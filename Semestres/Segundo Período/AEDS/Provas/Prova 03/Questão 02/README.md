# Sistema de Estacionamento - Java

## Enunciado

> **Disclaimer:** O enunciado original desta questão foi fornecido em folha de papel. Por isso, este texto foi gerado com o auxílio de inteligência artificial para fins de documentação.

Desenvolva um sistema de gerenciamento de estacionamento que utiliza uma **tabela hash** para armazenar e consultar informações sobre veículos cadastrados. O sistema deve permitir o cadastro de veículos e posterior consulta por placa.

### **Classe Carro (Fixa):**
A classe Carro deve conter os seguintes atributos e métodos:

```java
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
```

### **Funcionamento:**
O sistema deve implementar uma tabela hash onde:
- A **função hash** é calculada somando os valores ASCII de todos os caracteres da placa e aplicando o módulo pelo tamanho da tabela
- Colisões são tratadas usando **lista encadeada**
- Cada posição da tabela pode armazenar um veículo principal e uma lista para colisões

### **Entrada:**
- Primeira linha: um inteiro **n** representando o tamanho da tabela hash
- Seguem linhas com dados dos veículos no formato: `placa,modelo,tipo,chassi`
- A palavra **"FIM"** indica o fim do cadastro
- Seguem linhas com placas para consulta
- A palavra **"FIM_CONSULTA"** indica o fim das consultas

### **Saída:**
Para cada consulta, imprima:
- Se o veículo for encontrado: `placa modelo tipo chassi`
- Se o veículo não for encontrado: `VEICULO NAO CADASTRADO`

### **Exemplo:**

**Entrada:**
```
11
GTR1212,Fusca,carro,11AABBCCDD22EEFFG
HZX4545,Brasilia,carro,33XXYYZZWW44VVUU
LPO9889,Chevette,carro,55LLPPOONN66MMKK
QWE7766,Opala,carro,77QQWWEE RR88TTYY
FIM
HZX4545
ABC1234
QWE7766
GTR1212
FIM_CONSULTA
```

**Saída:**
```
HZX4545 Brasilia carro 33XXYYZZWW44VVUU
VEICULO NAO CADASTRADO
QWE7766 Opala carro 77QQWWEE RR88TTYY
GTR1212 Fusca carro 11AABBCCDD22EEFFG
```

## Erro que eu Cometi

### **Problema:** Falta de Recursividade na Função Buscar

O erro principal nesta implementação foi **esquecer de incluir a chamada recursiva** na função `buscar` da classe `Lista`. 

**Código com erro:**
```java
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
```

**Correção necessária:**
```java
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
        return buscar(placa, i.prox);
    } else {
        return false;
    }
}
```

**Consequência do erro:** Quando há colisões na tabela hash, apenas o primeiro elemento da lista encadeada é verificado. Os demais elementos da lista nunca são encontrados, resultando em "VEICULO NAO CADASTRADO" mesmo quando o veículo está cadastrado.

## Arquivos de Teste

As entradas e saídas públicas do programa estão na pasta **pubs**.
