#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX 20

#ifdef _WIN32
#define LIMPAR_TELA "cls"
#else
#define LIMPAR_TELA "clear"
#endif

void cadastrar(int codigo[], char nome[][50], float preco[], int quantidade[], int *total) {
  int c;
  float subtotal;

  system(LIMPAR_TELA);
  printf("=========================================\n");
  printf("          CADASTRAR PRODUTO              \n");
  printf("=========================================\n");

  if (*total >= TAM_MAX) {
    printf("Limite máximo de cadastros atingido.\n");
  } else {
    printf("Digite o código: ");
    while (1) {
      if (scanf("%d", &codigo[*total]) == 1) {
        c = getchar();
        while (c == ' ' || c == '\t')
          c = getchar();
        if (c == '\n' && codigo[*total] > 0)
          break;
        while (c != '\n' && c != EOF)
          c = getchar();
      } else {
        while ((c = getchar()) != '\n' && c != EOF)
          ;
      }
      printf("Código inválido! Digite apenas números: ");
    }

    printf("Digite o nome: ");
    scanf(" %49[^\n]", nome[*total]);
    while ((c = getchar()) != '\n' && c != EOF)
      ;

    printf("Digite o preço: R$ ");
    while (1) {
      if (scanf("%f", &preco[*total]) == 1) {
        c = getchar();
        while (c == ' ' || c == '\t')
          c = getchar();
        if (c == '\n' && preco[*total] >= 0)
          break;
        while (c != '\n' && c != EOF)
          c = getchar();
      } else {
        while ((c = getchar()) != '\n' && c != EOF)
          ;
      }
      printf("Preço inválido! Digite apenas números: R$ ");
    }

    printf("Digite a quantidade: ");
    while (1) {
      if (scanf("%d", &quantidade[*total]) == 1) {
        c = getchar();
        while (c == ' ' || c == '\t')
          c = getchar();
        if (c == '\n' && quantidade[*total] >= 0)
          break;
        while (c != '\n' && c != EOF)
          c = getchar();
      } else {
        while ((c = getchar()) != '\n' && c != EOF)
          ;
      }
      printf("Quantidade inválida! Digite apenas números: ");
    }

    (*total)++;
    subtotal = preco[*total - 1] * quantidade[*total - 1];
    printf("\nProduto cadastrado com sucesso! Total em valor: R$ %.2f\n",
           subtotal);
  }

  printf("\nPressione ENTER para continuar...");
  getchar();
}

void consultar(int codigo[], char nome[][50], float preco[], int quantidade[], int total) {
  int busca;
  int i;
  int encontrado;
  int c;
  float subtotal;

  system(LIMPAR_TELA);
  printf("=========================================\n");
  printf("          CONSULTAR PRODUTO              \n");
  printf("=========================================\n");

  if (total == 0) {
    printf("Registro não encontrado.\n");
  } else {
    printf("Digite o código para consulta: ");
    while (1) {
      if (scanf("%d", &busca) == 1) {
        c = getchar();
        while (c == ' ' || c == '\t')
          c = getchar();
        if (c == '\n' && busca > 0)
          break;
        while (c != '\n' && c != EOF)
          c = getchar();
      } else {
        while ((c = getchar()) != '\n' && c != EOF)
          ;
      }
      printf("Código inválido! Digite apenas números: ");
    }

    encontrado = 0;
    for (i = 0; i < total; i++) {
      if (codigo[i] == busca) {
        subtotal = preco[i] * quantidade[i];
        printf("\nCódigo: %d\n", codigo[i]);
        printf("Nome: %s\n", nome[i]);
        printf("Preço: R$ %.2f\n", preco[i]);
        printf("Quantidade: %d\n", quantidade[i]);
        printf("Total em valor: R$ %.2f\n", subtotal);
        encontrado = 1;
        break;
      }
    }

    if (!encontrado) {
      printf("\nRegistro não encontrado.\n");
    }
  }

  printf("\nPressione ENTER para continuar...");
  getchar();
}

void listar(int codigo[], char nome[][50], float preco[], int quantidade[], int total) {
  int i;
  float subtotal;
  float totalAcumulado;

  system(LIMPAR_TELA);
  printf("=========================================\n");
  printf("          LISTA DE PRODUTOS              \n");
  printf("=========================================\n");

  if (total == 0) {
    printf("Nenhum registro cadastrado.\n");
  } else {
    totalAcumulado = 0.0f;

    for (i = 0; i < total; i++) {
      subtotal = preco[i] * quantidade[i];
      totalAcumulado += subtotal;

      printf("\nCódigo: %d\n", codigo[i]);
      printf("Nome: %s\n", nome[i]);
      printf("Preço: R$ %.2f\n", preco[i]);
      printf("Quantidade: %d\n", quantidade[i]);
      printf("Total em valor: R$ %.2f\n", subtotal);
      printf("-----------------------------------------\n");
    }
    printf("Total de registros cadastrados: %d\n", total);
    printf("Total em preço acumulado: R$ %.2f\n", totalAcumulado);
  }

  printf("\nPressione ENTER para continuar...");
  getchar();
}

