/*
# Desafio 29: Senha
Crie um algoritmo que solicite uma senha. A senha correta é: 1234
Enquanto a senha estiver incorreta, apresente: "Senha incorreta. Tente novamente."
Quando estiver correta: "Acesso autorizado."
*/
#include <stdio.h>

int main() {
  int senha;

  printf("Digite a senha: ");
  scanf("%d", &senha);

  while (senha != 1234) {
    printf("Senha incorreta. Tente novamente.\n");
    printf("Digite a senha: ");
    scanf("%d", &senha);
  }

  printf("Acesso autorizado.\n");

  return 0;
}
