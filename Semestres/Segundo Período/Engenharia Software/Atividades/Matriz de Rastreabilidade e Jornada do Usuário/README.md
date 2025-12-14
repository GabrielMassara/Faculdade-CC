# Matriz de Rastreabilidade e Jornada do Usuário - Sistema de Logística

## 📋 Contextualização da Atividade

### Objetivo Principal
O Time de Engenharia de Software deverá fazer uma **revisão da consistência geral** da lista de requisitos de software e histórias de usuários para construir uma **Matriz de Rastreabilidade de Requisitos Funcionais** única para todo o Sistema de Logística.

### Escopo da Revisão
- **Análise de consistência** entre histórias de usuários e requisitos funcionais
- **Consolidação** de todos os requisitos em uma matriz única
- **Mapeamento** da rastreabilidade entre elementos do sistema

## 🎯 Componentes da Entrega

### **a) Matriz de Rastreabilidade Geral**
Matriz única contendo **todos os requisitos funcionais** do sistema, contemplando:

#### Estrutura da Matriz
| ID História | Descrição da História | ID RF | Descrição do RF | Stakeholder | Prioridade | Status |
|-------------|----------------------|--------|-----------------|-------------|------------|---------|
| HU-01 | Como [usuário]... | RF-01 | Sistema deve... | Motorista | Alta | Definido |
| HU-01 | Como [usuário]... | RF-02 | Sistema deve... | Motorista | Média | Definido |
| HU-02 | Como [usuário]... | RF-03 | Sistema deve... | Gerente | Alta | Definido |

#### Elementos de Rastreabilidade
- **ID da História de Usuário:** Identificação única (HU-XX)
- **Descrição da História:** História completa do usuário
- **ID do Requisito Funcional:** Identificação única (RF-XXX)
- **Descrição do Requisito:** Requisito funcional detalhado
- **Stakeholder Principal:** Persona beneficiada
- **Prioridade:** Alta/Média/Baixa
- **Status:** Definido/Em análise/Aprovado

### **b) Jornadas do Usuário Individuais**

Cada componente do grupo deverá elaborar a **Jornada do Usuário** para suas histórias de responsabilidade.

#### Estrutura da Jornada
Descrição sequencial das **ações do usuário** e **reações do sistema**:

1. **[Ação do Usuário]** → Descrição da ação
2. **[Reação do Sistema]** → Resposta/apresentação do sistema
3. **[Ação do Usuário]** → Próxima ação
4. **[Reação do Sistema]** → Nova resposta do sistema
5. **[...]** → Continuidade até completar o fluxo

## 💡 Exemplo de Jornada do Usuário

### História: "Como motorista, desejo ver alertas de trechos perigosos para viajar com segurança"

**Jornada Detalhada:**

1. **Motorista abre o aplicativo de navegação**
2. **Sistema apresenta tela inicial com mapa e opções de rota**
3. **Motorista insere destino da viagem no campo de busca**
4. **Sistema processa o destino e calcula possíveis rotas**
5. **Motorista seleciona a rota preferida**
6. **Sistema consulta banco de dados de trechos perigosos na rota selecionada**
7. **Sistema exibe rota no mapa com ícones de alerta nos trechos perigosos**
8. **Motorista inicia navegação pressionando botão "Iniciar"**
9. **Sistema ativa GPS e inicia navegação em tempo real**
10. **Sistema emite alerta sonoro ao se aproximar de trecho perigoso**
11. **Motorista recebe notificação visual e sonora do alerta**
12. **Sistema continua monitoramento até chegada ao destino**

## 🔍 Critérios de Qualidade

### Para a Matriz de Rastreabilidade
- **Completude:** Todos os RF devem estar mapeados para HU
- **Consistência:** Não deve haver conflitos entre requisitos
- **Rastreabilidade bidirecional:** HU ↔ RF claramente relacionados
- **Priorização:** Requisitos classificados por importância
- **Cobertura:** Todas as personas contempladas

