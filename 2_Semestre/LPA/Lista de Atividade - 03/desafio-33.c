/*
# Desafio 33: Eleição
Leia votos para três candidatos: Candidato 1, Candidato 2, Candidato 3.
O programa deverá permitir a entrada de vários votos. Utilize 0 para encerrar a votação.
Ao final, apresente: votos do candidato 1; votos do candidato 2; votos do candidato 3;
total de votos; candidato vencedor.
*/
#include <stdio.h>

int main() {
  int voto;
  int votos1 = 0, votos2 = 0, votos3 = 0, total = 0;

  printf("=== SISTEMA DE VOTACAO ===\n");
  printf("1 - Candidato 1\n");
  printf("2 - Candidato 2\n");
  printf("3 - Candidato 3\n");
  printf("0 - Encerrar votacao\n\n");

  do {
    printf("Informe seu voto (0 a 3): ");
    scanf("%d", &voto);

    switch (voto) {
      case 1:
        votos1++;
        total++;
        break;
      case 2:
        votos2++;
        total++;
        break;
      case 3:
        votos3++;
        total++;
        break;
      case 0:
        printf("\nVotacao encerrada.\n");
        break;
      default:
        printf("Voto invalido! Tente novamente.\n");
        break;
    }
  } while (voto != 0);

  printf("\n=== RESULTADO DA ELEICAO ===\n");
  printf("Votos Candidato 1: %d\n", votos1);
  printf("Votos Candidato 2: %d\n", votos2);
  printf("Votos Candidato 3: %d\n", votos3);
  printf("Total de votos: %d\n", total);

  if (total == 0) {
    printf("Nenhum voto foi registrado.\n");
  } else if (votos1 > votos2 && votos1 > votos3) {
    printf("Vencedor: Candidato 1\n");
  } else if (votos2 > votos1 && votos2 > votos3) {
    printf("Vencedor: Candidato 2\n");
  } else if (votos3 > votos1 && votos3 > votos2) {
    printf("Vencedor: Candidato 3\n");
  } else {
    printf("Houve empate entre os candidatos mais votados!\n");
  }

  return 0;
}
