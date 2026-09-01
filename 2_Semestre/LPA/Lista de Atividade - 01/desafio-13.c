/*
# Desafio 13: Conversão de Medidas de Comprimento
Sabe-se que:
1 pé = 12 polegadas
1 jarda = 3 pés
1 milha = 1760 jardas

Faça um programa que receba uma medida em pés, faça as conversões a seguir e
mostre os resultados: a) Polegadas; b) Jardas; c) Milhas.
*/
#include <stdio.h>

int main() {
  float pes, polegadas, jardas, milhas;

  printf("Digite uma medida em pes: ");
  scanf("%f", &pes);

  polegadas = pes * 12;
  jardas = pes / 3;
  milhas = jardas / 1760;

  printf("a) A medida em polegadas e: %.2f\n", polegadas);
  printf("b) A medida em jardas e: %.2f\n", jardas);
  printf("c) A medida em milhas e: %.2f\n", milhas);

  return 0;
}
