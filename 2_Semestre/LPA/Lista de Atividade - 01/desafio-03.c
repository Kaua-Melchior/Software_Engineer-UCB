/*
# Desafio 03: Média Ponderada
Faça um programa que receba três notas e seus respectivos pesos, calcule e
mostre a média ponderada dessas notas.
*/
#include <stdio.h>

int main() {
  float nota1, nota2, nota3, peso1, peso2, peso3, media;

  printf("Insira a nota numero 1: ");
  scanf("%f", &nota1);
  printf("Insira a nota numero 2: ");
  scanf("%f", &nota2);
  printf("Insira a nota numero 3: ");
  scanf("%f", &nota3);
  printf("Insira o peso numero 1: ");
  scanf("%f", &peso1);
  printf("Insira o peso numero 2: ");
  scanf("%f", &peso2);
  printf("Insira o peso numero 3: ");
  scanf("%f", &peso3);

  media =
      (nota1 * peso1 + nota2 * peso2 + nota3 * peso3) / (peso1 + peso2 + peso3);

  printf("A media ponderada e: %.2f\n", media);

  return 0;
}
