/*
# Desafio 09: Área de um Triângulo
Faça um programa que calcule e mostre a área de um triângulo. Sabe-se que: Área
= (base * altura)/2.
*/
#include <stdio.h>

int main() {
  float base, altura, area;

  printf("Insira a base do triangulo: ");
  scanf("%f", &base);
  printf("Insira a altura do triangulo: ");
  scanf("%f", &altura);

  area = (base * altura) / 2;

  printf("A area do triangulo e: %.2f\n", area);

  return 0;
}
