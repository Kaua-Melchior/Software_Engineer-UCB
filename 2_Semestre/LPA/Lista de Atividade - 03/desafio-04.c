/*
# Desafio 04: Média do Aluno
Leia três notas de um aluno e calcule sua média aritmética.
Média = (N1 + N2 + N3) / 3
Apresente a média final.
*/
#include <stdio.h>

int main() {
  float n1, n2, n3, media;

  printf("Digite a primeira nota: ");
  scanf("%f", &n1);
  printf("Digite a segunda nota: ");
  scanf("%f", &n2);
  printf("Digite a terceira nota: ");
  scanf("%f", &n3);

  media = (n1 + n2 + n3) / 3.0f;

  printf("A media final e: %.2f\n", media);

  return 0;
}
