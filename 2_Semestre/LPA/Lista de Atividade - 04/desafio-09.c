/*
# Desafio 09: Valores Pares na Ordem Inversa
Crie um programa que lê 6 valores inteiros pares e, em seguida, mostre na tela
os valores lidos na ordem inversa.
*/
#include <stdio.h>

int main() {
  int pares[6];
  int count = 0;

  printf("Digite 6 valores inteiros PARES:\n");
  while (count < 6) {
    int valor;
    printf("Digite o %do numero par: ", count + 1);
    scanf("%d", &valor);

    if (valor % 2 == 0) {
      pares[count] = valor;
      count++;
    } else {
      printf("Valor invalido! O numero deve ser par. Tente novamente.\n");
    }
  }

  printf("\nValores pares lidos na ordem inversa:\n");
  for (int i = 5; i >= 0; i--) {
    printf("%d ", pares[i]);
  }
  printf("\n");

  return 0;
}
