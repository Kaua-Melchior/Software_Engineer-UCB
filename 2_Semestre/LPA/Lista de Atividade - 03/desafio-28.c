/*
# Desafio 28: Maior Número
Leia 10 números e determine qual foi o maior número informado.
*/
#include <stdio.h>

int main() {
  float num, maior;

  printf("Digite o numero 1: ");
  scanf("%f", &num);
  maior = num;

  for (int i = 2; i <= 10; i++) {
    printf("Digite o numero %d: ", i);
    scanf("%f", &num);
    if (num > maior) {
      maior = num;
    }
  }

  printf("\nO maior numero informado foi: %.2f\n", maior);

  return 0;
}
