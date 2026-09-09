/*
# Desafio 11: Condições de Pagamento de um Produto
Elabore um algoritmo que calcule o valor a ser pago por um produto, considerando
o preço normal da etiqueta e a condição de pagamento escolhida.
Utilize os códigos abaixo:
Código   Condição de pagamento
1        À vista em dinheiro ou cheque: 10% de desconto
2        À vista no cartão de crédito: 15% de desconto
3        Em duas parcelas: preço normal, sem juros
4        Em duas parcelas: acréscimo de 10% sobre o preço normal

O algoritmo deve ler:
• o preço do produto;
• o código da condição de pagamento;
e apresentar o valor final a ser pago.
*/
#include <stdio.h>

int main() {
  float preco, valor_final;
  int codigo;

  printf("Digite o preco normal do produto: R$ ");
  scanf("%f", &preco);

  printf("\n--- Formas de Pagamento ---\n");
  printf("1 - A vista em dinheiro ou cheque (10%% de desconto)\n");
  printf("2 - A vista no cartao de credito (15%% de desconto)\n");
  printf("3 - Em duas parcelas (preco normal, sem juros)\n");
  printf("4 - Em duas parcelas (acrescimo de 10%% sobre o preco normal)\n");
  printf("Digite o codigo da condicao de pagamento: ");
  scanf("%d", &codigo);

  switch (codigo) {
    case 1:
      valor_final = preco * 0.90f;
      printf("\nOpcao escolhida: A vista em dinheiro ou cheque (10%% de desconto)\n");
      printf("Valor final a pagar: R$ %.2f\n", valor_final);
      break;
    case 2:
      valor_final = preco * 0.85f;
      printf("\nOpcao escolhida: A vista no cartao de credito (15%% de desconto)\n");
      printf("Valor final a pagar: R$ %.2f\n", valor_final);
      break;
    case 3:
      valor_final = preco;
      printf("\nOpcao escolhida: Em duas parcelas (sem juros)\n");
      printf("Valor final a pagar: R$ %.2f (2 parcelas de R$ %.2f)\n", valor_final, valor_final / 2.0f);
      break;
    case 4:
      valor_final = preco * 1.10f;
      printf("\nOpcao escolhida: Em duas parcelas (10%% de acrescimo)\n");
      printf("Valor final a pagar: R$ %.2f (2 parcelas de R$ %.2f)\n", valor_final, valor_final / 2.0f);
      break;
    default:
      printf("\nCodigo de condicao de pagamento invalido!\n");
      break;
  }

  return 0;
}
