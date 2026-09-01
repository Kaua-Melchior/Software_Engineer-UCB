/*
# Desafio 17: Saldo Bancário com Desconto de CPMF
Um trabalhador recebeu seu salário e depositou em sua conta corrente bancária.
Esse trabalhador emitiu dois cheques e agora deseja saber seu saldo atual.
Sabe-se que cada operação bancária de retirada paga CPMF de 0,38% e o saldo
inicial da conta está zerado.
*/
#include <stdio.h>

int main() {

  float salario, cheque1, cheque2, saldo, cpmf1, cpmf2;

  printf("Digite o salario: ");
  scanf("%f", &salario);
  printf("Digite o valor do primeiro cheque: ");
  scanf("%f", &cheque1);
  printf("Digite o valor do segundo cheque: ");
  scanf("%f", &cheque2);

  saldo = salario - cheque1 - cheque2;
  cpmf1 = cheque1 * 0.0038;
  cpmf2 = cheque2 * 0.0038;
  saldo = saldo - cpmf1 - cpmf2;

  printf("O saldo atual e: %.2f\n", saldo);

  return 0;
}
