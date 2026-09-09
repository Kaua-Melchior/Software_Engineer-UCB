/*
# Desafio 07: Operação Condicional Par ou Ímpar
Faça um algoritmo que leia um número inteiro.
• Caso seja par, some 5 ao seu valor.
• Caso seja ímpar, some 8 ao seu valor.
Ao final, apresente o resultado da operação.
*/
#include <stdio.h>

int main() {
  int num, resultado;

  printf("Digite um numero inteiro: ");
  scanf("%d", &num);

  if (num % 2 == 0) {
    resultado = num + 5;
    printf("O numero %d e PAR. Somando 5: %d\n", num, resultado);
  } else {
    resultado = num + 8;
    printf("O numero %d e IMPAR. Somando 8: %d\n", num, resultado);
  }

  printf("Resultado final: %d\n", resultado);

  return 0;
}
