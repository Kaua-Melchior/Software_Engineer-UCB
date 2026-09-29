/*
# Desafio 13: Número Par ou Ímpar
Leia um número inteiro e determine se ele é par ou ímpar.
*/
#include <stdio.h>

int main() {
  int num;

  printf("Digite um numero inteiro: ");
  scanf("%d", &num);

  if (num % 2 == 0) {
    printf("O numero %d e par.\n", num);
  } else {
    printf("O numero %d e impar.\n", num);
  }

  return 0;
}
