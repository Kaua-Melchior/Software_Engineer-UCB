/*
# Desafio 12: Estatísticas de 5 Valores
Fazer um programa para ler 5 valores e, em seguida, mostrar todos os valores lidos
juntamente com o maior, o menor e a média dos valores.
*/
#include <stdio.h>

int main() {
  float valores[5];
  float soma = 0.0f;

  for (int i = 0; i < 5; i++) {
    printf("Digite o valor [%d]: ", i);
    scanf("%f", &valores[i]);
    soma += valores[i];
  }

  float maior = valores[0];
  float menor = valores[0];

  for (int i = 1; i < 5; i++) {
    if (valores[i] > maior) {
      maior = valores[i];
    }
    if (valores[i] < menor) {
      menor = valores[i];
    }
  }

  printf("\nValores lidos: ");
  for (int i = 0; i < 5; i++) {
    printf("%.2f ", valores[i]);
  }
  printf("\n");

  printf("Maior valor: %.2f\n", maior);
  printf("Menor valor: %.2f\n", menor);
  printf("Media dos valores: %.2f\n", soma / 5.0f);

  return 0;
}
