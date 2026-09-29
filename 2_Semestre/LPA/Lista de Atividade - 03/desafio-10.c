/*
# Desafio 10: Valor da Compra
Leia:
• nome de um produto;
• quantidade comprada;
• preço unitário.
Calcule e apresente o valor total da compra.
*/
#include <stdio.h>

int main() {
  char produto[100];
  int quantidade;
  float preco_unitario, total;

  printf("Digite o nome do produto: ");
  scanf(" %99[^\n]", produto);
  printf("Digite a quantidade comprada: ");
  scanf("%d", &quantidade);
  printf("Digite o preco unitario: R$ ");
  scanf("%f", &preco_unitario);

  total = quantidade * preco_unitario;

  printf("\nProduto: %s\n", produto);
  printf("Quantidade: %d\n", quantidade);
  printf("Preco unitario: R$ %.2f\n", preco_unitario);
  printf("Valor total da compra: R$ %.2f\n", total);

  return 0;
}
