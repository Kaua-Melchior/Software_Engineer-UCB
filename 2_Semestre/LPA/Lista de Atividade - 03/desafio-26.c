/*
# Desafio 26: Média da Turma
Leia a quantidade de alunos de uma turma.
Em seguida, leia a nota de cada aluno.
Ao final, apresente a média geral da turma.
*/
#include <stdio.h>

int main() {
  int qtd_alunos;
  float nota, soma = 0.0f, media;

  printf("Informe a quantidade de alunos na turma: ");
  scanf("%d", &qtd_alunos);

  if (qtd_alunos <= 0) {
    printf("Quantidade invalida!\n");
    return 1;
  }

  for (int i = 1; i <= qtd_alunos; i++) {
    printf("Digite a nota do aluno %d: ", i);
    scanf("%f", &nota);
    soma += nota;
  }

  media = soma / qtd_alunos;
  printf("\nA media geral da turma e: %.2f\n", media);

  return 0;
}
