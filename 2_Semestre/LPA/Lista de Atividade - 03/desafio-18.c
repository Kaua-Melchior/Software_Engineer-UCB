/*
# Desafio 18: Faixa Etária
Leia a idade de uma pessoa e classifique-a como:
• 0 a 12 anos → Criança
• 13 a 17 anos → Adolescente
• 18 a 59 anos → Adulto
• 60 anos ou mais → Idoso
*/
#include <stdio.h>

int main() {
  int idade;

  printf("Digite a idade: ");
  scanf("%d", &idade);

  if (idade >= 0 && idade <= 12) {
    printf("Classificacao: Crianca\n");
  } else if (idade >= 13 && idade <= 17) {
    printf("Classificacao: Adolescente\n");
  } else if (idade >= 18 && idade <= 59) {
    printf("Classificacao: Adulto\n");
  } else if (idade >= 60) {
    printf("Classificacao: Idoso\n");
  } else {
    printf("Idade invalida!\n");
  }

  return 0;
}
