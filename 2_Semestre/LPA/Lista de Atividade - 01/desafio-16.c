/*
# Desafio 16: Cálculo de Salário por Horas Trabalhadas
Faça um programa que receba o número de horas trabalhadas e o valor do salário
mínimo. Calcule e mostre o salário a receber seguindo as regras abaixo: a) A
hora trabalhada vale a metade do salário mínimo; b) O salário bruto equivale ao
número de horas trabalhadas multiplicado pelo valor da hora trabalhada; c) O
imposto equivale a 3% do salário bruto; d) O salário a receber equivale ao
salário bruto menos o imposto.
*/
#include <stdio.h>

int main() {

  int horas, salario_minimo, hora_trabalhada, salario_bruto, imposto,
      salario_a_receber;

  printf("Digite o numero de horas trabalhadas: ");
  scanf("%d", &horas);
  printf("Digite o valor do salario minimo: ");
  scanf("%d", &salario_minimo);

  hora_trabalhada = salario_minimo / 2;
  salario_bruto = horas * hora_trabalhada;
  imposto = salario_bruto * 0.03;
  salario_a_receber = salario_bruto - imposto;

  printf("a) A hora trabalhada vale: %d\n", hora_trabalhada);
  printf("b) O salario bruto equivale a: %d\n", salario_bruto);
  printf("c) O imposto equivale a: %d\n", imposto);
  printf("d) O salario a receber equivale a: %d\n", salario_a_receber);

  return 0;
}
