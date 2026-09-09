/*
# Desafio 04: Soma ou Multiplicação Condicional
Faça um algoritmo que leia dois valores inteiros, A e B.
• Se os valores forem iguais, some A + B.
• Caso sejam diferentes, multiplique A * B.
Ao final, armazene o resultado em uma variável C e apresente seu valor na tela.
*/
#include <stdio.h>

int main() {
  int a, b, c;

  printf("Digite o valor de A: ");
  scanf("%d", &a);
  printf("Digite o valor de B: ");
  scanf("%d", &b);

  if (a == b) {
    c = a + b;
    printf("Os valores sao iguais. A soma (A + B) e: %d\n", c);
  } else {
    c = a * b;
    printf("Os valores sao diferentes. A multiplicacao (A * B) e: %d\n", c);
  }

  printf("Valor armazenado em C: %d\n", c);

  return 0;
}
