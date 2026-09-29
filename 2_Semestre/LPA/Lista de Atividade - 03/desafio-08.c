/*
# Desafio 08: Salário Mensal
Leia:
• quantidade de horas trabalhadas;
• valor recebido por hora.
Calcule e apresente o salário bruto do funcionário.
*/
#include <stdio.h>

int main() {
  float horas, valor_hora, salario_bruto;

  printf("Digite a quantidade de horas trabalhadas: ");
  scanf("%f", &horas);
  printf("Digite o valor recebido por hora: R$ ");
  scanf("%f", &valor_hora);

  salario_bruto = horas * valor_hora;

  printf("O salario bruto do funcionario e: R$ %.2f\n", salario_bruto);

  return 0;
}
