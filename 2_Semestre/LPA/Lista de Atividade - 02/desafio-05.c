/*
# Desafio 05: Dobro ou Triplo de um Número
Faça um algoritmo que leia um número.
• Caso ele seja positivo, calcule o seu dobro.
• Caso ele seja negativo, calcule o seu triplo.
Ao final, apresente o resultado.
*/
#include <stdio.h>

int main() {
  float num, resultado;

  printf("Digite um numero: ");
  scanf("%f", &num);

  if (num >= 0) {
    resultado = num * 2;
    printf("O numero e positivo (ou zero). O seu dobro e: %.2f\n", resultado);
  } else {
    resultado = num * 3;
    printf("O numero e negativo. O seu triplo e: %.2f\n", resultado);
  }

  printf("Resultado final: %.2f\n", resultado);

  return 0;
}
