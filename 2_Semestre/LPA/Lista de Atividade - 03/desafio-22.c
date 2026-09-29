/*
# Desafio 22: Contagem Regressiva
Apresente uma contagem regressiva de: 10, 9, 8, 7... 1, 0.
Ao final, apresente: "Fim da contagem!"
*/
#include <stdio.h>

int main() {
  for (int i = 10; i >= 0; i--) {
    printf("%d\n", i);
  }
  printf("Fim da contagem!\n");
  return 0;
}
