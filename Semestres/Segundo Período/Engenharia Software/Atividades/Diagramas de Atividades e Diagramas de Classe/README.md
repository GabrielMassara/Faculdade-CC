# Diagramas de Atividades e Diagramas de Classe - Sistema de Logística

## 📋 Contextualização da Atividade

### Objetivo Principal
Construir os **Diagramas de Atividades** e **Diagramas de Classes** correspondentes a cada Caso de Uso do Sistema de Logística, além do **Modelo de Classe de Domínio** consolidado.

### Escopo da Entrega
- **Diagramas de Atividades:** Para cada caso de uso identificado
- **Diagramas de Classes:** Correspondentes aos casos de uso
- **Modelo de Classe de Domínio:** Classes de entidade consolidadas
- **Modelo de Caso de Uso:** Versão corrigida da atividade anterior

## 🎯 Componentes da Entrega

### **1. Diagramas de Atividades**
Para **cada caso de uso** do sistema:
- **Fluxo detalhado** das atividades
- **Decisões e condições** do processo
- **Paralelismo** quando aplicável
- **Início e fim** claramente definidos

### **2. Diagramas de Classes por Caso de Uso**
Para **cada caso de uso** específico:
- **Classes controladoras** necessárias
- **Classes de interface** (boundary)
- **Classes de entidade** envolvidas
- **Relacionamentos** entre as classes
- **Métodos principais** de cada classe

### **3. Modelo de Classe de Domínio**
**Consolidação** de todas as classes de entidade:
- **Apenas classes de entidade** do sistema
- **Relacionamentos completos** entre entidades
- **Atributos principais** de cada entidade
- **Multiplicidades** dos relacionamentos
- **Chaves primárias e estrangeiras**

### **4. Modelo de Caso de Uso Corrigido**
Versão **revisada e melhorada** da atividade anterior baseada nos feedbacks.

## 🛠️ Ferramenta Recomendada

### **Visual Paradigm Community Edition**
- **Download:** https://www.visual-paradigm.com/editions/community/
- **Vantagens:** Ferramenta CASE completa e gratuita
- **Recursos UML:** Diagramas de atividades, classes, casos de uso
- **Arquivos .vpp:** Disponíveis no Canvas para referência

## 📊 Estrutura dos Diagramas

### **Diagrama de Atividades - Componentes**

```
🟢 Início (círculo preenchido)
   ↓
📋 Atividade (retângulo com cantos arredondados)
   ↓
◆️ Decisão (losango)
   ↓ [condição]
🔄 Junção/Fork (barra horizontal)
   ↓
📋 Atividades paralelas
   ↓
🔗 Sincronização (barra horizontal)
   ↓
⚫ Fim (círculo com borda)
```

### **Diagrama de Classes - Estereótipos**

```
<<boundary>>     - Classes de interface (UI)
<<control>>      - Classes controladoras (lógica)  
<<entity>>       - Classes de entidade (dados)
```

## 💡 Exemplos Práticos

### **Exemplo: UC01 - Visualizar Alertas de Segurança**

#### **Diagrama de Atividades - UC01**
```
🟢 Início
   ↓
📋 Motorista abre aplicativo
   ↓
📋 Sistema carrega interface inicial
   ↓
📋 Motorista insere destino
   ↓
◆️ Destino válido?
   ↓ [Não]
📋 Sistema solicita nova entrada → [volta para inserir destino]
   ↓ [Sim]
📋 Sistema calcula rota
   ↓
🔄 Fork: Processamento paralelo
   ├── 📋 Consulta trechos perigosos
   └── 📋 Consulta pontos de parada
   ↓
🔗 Sincronização
   ↓
📋 Sistema exibe mapa com alertas
   ↓
📋 Motorista inicia navegação
   ↓
⚫ Fim
```

#### **Diagrama de Classes - UC01**
```
<<boundary>>
+InterfaceNavegacao
- mapa: Mapa
- campoDestino: String
+ exibirRota()
+ mostrarAlertas()
+ capturarDestino()

<<control>>
+ControladorNavegacao
- rotaAtual: Rota
+ calcularRota(destino: String)
+ buscarAlertas(rota: Rota)
+ iniciarNavegacao()

<<entity>>
+Rota
- id: Long
- origem: Coordenada
- destino: Coordenada
- distancia: Double
+ adicionarAlerta()

<<entity>>
+AlertaSeguranca
- id: Long
- tipo: TipoAlerta
- coordenada: Coordenada
- descricao: String
+ isAtivo()
```

### **Modelo de Classe de Domínio - Exemplo Consolidado**

```
+Motorista                    +Veiculo
- id: Long                   - id: Long
- nome: String              - placa: String
- cnh: String               - modelo: String
- telefone: String          - capacidade: Double
+ autenticar()              + calcularManutencao()
      |                            |
      | 1..*                       | 1..*
      |                            |
      +----- +Viagem ------+-------+
            - id: Long
            - dataInicio: Date
            - dataFim: Date
            - status: StatusViagem
            + iniciar()
            + finalizar()
                  |
                  | 1..*
                  |
            +Entrega
            - id: Long
            - endereco: String
            - status: StatusEntrega
            - dataPrevisao: Date
            + confirmarEntrega()
                  |
                  | *..1
                  |
            +Cliente
            - id: Long
            - razaoSocial: String
            - cnpj: String
            + solicitarEntrega()
```

## 📝 Templates de Desenvolvimento

### **Checklist por Caso de Uso**

