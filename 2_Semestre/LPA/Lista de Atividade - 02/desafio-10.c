/*
# Desafio 10: Índice de Massa Corporal (IMC)
O IMC — Índice de Massa Corporal — é um indicador utilizado para avaliar a
condição de peso de uma pessoa adulta.
Fórmula: IMC = peso / altura²

Faça um algoritmo que leia o peso e a altura de uma pessoa, calcule seu IMC
e apresente sua condição de acordo com a tabela:
IMC              Condição
Menor que 18,5   Abaixo do peso
Entre 18,5 e 25  Peso normal
Entre 25 e 30    Acima do peso
Acima de 30      Obeso
*/
#include <stdio.h>

int main() {
  float peso, altura, imc;

  printf("Digite o peso (em kg, ex: 70.5): ");
  scanf("%f", &peso);
  printf("Digite a altura (em metros, ex: 1.75): ");
  scanf("%f", &altura);

  if (altura <= 0.0f || peso <= 0.0f) {
    printf("Valores invalidos de peso ou altura.\n");
    return 1;
  }

  imc = peso / (altura * altura);

  printf("\nIMC calculado: %.2f\n", imc);
  printf("Condicao: ");

  if (imc < 18.5f) {
    printf("Abaixo do peso\n");
  } else if (imc <= 25.0f) {
    printf("Peso normal\n");
  } else if (imc <= 30.0f) {
    printf("Acima do peso\n");
  } else {
    printf("Obeso\n");
  }

  return 0;
}
