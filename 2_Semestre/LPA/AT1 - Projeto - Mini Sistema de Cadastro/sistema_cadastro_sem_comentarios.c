#include <stdio.h>
#include <stdlib.h>

#define TAM_MAX 20

#ifdef _WIN32
#define LIMPAR_TELA "cls"
#else
#define LIMPAR_TELA "clear"
#endif

int main() {
#ifdef _WIN32
  system("chcp 65001 > nul");
#endif

  int codigo[TAM_MAX];
  char nome[TAM_MAX][50];
  float preco[TAM_MAX];
  int quantidade[TAM_MAX];

  int total = 0;
  int opcao;
  int i, j;
  int codigoBusca;
  int posicao;
  int encontrado;
  int c;
  float subtotal;
  float totalAcumulado;

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
      system(LIMPAR_TELA);
      printf("=========================================\n");
      printf("          CADASTRAR PRODUTO              \n");
      printf("=========================================\n");

      if (total >= TAM_MAX) {
        printf("Limite máximo de cadastros atingido.\n");
      } else {
        printf("Digite o código: ");
        while (1) {
          if (scanf("%d", &codigo[total]) == 1) {
            c = getchar();
            while (c == ' ' || c == '\t')
              c = getchar();
            if (c == '\n' && codigo[total] > 0)
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
        scanf(" %49[^\n]", nome[total]);
        while ((c = getchar()) != '\n' && c != EOF)
          ;

        printf("Digite o preço: R$ ");
        while (1) {
          if (scanf("%f", &preco[total]) == 1) {
            c = getchar();
            while (c == ' ' || c == '\t')
              c = getchar();
            if (c == '\n' && preco[total] >= 0)
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
          if (scanf("%d", &quantidade[total]) == 1) {
            c = getchar();
            while (c == ' ' || c == '\t')
              c = getchar();
            if (c == '\n' && quantidade[total] >= 0)
              break;
            while (c != '\n' && c != EOF)
              c = getchar();
          } else {
            while ((c = getchar()) != '\n' && c != EOF)
              ;
          }
          printf("Quantidade inválida! Digite apenas números: ");
        }

        total++;
        subtotal = preco[total - 1] * quantidade[total - 1];
        printf("\nProduto cadastrado com sucesso! Total em valor: R$ %.2f\n",
               subtotal);
      }

      printf("\nPressione ENTER para continuar...");
      getchar();
      break;

    case 2:
      system(LIMPAR_TELA);
      printf("=========================================\n");
      printf("          CONSULTAR PRODUTO              \n");
      printf("=========================================\n");

      if (total == 0) {
        printf("Registro não encontrado.\n");
      } else {
        printf("Digite o código para consulta: ");
        while (1) {
          if (scanf("%d", &codigoBusca) == 1) {
            c = getchar();
            while (c == ' ' || c == '\t')
              c = getchar();
            if (c == '\n' && codigoBusca > 0)
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
          if (codigo[i] == codigoBusca) {
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
      break;

    case 3:
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
      break;

    case 4:
      system(LIMPAR_TELA);
      printf("=========================================\n");
      printf("          ALTERAR PRODUTO                \n");
      printf("=========================================\n");

      if (total == 0) {
        printf("Registro não encontrado.\n");
      } else {
        printf("Digite o código do produto a alterar: ");
        while (1) {
          if (scanf("%d", &codigoBusca) == 1) {
            c = getchar();
            while (c == ' ' || c == '\t')
              c = getchar();
            if (c == '\n' && codigoBusca > 0)
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
          if (codigo[i] == codigoBusca) {
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
          printf(
              "\nCadastro alterado com sucesso! Novo total em valor: R$ %.2f\n",
              subtotal);
        }
      }

      printf("\nPressione ENTER para continuar...");
      getchar();
      break;

    case 5:
      system(LIMPAR_TELA);
      printf("=========================================\n");
      printf("          EXCLUIR PRODUTO                \n");
      printf("=========================================\n");

      if (total == 0) {
        printf("Não foi possível excluir.\n");
      } else {
        printf("Digite o código do produto a excluir: ");
        while (1) {
          if (scanf("%d", &codigoBusca) == 1) {
            c = getchar();
            while (c == ' ' || c == '\t')
              c = getchar();
            if (c == '\n' && codigoBusca > 0)
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
          if (codigo[i] == codigoBusca) {
            posicao = i;
            break;
          }
        }

        if (posicao == -1) {
          printf("\nNão foi possível excluir.\n");
        } else {
          for (i = posicao; i < total - 1; i++) {
            codigo[i] = codigo[i + 1];
            preco[i] = preco[i + 1];
            quantidade[i] = quantidade[i + 1];
            for (j = 0; j < 50; j++) {
              nome[i][j] = nome[i + 1][j];
            }
          }
          total--;
          printf("\nRegistro excluído com sucesso!\n");
        }
      }

      printf("\nPressione ENTER para continuar...");
      getchar();
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
