/*
# Desafio 04: Soma de Posições X e Y
Faça um programa que leia um vetor de 8 posições e, em seguida, leia também
dois valores X e Y quaisquer correspondentes a duas posições no vetor.
Ao final seu programa deverá escrever a soma dos valores encontrados
nas respectivas posições X e Y.
*/
#include <stdio.h>

int main() {
  int vetor[8];
  int x, y;

  for (int i = 0; i < 8; i++) {
    printf("Digite o valor para a posicao [%d]: ", i);
    scanf("%d", &vetor[i]);
  }

  do {
    printf("\nDigite o indice X (0 a 7): ");
    scanf("%d", &x);
  } while (x < 0 || x > 7);

  do {
    printf("Digite o indice Y (0 a 7): ");
    scanf("%d", &y);
  } while (y < 0 || y > 7);

  int soma = vetor[x] + vetor[y];

  printf("\nValor na posicao %d: %d\n", x, vetor[x]);
  printf("Valor na posicao %d: %d\n", y, vetor[y]);
  printf("Soma dos valores: %d\n", soma);

  return 0;
}
