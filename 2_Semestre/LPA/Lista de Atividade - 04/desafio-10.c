/*
# Desafio 10: Média Geral das Notas
Faça um programa para ler a nota da prova de 15 alunos e armazene num vetor,
calcule e imprima a média geral.
*/
#include <stdio.h>

int main() {
  const int TOTAL = 15;
  float notas[15];
  float soma = 0.0f;

  for (int i = 0; i < TOTAL; i++) {
    printf("Digite a nota do aluno %d: ", i + 1);
    scanf("%f", &notas[i]);
    soma += notas[i];
  }

  float media = soma / TOTAL;
  printf("\nA media geral das notas da prova e: %.2f\n", media);

  return 0;
}
