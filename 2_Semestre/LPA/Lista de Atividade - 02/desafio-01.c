/*
# Desafio 01: Soma de A + B Menor que C
Faça um algoritmo que leia três valores inteiros A, B e C e informe se a soma de
A + B é menor que C.
*/
#include <stdio.h>

int main() {
  int a, b, c, soma;

  printf("Digite o valor de A: ");
  scanf("%d", &a);
  printf("Digite o valor de B: ");
  scanf("%d", &b);
  printf("Digite o valor de C: ");
  scanf("%d", &c);

  soma = a + b;

  if (soma < c) {
    printf("A soma de A + B (%d) e MENOR que C (%d).\n", soma, c);
  } else {
    printf("A soma de A + B (%d) NAO e menor que C (%d).\n", soma, c);
  }

  return 0;
}
