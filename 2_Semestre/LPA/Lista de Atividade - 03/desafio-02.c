/*
# Desafio 02: Soma de Dois Números
Leia dois números inteiros e apresente:
• o primeiro número;
• o segundo número;
• a soma dos dois números.
*/
#include <stdio.h>

int main() {
  int num1, num2, soma;

  printf("Digite o primeiro numero: ");
  scanf("%d", &num1);
  printf("Digite o segundo numero: ");
  scanf("%d", &num2);

  soma = num1 + num2;

  printf("Primeiro numero: %d\n", num1);
  printf("Segundo numero: %d\n", num2);
  printf("Soma dos dois numeros: %d\n", soma);

  return 0;
}