### Para as Jornadas do Usuário
- **Sequência lógica:** Fluxo natural de interações
- **Detalhamento adequado:** Ações e reações específicas
- **Cobertura completa:** Do início ao fim da funcionalidade
- **Clareza:** Linguagem simples e objetiva
- **Realismo:** Cenários factíveis e práticos

## 📊 Modelo de Matriz de Rastreabilidade

### Exemplo Consolidado

| ID HU | História de Usuário | ID RF | Requisito Funcional | Stakeholder | Prioridade | Status |
|-------|---------------------|--------|-------------------|-------------|------------|---------|
| HU-01 | Como motorista, quero ver alertas de trechos perigosos... | RF-001 | Sistema deve identificar trechos perigosos automaticamente | Motorista | Alta | Definido |
| HU-01 | Como motorista, quero ver alertas de trechos perigosos... | RF-002 | Sistema deve exibir alertas visuais no mapa | Motorista | Alta | Definido |
| HU-02 | Como gerente, quero monitorar frota em tempo real... | RF-003 | Sistema deve rastrear localização dos veículos | Gerente | Alta | Definido |
| HU-02 | Como gerente, quero monitorar frota em tempo real... | RF-004 | Sistema deve apresentar dashboard de monitoramento | Gerente | Média | Definido |
| HU-03 | Como cliente, quero acompanhar status da entrega... | RF-005 | Sistema deve atualizar status de entrega em tempo real | Cliente | Alta | Definido |

## 📝 Template de Entrega

```
============================================================================
SISTEMA DE LOGÍSTICA - MATRIZ DE RASTREABILIDADE E JORNADAS DO USUÁRIO

GRUPO: _______
INTEGRANTES: _______

============================================================================

A) MATRIZ DE RASTREABILIDADE GERAL DE REQUISITOS FUNCIONAIS

[Tabela consolidada com todos os RF do sistema]

============================================================================

B) JORNADAS DO USUÁRIO

INTEGRANTE 1: [Nome]
HISTÓRIAS DE RESPONSABILIDADE: HU-XX, HU-YY

JORNADA DO USUÁRIO - HU-XX:
[História completa]
1. [Ação do usuário]
2. [Reação do sistema]
3. [Ação do usuário]
...

JORNADA DO USUÁRIO - HU-YY:
[História completa]
1. [Ação do usuário]
2. [Reação do sistema]
...

---

INTEGRANTE 2: [Nome]
HISTÓRIAS DE RESPONSABILIDADE: HU-ZZ

JORNADA DO USUÁRIO - HU-ZZ:
[Descrição detalhada da jornada]

---

[Repetir para todos os N integrantes do grupo]

============================================================================
```

## ✅ Checklist de Verificação

### Antes da Entrega
- [ ] Todos os requisitos funcionais estão na matriz
- [ ] Rastreabilidade HU → RF está clara
- [ ] Prioridades estão definidas
- [ ] Cada integrante tem suas jornadas detalhadas
- [ ] Jornadas cobrem fluxo completo das funcionalidades
- [ ] Linguagem está clara e objetiva
- [ ] Documento está bem formatado
- [ ] Revisão de consistência foi realizada

### Qualidade das Jornadas
- [ ] Sequência lógica de ações
- [ ] Interações usuário-sistema bem definidas
- [ ] Cenários realistas
- [ ] Cobertura de casos de uso principais
- [ ] Detalhamento adequado sem excessos

## 🎯 Benefícios da Atividade

1. **Visão Sistêmica:** Compreensão global dos requisitos
2. **Rastreabilidade:** Controle de mudanças e impactos
3. **Consistência:** Verificação de conflitos e lacunas
4. **UX Design:** Melhoria da experiência do usuário
5. **Documentação:** Base para desenvolvimento e testes

---

*Atividade realizada como parte da disciplina de Engenharia de Software - Matriz de Rastreabilidade e Jornada do Usuário*