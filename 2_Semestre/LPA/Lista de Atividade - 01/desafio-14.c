/*
# Desafio 14: Cálculo de Idade Atual e em 2050
Faça um programa que receba o ano de nascimento de uma pessoa e o ano atual.
Calcule e mostre: a) A idade dessa pessoa. b) Quantos anos essa pessoa terá em
2050.
*/
#include <stdio.h>

int main() {
  int ano_nasc, ano_atual, idade, idade_2050;

  printf("Digite o ano de nascimento: ");
  scanf("%d", &ano_nasc);
  printf("Digite o ano atual: ");
  scanf("%d", &ano_atual);

  idade = ano_atual - ano_nasc;
  idade_2050 = 2050 - ano_nasc;

  printf("a) A idade dessa pessoa e: %d\n", idade);
  printf("b) Quantos anos essa pessoa tera em 2050: %d\n", idade_2050);

  return 0;
}
