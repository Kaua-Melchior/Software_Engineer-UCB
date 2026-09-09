/*
# Desafio 12: Média de Aproveitamento e Conceito
Escreva um algoritmo que leia:
• o número de identificação do aluno;
• três notas obtidas nas avaliações;
• a média dos exercícios.

Calcule a média de aproveitamento utilizando a fórmula:
MA = (nota1 + nota2 * 2 + nota3 * 3 + ME) / 7

Em seguida, atribua o conceito conforme a tabela:
Média de Aproveitamento   Conceito
MA >= 90                  A
75 <= MA < 90             B
60 <= MA < 75             C
40 <= MA < 60             D
MA < 40                   E

O algoritmo deverá apresentar:
• número de identificação do aluno;
• nota 1, nota 2 e nota 3;
• média dos exercícios;
• média de aproveitamento;
• conceito obtido;
• situação final: Aprovado (A, B ou C) ou Reprovado (D ou E).
*/
#include <stdio.h>

int main() {
  int id_aluno;
  float nota1, nota2, nota3, me, ma;
  char conceito;

  printf("Digite o numero de identificacao do aluno: ");
  scanf("%d", &id_aluno);

  printf("Digite a nota 1 (0 a 100): ");
  scanf("%f", &nota1);
  printf("Digite a nota 2 (0 a 100): ");
  scanf("%f", &nota2);
  printf("Digite a nota 3 (0 a 100): ");
  scanf("%f", &nota3);
  printf("Digite a media dos exercicios (ME) (0 a 100): ");
  scanf("%f", &me);

  ma = (nota1 + (nota2 * 2.0f) + (nota3 * 3.0f) + me) / 7.0f;

  if (ma >= 90.0f) {
    conceito = 'A';
  } else if (ma >= 75.0f) {
    conceito = 'B';
  } else if (ma >= 60.0f) {
    conceito = 'C';
  } else if (ma >= 40.0f) {
    conceito = 'D';
  } else {
    conceito = 'E';
  }

  printf("\n=========== BOLETIM DO ALUNO ===========\n");
  printf("Numero de Identificacao: %d\n", id_aluno);
  printf("Nota 1: %.2f\n", nota1);
  printf("Nota 2: %.2f\n", nota2);
  printf("Nota 3: %.2f\n", nota3);
  printf("Media dos Exercicios (ME): %.2f\n", me);
  printf("Media de Aproveitamento (MA): %.2f\n", ma);
  printf("Conceito Obtido: %c\n", conceito);

  if (conceito == 'A' || conceito == 'B' || conceito == 'C') {
    printf("Situacao Final: Aprovado\n");
  } else {
    printf("Situacao Final: Reprovado\n");
  }
  printf("========================================\n");

  return 0;
}
