/*
# Desafio 32: Sistema de Estacionamento
Leia: hora de entrada; hora de saída.
Calcule o número de horas que o veículo permaneceu estacionado. Considere:
• primeira hora → R$ 10,00;
• demais horas → R$ 5,00 por hora.
Apresente o tempo de permanência e o valor total.
*/
#include <stdio.h>

int main() {
  int entrada, saida, permanencia;
  float valor_total;

  printf("Digite a hora de entrada (0 a 23): ");
  scanf("%d", &entrada);
  printf("Digite a hora de saida (0 a 23): ");
  scanf("%d", &saida);

  if (saida >= entrada) {
    permanencia = saida - entrada;
  } else {
    permanencia = (24 - entrada) + saida;
  }

  if (permanencia == 0) {
    permanencia = 1;
  }

  if (permanencia == 1) {
    valor_total = 10.0f;
  } else {
    valor_total = 10.0f + (permanencia - 1) * 5.0f;
  }

  printf("\nTempo de permanencia: %d hora(s)\n", permanencia);
  printf("Valor total a pagar: R$ %.2f\n", valor_total);

  return 0;
}
