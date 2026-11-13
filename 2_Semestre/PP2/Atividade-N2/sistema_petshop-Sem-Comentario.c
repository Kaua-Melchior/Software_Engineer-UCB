#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#define LIMPAR_TELA "cls"
#else
#define LIMPAR_TELA "clear"
#endif

void pausar() {
  int c;
  printf("\nPressione ENTER para continuar...");
  while ((c = getchar()) != '\n' && c != EOF)
    ;
  getchar();
}

float servicoBanho(int porte) {
  switch (porte) {
  case 1:
    return 40.0;
  case 2:
    return 55.0;
  case 3:
    return 70.0;
  default:
    return 0.0;
  }
}

float servicoTosa(int tipo) {
  switch (tipo) {
  case 1:
    return 35.0;
  case 2:
    return 50.0;
  case 3:
    return 65.0;
  default:
    return 0.0;
  }
}

float servicoVeterinaria(int tipo) {
  switch (tipo) {
  case 1:
    return 120.0;
  case 2:
    return 80.0;
  case 3:
    return 95.0;
  default:
    return 0.0;
  }
}

int main() {
#ifdef _WIN32
  SetConsoleOutputCP(65001);
  SetConsoleCP(65001);
#endif

  char usuario[30];
  char senha[30];
  int tentativas = 0;
  int logado = 0;

  int opcaoPrincipal;
  int opcaoCadastro;
  int opcaoServico;
  int opcaoCategoria;
  int tipoEscolhido;
  int prodEscolhido;
  int qtdEscolhida;
  int i;

  int clienteCadastrado = 0;
  char nomeCliente[50] = "Não cadastrado";
  char telefoneCliente[30] = "Não cadastrado";

  int petCadastrado = 0;
  char nomePet[50] = "Não cadastrado";
  char especiePet[20] = "Não cadastrado";
  char racaPet[30] = "Não cadastrado";
  int portePet = 0;

  char nomesAlimentos[3][30] = {"Ração cão 10kg", "Ração gato 3kg", "Petisco"};
  float precosAlimentos[3] = {120.0, 65.0, 15.0};

  char nomesAcessorios[3][30] = {"Coleira", "Brinquedo", "Caminha"};
  float precosAcessorios[3] = {45.0, 25.0, 110.0};

  char nomesHigiene[3][30] = {"Shampoo", "Escova", "Tapete higiênico"};
  float precosHigiene[3] = {30.0, 20.0, 55.0};

  char itemDescricao[50][30];
  int itemQuantidade[50];
  float itemValor[50];
  int totalItens = 0;
  float valorTotal = 0.0;
  float valorServico = 0.0;
  float valorProduto = 0.0;

  while (tentativas < 3) {
    system(LIMPAR_TELA);
    printf("\n=== LOGIN DO FUNCIONÁRIO (Tentativa %d de 3) ===\n",
           tentativas + 1);
    printf("Usuário: ");
    scanf("%s", usuario);
    printf("Senha: ");
    scanf("%s", senha);

    if (strcmp(usuario, "admin") == 0 && strcmp(senha, "1234") == 0) {
      printf("\nLogin realizado com sucesso!\n");
      logado = 1;
      pausar();
      break;
    } else {
      tentativas++;
      printf("Usuário ou senha incorretos!\n");
      pausar();
    }
  }

  if (logado == 0) {
    printf("\nLimite de 3 tentativas atingido. Encerrando o programa.\n");
    return 0;
  }

  do {
    system(LIMPAR_TELA);
    printf("\n==============================\n");
    printf("      PETSHOP AMIGO FIEL\n");
    printf("==============================\n");
    printf("  1 - Cadastros\n");
    printf("  2 - Serviços\n");
    printf("  3 - Produtos\n");
    printf("  4 - Comprovante final\n");
    printf("  0 - Sair\n");
    printf("==============================\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcaoPrincipal);

    switch (opcaoPrincipal) {

    case 1:
      do {
        system(LIMPAR_TELA);
        printf("\n--------- CADASTROS ----------\n");
        printf("  1 - Cadastrar cliente\n");
        printf("  2 - Cadastrar pet\n");
        printf("  0 - Voltar\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcaoCadastro);

        switch (opcaoCadastro) {
        case 1:
          printf("\nNome do cliente: ");
          scanf(" %[^\n]", nomeCliente);
          printf("Telefone do cliente: ");
          scanf(" %[^\n]", telefoneCliente);
          clienteCadastrado = 1;
          printf("Cliente cadastrado com sucesso!\n");
          pausar();
          break;

        case 2:
          if (clienteCadastrado == 0) {
            printf("\nAtenção: Cadastre o cliente primeiro!\n");
          } else {
            printf("\nNome do pet: ");
            scanf(" %[^\n]", nomePet);
            printf("Espécie (Cão ou Gato): ");
            scanf(" %[^\n]", especiePet);
            printf("Raça do pet: ");
            scanf(" %[^\n]", racaPet);
            printf("Porte do pet (1-Pequeno, 2-Médio, 3-Grande): ");
            scanf("%d", &portePet);

            if (portePet < 1 || portePet > 3) {
              portePet = 1;
            }

            petCadastrado = 1;
            printf("Pet cadastrado com sucesso!\n");
          }
          pausar();
          break;

        case 0:
          printf("Voltando ao menu principal...\n");
          break;

        default:
          printf("Opção inválida!\n");
          pausar();
          break;
        }
      } while (opcaoCadastro != 0);
      break;

    case 2:
      if (petCadastrado == 0) {
        printf("\nAtenção: Cadastre o cliente e o pet antes de escolher "
               "serviços!\n");
        pausar();
      } else {
        do {
          system(LIMPAR_TELA);
          printf("\n---------- SERVIÇOS ----------\n");
          printf("  1 - Banho\n");
          printf("  2 - Tosa\n");
          printf("  3 - Veterinária\n");
          printf("  0 - Voltar\n");
          printf("Escolha uma opção: ");
          scanf("%d", &opcaoServico);

          switch (opcaoServico) {
          case 1:
            valorServico = servicoBanho(portePet);
            strcpy(itemDescricao[totalItens], "Banho");
            itemQuantidade[totalItens] = 1;
            itemValor[totalItens] = valorServico;
            totalItens++;
            valorTotal += valorServico;
            printf("Banho registrado! Valor: R$ %.2f\n", valorServico);
            pausar();
            break;

          case 2:
            printf("\nTipo de Tosa:\n");
            printf("  1 - Higiênica  (R$ 35.00)\n");
            printf("  2 - Completa   (R$ 50.00)\n");
            printf("  3 - Na tesoura (R$ 65.00)\n");
            printf("Escolha o tipo: ");
            scanf("%d", &tipoEscolhido);

            valorServico = servicoTosa(tipoEscolhido);
            if (valorServico > 0) {
              if (tipoEscolhido == 1)
                strcpy(itemDescricao[totalItens], "Tosa Higiênica");
              if (tipoEscolhido == 2)
                strcpy(itemDescricao[totalItens], "Tosa Completa");
              if (tipoEscolhido == 3)
                strcpy(itemDescricao[totalItens], "Tosa na Tesoura");

              itemQuantidade[totalItens] = 1;
              itemValor[totalItens] = valorServico;
              totalItens++;
              valorTotal += valorServico;
              printf("Tosa registrada! Valor: R$ %.2f\n", valorServico);
            } else {
              printf("Opção de tosa inválida!\n");
            }
            pausar();
            break;

          case 3:
            printf("\nServiço de Veterinária:\n");
            printf("  1 - Consulta (R$ 120.00)\n");
            printf("  2 - Vacina   (R$  80.00)\n");
            printf("  3 - Exame    (R$  95.00)\n");
            printf("Escolha o serviço: ");
            scanf("%d", &tipoEscolhido);

            valorServico = servicoVeterinaria(tipoEscolhido);
            if (valorServico > 0) {
              if (tipoEscolhido == 1)
                strcpy(itemDescricao[totalItens], "Consulta Vet.");
              if (tipoEscolhido == 2)
                strcpy(itemDescricao[totalItens], "Vacina Vet.");
              if (tipoEscolhido == 3)
                strcpy(itemDescricao[totalItens], "Exame Vet.");

              itemQuantidade[totalItens] = 1;
              itemValor[totalItens] = valorServico;
              totalItens++;
              valorTotal += valorServico;
              printf("Serviço veterinário registrado! Valor: R$ %.2f\n",
                     valorServico);
            } else {
              printf("Opção de veterinária inválida!\n");
            }
            pausar();
            break;

          case 0:
            printf("Voltando ao menu principal...\n");
            break;

          default:
            printf("Opção inválida!\n");
            pausar();
            break;
          }
        } while (opcaoServico != 0);
      }
      break;

    case 3:
      do {
        system(LIMPAR_TELA);
        printf("\n---------- PRODUTOS ----------\n");
        printf("  1 - Alimentos\n");
        printf("  2 - Acessórios\n");
        printf("  3 - Higiene\n");
        printf("  0 - Voltar\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcaoCategoria);

        switch (opcaoCategoria) {
        case 1:
          system(LIMPAR_TELA);
          printf("\n--------- ALIMENTOS ----------\n");
          for (i = 0; i < 3; i++) {
            printf("  %d - %-18s R$ %.2f\n", i + 1, nomesAlimentos[i],
                   precosAlimentos[i]);
          }
          printf("  0 - Voltar\n");
          printf("Produto: ");
          scanf("%d", &prodEscolhido);

          if (prodEscolhido >= 1 && prodEscolhido <= 3) {
            printf("Quantidade: ");
            scanf("%d", &qtdEscolhida);
            valorProduto = precosAlimentos[prodEscolhido - 1] * qtdEscolhida;
            printf("Valor: R$ %.2f\n", valorProduto);

            strcpy(itemDescricao[totalItens],
                   nomesAlimentos[prodEscolhido - 1]);
            itemQuantidade[totalItens] = qtdEscolhida;
            itemValor[totalItens] = valorProduto;
            totalItens++;
            valorTotal += valorProduto;
            pausar();
          } else if (prodEscolhido != 0) {
            printf("Produto inválido!\n");
            pausar();
          }
          break;

        case 2:
          system(LIMPAR_TELA);
          printf("\n--------- ACESSÓRIOS ---------\n");
          for (i = 0; i < 3; i++) {
            printf("  %d - %-18s R$ %.2f\n", i + 1, nomesAcessorios[i],
                   precosAcessorios[i]);
          }
          printf("  0 - Voltar\n");
          printf("Produto: ");
          scanf("%d", &prodEscolhido);

          if (prodEscolhido >= 1 && prodEscolhido <= 3) {
            printf("Quantidade: ");
            scanf("%d", &qtdEscolhida);
            valorProduto = precosAcessorios[prodEscolhido - 1] * qtdEscolhida;
            printf("Valor: R$ %.2f\n", valorProduto);

            strcpy(itemDescricao[totalItens],
                   nomesAcessorios[prodEscolhido - 1]);
            itemQuantidade[totalItens] = qtdEscolhida;
            itemValor[totalItens] = valorProduto;
            totalItens++;
            valorTotal += valorProduto;
            pausar();
          } else if (prodEscolhido != 0) {
            printf("Produto inválido!\n");
            pausar();
          }
          break;

        case 3:
          system(LIMPAR_TELA);
          printf("\n---------- HIGIENE -----------\n");
          for (i = 0; i < 3; i++) {
            printf("  %d - %-18s R$ %.2f\n", i + 1, nomesHigiene[i],
                   precosHigiene[i]);
          }
          printf("  0 - Voltar\n");
          printf("Produto: ");
          scanf("%d", &prodEscolhido);

          if (prodEscolhido >= 1 && prodEscolhido <= 3) {
            printf("Quantidade: ");
            scanf("%d", &qtdEscolhida);
            valorProduto = precosHigiene[prodEscolhido - 1] * qtdEscolhida;
            printf("Valor: R$ %.2f\n", valorProduto);

            strcpy(itemDescricao[totalItens], nomesHigiene[prodEscolhido - 1]);
            itemQuantidade[totalItens] = qtdEscolhida;
            itemValor[totalItens] = valorProduto;
            totalItens++;
            valorTotal += valorProduto;
            pausar();
          } else if (prodEscolhido != 0) {
            printf("Produto inválido!\n");
            pausar();
          }
          break;

        case 0:
          printf("Voltando ao menu principal...\n");
          break;

        default:
          printf("Opção inválida!\n");
          pausar();
          break;
        }
      } while (opcaoCategoria != 0);
      break;

    case 4:
      system(LIMPAR_TELA);
      printf("\n========================================\n");
      printf("      COMPROVANTE DE ATENDIMENTO\n");
      printf("========================================\n");
      printf("Funcionário: %s\n", usuario);
      printf("Cliente: %s | Tel: %s\n", nomeCliente, telefoneCliente);
      printf("Pet: %s | Espécie: %s | Raça: %s | Porte: %d\n", nomePet,
             especiePet, racaPet, portePet);
      printf("----------------------------------------\n");
      printf("ITENS ESCOLHIDOS:\n");

      if (totalItens == 0) {
        printf("Nenhum item registrado.\n");
      } else {
        for (i = 0; i < totalItens; i++) {
          printf("%d. %-18s | Qtd: %d | R$ %.2f\n", i + 1, itemDescricao[i],
                 itemQuantidade[i], itemValor[i]);
        }
      }

      printf("----------------------------------------\n");
      printf("VALOR TOTAL DO ATENDIMENTO: R$ %.2f\n", valorTotal);
      printf("========================================\n");
      pausar();
      break;

    case 0:
      printf("\nEncerrando o sistema...\n");
      break;

    default:
      printf("\nOpção inválida!\n");
      pausar();
      break;
    }

  } while (opcaoPrincipal != 0);

  return 0;
}
