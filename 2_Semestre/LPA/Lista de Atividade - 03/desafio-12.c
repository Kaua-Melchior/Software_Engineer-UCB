/*
# Desafio 12: Número Positivo ou Negativo
Leia um número e informe se ele é: positivo; negativo; zero.
*/
#include <stdio.h>

int main() {
  float num;

  printf("Digite um numero: ");
  scanf("%f", &num);

  if (num > 0) {
    printf("O numero %.2f e positivo.\n", num);
  } else if (num < 0) {
    printf("O numero %.2f e negativo.\n", num);
  } else {
    printf("O numero e zero.\n");
  }

  return 0;
}
