/*
# Desafio 07: Maior Elemento e Sua Posição
Escreva um programa que leia 10 números inteiros e os armazene em um vetor.
Imprima o vetor, o maior elemento e a posição que ele se encontra.
*/
#include <stdio.h>

int main() {
  int vetor[10];
  int pos_maior = 0;

  for (int i = 0; i < 10; i++) {
    printf("Digite o numero [%d]: ", i);
    scanf("%d", &vetor[i]);
    if (i > 0 && vetor[i] > vetor[pos_maior]) {
      pos_maior = i;
    }
  }

  printf("\nVetor lido:\n");
  for (int i = 0; i < 10; i++) {
    printf("%d ", vetor[i]);
  }
  printf("\n");

  printf("Maior elemento: %d\n", vetor[pos_maior]);
  printf("Posicao (indice) do maior elemento: %d\n", pos_maior);

  return 0;
}
