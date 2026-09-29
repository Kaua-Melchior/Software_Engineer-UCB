/*
# Desafio 06: Área do Círculo
Leia o raio de um círculo e calcule sua área.
Considere: π = 3,14159
Área = π × raio²
*/
#include <stdio.h>

int main() {
  const float PI = 3.14159f;
  float raio, area;

  printf("Digite o raio do circulo: ");
  scanf("%f", &raio);

  area = PI * raio * raio;

  printf("A area do circulo e: %.2f\n", area);

  return 0;
}
