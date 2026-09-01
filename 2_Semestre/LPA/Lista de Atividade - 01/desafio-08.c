/*
# Desafio 08: Rendimento de Depósito
Faça um programa que receba o valor de um depósito e o valor da taxa de juros,
calcule e mostre o valor do rendimento e o valor total depois do rendimento.
*/
#include <stdio.h>

int main() {

  float valor, taxa, rendimento, total;

  printf("Insira o valor do deposito: ");
  scanf("%f", &valor);
  printf("Insira o valor da taxa de juros: ");
  scanf("%f", &taxa);

  rendimento = valor * (taxa / 100);
  total = valor + rendimento;

  printf("O valor do rendimento e: %.2f\n", rendimento);
  printf("O valor total depois do rendimento e: %.2f\n", total);

  return 0;
}