void alterar(int codigo[], char nome[][50], float preco[], int quantidade[], int total) {
  int busca;
  int i;
  int posicao;
  int c;
  float subtotal;

  system(LIMPAR_TELA);
  printf("=========================================\n");
  printf("          ALTERAR PRODUTO                \n");
  printf("=========================================\n");

  if (total == 0) {
    printf("Registro não encontrado.\n");
  } else {
    printf("Digite o código do produto a alterar: ");
    while (1) {
      if (scanf("%d", &busca) == 1) {
        c = getchar();
        while (c == ' ' || c == '\t')
          c = getchar();
        if (c == '\n' && busca > 0)
          break;
        while (c != '\n' && c != EOF)
          c = getchar();
      } else {
        while ((c = getchar()) != '\n' && c != EOF)
          ;
      }
      printf("Código inválido! Digite apenas números: ");
    }

    posicao = -1;
    for (i = 0; i < total; i++) {
      if (codigo[i] == busca) {
        posicao = i;
        break;
      }
    }

    if (posicao == -1) {
      printf("\nRegistro não encontrado.\n");
    } else {
      subtotal = preco[posicao] * quantidade[posicao];
      printf("\nDados atuais do produto:\n");
      printf("Código: %d\n", codigo[posicao]);
      printf("Nome: %s\n", nome[posicao]);
      printf("Preço: R$ %.2f\n", preco[posicao]);
      printf("Quantidade: %d\n", quantidade[posicao]);
      printf("Total em valor: R$ %.2f\n", subtotal);

      printf("\nDigite os novos dados:\n");
      printf("Novo nome: ");
      scanf(" %49[^\n]", nome[posicao]);
      while ((c = getchar()) != '\n' && c != EOF)
        ;

      printf("Novo preço: R$ ");
      while (1) {
        if (scanf("%f", &preco[posicao]) == 1) {
          c = getchar();
          while (c == ' ' || c == '\t')
            c = getchar();
          if (c == '\n' && preco[posicao] >= 0)
            break;
          while (c != '\n' && c != EOF)
            c = getchar();
        } else {
          while ((c = getchar()) != '\n' && c != EOF)
            ;
        }
        printf("Preço inválido! Digite apenas números: R$ ");
      }

      printf("Nova quantidade: ");
      while (1) {
        if (scanf("%d", &quantidade[posicao]) == 1) {
          c = getchar();
          while (c == ' ' || c == '\t')
            c = getchar();
          if (c == '\n' && quantidade[posicao] >= 0)
            break;
          while (c != '\n' && c != EOF)
            c = getchar();
        } else {
          while ((c = getchar()) != '\n' && c != EOF)
            ;
        }
        printf("Quantidade inválida! Digite apenas números: ");
      }

      subtotal = preco[posicao] * quantidade[posicao];
      printf("\nCadastro alterado com sucesso! Novo total em valor: R$ %.2f\n",
             subtotal);
    }
  }

  printf("\nPressione ENTER para continuar...");
  getchar();
}

void excluir(int codigo[], char nome[][50], float preco[], int quantidade[], int *total) {
  int busca;
  int i, j;
  int posicao;
  int c;

  system(LIMPAR_TELA);
  printf("=========================================\n");
  printf("          EXCLUIR PRODUTO                \n");
  printf("=========================================\n");

  if (*total == 0) {
    printf("Não foi possível excluir.\n");
  } else {
    printf("Digite o código do produto a excluir: ");
    while (1) {
      if (scanf("%d", &busca) == 1) {
        c = getchar();
        while (c == ' ' || c == '\t')
          c = getchar();
        if (c == '\n' && busca > 0)
          break;
        while (c != '\n' && c != EOF)
          c = getchar();
      } else {
        while ((c = getchar()) != '\n' && c != EOF)
          ;
      }
      printf("Código inválido! Digite apenas números: ");
    }

    posicao = -1;
    for (i = 0; i < *total; i++) {
      if (codigo[i] == busca) {
        posicao = i;
        break;
      }
    }

    if (posicao == -1) {
      printf("\nNão foi possível excluir.\n");
    } else {
      for (j = posicao; j < *total - 1; j++) {
        codigo[j] = codigo[j + 1];
        preco[j] = preco[j + 1];
        quantidade[j] = quantidade[j + 1];
        strcpy(nome[j], nome[j + 1]);
      }

      (*total)--;
      printf("\nRegistro excluído com sucesso!\n");
    }
  }

  printf("\nPressione ENTER para continuar...");
  getchar();
}

int main(void) {
#ifdef _WIN32
  system("chcp 65001 > nul");
#endif

  int codigo[TAM_MAX];
  char nome[TAM_MAX][50];
  float preco[TAM_MAX];
  int quantidade[TAM_MAX];

  int total = 0;
  int opcao;
  int c;

  do {
    system(LIMPAR_TELA);

    printf("=========================================\n");
    printf("     SISTEMA DE CADASTRO DE PRODUTOS     \n");
    printf("=========================================\n");
    printf("1 - Cadastrar\n");
    printf("2 - Consultar\n");
    printf("3 - Listar\n");
    printf("4 - Alterar\n");
    printf("5 - Excluir\n");
    printf("0 - Sair\n");
    printf("=========================================\n");
    printf("Escolha uma opção: ");

    while (1) {
      if (scanf("%d", &opcao) == 1) {
        c = getchar();
        while (c == ' ' || c == '\t')
          c = getchar();
        if (c == '\n')
          break;
        while (c != '\n' && c != EOF)
          c = getchar();
      } else {
        while ((c = getchar()) != '\n' && c != EOF)
          ;
      }
      printf("Opção inválida! Digite apenas números: ");
    }

    switch (opcao) {
    case 1:
      cadastrar(codigo, nome, preco, quantidade, &total);
      break;

    case 2:
      consultar(codigo, nome, preco, quantidade, total);
      break;

    case 3:
      listar(codigo, nome, preco, quantidade, total);
      break;

    case 4:
      alterar(codigo, nome, preco, quantidade, total);
      break;

    case 5:
      excluir(codigo, nome, preco, quantidade, &total);
      break;

    case 0:
      printf("\nEncerrando o programa... Até logo!\n");
      break;

    default:
      printf("\nOpção inválida.\n");
      printf("\nPressione ENTER para continuar...");
      getchar();
      break;
    }

  } while (opcao != 0);

  return 0;
}

