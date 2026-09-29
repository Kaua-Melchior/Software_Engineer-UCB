/*
# Desafio 03: Quatro Operações
Leia dois números e calcule:
• soma;
• subtração;
• multiplicação;
• divisão.
Apresente todos os resultados.
*/
#include <stdio.h>

int main() {
  float n1, n2;

  printf("Digite o primeiro numero: ");
  scanf("%f", &n1);
  printf("Digite o segundo numero: ");
  scanf("%f", &n2);

  printf("Soma: %.2f\n", n1 + n2);
  printf("Subtracao: %.2f\n", n1 - n2);
  printf("Multiplicacao: %.2f\n", n1 * n2);

  if (n2 != 0) {
    printf("Divisao: %.2f\n", n1 / n2);
  } else {
    printf("Divisao: Nao e possivel dividir por zero!\n");
  }

  return 0;
}
