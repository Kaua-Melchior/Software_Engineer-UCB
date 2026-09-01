/*
# Desafio 11: Operações Matemáticas (Quadrado, Cubo, Raízes)
Faça um programa que receba um número positivo e maior que zero, calcule e
mostre: a) O número digitado ao quadrado. b) O número digitado ao cubo. c) A
raiz quadrada do número digitado. d) A raiz cúbica do número digitado.
*/
#include <math.h>
#include <stdio.h>

int main() {
  float num, quadrado, cubo, raiz_quadrada, raiz_cubica;

  printf("Digite um numero positivo e maior que zero: ");
  scanf("%f", &num);

  if (num <= 0) {
    printf("O numero deve ser positivo e maior que zero.\n");
    return 1;
  }

  quadrado = num * num;
  cubo = num * num * num;
  raiz_quadrada = sqrt(num);
  raiz_cubica = cbrt(num);

  printf("a) O numero ao quadrado e: %.2f\n", quadrado);
  printf("b) O numero ao cubo e: %.2f\n", cubo);
  printf("c) A raiz quadrada do numero e: %.2f\n", raiz_quadrada);
  printf("d) A raiz cubica do numero e: %.2f\n", raiz_cubica);

  return 0;
}
