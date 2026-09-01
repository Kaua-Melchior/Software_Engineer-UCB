/*
# Desafio 12: Potenciação de Dois Números
Faça um programa que receba dois números maiores que zero, calcule e mostre um
elevado ao outro.
*/
#include <math.h>
#include <stdio.h>

int main() {
  float num1, num2, resultado;

  printf("Digite o primeiro numero: ");
  scanf("%f", &num1);
  printf("Digite o segundo numero: ");
  scanf("%f", &num2);

  if (num1 <= 0 || num2 <= 0) {
    printf("Os numeros devem ser maiores que zero.\n");
    return 1;
  }

  resultado = pow(num1, num2);

  printf("O resultado de %.2f elevado a %.2f e: %.2f\n", num1, num2, resultado);

  return 0;
}
