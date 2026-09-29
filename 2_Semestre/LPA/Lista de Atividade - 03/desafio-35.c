/*
# Desafio 35: Sistema Acadêmico
Desenvolva um algoritmo para controlar os resultados de uma turma.
Primeiramente, informe a quantidade de alunos. Para cada aluno, leia: nome; nota
da primeira avaliação; nota da segunda avaliação. Calcule a média e classifique:
• Média ≥ 7 → Aprovado
• Média ≥ 5 e < 7 → Recuperação
• Média < 5 → Reprovado
Ao final, apresente: quantidade de alunos; quantidade de aprovados; quantidade
em recuperação; quantidade de reprovados; média geral da turma; maior média;
menor média.
*/
#include <stdio.h>

int main() {
  int qtd_alunos;
  int aprovados = 0, recuperacao = 0, reprovados = 0;
  float n1, n2, media, soma_medias = 0.0f;
  float maior_media = -1.0f, menor_media = 11.0f;
  char nome[100];

  printf("Informe a quantidade de alunos da turma: ");
  scanf("%d", &qtd_alunos);

  if (qtd_alunos <= 0) {
    printf("Quantidade invalida de alunos!\n");
    return 1;
  }

  for (int i = 1; i <= qtd_alunos; i++) {
    printf("\nAluno %d - Nome: ", i);
    scanf(" %99[^\n]", nome);
    printf("Nota 1: ");
    scanf("%f", &n1);
    printf("Nota 2: ");
    scanf("%f", &n2);

    media = (n1 + n2) / 2.0f;
    soma_medias += media;

    if (media > maior_media) {
      maior_media = media;
    }
    if (media < menor_media) {
      menor_media = media;
    }

    printf("Media de %s: %.2f - ", nome, media);
    if (media >= 7.0f) {
      printf("Aprovado\n");
      aprovados++;
    } else if (media >= 5.0f) {
      printf("Recuperacao\n");
      recuperacao++;
    } else {
      printf("Reprovado\n");
      reprovados++;
    }
  }

  printf("\n=== RESULTADOS GERAIS DA TURMA ===\n");
  printf("Quantidade total de alunos: %d\n", qtd_alunos);
  printf("Quantidade de aprovados: %d\n", aprovados);
  printf("Quantidade em recuperacao: %d\n", recuperacao);
  printf("Quantidade de reprovados: %d\n", reprovados);
  printf("Media geral da turma: %.2f\n", soma_medias / qtd_alunos);
  printf("Maior media: %.2f\n", maior_media);
  printf("Menor media: %.2f\n", menor_media);

  return 0;
}
