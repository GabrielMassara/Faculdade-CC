# Teclado Defeituoso - JAVA

## Enunciado

> **Disclaimer:** O enunciado original desta questão foi fornecido em folha de papel. Por isso, este texto foi gerado com o auxílio de inteligência artificial para fins de documentação.

Problema do teclado defeituoso! Às vezes quando você digita em um computador velho, certas teclas podem ficar presas ou não funcionar corretamente, fazendo com que o texto seja digitado fora de ordem.

Neste problema, você deve simular um teclado onde tudo que é digitado entre colchetes `[` e `]` aparece no início da linha, enquanto o restante do texto aparece normalmente após esse texto "prioritário".

**Regras:**
- Texto entre `[` e `]` deve aparecer no início da saída
- Texto fora dos colchetes aparece após o texto dos colchetes
- Os colchetes em si não aparecem na saída final
- Podem haver múltiplos pares de colchetes na mesma linha

**Entrada:**
Múltiplas linhas de texto contendo caracteres normais e texto entre colchetes `[texto]`.

**Saída:**
Para cada linha de entrada, imprima o texto reorganizado conforme as regras acima.

## Exemplo

**Entrada:**
```
This_is_a_[Beiju]_text
[[]][]Happy_Birthday_Tsinghua_University
```

**Saída:**
```
BeijuThis_is_a__text
Happy_Birthday_Tsinghua_University
```

## Arquivos de Teste

As entradas e saídas públicas do programa estão na pasta **pubs**.
