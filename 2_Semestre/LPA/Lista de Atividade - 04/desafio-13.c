/*
# Desafio 13: Posição do Maior e Menor Valor
Fazer um programa para ler 5 valores e, em seguida, mostrar a posição
onde se encontram o maior e o menor valor.
*/
#include <stdio.h>

int main() {
  float valores[5];
  int pos_maior = 0, pos_menor = 0;

  for (int i = 0; i < 5; i++) {
    printf("Digite o valor [%d]: ", i);
    scanf("%f", &valores[i]);
    if (i > 0) {
      if (valores[i] > valores[pos_maior]) {
        pos_maior = i;
      }
      if (valores[i] < valores[pos_menor]) {
        pos_menor = i;
      }
    }
  }

  printf("\nMaior valor: %.2f na posicao (indice): %d\n", valores[pos_maior], pos_maior);
  printf("Menor valor: %.2f na posicao (indice): %d\n", valores[pos_menor], pos_menor);

  return 0;
}
