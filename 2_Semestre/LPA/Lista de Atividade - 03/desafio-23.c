/*
# Desafio 23: Números Pares
Apresente todos os números pares existentes entre 1 e 100.
*/
#include <stdio.h>

int main() {
  printf("Numeros pares entre 1 e 100:\n");
  for (int i = 2; i <= 100; i += 2) {
    printf("%d ", i);
  }
  printf("\n");
  return 0;
}
