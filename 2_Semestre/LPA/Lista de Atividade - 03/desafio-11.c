/*
# Desafio 11: Maior de Idade
Leia a idade de uma pessoa. Apresente:
• "Maior de idade", caso tenha 18 anos ou mais;
• "Menor de idade", caso contrário.
*/
#include <stdio.h>

int main() {
  int idade;

  printf("Digite a idade: ");
  scanf("%d", &idade);

  if (idade >= 18) {
    printf("Maior de idade\n");
  } else {
    printf("Menor de idade\n");
  }

  return 0;
}
