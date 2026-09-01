/*
# Desafio 18: Consumo de Ração dos Gatos
Pedro comprou um saco de ração com peso em quilos. Ele possui dois gatos, para
os quais fornece a quantidade de ração em gramas. A quantidade diária de
ração fornecida para cada gato é sempre a mesma. Faça um programa que receba o
peso do saco de ração e a quantidade de ração fornecida para cada gato,
calcule e mostre quanto restará de ração no saco após cinco dias.
*/
#include <stdio.h>

int main() {

  float peso, racao, total;

  printf("Digite o peso em quilos do saco de racao: ");
  scanf("%f", &peso);
  printf("Digite a quantidade de racao fornecida para cada gato: ");
  scanf("%f", &racao);

  total = (peso * 1000) - (racao * 2 * 5);

  printf("Restara %.2fkg de racao no saco apos cinco dias.\n", total / 1000);

  return 0;
}
