# Requisitos Funcionais e Não-funcionais - Sistema de Logística

## 📋 Contextualização da Sprint 2

### Objetivo Principal
A partir das **Histórias de Usuários** criadas na Sprint 1, apresentar a lista completa de **Requisitos Funcionais** e o conjunto de **Requisitos Não-funcionais** do Sistema de Logística.

**Contexto:** Mesmo cenário da Sprint 1 - empresa de logística de transporte a nível nacional no Brasil.

## 🎯 Características dos Requisitos

Os requisitos precisam ser:

### ✅ **Completos**
- Riqueza de detalhes
- Sem excesso de "tecniquês"
- Incluir descrição de todos os serviços necessários

### ⚙️ **Implementáveis**
- Factíveis com a tecnologia vigente

### 🔄 **Consistentes**
- Sem conflitos ou contradições entre si

### ✔️ **Verificáveis**
- Quando implementado, deve ser fácil perceber se foi atendido

### 🔍 **Rastreáveis**
- Possível detectar qual necessidade gerou o requisito

### 📖 **Sem Ambiguidade**
- Clareza na interpretação
- Sem margem para outras interpretações

## 📝 Estrutura dos Requisitos

### Requisito Funcional (RF)
Deve conter:
- **Entrada:** Dados de input do sistema
- **Processamento:** Como o sistema manipula os dados
- **Saída:** Resultado apresentado ao usuário
- **Serviços Necessários:** APIs, bancos de dados, etc.
- **Condição de aceitação/verificação:** Critérios para validar
- **Rastreabilidade:** Ligação com a história de usuário

### Requisito Não-funcional (RNF)
Deve especificar:
- **Critérios mensuráveis** (performance, precisão, etc.)
- **Condições de funcionamento**
- **Segurança e confiabilidade**
- **Condição de aceitação/verificação**
- **Rastreabilidade**

## 💡 Exemplo Detalhado

### História de Usuário Base:
> "Como motorista, desejo ver alertas de trechos perigosos e pontos de parada confiáveis na minha rota para viajar com mais segurança e planejar minhas paradas."

---

### **RF-01: Exibição de Alertas e Pontos de Parada**

O sistema deverá identificar automaticamente os trechos perigosos e os pontos de parada confiáveis ao longo da rota definida pelo motorista e exibir essas informações em tempo real no aplicativo de navegação.

**Detalhamento do Sistema:**
- **Entrada:** Rota definida pelo motorista no aplicativo (por endereço, coordenadas ou destino)
- **Processamento:** O sistema consulta um banco de dados atualizado de trechos perigosos (curvas acentuadas, alto índice de acidentes, obras, áreas de risco) e pontos de parada confiáveis (postos de combustível, restaurantes, áreas de descanso com infraestrutura). Os dados são processados para verificar se estão no trajeto atual do motorista.
- **Saída:** Exibir no mapa ícones visuais diferenciados para "trechos perigosos" (triângulo de alerta) e "pontos de parada confiáveis" (ícone de bomba de combustível ou cama para hotel). Exibir aviso sonoro opcional ao se aproximar de um trecho perigoso.
- **Serviços Necessários:** 
  - API de mapas/rotas (Google Maps, OpenStreetMap ou similar)
  - Banco de dados confiável atualizado com trechos perigosos e pontos de parada
  - Serviço de geolocalização do dispositivo
- **Condição de aceitação/verificação:** Ao simular ou percorrer uma rota contendo trechos perigosos e pontos de parada confiáveis cadastrados, o aplicativo deve exibir ícones e alertas correspondentes no mapa.
- **Rastreabilidade:** Está diretamente ligado à necessidade do motorista de viajar com mais segurança e planejar suas paradas.

---

### **RNF-01: Precisão e Atualização das Informações**

O sistema deverá apresentar informações atualizadas e precisas sobre trechos perigosos e pontos de parada confiáveis, com atualização dos dados pelo menos uma vez a cada 24 horas, garantindo que o motorista receba alertas válidos e úteis durante a viagem.

**Especificações:**
- **Critérios de precisão:** A localização exibida dos pontos de parada e trechos perigosos deve ter margem de erro máxima de 20 metros em relação ao ponto real.
- **Critérios de atualização:** O banco de dados do aplicativo deve ser sincronizado automaticamente com o servidor central no mínimo uma vez a cada 24h, mesmo sem intervenção do usuário.
- **Desempenho:** A atualização não deve comprometer o desempenho do aplicativo, devendo ocorrer em background.
- **Segurança e confiabilidade:** As informações devem vir de fontes verificadas (órgãos de trânsito, concessionárias de rodovias, estabelecimentos com cadastro oficial).
- **Condição de aceitação/verificação:** Auditoria dos dados no servidor mostrando atualização dentro do prazo. Teste de campo comparando o ponto exibido no aplicativo com a localização real.
- **Rastreabilidade:** Atende à necessidade do motorista de receber alertas confiáveis para planejar a rota com segurança.

## 📄 Template de Entrega

```
============================================================================
NOME: ________
GRUPO: _______

HISTÓRIA DE USUÁRIO 01: [Descrição da história]

RF-01: [Título]
[Descrição detalhada com entrada, processamento, saída, serviços, condições e rastreabilidade]

RF-02: [Título]
[Descrição detalhada...]

...

RF-N: [Título]
[Descrição detalhada...]

HISTÓRIA DE USUÁRIO 02: [Descrição da história]

RF-01: [Título]
[Descrição detalhada...]

RF-02: [Título]
[Descrição detalhada...]

...

RF-M: [Título]
[Descrição detalhada...]

HISTÓRIA DE USUÁRIO 03: [Descrição da história]

RF-01: [Título]
[Descrição detalhada...]

...

HISTÓRIA DE USUÁRIO 04: [Descrição da história]

RF-01: [Título]
[Descrição detalhada...]

...

HISTÓRIA DE USUÁRIO 05: [Descrição da história]

RF-01: [Título]
[Descrição detalhada...]

...

RNF-01: [Título]
[Descrição detalhada com critérios mensuráveis, condições e rastreabilidade]

RNF-02: [Título]
[Descrição detalhada...]

...

RNF-S: [Título]
[Descrição detalhada...]

============================================================================
```

## 📚 Documentos de Referência

Para basear a estrutura e qualidade dos requisitos:

1. **ReqView Example Software Requirements Specification**
   - https://www.reqview.com/papers/ReqView-Example_Software_Requirements_Specification_SRS_Document.pdf

2. **iTest Software Requirements Specification**
   - https://itest.sourceforge.net/documentation/developer/Software_Requirements_Specification-iTest.pdf

3. **Gephi SRS Document**
   - https://gephi.org/users/gephi_srs_document.pdf

4. **Enabel Detailed Software Requirements Specification**
   - https://www.enabel.be/app/uploads/2025/06/Annex-A-Detailed-Software-Requirements-Specification-SRS.pdf

> **Nota:** Estes são documentos reais - nem todos os requisitos atendem 100% às características ideais descritas acima.

## ⚠️ Observações Importantes

- **O PDF do grupo é único** e deve conter todos os requisitos de todas as histórias de usuários de responsabilidade de cada aluno
- Cada requisito deve ser numerado sequencialmente
- Requisitos funcionais são derivados diretamente das histórias de usuários
- Requisitos não-funcionais complementam e qualificam os funcionais
- Manter rastreabilidade clara entre histórias de usuários e requisitos

---

*Atividade realizada como parte da disciplina de Engenharia de Software - Sprint II*