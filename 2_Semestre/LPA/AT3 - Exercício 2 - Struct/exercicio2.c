#include <stdio.h>

#define MAX_PRODUTOS 15

struct Produto {
  int codigo;
  char nome[50];
  float preco;
  int quantidade;
};

int buscarPorCodigo(struct Produto produtos[], int total, int codigo) {
  int i;
  for (i = 0; i < total; i++) {
    if (produtos[i].codigo == codigo) {
      return i;
    }
  }
  return -1;
}

void reporEstoque(struct Produto produtos[], int total) {
  int codigo, qtd, pos;

  printf("\nDigite o codigo do produto para repor: ");
  scanf("%d", &codigo);

  pos = buscarPorCodigo(produtos, total, codigo);
  if (pos == -1) {
    printf("Produto nao encontrado.\n");
    return;
  }

  printf("Quantidade a adicionar ao estoque: ");
  scanf("%d", &qtd);

  if (qtd <= 0) {
    printf("Quantidade invalida.\n");
    return;
  }

  produtos[pos].quantidade += qtd;
  printf("Estoque atualizado! Nova quantidade de %s: %d\n",
         produtos[pos].nome, produtos[pos].quantidade);
}

void registrarVenda(struct Produto produtos[], int total) {
  int codigo, qtd, pos;

  printf("\nDigite o codigo do produto vendido: ");
  scanf("%d", &codigo);

  pos = buscarPorCodigo(produtos, total, codigo);
  if (pos == -1) {
    printf("Produto nao encontrado.\n");
    return;
  }

  printf("Quantidade vendida (disponivel: %d): ", produtos[pos].quantidade);
  scanf("%d", &qtd);

  if (qtd <= 0) {
    printf("Quantidade invalida.\n");
    return;
  }

  if (qtd > produtos[pos].quantidade) {
    printf("Erro: estoque insuficiente! Disponivel apenas %d unidades.\n",
           produtos[pos].quantidade);
    return;
  }

  produtos[pos].quantidade -= qtd;
  printf("Venda registrada! Valor: R$ %.2f | Estoque restante: %d\n",
         produtos[pos].preco * qtd, produtos[pos].quantidade);
}

int main() {
  struct Produto produtos[MAX_PRODUTOS];
  int total = 0;
  int opcao;
  int i, codigoBusca, pos, idxMaior;
  float valorItem, valorTotalEstoque, maiorValorItem;

  do {
    printf("\n=== PAPELARIA - CONTROLE DE ESTOQUE ===\n");
    printf("1 - Cadastrar produto\n");
    printf("2 - Listar produtos e resumo do estoque\n");
    printf("3 - Repor estoque\n");
    printf("4 - Registrar venda\n");
    printf("5 - Consultar produto pelo codigo\n");
    printf("0 - Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1:
      if (total >= MAX_PRODUTOS) {
        printf("\nLimite maximo de %d produtos atingido!\n", MAX_PRODUTOS);
      } else {
        printf("\nCodigo do produto: ");
        scanf("%d", &codigoBusca);

        if (buscarPorCodigo(produtos, total, codigoBusca) != -1) {
          printf("Erro: ja existe um produto com esse codigo!\n");
        } else {
          produtos[total].codigo = codigoBusca;
          printf("Nome do produto: ");
          scanf(" %[^\n]", produtos[total].nome);
          printf("Preco: R$ ");
          scanf("%f", &produtos[total].preco);
          printf("Quantidade em estoque: ");
          scanf("%d", &produtos[total].quantidade);
          total++;
          printf("Produto cadastrado com sucesso!\n");
        }
      }
      break;

    case 2:
      if (total == 0) {
        printf("\nNenhum produto cadastrado.\n");
      } else {
        valorTotalEstoque = 0.0;
        idxMaior = 0;
        maiorValorItem = produtos[0].preco * produtos[0].quantidade;

        printf("\n=== LISTA DE PRODUTOS ===\n");
        for (i = 0; i < total; i++) {
          valorItem = produtos[i].preco * produtos[i].quantidade;
          valorTotalEstoque += valorItem;

          if (valorItem > maiorValorItem) {
            maiorValorItem = valorItem;
            idxMaior = i;
          }

          printf("Cod: %d | %s | Preco: R$ %.2f | Qtd: %d | Total: R$ %.2f\n",
                 produtos[i].codigo, produtos[i].nome, produtos[i].preco,
                 produtos[i].quantidade, valorItem);
        }

        printf("\nValor total de todos os produtos em estoque: R$ %.2f\n",
               valorTotalEstoque);
        printf("Produto com maior valor total em estoque: %s (R$ %.2f)\n",
               produtos[idxMaior].nome, maiorValorItem);
      }
      break;

    case 3:
      if (total == 0) {
        printf("\nNenhum produto cadastrado.\n");
      } else {
        reporEstoque(produtos, total);
      }
      break;

    case 4:
      if (total == 0) {
        printf("\nNenhum produto cadastrado.\n");
      } else {
        registrarVenda(produtos, total);
      }
      break;

    case 5:
      printf("\nDigite o codigo para consultar: ");
      scanf("%d", &codigoBusca);
      pos = buscarPorCodigo(produtos, total, codigoBusca);

      if (pos == -1) {
        printf("Produto nao encontrado.\n");
      } else {
        printf("\nCodigo: %d\n", produtos[pos].codigo);
        printf("Nome: %s\n", produtos[pos].nome);
        printf("Preco: R$ %.2f\n", produtos[pos].preco);
        printf("Quantidade: %d\n", produtos[pos].quantidade);
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
