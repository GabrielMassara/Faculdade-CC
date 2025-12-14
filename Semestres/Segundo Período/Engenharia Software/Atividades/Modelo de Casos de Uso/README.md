# Modelo de Casos de Uso - Sistema de Logística

## 📋 Contextualização da Atividade

### Objetivo Principal
Construir o **Modelo de Casos de Uso completo** do Sistema de Logística, incluindo:
- **Um único Diagrama de Casos de Uso** consolidado
- **Todos os detalhamentos** dos casos de uso identificados
- **Respectivos responsáveis** por cada caso de uso

### Escopo do Sistema
Sistema de logística para transporte de bens e matérias-primas em território nacional brasileiro, contemplando as necessidades de:
- **Motoristas** (navegação, segurança, paradas)
- **Gerentes de Operações** (monitoramento, controle, otimização)
- **Clientes Empresariais** (acompanhamento, transparência, comunicação)

## 🎯 Componentes da Entrega

### **1. Diagrama de Casos de Uso Único**
Representação visual consolidada contendo:
- **Atores do sistema** (Motorista, Gerente, Cliente, Sistema Externo)
- **Casos de uso principais** derivados das histórias de usuários
- **Relacionamentos** entre atores e casos de uso
- **Limites do sistema** claramente definidos

### **2. Detalhamentos Completos**
Para cada caso de uso identificado, incluir:
- **Especificação detalhada**
- **Fluxo principal**
- **Fluxos alternativos**
- **Pré-condições e pós-condições**
- **Requisitos funcionais relacionados**

### **3. Responsabilidades Definidas**
Cada membro do time deve ser **responsável específico** por determinados casos de uso.

## 🛠️ Ferramenta Recomendada

### **Visual Paradigm Community Edition**
- **Download:** https://www.visual-paradigm.com/editions/community/
- **Vantagens:** Ferramenta CASE gratuita e completa
- **Recursos:** Criação de diagramas UML profissionais
- **Compatibilidade:** Arquivos .vpp para reutilização

### **Arquivo de Referência**
- **20251028 CE Notas de Aulas.vpp** - Exemplos de casos de uso
- Disponível para consulta e adaptação

## 📊 Estrutura do Diagrama

### **Atores Principais**
```
👤 Motorista
   - Persona: Condutor responsável pelo transporte
   - Necessidades: Navegação segura, pontos de parada, comunicação

👨‍💼 Gerente de Operações  
   - Persona: Responsável pelo controle da frota
   - Necessidades: Monitoramento, otimização, relatórios

🏢 Cliente Empresarial
   - Persona: Empresa contratante do serviço
   - Necessidades: Acompanhamento, transparência, comunicação

🌐 Sistema Externo
   - APIs de mapas, órgãos de trânsito, sistemas fiscais
```

### **Casos de Uso Derivados das Histórias**

#### **UC01 - Visualizar Alertas de Segurança**
- **Ator Principal:** Motorista
- **Objetivo:** Receber alertas de trechos perigosos e pontos de parada
- **RF Relacionados:** RF-001, RF-002

#### **UC02 - Monitorar Frota em Tempo Real**
- **Ator Principal:** Gerente de Operações
- **Objetivo:** Acompanhar localização e status dos veículos
- **RF Relacionados:** RF-003, RF-004

#### **UC03 - Acompanhar Status de Entrega**
- **Ator Principal:** Cliente Empresarial
- **Objetivo:** Visualizar progresso das entregas contratadas
- **RF Relacionados:** RF-005, RF-006

#### **UC04 - Otimizar Rotas**
- **Ator Principal:** Gerente de Operações
- **Objetivo:** Calcular melhores rotas considerando múltiplos fatores
- **RF Relacionados:** RF-007, RF-008

#### **UC05 - Gerenciar Documentação Digital**
- **Ator Principal:** Motorista
- **Objetivo:** Digitalizar e validar documentos fiscais
- **RF Relacionados:** RF-009, RF-010

## 📝 Template de Especificação

### **Modelo de Detalhamento por Caso de Uso**

```
============================================================================
CASO DE USO: UC0X - [Nome do Caso de Uso]
RESPONSÁVEL: [Nome do Integrante]
============================================================================

1. IDENTIFICAÇÃO
   - ID: UC0X
   - Nome: [Nome Descritivo]
   - Ator Principal: [Motorista/Gerente/Cliente]
   - Atores Secundários: [Se aplicável]

2. OBJETIVO
   [Descrição clara do que o caso de uso pretende alcançar]

3. PRÉ-CONDIÇÕES
   - [Condição 1 que deve existir antes da execução]
   - [Condição 2 que deve existir antes da execução]

4. PÓS-CONDIÇÕES
   - [Resultado 1 garantido após execução bem-sucedida]
   - [Resultado 2 garantido após execução bem-sucedida]

5. FLUXO PRINCIPAL
   1. [Passo 1 - Ação do ator]
   2. [Passo 2 - Resposta do sistema]
   3. [Passo 3 - Continuação...]
   4. [...]
   N. Caso de uso finalizado com sucesso

6. FLUXOS ALTERNATIVOS
   A1. [Cenário alternativo 1]
      A1.1. [Condição que gera o fluxo alternativo]
      A1.2. [Ações do fluxo alternativo]
      A1.3. [Retorno ao fluxo principal ou finalização]
   
   A2. [Cenário alternativo 2]
      [...]

7. FLUXOS DE EXCEÇÃO
   E1. [Cenário de erro 1]
      E1.1. [Condição de erro]
      E1.2. [Tratamento do erro]
      E1.3. [Finalização ou recuperação]

8. REQUISITOS FUNCIONAIS RELACIONADOS
   - RF-XXX: [Descrição do requisito]
   - RF-YYY: [Descrição do requisito]

9. REQUISITOS NÃO-FUNCIONAIS RELACIONADOS
   - RNF-XXX: [Descrição do requisito]

10. REGRAS DE NEGÓCIO
    - RN-XXX: [Regra específica do domínio]

============================================================================
```

