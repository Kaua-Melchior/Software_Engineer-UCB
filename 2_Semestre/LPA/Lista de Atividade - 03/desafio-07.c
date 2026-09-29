/*
# Desafio 07: Conversão de Temperatura
Leia uma temperatura em graus Celsius e converta para Fahrenheit.
F = (C × 9/5) + 32
*/
#include <stdio.h>

int main() {
  float c, f;

  printf("Digite a temperatura em graus Celsius: ");
  scanf("%f", &c);

  f = (c * 9.0f / 5.0f) + 32.0f;

  printf("A temperatura em Fahrenheit e: %.2f F\n", f);

  return 0;
}
