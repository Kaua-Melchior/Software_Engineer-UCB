/*
# Desafio 05: Contagem de Valores Pares
Leia um vetor de 10 posições. Contar e escrever quantos valores pares ele possui.
*/
#include <stdio.h>

int main() {
  int vetor[10];
  int pares = 0;

  for (int i = 0; i < 10; i++) {
    printf("Digite o elemento [%d]: ", i);
    scanf("%d", &vetor[i]);
    if (vetor[i] % 2 == 0) {
      pares++;
    }
  }

  printf("\nO vetor possui %d valor(es) par(es).\n", pares);

  return 0;
}
