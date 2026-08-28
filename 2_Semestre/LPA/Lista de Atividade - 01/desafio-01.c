/*
# Desafio 1: Soma de Quatro Números
Faça um programa que receba quatro números inteiros, calcule e mostre a soma
desses números.
*/

#include <stdio.h>

int main() {
  int n1, soma = 0;
  for (int i = 0; i < 4; i++) {
    printf("Digite o numero %d: ", i + 1);
    scanf("%d", &n1);
    soma += n1;
  }
  printf("A soma dos numeros e: %d\n", soma);
  return 0;
}
