/*
# Desafio 03: Quadrado dos Componentes
Ler um conjunto de números reais, armazenando-o em vetor e calcular o quadrado
das componentes deste vetor, armazenando o resultado em outro vetor.
Os conjuntos têm 10 elementos cada. Imprimir todos os conjuntos.
*/
#include <stdio.h>

int main() {
  float original[10], quadrados[10];

  for (int i = 0; i < 10; i++) {
    printf("Digite o numero real [%d]: ", i);
    scanf("%f", &original[i]);
    quadrados[i] = original[i] * original[i];
  }

  printf("\n=== VETOR ORIGINAL ===\n");
  for (int i = 0; i < 10; i++) {
    printf("%.2f ", original[i]);
  }
  printf("\n");

  printf("\n=== VETOR DOS QUADRADOS ===\n");
  for (int i = 0; i < 10; i++) {
    printf("%.2f ", quadrados[i]);
  }
  printf("\n");

  return 0;
}
