/*
# Desafio 02: Média Aritmética
Faça um programa que receba três notas, calcule e mostre a média aritmética
entre elas.
*/
#include <stdio.h>

int main() {
  float nota1, nota2, nota3, media;

  printf("Insira a nota numero 1: ");
  scanf("%f", &nota1);
  printf("Insira a nota numero 2: ");
  scanf("%f", &nota2);
  printf("Insira a nota numero 3: ");
  scanf("%f", &nota3);

  media = (nota1 + nota2 + nota3) / 3;

  printf("A media e: %.2f\n", media);

  return 0;
}
