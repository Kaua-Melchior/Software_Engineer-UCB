#include <stdio.h>

#define TOTAL_ALUNOS 10

struct Aluno {
  int matricula;
  char nome[50];
  float nota1;
  float nota2;
  float media;
};

float calcularMedia(float n1, float n2) {
  return (n1 + n2) / 2.0;
}

int main() {
  struct Aluno alunos[TOTAL_ALUNOS];
  int i;
  float somaTurma = 0.0;
  float mediaGeral;
  int acimaMediaGeral = 0;
  int idxMaior = 0;
  int idxMenor = 0;

  printf("=== CADASTRO DE %d ALUNOS ===\n", TOTAL_ALUNOS);

  for (i = 0; i < TOTAL_ALUNOS; i++) {
    printf("\n--- Aluno %d ---\n", i + 1);
    printf("Matricula: ");
    scanf("%d", &alunos[i].matricula);
    printf("Nome: ");
    scanf(" %[^\n]", alunos[i].nome);
    printf("Nota 1: ");
    scanf("%f", &alunos[i].nota1);
    printf("Nota 2: ");
    scanf("%f", &alunos[i].nota2);

    alunos[i].media = calcularMedia(alunos[i].nota1, alunos[i].nota2);
    somaTurma += alunos[i].media;

    if (alunos[i].media > alunos[idxMaior].media) {
      idxMaior = i;
    }
    if (alunos[i].media < alunos[idxMenor].media) {
      idxMenor = i;
    }
  }

  mediaGeral = somaTurma / TOTAL_ALUNOS;

  printf("\n=== SITUACAO DOS ALUNOS ===\n");
  for (i = 0; i < TOTAL_ALUNOS; i++) {
    printf("Matricula: %d | Nome: %s | Media: %.2f | Situacao: ",
           alunos[i].matricula, alunos[i].nome, alunos[i].media);

    if (alunos[i].media >= 6.0) {
      printf("Aprovado\n");
    } else {
      printf("Reprovado\n");
    }

    if (alunos[i].media > mediaGeral) {
      acimaMediaGeral++;
    }
  }

  printf("\n=== RESUMO DA TURMA ===\n");
  printf("Maior media: %s (%.2f)\n", alunos[idxMaior].nome, alunos[idxMaior].media);
  printf("Menor media: %s (%.2f)\n", alunos[idxMenor].nome, alunos[idxMenor].media);
  printf("Media geral da turma: %.2f\n", mediaGeral);
  printf("Alunos acima da media geral: %d\n", acimaMediaGeral);

  return 0;
}
