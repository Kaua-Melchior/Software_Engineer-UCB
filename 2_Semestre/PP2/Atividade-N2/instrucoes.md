# Avaliação N2 — Sistema de Petshop em Linguagem C

**Metodologia:** Aprendizagem Baseada em Projetos (PBL)  
**Conteúdos avaliados:** Repetição, switch, strings, vetores e funções  
**Pontuação:** 0 a 4,5  

---

## 1. Atendimento aos Critérios de Avaliação (4,5 pontos)

| Critério | Pontuação | Onde está no código |
| :--- | :---: | :--- |
| **Login do funcionário com limite de tentativas** | **0,5** | Laço `while (tentativas < 3)` usando `strcmp(usuario, "admin") == 0 && strcmp(senha, "1234") == 0`. Se errar 3 vezes (`logado == 0`), encerra com `return 0;`. |
| **Cadastro do cliente e do pet** | **0,5** | `case 1` do menu principal. Variáveis `clienteCadastrado` e `petCadastrado` garantem que o pet só é cadastrado após o cliente. |
| **Menus com repetição e switch** | **0,5** | Menu principal e submenus (`Cadastros`, `Serviços`, `Produtos`) dentro de laços `do-while` com `switch` e tratamento de erro no `default`. |
| **Banho e tosa usando funções** | **0,5** | Funções `servicoBanho(int porte)` e `servicoTosa(int tipo)` no topo do arquivo, recebendo a opção escolhida e retornando o `float` do preço. |
| **Serviços de veterinária** | **0,5** | Função `servicoVeterinaria(int tipo)` no topo do arquivo, retornando o valor de Consulta, Vacina ou Exame. |
| **Produtos por categoria usando vetores** | **1,0** | 3 categorias com vetores paralelos de nomes e preços (`nomesAlimentos`/`precosAlimentos`, `nomesAcessorios`/`precosAcessorios`, `nomesHigiene`/`precosHigiene`). |
| **Comprovante final completo** | **0,5** | Vetores `itemDescricao[50][30]`, `itemQuantidade[50]` e `itemValor[50]` que guardam tudo o que foi comprado e imprimem no `case 4` junto com `valorTotal`. |
| **Organização do código** | **0,5** | Apenas `<stdio.h>`, `<stdlib.h>` e `<string.h>`, funções diretas, variáveis com nomes claros e indentação limpa. |

---

## 2. Guia de Respostas na Ponta da Língua (Para a Apresentação)

### P1: Quais bibliotecas você usou e por quê?
- **`#include <stdio.h>`**: Para entrada e saída de dados (`printf`, `scanf` e `getchar`).
- **`#include <stdlib.h>`**: Para usar a função `system()`, que executa o comando de limpar a tela (`cls` no Windows ou `clear` no Linux/OnlineGDB).
- **`#include <string.h>`**: Para manipular textos (strings), especificamente para usar duas funções:
  - **`strcmp(str1, str2)`**: Compara duas strings (usada no Login). Quando as duas são iguais, ela retorna `0`.
  - **`strcpy(destino, origem)`**: Copia um texto para dentro de uma posição do vetor de descrições do comprovante (`itemDescricao[totalItens]`).
- **`#include <windows.h>`** (só quando estiver no Windows, via `#ifdef _WIN32`): Para usar `SetConsoleOutputCP(65001)` e `SetConsoleCP(65001)`, fazendo o terminal do Windows exibir acentos e `ç` corretamente em UTF-8.

### P1.5: Como funciona o `LIMPAR_TELA` (`cls` / `clear`) e a função `pausar()`?
- Usamos `#ifdef _WIN32`: se o código estiver rodando no Windows, `LIMPAR_TELA` vale `"cls"`; caso contrário (Linux/OnlineGDB), vale `"clear"`. Assim `system(LIMPAR_TELA)` funciona em qualquer computador.
- A função `pausar()` limpa o `\n` (Enter) que sobrou do `scanf` anterior e depois usa `getchar()` para esperar o usuário apertar Enter antes de a tela ser apagada.

### P2: Como funciona o Login com limite de 3 tentativas?
- Usamos `while (tentativas < 3)`.
- A cada tentativa, lemos `usuario` e `senha` com `scanf("%s", ...)`.
- Comparamos com `if (strcmp(usuario, "admin") == 0 && strcmp(senha, "1234") == 0)`.
- Se acertar, `logado = 1` e o `break` sai do `while`.
- Se errar, soma `tentativas++`. Quando `tentativas` chega a 3, o laço termina, o `if (logado == 0)` vê que não logou e dá `return 0`, encerrando o programa.

### P3: Por que no `scanf(" %[^\n]", nomeCliente)` tem um espaço antes do `%` e `[^\n]`?
- O `scanf("%s", ...)` normal para de ler no primeiro espaço (então não leria nomes compostos como `"Maria Silva"`).
- O `[^\n]` faz o `scanf` ler a linha inteira, incluindo espaços, até a pessoa apertar Enter (`\n`).
- O espaço em branco antes do `%` serve para limpar o Enter (`\n`) que sobrou da leitura anterior no buffer do teclado.

### P4: Como você impediu que o pet seja cadastrado antes do cliente, e os serviços antes do pet?
- Criamos duas variáveis de controle (flags) que começam em zero: `clienteCadastrado = 0` e `petCadastrado = 0`.
- Quando cadastra o cliente, mudamos `clienteCadastrado = 1`.
- Ao tentar cadastrar o pet, fazemos `if (clienteCadastrado == 0)` — se for zero, avisa que precisa cadastrar o cliente primeiro.
- Da mesma forma, ao entrar em Serviços (`case 2`), testamos `if (petCadastrado == 0)` — se for zero, bloqueia e pede para cadastrar o pet primeiro.

### P5: Como funcionam as funções de Serviços (`servicoBanho`, `servicoTosa`, `servicoVeterinaria`)?
- Cada função recebe um número `int` (que é o porte do pet ou o tipo de serviço escolhido), usa um `switch` para verificar a opção e retorna um `float` (que é o preço daquele serviço).
- Por exemplo, no banho chamamos `valorServico = servicoBanho(portePet);`. No `switch (porte)`, caso seja `1` retorna `40.0`, caso `2` retorna `55.0`, caso `3` retorna `70.0` (e `default` retorna `0.0`).

### P6: Por que nos produtos você usou `prodEscolhido - 1` nos vetores?
- Porque em C todo vetor começa no **índice 0** (posições `0`, `1` e `2`), mas na tela mostramos para o usuário os números `1`, `2` e `3`.
- Então, quando o usuário digita `1`, acessamos a posição `1 - 1 = 0` do vetor (`precosAlimentos[prodEscolhido - 1]`).

### P7: Como funciona o registro de itens para o Comprovante Final?
- Criamos 3 **vetores paralelos** de tamanho 50 e um contador `totalItens = 0`:
  1. `itemDescricao[50][30]` (guarda o nome do serviço ou produto)
  2. `itemQuantidade[50]` (guarda a quantidade)
  3. `itemValor[50]` (guarda o valor pago no item)
- Sempre que um serviço ou produto é escolhido, salvamos os dados na posição `totalItens`, aumentamos `totalItens++` para apontar para a próxima linha vazia, e somamos o valor em `valorTotal += ...`.
- Na opção 4 (Comprovante), um laço `for (i = 0; i < totalItens; i++)` percorre todas as posições preenchidas e imprime linha por linha.

---

## 3. Como Compilar e Executar

```bash
gcc -Wall -Wextra sistema_petshop.c -o sistema_petshop.exe
.\sistema_petshop.exe
```
