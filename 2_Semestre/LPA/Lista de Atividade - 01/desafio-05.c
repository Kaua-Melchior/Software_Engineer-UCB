/*
# Desafio 05: Aumento Salarial Percentual
Faça um programa que receba o salário de um funcionário e o percentual de
aumento, calcule e mostre o valor do aumento e o novo salário.
*/
#include <stdio.h>

int main() {

  float salario, percentual, aumento, novoSalario;

  printf("Insira o salario: ");
  scanf("%f", &salario);
  printf("Insira o percentual de aumento: ");
  scanf("%f", &percentual);

  aumento = salario * (percentual / 100);
  novoSalario = salario + aumento;

  printf("O valor do aumento e: %.2f\n", aumento);
  printf("O novo salario e: %.2f\n", novoSalario);

  return 0;
}
