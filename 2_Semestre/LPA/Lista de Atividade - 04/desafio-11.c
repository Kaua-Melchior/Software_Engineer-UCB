/*
# Desafio 11: Negativos e Soma dos Positivos
Faça um programa que preencha um vetor com 10 números reais,
calcule e mostre a quantidade de números negativos e a soma dos números positivos desse vetor.
*/
#include <stdio.h>

int main() {
  float vetor[10];
  int qtd_negativos = 0;
  float soma_positivos = 0.0f;

  for (int i = 0; i < 10; i++) {
    printf("Digite o numero real [%d]: ", i);
    scanf("%f", &vetor[i]);
    if (vetor[i] < 0) {
      qtd_negativos++;
    } else if (vetor[i] > 0) {
      soma_positivos += vetor[i];
    }
  }

  printf("\nQuantidade de numeros negativos: %d\n", qtd_negativos);
  printf("Soma dos numeros positivos: %.2f\n", soma_positivos);

  return 0;
}
