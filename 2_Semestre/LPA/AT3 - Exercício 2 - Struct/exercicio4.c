#include <stdio.h>

#define MAX_PRODUTOS 10
#define MAX_VENDAS 20

struct Produto {
  int codigo;
  char nome[50];
  float preco;
  int estoque;
};

struct Venda {
  struct Produto produto;
  int quantidadeVendida;
  float valorTotal;
};

int main() {
  struct Produto produtos[MAX_PRODUTOS];
  struct Venda vendas[MAX_VENDAS];
  int totalProdutos = 0;
  int totalVendas = 0;
  int opcao, i, j, codBusca, pos, qtd;
  float faturamentoTotal = 0.0;
  float faturamentoProduto, maiorFaturamento = -1.0;
  int idxMaiorProduto = -1;

  do {
    printf("\n=== CONTROLE DE VENDAS DA LOJA ===\n");
    printf("1 - Cadastrar produto\n");
    printf("2 - Registrar venda\n");
    printf("3 - Listar produtos\n");
    printf("4 - Relatorio de vendas e faturamento\n");
    printf("0 - Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1:
      if (totalProdutos >= MAX_PRODUTOS) {
        printf("\nLimite de %d produtos atingido!\n", MAX_PRODUTOS);
      } else {
        printf("\nCodigo do produto: ");
        scanf("%d", &produtos[totalProdutos].codigo);
        printf("Nome do produto: ");
        scanf(" %[^\n]", produtos[totalProdutos].nome);
        printf("Preco: R$ ");
        scanf("%f", &produtos[totalProdutos].preco);
        printf("Quantidade em estoque: ");
        scanf("%d", &produtos[totalProdutos].estoque);
        totalProdutos++;
        printf("Produto cadastrado!\n");
      }
      break;

    case 2:
      if (totalProdutos == 0) {
        printf("\nCadastre um produto primeiro!\n");
      } else if (totalVendas >= MAX_VENDAS) {
        printf("\nLimite de %d vendas atingido!\n", MAX_VENDAS);
      } else {
        printf("\nCodigo do produto para vender: ");
        scanf("%d", &codBusca);

        pos = -1;
        for (i = 0; i < totalProdutos; i++) {
          if (produtos[i].codigo == codBusca) {
            pos = i;
            break;
          }
        }

        if (pos == -1) {
          printf("Produto nao encontrado!\n");
        } else {
          printf("Produto: %s (Disponivel: %d)\n", produtos[pos].nome,
                 produtos[pos].estoque);
          printf("Quantidade vendida: ");
          scanf("%d", &qtd);

          if (qtd <= 0 || qtd > produtos[pos].estoque) {
            printf("Quantidade invalida ou estoque insuficiente!\n");
          } else {
            produtos[pos].estoque -= qtd;
            vendas[totalVendas].produto = produtos[pos];
            vendas[totalVendas].quantidadeVendida = qtd;
            vendas[totalVendas].valorTotal = produtos[pos].preco * qtd;
            faturamentoTotal += vendas[totalVendas].valorTotal;
            totalVendas++;
            printf("Venda registrada! Valor: R$ %.2f\n",
                   vendas[totalVendas - 1].valorTotal);
          }
        }
      }
      break;

    case 3:
      if (totalProdutos == 0) {
        printf("\nNenhum produto cadastrado.\n");
      } else {
        printf("\n=== PRODUTOS CADASTRADOS ===\n");
        for (i = 0; i < totalProdutos; i++) {
          printf("Cod: %d | %s | R$ %.2f | Estoque: %d\n",
                 produtos[i].codigo, produtos[i].nome, produtos[i].preco,
                 produtos[i].estoque);
        }
      }
      break;

    case 4:
      if (totalVendas == 0) {
        printf("\nNenhuma venda registrada.\n");
      } else {
        printf("\n=== RELATORIO DE VENDAS ===\n");
        for (i = 0; i < totalVendas; i++) {
          printf("Venda %d | Produto: %s | Qtd: %d | Total: R$ %.2f\n",
                 i + 1, vendas[i].produto.nome, vendas[i].quantidadeVendida,
                 vendas[i].valorTotal);
        }

        maiorFaturamento = -1.0;
        idxMaiorProduto = 0;
        for (i = 0; i < totalProdutos; i++) {
          faturamentoProduto = 0.0;
          for (j = 0; j < totalVendas; j++) {
            if (vendas[j].produto.codigo == produtos[i].codigo) {
              faturamentoProduto += vendas[j].valorTotal;
            }
          }
          if (faturamentoProduto > maiorFaturamento) {
            maiorFaturamento = faturamentoProduto;
            idxMaiorProduto = i;
          }
        }

        printf("\nFaturamento total: R$ %.2f\n", faturamentoTotal);
        printf("Produto com maior faturamento: %s (R$ %.2f)\n",
               produtos[idxMaiorProduto].nome, maiorFaturamento);
      }
      break;

    case 0:
      printf("\nEncerrando o programa...\n");
      break;

    default:
      printf("\nOpcao invalida!\n");
      break;
    }
  } while (opcao != 0);

  return 0;
}
