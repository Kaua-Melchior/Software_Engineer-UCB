/*
# Desafio 16: Situação Acadêmica
Leia duas notas de um aluno e calcule sua média. Considere:
• Média ≥ 7,0 → Aprovado
• Média ≥ 5,0 e < 7,0 → Recuperação
• Média < 5,0 → Reprovado
Apresente a média e a situação do aluno.
*/
#include <stdio.h>

int main() {
  float n1, n2, media;

  printf("Digite a primeira nota: ");
  scanf("%f", &n1);
  printf("Digite a segunda nota: ");
  scanf("%f", &n2);

  media = (n1 + n2) / 2.0f;

  printf("Media: %.2f\n", media);
  if (media >= 7.0f) {
    printf("Situacao: Aprovado\n");
  } else if (media >= 5.0f) {
    printf("Situacao: Recuperacao\n");
  } else {
    printf("Situacao: Reprovado\n");
  }

  return 0;
}
