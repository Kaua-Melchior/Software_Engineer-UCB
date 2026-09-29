/*
# Desafio 09: Consumo de Combustível
Leia:
• distância percorrida em quilômetros;
• quantidade de combustível utilizada em litros.
Calcule o consumo médio do veículo em km/L.
*/
#include <stdio.h>

int main() {
  float distancia, litros, consumo;

  printf("Digite a distancia percorrida em km: ");
  scanf("%f", &distancia);
  printf("Digite a quantidade de combustivel utilizada em litros: ");
  scanf("%f", &litros);

  if (litros > 0) {
    consumo = distancia / litros;
    printf("O consumo medio do veiculo e: %.2f km/L\n", consumo);
  } else {
    printf("Quantidade de combustivel invalida!\n");
  }

  return 0;
}
