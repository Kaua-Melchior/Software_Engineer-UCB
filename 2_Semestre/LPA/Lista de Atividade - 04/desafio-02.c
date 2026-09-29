/*
# Desafio 02: Leitura e Exibição de Vetor
Crie um programa que lê 6 valores inteiros e, em seguida, mostre na tela os valores lidos.
*/
#include <stdio.h>

int main() {
  int valores[6];

  for (int i = 0; i < 6; i++) {
    printf("Digite o valor para a posicao [%d]: ", i);
    scanf("%d", &valores[i]);
  }

  printf("\nValores lidos:\n");
  for (int i = 0; i < 6; i++) {
    printf("Posicao [%d]: %d\n", i, valores[i]);
  }

  return 0;
}
