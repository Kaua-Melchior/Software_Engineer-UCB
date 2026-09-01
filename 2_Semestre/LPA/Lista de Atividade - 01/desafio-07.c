/*
# Desafio 07: Salário a Receber (Gratificação Fixa R$ 50,00 e Imposto 10%)
Faça um programa que receba o salário-base de um funcionário, calcule e mostre
seu salário a receber, sabendo-se que esse funcionário tem gratificação de R$
50,00 e paga imposto de 10% sobre o salário-base.
*/
#include <stdio.h>

int main() {

  float salario, salarioFinal;

  printf("Insira o salario base: ");
  scanf("%f", &salario);

  salarioFinal = salario * 0.10;
  salarioFinal = salario - salarioFinal;
  salarioFinal = salarioFinal + 50;

  printf("O salario a receber e: %.2f\n", salarioFinal);

  return 0;
}
