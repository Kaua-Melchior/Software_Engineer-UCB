/*
# Desafio 31: Posto de Combustível
Um posto vende gasolina por determinado valor por litro. Leia:
• quantidade de litros abastecidos;
• preço do litro.
Se o cliente abastecer:
• menos de 20 litros → sem desconto;
• entre 20 e 40 litros → 3% de desconto;
• mais de 40 litros → 5% de desconto.
Apresente o valor bruto, desconto e valor final.
*/
#include <stdio.h>

int main() {
  float litros, preco_litro, valor_bruto, desconto = 0.0f, valor_final;
  float perc_desconto = 0.0f;

  printf("Digite a quantidade de litros abastecidos: ");
  scanf("%f", &litros);
  printf("Digite o preco por litro da gasolina: R$ ");
  scanf("%f", &preco_litro);

  valor_bruto = litros * preco_litro;

  if (litros < 20.0f) {
    perc_desconto = 0.0f;
  } else if (litros <= 40.0f) {
    perc_desconto = 3.0f;
  } else {
    perc_desconto = 5.0f;
  }

  desconto = valor_bruto * (perc_desconto / 100.0f);
  valor_final = valor_bruto - desconto;

  printf("\nValor bruto: R$ %.2f\n", valor_bruto);
  printf("Desconto (%.1f%%): R$ %.2f\n", perc_desconto, desconto);
  printf("Valor final: R$ %.2f\n", valor_final);

  return 0;
}
