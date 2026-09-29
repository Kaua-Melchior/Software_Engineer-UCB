/*
# Desafio 19: Cálculo do IMC
Leia o peso e a altura de uma pessoa. Calcule:
IMC = peso / altura²
Classifique o resultado:
• abaixo de 18,5 → Abaixo do peso
• 18,5 a 24,9 → Peso adequado
• 25,0 a 29,9 → Sobrepeso
• 30,0 ou mais → Obesidade
*/
#include <stdio.h>

int main() {
  float peso, altura, imc;

  printf("Digite o peso em kg (ex: 70.5): ");
  scanf("%f", &peso);
  printf("Digite a altura em metros (ex: 1.75): ");
  scanf("%f", &altura);

  imc = peso / (altura * altura);

  printf("IMC: %.2f\n", imc);
  if (imc < 18.5f) {
    printf("Classificacao: Abaixo do peso\n");
  } else if (imc <= 24.9f) {
    printf("Classificacao: Peso adequado\n");
  } else if (imc <= 29.9f) {
    printf("Classificacao: Sobrepeso\n");
  } else {
    printf("Classificacao: Obesidade\n");
  }

  return 0;
}
