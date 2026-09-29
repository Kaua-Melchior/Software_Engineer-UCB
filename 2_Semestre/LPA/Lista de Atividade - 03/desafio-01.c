/*
# Desafio 01: Saudação
Crie um algoritmo que solicite o nome de uma pessoa e apresente:
"Olá, [nome]! Seja bem-vindo(a) à disciplina de Lógica de Programação."
*/
#include <stdio.h>

int main() {
  char nome[100];

  printf("Digite seu nome: ");
  scanf("%99[\n]", nome);

  printf("Ola, %s! Seja bem-vindo(a) a disciplina de Logica de Programacao.\n",
         nome);

  return 0;
}
