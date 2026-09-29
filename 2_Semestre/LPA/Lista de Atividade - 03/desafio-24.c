/*
# Desafio 24: Tabuada
Leia um número inteiro e apresente sua tabuada de 1 até 10.
Exemplo para o número 5:
5 × 1 = 5
5 × 2 = 10
...
5 × 10 = 50
*/
#include <stdio.h>

int main() {
  int num;

  printf("Digite um numero inteiro para ver sua tabuada: ");
  scanf("%d", &num);

  printf("\n--- Tabuada de %d ---\n", num);
  for (int i = 1; i <= 10; i++) {
    printf("%d x %d = %d\n", num, i, num * i);
  }

  return 0;
}
