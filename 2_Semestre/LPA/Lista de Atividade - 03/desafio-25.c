/*
# Desafio 25: Soma de 1 até N
Leia um número inteiro positivo N.
Calcule a soma de todos os números de 1 até N.
Entrada: 5
Processamento: 1 + 2 + 3 + 4 + 5
Saída: 15
*/
#include <stdio.h>

int main() {
  int n, soma = 0;

  printf("Digite um numero inteiro positivo N: ");
  scanf("%d", &n);

  if (n <= 0) {
    printf("Numero invalido. Deve ser positivo.\n");
    return 1;
  }

  for (int i = 1; i <= n; i++) {
    soma += i;
  }

  printf("A soma de 1 ate %d e: %d\n", n, soma);

  return 0;
}