```
CASO DE USO: UC0X - [Nome]
RESPONSÁVEL: [Nome do Integrante]

□ Diagrama de Atividades criado
  - Início e fim definidos
  - Fluxo principal mapeado
  - Decisões identificadas
  - Fluxos paralelos (se aplicável)
  
□ Diagrama de Classes criado
  - Classes boundary identificadas
  - Classes control definidas
  - Classes entity mapeadas
  - Relacionamentos estabelecidos
  - Métodos principais definidos

□ Classes de Entidade separadas para Modelo de Domínio
```

### **Estrutura de Classes por Estereótipo**

#### **Classes Boundary (Interface)**
```
+[NomeInterface]
- atributos de interface (campos, botões)
+ métodos de interação com usuário
+ métodos de exibição
```

#### **Classes Control (Controladora)**
```
+[NomeControlador]
- atributos de controle (estado, dados temporários)
+ métodos de processamento
+ métodos de coordenação
+ métodos de validação
```

#### **Classes Entity (Entidade)**
```
+[NomeEntidade]
- atributos do domínio (dados persistentes)
+ métodos de acesso (getters/setters)  
+ métodos de negócio
+ métodos de validação de domínio
```

## 🔍 Critérios de Qualidade

### **Para Diagramas de Atividades**
- **Completude:** Todos os passos do caso de uso representados
- **Clareza:** Fluxo fácil de seguir
- **Decisões:** Condições bem definidas
- **Paralelismo:** Identificado quando apropriado
- **Consistência:** Notação UML correta

### **Para Diagramas de Classes**
- **Separação de responsabilidades:** Boundary/Control/Entity bem definidos
- **Coesão:** Classes com responsabilidade única
- **Acoplamento:** Relacionamentos necessários e suficientes
- **Nomenclatura:** Nomes claros e descritivos
- **Métodos:** Operações principais identificadas

### **Para Modelo de Domínio**
- **Entidades completas:** Todas as classes de negócio
- **Relacionamentos corretos:** Multiplicidades adequadas
- **Atributos essenciais:** Dados fundamentais do domínio
- **Integridade:** Consistência entre relacionamentos
- **Simplicidade:** Apenas o essencial do domínio

## ✅ Checklist de Verificação

### **Antes da Entrega**
- [ ] Diagrama de atividades para cada caso de uso
- [ ] Diagrama de classes para cada caso de uso
- [ ] Modelo de domínio consolidado criado
- [ ] Modelo de casos de uso corrigido incluído
- [ ] Responsabilidades definidas para cada membro
- [ ] Notação UML correta em todos os diagramas
- [ ] Relacionamentos bem definidos
- [ ] Documento final em PDF gerado

### **Qualidade dos Diagramas**
- [ ] Legibilidade adequada
- [ ] Elementos bem posicionados
- [ ] Cores e estilos consistentes
- [ ] Títulos e legendas presentes
- [ ] Escala apropriada para visualização

### **Consistência entre Artefatos**
- [ ] Classes do domínio consistentes entre diagramas
- [ ] Atividades alinhadas com casos de uso
- [ ] Nomenclatura padronizada
- [ ] Relacionamentos coerentes

## 📄 Estrutura da Entrega Final

```
============================================================================
DIAGRAMAS DE ATIVIDADES E CLASSES - SISTEMA DE LOGÍSTICA

GRUPO: _______
INTEGRANTES: _______

============================================================================

1. MODELO DE CASOS DE USO CORRIGIDO
   1.1. Diagrama de Casos de Uso
   1.2. Especificações Detalhadas dos Casos de Uso

2. DIAGRAMAS POR CASO DE USO

   RESPONSÁVEL: [Integrante 1]
   
   2.1. UC01 - [Nome do Caso de Uso]
        2.1.1. Diagrama de Atividades UC01
        2.1.2. Diagrama de Classes UC01
   
   2.2. UC02 - [Nome do Caso de Uso]  
        2.2.1. Diagrama de Atividades UC02
        2.2.2. Diagrama de Classes UC02

   RESPONSÁVEL: [Integrante 2]
   
   2.3. UC03 - [Nome do Caso de Uso]
        2.3.1. Diagrama de Atividades UC03
        2.3.2. Diagrama de Classes UC03
   
   [Continuar para todos os casos de uso e integrantes]

3. MODELO DE CLASSE DE DOMÍNIO CONSOLIDADO
   3.1. Diagrama de Classes de Entidade
   3.2. Descrição das Entidades Principais
   3.3. Relacionamentos e Multiplicidades

============================================================================
```

## 🎯 Estratégia de Desenvolvimento

### **Passo 1: Preparação Individual**
Cada membro deve:
1. Criar diagrama de atividades para seus casos de uso
2. Desenvolver diagrama de classes correspondente
3. **Separar classes de entidade** para consolidação posterior

### **Passo 2: Consolidação em Grupo**
1. **Reunir todas as classes de entidade** separadas
2. **Eliminar duplicações** e inconsistências
3. **Definir relacionamentos** entre entidades
4. **Criar modelo de domínio** único e consistente

### **Passo 3: Revisão e Integração**
1. Verificar **consistência** entre todos os diagramas
2. **Corrigir modelo de casos de uso** baseado em feedbacks
3. **Validar nomenclatura** e padrões
4. **Gerar documento final** em PDF

## 🌟 Benefícios da Atividade

1. **Visão Comportamental:** Compreensão dos processos (atividades)
2. **Visão Estrutural:** Organização das classes (estrutura)
3. **Modelo de Domínio:** Base sólida para implementação
4. **Comunicação:** Linguagem visual comum
5. **Arquitetura:** Fundação para design detalhado

---

*Atividade realizada como parte da disciplina de Engenharia de Software - Diagramas de Atividades e Classes*