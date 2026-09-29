/*
# Desafio 36: Desafio Final - Controle de Pedidos de Lanchonete
Escolha um problema do cotidiano que possa ser solucionado computacionalmente.
• Descrição do problema: Sistema interativo para registrar pedidos de uma lanchonete,
  acumular o total da compra e aplicar desconto dependendo da forma de pagamento.
• Entradas: Código do item do cardápio, quantidade desejada, forma de pagamento.
• Processamento: Cálculo de subtotal por item, soma total do pedido, aplicação de
  desconto de 10% para pagamento em dinheiro ou PIX.
• Saídas: Discriminação do pedido, subtotal, valor do desconto e total final a pagar.
*/
#include <stdio.h>

int main() {
  int opcao, qtd, forma_pagamento;
  float preco = 0.0f, subtotal = 0.0f, total_pedido = 0.0f, desconto = 0.0f, total_final;
  char continuar;

  printf("=========================================\n");
  printf("          LANCHONETE SABOR & CIA         \n");
  printf("=========================================\n");

  do {
    printf("\n--- CARDAPIO ---\n");
    printf("1. X-Burguer               - R$ 15.00\n");
    printf("2. X-Salada                - R$ 18.00\n");
    printf("3. X-Tudo                  - R$ 24.00\n");
    printf("4. Porcao de Batata Frita  - R$ 12.00\n");
    printf("5. Refrigerante Lata       - R$  6.00\n");
    printf("Escolha o codigo do item desejado: ");
    scanf("%d", &opcao);

    switch (opcao) {
      case 1:
        preco = 15.0f;
        break;
      case 2:
        preco = 18.0f;
        break;
      case 3:
        preco = 24.0f;
        break;
      case 4:
        preco = 12.0f;
        break;
      case 5:
        preco = 6.0f;
        break;
      default:
        printf("Opcao invalida!\n");
        preco = 0.0f;
        break;
    }

    if (preco > 0) {
      printf("Quantidade: ");
      scanf("%d", &qtd);
      if (qtd > 0) {
        subtotal = preco * qtd;
        total_pedido += subtotal;
        printf("Item adicionado! Subtotal: R$ %.2f\n", subtotal);
      } else {
        printf("Quantidade invalida!\n");
      }
    }

    printf("Deseja adicionar outro item? (S/N): ");
    scanf(" %c", &continuar);
  } while (continuar == 'S' || continuar == 's');

  if (total_pedido > 0) {
    printf("\nFormas de pagamento:\n");
    printf("1 - Dinheiro / PIX (10%% de desconto)\n");
    printf("2 - Cartao de Debito\n");
    printf("3 - Cartao de Credito\n");
    printf("Selecione a forma de pagamento: ");
    scanf("%d", &forma_pagamento);

    if (forma_pagamento == 1) {
      desconto = total_pedido * 0.10f;
    }

    total_final = total_pedido - desconto;

    printf("\n============= RESUMO DO PEDIDO =============\n");
    printf("Subtotal:            R$ %8.2f\n", total_pedido);
    printf("Desconto:            R$ %8.2f\n", desconto);
    printf("Total a pagar:       R$ %8.2f\n", total_final);
    printf("============================================\n");
    printf("Obrigado pela preferencia! Volte sempre!\n");
  } else {
    printf("\nNenhum item foi adicionado ao pedido.\n");
  }

  return 0;
}
