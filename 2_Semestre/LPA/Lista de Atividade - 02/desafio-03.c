/*
# Desafio 03: Par ou Ímpar
Faça um algoritmo que receba um número inteiro qualquer e informe se ele é par ou ímpar.
*/
#include <stdio.h>

int main() {
  int num;

  printf("Digite um numero inteiro: ");
  scanf("%d", &num);

  if (num % 2 == 0) {
    printf("O numero %d e PAR.\n", num);
  } else {
    printf("O numero %d e IMPAR.\n", num);
  }

  return 0;
}
