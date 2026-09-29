/*
# Desafio 20: Calculadora
Leia:
• primeiro número;
• segundo número;
• operação desejada (+, -, * ou /).
Realize a operação escolhida e apresente o resultado.
O algoritmo deverá verificar a tentativa de divisão por zero.
*/
#include <stdio.h>

int main() {
  float n1, n2, resultado;
  char operacao;

  printf("Digite o primeiro numero: ");
  scanf("%f", &n1);
  printf("Digite o segundo numero: ");
  scanf("%f", &n2);
  printf("Digite a operacao desejada (+, -, *, /): ");
  scanf(" %c", &operacao);

  switch (operacao) {
    case '+':
      resultado = n1 + n2;
      printf("Resultado: %.2f + %.2f = %.2f\n", n1, n2, resultado);
      break;
    case '-':
      resultado = n1 - n2;
      printf("Resultado: %.2f - %.2f = %.2f\n", n1, n2, resultado);
      break;
    case '*':
      resultado = n1 * n2;
      printf("Resultado: %.2f * %.2f = %.2f\n", n1, n2, resultado);
      break;
    case '/':
      if (n2 == 0) {
        printf("Erro: Nao e possivel realizar divisao por zero.\n");
      } else {
        resultado = n1 / n2;
        printf("Resultado: %.2f / %.2f = %.2f\n", n1, n2, resultado);
      }
      break;
    default:
      printf("Operacao invalida!\n");
      break;
  }

  return 0;
}
