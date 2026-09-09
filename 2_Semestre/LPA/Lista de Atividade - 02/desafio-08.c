/*
# Desafio 08: Três Valores em Ordem Decrescente
Escreva um algoritmo que leia três valores inteiros diferentes entre si e
apresente-os em ordem decrescente.
*/
#include <stdio.h>

int main() {
  int a, b, c;

  printf("Digite o primeiro valor inteiro: ");
  scanf("%d", &a);
  printf("Digite o segundo valor inteiro: ");
  scanf("%d", &b);
  printf("Digite o terceiro valor inteiro: ");
  scanf("%d", &c);

  printf("\nValores em ordem decrescente: ");

  if (a >= b && a >= c) {
    if (b >= c) {
      printf("%d, %d, %d\n", a, b, c);
    } else {
      printf("%d, %d, %d\n", a, c, b);
    }
  } else if (b >= a && b >= c) {
    if (a >= c) {
      printf("%d, %d, %d\n", b, a, c);
    } else {
      printf("%d, %d, %d\n", b, c, a);
    }
  } else {
    if (a >= b) {
      printf("%d, %d, %d\n", c, a, b);
    } else {
      printf("%d, %d, %d\n", c, b, a);
    }
  }

  return 0;
}
