/*
# Desafio 10: Área de um Círculo
Faça um programa que calcule e mostre a área de um círculo. Sabe-se que: Área =
π * raio².
*/
#include <stdio.h>

int main() {
  float raio, area;
  const float PI = 3.1415926535;

  printf("Insira o raio do circulo: ");
  scanf("%f", &raio);

  area = PI * (raio * raio);

  printf("A area do circulo e: %.2f\n", area);

  return 0;
}
