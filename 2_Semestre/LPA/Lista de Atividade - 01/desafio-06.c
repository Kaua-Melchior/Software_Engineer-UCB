/*
# Desafio 06: Salário a Receber (Gratificação 5% e Imposto 7%)
Faça um programa que receba o salário-base de um funcionário, calcule e mostre o
salário a receber, sabendo-se que esse funcionário tem gratificação de 5% sobre
o salário-base e paga imposto de 7% sobre o salário-base.
*/
#include <stdio.h>

int main() {

  float salario, salarioFinal = 0;

  printf("Insira o salario base: ");
  scanf("%f", &salario);

  salarioFinal = salario * 0.02;
  salarioFinal = salario - salarioFinal;

  printf("O salario a receber e: %.2f\n", salarioFinal);

  return 0;
}
