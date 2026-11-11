# Atividade Avaliativa - AT2: Modularização do Sistema de Cadastro em C

**Instituição:** Universidade Católica de Brasília (UCB)  
**Curso:** Engenharia de Software - 2º Semestre  
**Disciplina:** Lógica de Programação e Algoritmos (LPA)  
**Docente:** Profª Hially  

---

## 📌 Visão Geral da Atividade

Esta atividade consiste na **reorganização e modularização** do **Mini-Sistema de Cadastro e Controle de Produtos** desenvolvido na AT1, separando cada operação principal do sistema em uma função específica e mantendo o menu interativo e a declaração dos vetores na função `main()`.

---

## 🧩 Estrutura Modular (Funções Implementadas)

Conforme as instruções da atividade, o sistema foi dividido em **cinco funções**, preservando a lógica, as validações e os cálculos financeiros do projeto original:

| Função | Assinatura | Passagem de `total` | Responsabilidade |
|:---|:---|:---:|:---|
| **1. Cadastrar** | `void cadastrar(int codigo[], char nome[][50], float preco[], int quantidade[], int *total)` | **Por referência (`int *total`)** | Verifica se há espaço (`*total < TAM_MAX`), lê código, nome, preço e quantidade com validação, calcula o subtotal e incrementa `(*total)++`. |
| **2. Consultar** | `void consultar(int codigo[], char nome[][50], float preco[], int quantidade[], int total)` | **Por valor (`int total`)** | Solicita o código de busca, percorre o vetor com `for` e `if`, e exibe os dados e o subtotal do produto encontrado. |
| **3. Listar** | `void listar(int codigo[], char nome[][50], float preco[], int quantidade[], int total)` | **Por valor (`int total`)** | Percorre os registros de `0` até `total - 1`, exibindo cada produto, seu valor em estoque e o **total acumulado**. |
| **4. Alterar** | `void alterar(int codigo[], char nome[][50], float preco[], int quantidade[], int total)` | **Por valor (`int total`)** | Localiza o produto pelo código usando `for` e `if`, exibe os dados atuais e atualiza nome, preço e quantidade na mesma posição. |
| **5. Excluir** | `void excluir(int codigo[], char nome[][50], float preco[], int quantidade[], int *total)` | **Por referência (`int *total`)** | Localiza o registro, desloca os itens seguintes uma posição para a esquerda (usando `strcpy` para o nome) e decrementa `(*total)--`. |

> **Por que `cadastrar()` e `excluir()` recebem `int *total`?**  
> Porque essas duas operações precisam **alterar** a quantidade total de registros armazenados na variável `total` declarada dentro da `main()`. Já `consultar()`, `listar()` e `alterar()` recebem apenas `int total` (por valor), pois apenas consultam esse limite sem modificá-lo.

---

## 🎯 Estrutura de Dados Mantida na `main()`

- **Capacidade Máxima:** Até 20 produtos simultâneos (`#define TAM_MAX 20`)
- **Vetores Paralelos:**
  1. `codigo[TAM_MAX]` (`int`): Identificador único do produto.
  2. `nome[TAM_MAX][50]` (`char[50]`): Nome / Descrição do produto.
  3. `preco[TAM_MAX]` (`float`): Preço unitário em Reais (R$).
  4. `quantidade[TAM_MAX]` (`int`): Quantidade disponível no estoque.

---

## 🚀 Como Compilar e Executar

### Compilação (Windows / Linux)
```bash
gcc -Wall -Wextra -pedantic sistema_cadastro.c -o sistema_cadastro.exe
```
Ou a versão sem comentários:
```bash
gcc -Wall -Wextra -pedantic sistema_cadastro_sem_comentarios.c -o sistema_cadastro_sem_comentarios.exe
```

### Execução no Windows
```bash
.\sistema_cadastro.exe
```

### Execução no Linux / Online GDB
```bash
./sistema_cadastro
```

---

## 📂 Estrutura de Arquivos da Pasta

```
AT2 - Modularização da AT1/
├── sistema_cadastro.c                  # Código-fonte modularizado com comentários explicativos
├── sistema_cadastro_sem_comentarios.c  # Versão sem comentários (pronta para entrega / Online GDB)
├── sistema_cadastro.exe                # Executável compilado
├── README.md                           # Documentação da atividade AT2
└── intruções.txt                       # Instruções originais da atividade
```

