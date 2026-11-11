# Avaliação N2 — Sistema de Petshop em Linguagem C

**Metodologia:** Aprendizagem Baseada em Projetos (PBL)  
**Conteúdos avaliados:** Repetição, switch, strings, vetores e funções  
**Pontuação:** 0 a 4,5  

---

## 1. Objetivo

Desenvolver, em linguagem C, um sistema completo de atendimento para petshop utilizado pelo funcionário da loja. O sistema realiza autenticação do atendente, gerencia cadastros de clientes e pets, contrata serviços especializados, efetua vendas de produtos por categoria e emite um comprovante final detalhado do atendimento.

---

## 2. Estrutura do Projeto e Atendimento aos Critérios

| Critério | Pontuação | Implementação no Código |
| :--- | :---: | :--- |
| **Login do funcionário com limite de tentativas** | **0,5** | Função `realizarLogin(usuarioLogado)` com até 3 tentativas, verificação via `strcmp` e encerramento em caso de falha. |
| **Cadastro do cliente e do pet** | **0,5** | Funções `cadastrarCliente` e `cadastrarPet`. Validação estrita: o pet só pode ser cadastrado após o cliente. |
| **Menus com repetição e switch** | **0,5** | Menu principal e todos os submenus utilizam laços `do-while` e blocos `switch/case` com tratamento de opção inválida via `default`. |
| **Banho e tosa usando funções** | **0,5** | Funções dedicadas `servicoBanho(porte)` (preço pelo porte do pet) e `servicoTosa(opcaoTosa)`. |
| **Serviços de veterinária** | **0,5** | Função `servicoVeterinaria(opcaoVet)` com consulta, vacina e exames. |
| **Produtos por categoria usando vetores** | **1,0** | Categorias (Alimentos, Acessórios e Higiene) com vetores paralelos de nomes e preços. Seleção de produto e quantidade com cálculo de subtotal. |
| **Comprovante final completo** | **0,5** | Função `exibirComprovante` utilizando vetores de itens (descrição, quantidade, valor unitário) para detalhar atendente, cliente, pet, itens e total geral. |
| **Organização do código** | **0,5** | Funções modulares, nomenclatura clara, indentação consistente, validação de entrada e tratamento de buffer/codificação UTF-8. |
| **TOTAL** | **4,5** | **100% dos requisitos contemplados** |

---

## 3. Credenciais de Login Pré-definidas

- **Usuário:** `admin` | **Senha:** `1234`
- **Tentativas permitidas:** Até 3 tentativas.

---

## 4. Como Compilar e Executar

### Compilação com GCC:
```bash
gcc -Wall -Wextra -std=c99 -o sistema_petshop.exe sistema_petshop.c
```

### Execução no Terminal:
```bash
.\sistema_petshop.exe
```

---

## 5. Arquivos Disponíveis

- [sistema_petshop.c](file:///k:/Arquivos/DEV/Pessoal/Estudos/UCB/Software_Engineer-UCB/2_Semestre/PP2/Atividade-N2/sistema_petshop.c): Código-fonte completo com comentários explicativos didáticos para cada etapa e critério de avaliação.
- [sistema_petshop-Sem-Comentario.c](file:///k:/Arquivos/DEV/Pessoal/Estudos/UCB/Software_Engineer-UCB/2_Semestre/PP2/Atividade-N2/sistema_petshop-Sem-Comentario.c): Versão limpa do código-fonte sem comentários, pronta para entrega direta.
- [referencia.txt](file:///k:/Arquivos/DEV/Pessoal/Estudos/UCB/Software_Engineer-UCB/2_Semestre/PP2/Atividade-N2/referencia.txt): Enunciado e regras originais da Avaliação N2.