## 💡 Exemplo Completo

### **UC01 - Visualizar Alertas de Segurança**

**Responsável:** [Nome do Integrante]

1. **IDENTIFICAÇÃO**
   - ID: UC01
   - Nome: Visualizar Alertas de Segurança na Rota
   - Ator Principal: Motorista
   - Atores Secundários: Sistema de Mapas (API)

2. **OBJETIVO**
   Permitir que o motorista visualize alertas de trechos perigosos e pontos de parada confiáveis em sua rota planejada.

3. **PRÉ-CONDIÇÕES**
   - Motorista deve estar autenticado no sistema
   - Dispositivo deve ter conexão com internet
   - GPS deve estar habilitado

4. **PÓS-CONDIÇÕES**
   - Rota é exibida com alertas visuais
   - Sistema mantém monitoramento ativo
   - Alertas sonoros estão configurados

5. **FLUXO PRINCIPAL**
   1. Motorista abre aplicativo de navegação
   2. Sistema apresenta tela inicial com mapa
   3. Motorista insere destino da viagem
   4. Sistema calcula rota otimizada
   5. Sistema consulta base de dados de alertas de segurança
   6. Sistema exibe rota com ícones de alerta nos trechos perigosos
   7. Sistema exibe pontos de parada recomendados
   8. Motorista confirma rota e inicia navegação
   9. Sistema ativa alertas sonoros para proximidade de perigos
   10. Caso de uso finalizado com sucesso

6. **FLUXOS ALTERNATIVOS**
   A1. Destino não encontrado
      A1.1. Sistema não localiza endereço informado
      A1.2. Sistema solicita esclarecimento do destino
      A1.3. Retorna ao passo 3 do fluxo principal

7. **FLUXOS DE EXCEÇÃO**
   E1. Perda de conexão durante navegação
      E1.1. Sistema detecta ausência de internet
      E1.2. Sistema utiliza dados locais cached
      E1.3. Sistema notifica limitação de funcionalidades

8. **REQUISITOS FUNCIONAIS RELACIONADOS**
   - RF-001: Identificação automática de trechos perigosos
   - RF-002: Exibição de alertas visuais no mapa

## 🔍 Critérios de Qualidade

### **Para o Diagrama**
- **Completude:** Todos os casos principais representados
- **Clareza:** Relacionamentos bem definidos
- **Consistência:** Nomenclatura padronizada
- **Organização:** Layout limpo e compreensível

### **Para os Detalhamentos**
- **Precisão:** Fluxos bem definidos e realistas
- **Cobertura:** Cenários principais e alternativos
- **Rastreabilidade:** Ligação clara com requisitos
- **Testabilidade:** Especificações verificáveis

## ✅ Checklist de Verificação

### **Antes da Entrega**
- [ ] Diagrama único consolidado criado
- [ ] Todos os casos de uso detalhados
- [ ] Responsabilidades atribuídas aos membros
- [ ] Fluxos principais bem definidos
- [ ] Fluxos alternativos identificados
- [ ] Pré e pós-condições especificadas
- [ ] Rastreabilidade com requisitos estabelecida
- [ ] Revisão de consistência realizada
- [ ] Documento final em PDF gerado

### **Qualidade dos Casos de Uso**
- [ ] Objetivos claros e mensuráveis
- [ ] Atores bem identificados
- [ ] Fluxos sequenciais e lógicos
- [ ] Cenários de erro contemplados
- [ ] Linguagem clara e padronizada

## 📄 Estrutura da Entrega Final

```
============================================================================
MODELO DE CASOS DE USO - SISTEMA DE LOGÍSTICA

GRUPO: _______
INTEGRANTES: _______

============================================================================

1. DIAGRAMA DE CASOS DE USO CONSOLIDADO
   [Diagrama visual único com todos os casos de uso]

2. ESPECIFICAÇÕES DETALHADAS

   RESPONSÁVEL: [Integrante 1]
   - UC01 - [Nome do Caso]
   - UC02 - [Nome do Caso]
   [Detalhamentos completos]

   RESPONSÁVEL: [Integrante 2]  
   - UC03 - [Nome do Caso]
   - UC04 - [Nome do Caso]
   [Detalhamentos completos]

   [Continuar para todos os integrantes]

3. MATRIZ DE RASTREABILIDADE UC x RF
   [Tabela relacionando casos de uso com requisitos funcionais]

============================================================================
```

## 🎯 Benefícios da Atividade

1. **Visão Funcional:** Compreensão das funcionalidades do sistema
2. **Comunicação:** Linguagem comum entre stakeholders
3. **Planejamento:** Base para estimativas e cronograma
4. **Testes:** Cenários para validação do sistema
5. **Arquitetura:** Insumo para design da solução

---

*Atividade realizada como parte da disciplina de Engenharia de Software - Modelo de Casos de Uso*