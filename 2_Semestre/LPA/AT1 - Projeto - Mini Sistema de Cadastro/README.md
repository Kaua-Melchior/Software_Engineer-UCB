# Atividade Avaliativa - AT1: Mini-Sistema de Cadastro em C

**Instituição:** Universidade Católica de Brasília (UCB)  
**Curso:** Engenharia de Software - 2º Semestre  
**Disciplina:** Lógica de Programação e Algoritmos (LPA)  
**Docente:** Profª Hially  
**Data da Apresentação:** 14/10/2026  
**Nota Total:** 2,0 pontos  

---

## 📌 Visão Geral do Projeto

Este projeto consiste no desenvolvimento de um **Mini-Sistema de Cadastro e Controle de Produtos** implementado em linguagem C para gerenciamento de estoque em memória.

O sistema adota **vetores paralelos** para armazenar e relacionar as informações, integrando as cinco operações fundamentais de manipulação de dados (**Cadastrar**, **Consultar**, **Listar**, **Alterar** e **Excluir**) sob um menu interativo contínuo com estrutura `do-while` e `switch-case`.

---

## 📊 Distribuição da Nota (2,0 Pontos)

Conforme as instruções da atividade avaliativa, a pontuação está distribuída igualmente entre as funcionalidades:

| Funcionalidade | Pontuação | Descrição da Implementação |
|:---|:---:|:---|
| **Cadastro** | **0,4 pt** | Valida capacidade máxima do vetor (`total < TAM_MAX`), lê dados com validação, armazena na posição `total`, calcula total do produto e incrementa `total++`. |
| **Consulta** | **0,4 pt** | Busca linear pelo identificador único (`codigo[i] == codigoBusca`) e exibe código, nome, preço, quantidade e total em valor do produto. |
| **Listagem** | **0,4 pt** | Percorre de `0` até `total - 1`, exibindo cada produto, seu respectivo total em valor e o **total em preço acumulado** de todo o estoque. |
| **Alteração** | **0,4 pt** | Localiza a posição do produto pelo código informado, exibe os dados atuais e permite sobrescrever nome, preço e quantidade mantendo a integridade da posição. |
| **Exclusão** | **0,4 pt** | Localiza a posição do produto e realiza o **deslocamento de elementos** posteriores para a esquerda (`i = i + 1`), decrementando a variável `total`. |

---

## 🎯 Tema e Estrutura de Dados

- **Tema:** Cadastro e Controle de Estoque de Produtos
- **Capacidade Máxima:** Até 20 produtos simultâneos (`#define TAM_MAX 20`)
- **Campos Armazenados (4 campos):**
  1. `codigo[20]` (`int`): Identificador único do produto.
  2. `nome[20][50]` (`char[50]`): Nome / Descrição do produto (suporta nomes compostos com espaços).
  3. `preco[20]` (`float`): Preço unitário em Reais (R$).
  4. `quantidade[20]` (`int`): Quantidade disponível no estoque.

### Relação entre os Vetores Paralelos
A correspondência entre as informações é preservada através do mesmo índice `i`:
```
Índice:        0                 1                 2
codigo:    [  101  ]         [  102  ]         [  103  ]
nome:      ["Mouse"]         ["Teclado"]       ["Monitor"]
preco:     [ 59.90 ]         [ 120.00]         [ 900.00]
quantidade:[  10   ]         [   5   ]         [   3   ]
Subtotal:  [ 599.00]         [ 600.00]         [2700.00]
```
`codigo[i]`, `nome[i]`, `preco[i]` e `quantidade[i]` pertencem estritamente ao mesmo produto.

---

## 🛠️ Cálculos Financeiros em Tempo Real

1. **Total em Valor por Produto (`preço * quantidade`):**
   - Calculado através de `subtotal = preco[i] * quantidade[i]`.
   - Exibido no Cadastro, Consulta, Listagem e Alteração.

2. **Total em Preço Acumulado (Listagem):**
   - Na opção de Listagem, a variável `totalAcumulado` soma todos os subtotais dos itens cadastrados.
   - Apresenta o valor monetário global de todo o estoque da loja.

---

## 🛡️ Tratamento de Situações Especiais e Validação de Entrada

### Respostas Padrão do Guia Didático (Seção 12)
| Situação | Resposta do Sistema |
|:---|:---|
| **Opção de menu inexistente** | `Opção inválida.` |
| **Consulta sem resultado** | `Registro não encontrado.` |
| **Exclusão sem resultado** | `Não foi possível excluir.` |
| **Listagem vazia** | `Nenhum registro cadastrado.` |
| **Vetor cheio** | `Limite máximo de cadastros atingido.` |

### Proteção de Teclado (Apenas Números)
- Qualquer tentativa de digitar caracteres não numéricos em campos numéricos (como `a2`) é interceptada pelo retorno do `scanf`. O buffer do teclado é limpo com `while ((c = getchar()) != '\n' && c != EOF)` e o programa solicita a digitação correta sem travar ou pular campos.

### Suporte Nativo a Caracteres Especiais (`ç` e Acentos)
- O programa executa `system("chcp 65001 > nul")` no início da execução, ativando a codificação UTF-8 no terminal Windows e garantindo que palavras como `Preço: R$`, `Código:`, `Opção:` e `Exclusão:` apareçam perfeitas.

---

## 🚀 Como Compilar e Executar

### Pré-requisitos
- Compilador GCC instalado.

### Compilação
```bash
gcc -Wall -Wextra -pedantic sistema_cadastro.c -o sistema_cadastro.exe
```

### Execução
```bash
.\sistema_cadastro.exe
```

---

## 📋 Checklist Final (Seção 15 do Guia Didático)

- [x] **Definimos um tema simples para o sistema:** Cadastro de Produtos.
- [x] **Escolhemos de 3 a 5 informações importantes:** Código, Nome, Preço e Quantidade (4 campos).
- [x] **Criamos os vetores e a variável total:** Vetores de tamanho 20 e controle `total = 0`.
- [x] **O menu permanece ativo até a opção Sair:** Implementado com laço `do-while`.
- [x] **O cadastro funciona e respeita o limite do vetor:** Verificação `total >= TAM_MAX`.
- [x] **A listagem mostra somente os registros válidos:** Percorre de `0` a `total - 1`.
- [x] **A consulta localiza registros pelo identificador:** Busca com `codigo[i] == codigoBusca`.
- [x] **A alteração modifica o registro correto:** Sobrescreve dados no índice `posicao`.
- [x] **A exclusão desloca corretamente os elementos:** Deslocamento com laço de cópia e `total--`.
- [x] **Tratamos situações inválidas:** Todas as 5 respostas da Seção 12 + validação numérica.
- [x] **Testamos todas as operações:** 100% dos fluxos e casos de borda validados.
- [x] **O código está organizado e legível:** Código limpo e intuitivo para defesa oral.

---

## 📂 Estrutura de Arquivos da Pasta

```
AT1 - Projeto - Mini Sistema de Cadastro/
├── sistema_cadastro.c          # Código-fonte principal em C (100% documentado e limpo)
├── sistema_cadastro.exe        # Executável compilado
├── README.md                   # Documentação completa do projeto
└── Referencia/
    ├── Guia_Didatico_AT1_Mini_Sistema_C.pdf   # Guia oficial da professora Hially
    └── Instruções.txt                        # Instruções e critérios de avaliação
```
