/*
# Desafio 04: Novo Salário com Aumento de 25%
Faça um programa que receba o salário de um funcionário, calcule e mostre o novo
salário, sabendo-se que este sofreu um aumento de 25%.
*/
#include <stdio.h>

int main() {
  float salario;

  printf("Insira o salario: ");
  scanf("%f", &salario);

  salario = salario * 1.25;

  printf("O novo salario e: %.2f\n", salario);

  return 0;
}
