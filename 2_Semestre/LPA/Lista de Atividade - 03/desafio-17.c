/*
# Desafio 17: Desconto na Compra
Uma loja oferece desconto de acordo com o valor da compra:
• até R$ 100,00 → sem desconto;
• de R$ 100,01 até R$ 500,00 → 5% de desconto;
• acima de R$ 500,00 → 10% de desconto.
Leia o valor da compra e apresente: valor original; percentual de desconto; valor do desconto; valor final.
*/
#include <stdio.h>

int main() {
  float valor_original, percentual = 0.0f, desconto, valor_final;

  printf("Digite o valor da compra: R$ ");
  scanf("%f", &valor_original);

  if (valor_original <= 100.0f) {
    percentual = 0.0f;
  } else if (valor_original <= 500.0f) {
    percentual = 5.0f;
  } else {
    percentual = 10.0f;
  }

  desconto = valor_original * (percentual / 100.0f);
  valor_final = valor_original - desconto;

  printf("\nValor original: R$ %.2f\n", valor_original);
  printf("Percentual de desconto: %.1f%%\n", percentual);
  printf("Valor do desconto: R$ %.2f\n", desconto);
  printf("Valor final: R$ %.2f\n", valor_final);

  return 0;
}
