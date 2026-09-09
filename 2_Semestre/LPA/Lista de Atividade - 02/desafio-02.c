/*
# Desafio 02: Dados de Pessoa e Tempo de Casamento
Faça um algoritmo que leia o nome, o sexo e o estado civil de uma pessoa. Caso o
sexo seja F e o estado civil seja CASADA, solicite também o tempo de casamento,
em anos.
*/
#include <stdio.h>

int main() {
  char nome[100];
  char sexo;
  char estado_civil[30];
  int tempo_casamento = 0;

  printf("Digite o nome: ");
  scanf(" %[^\n]", nome);

  printf("Digite o sexo (M/F): ");
  scanf(" %c", &sexo);

  printf("Digite o estado civil (ex: CASADA, SOLTEIRO): ");
  scanf(" %s", estado_civil);

  if ((sexo == 'F' || sexo == 'f') &&
      (estado_civil[0] == 'C' || estado_civil[0] == 'c')) {
    printf("Digite o tempo de casamento (em anos): ");
    scanf("%d", &tempo_casamento);
  }

  printf("\n--- Dados Cadastrados ---\n");
  printf("Nome: %s\n", nome);
  printf("Sexo: %c\n", sexo);
  printf("Estado Civil: %s\n", estado_civil);
  if ((sexo == 'F' || sexo == 'f') &&
      (estado_civil[0] == 'C' || estado_civil[0] == 'c')) {
    printf("Tempo de casamento: %d anos\n", tempo_casamento);
  }

  return 0;
}
