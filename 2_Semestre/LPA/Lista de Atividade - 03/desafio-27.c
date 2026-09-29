/*
# Desafio 27: Aprovados e Reprovados
Leia as notas de 10 alunos. Considere:
• nota ≥ 7 → aprovado;
• nota < 7 → reprovado.
Ao final, apresente: quantidade de aprovados; quantidade de reprovados; percentual de aprovação.
*/
#include <stdio.h>

int main() {
  const int TOTAL = 10;
  float nota;
  int aprovados = 0, reprovados = 0;

  for (int i = 1; i <= TOTAL; i++) {
    printf("Digite a nota do aluno %d: ", i);
    scanf("%f", &nota);
    if (nota >= 7.0f) {
      aprovados++;
    } else {
      reprovados++;
    }
  }

  float percentual = (aprovados * 100.0f) / TOTAL;

  printf("\nQuantidade de aprovados: %d\n", aprovados);
  printf("Quantidade de reprovados: %d\n", reprovados);
  printf("Percentual de aprovacao: %.2f%%\n", percentual);

  return 0;
}
