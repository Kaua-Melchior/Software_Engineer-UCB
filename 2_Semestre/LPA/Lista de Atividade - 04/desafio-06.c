/*
# Desafio 06: Maior e Menor Elemento
Faça um programa que receba do usuário um vetor com 10 posições.
Em seguida deverá ser impresso o maior e o menor elemento do vetor.
*/
#include <stdio.h>

int main() {
  int vetor[10];

  printf("Digite o elemento [0]: ");
  scanf("%d", &vetor[0]);
  int maior = vetor[0];
  int menor = vetor[0];

  for (int i = 1; i < 10; i++) {
    printf("Digite o elemento [%d]: ", i);
    scanf("%d", &vetor[i]);
    if (vetor[i] > maior) {
      maior = vetor[i];
    }
    if (vetor[i] < menor) {
      menor = vetor[i];
    }
  }

  printf("\nMaior elemento: %d\n", maior);
  printf("Menor elemento: %d\n", menor);

  return 0;
}
