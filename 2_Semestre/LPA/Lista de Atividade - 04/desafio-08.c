/*
# Desafio 08: Ordem Inversa
Crie um programa que lê 6 valores inteiros e, em seguida, mostre na tela
os valores lidos na ordem inversa.
*/
#include <stdio.h>

int main() {
  int valores[6];

  for (int i = 0; i < 6; i++) {
    printf("Digite o valor [%d]: ", i);
    scanf("%d", &valores[i]);
  }

  printf("\nValores na ordem inversa:\n");
  for (int i = 5; i >= 0; i--) {
    printf("%d ", valores[i]);
  }
  printf("\n");

  return 0;
}
