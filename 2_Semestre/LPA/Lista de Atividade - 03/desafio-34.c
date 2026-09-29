/*
# Desafio 34: Sistema de Vendas
Uma loja deseja registrar várias vendas durante o dia. Para cada venda, leia:
• nome do produto;
• quantidade;
• preço unitário.
Calcule o total de cada venda. Utilize uma opção para informar quando não existem mais vendas.
Ao final, apresente: quantidade de vendas realizadas; quantidade total de produtos vendidos;
faturamento total; maior venda realizada.
*/
#include <stdio.h>

int main() {
  char nome[100];
  int qtd, total_produtos = 0, qtd_vendas = 0;
  float preco, total_venda, faturamento_total = 0.0f, maior_venda = 0.0f;
  char continuar;

  do {
    printf("\n--- Registro de Venda %d ---\n", qtd_vendas + 1);
    printf("Nome do produto: ");
    scanf(" %99[^\n]", nome);
    printf("Quantidade: ");
    scanf("%d", &qtd);
    printf("Preco unitario: R$ ");
    scanf("%f", &preco);

    total_venda = qtd * preco;
    printf("Total desta venda: R$ %.2f\n", total_venda);

    qtd_vendas++;
    total_produtos += qtd;
    faturamento_total += total_venda;

    if (total_venda > maior_venda) {
      maior_venda = total_venda;
    }

    printf("Deseja registrar outra venda? (S/N): ");
    scanf(" %c", &continuar);
  } while (continuar == 'S' || continuar == 's');

  printf("\n=== RESUMO DO DIA ===\n");
  printf("Quantidade de vendas realizadas: %d\n", qtd_vendas);
  printf("Quantidade total de produtos vendidos: %d\n", total_produtos);
  printf("Faturamento total: R$ %.2f\n", faturamento_total);
  printf("Maior venda realizada: R$ %.2f\n", maior_venda);

  return 0;
}
