/*
# Desafio 09: Peso Ideal por Altura e Sexo
Tendo como dados de entrada a altura e o sexo de uma pessoa, construa um algoritmo
que calcule seu peso ideal utilizando as seguintes fórmulas:
• Para homens: peso ideal = (72,7 × altura) - 58
• Para mulheres: peso ideal = (62,1 × altura) - 44,7
*/
#include <stdio.h>

int main() {
  float altura, peso_ideal;
  char sexo;

  printf("Digite a altura (em metros, ex: 1.75): ");
  scanf("%f", &altura);

  printf("Digite o sexo (M para Masculino, F para Feminino): ");
  scanf(" %c", &sexo);

  if (sexo == 'M' || sexo == 'm') {
    peso_ideal = (72.7f * altura) - 58.0f;
    printf("\nSexo: Masculino | Altura: %.2fm\n", altura);
    printf("Peso ideal: %.2f kg\n", peso_ideal);
  } else if (sexo == 'F' || sexo == 'f') {
    peso_ideal = (62.1f * altura) - 44.7f;
    printf("\nSexo: Feminino | Altura: %.2fm\n", altura);
    printf("Peso ideal: %.2f kg\n", peso_ideal);
  } else {
    printf("\nSexo informado invalido! Digite M ou F.\n");
  }

  return 0;
}

