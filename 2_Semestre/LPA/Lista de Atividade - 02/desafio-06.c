/*
# Desafio 06: Comparação de Valores Lógicos
Escreva um algoritmo que leia dois valores booleanos (lógicos) e determine se
ambos são VERDADEIROS ou se ambos são FALSOS.
*/
#include <stdio.h>

int main() {
  int v1, v2;

  printf("Digite o primeiro valor logico (1 para Verdadeiro, 0 para Falso): ");
  scanf("%d", &v1);
  printf("Digite o segundo valor logico (1 para Verdadeiro, 0 para Falso): ");
  scanf("%d", &v2);

  if (v1 && v2) {
    printf("Ambos os valores sao VERDADEIROS.\n");
  } else if (!v1 && !v2) {
    printf("Ambos os valores sao FALSOS.\n");
  } else {
    printf("Os valores sao DIFERENTES (um e verdadeiro e o outro e falso).\n");
  }

  return 0;
}
