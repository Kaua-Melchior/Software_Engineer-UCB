/*
# Desafio 30: Caixa Eletrônico
Crie um algoritmo que simule operações básicas de um caixa eletrônico.
O usuário deverá iniciar com um saldo informado pelo programa e visualizar o seguinte menu:
1. Consultar saldo
2. Depositar
3. Sacar
4. Sair
O programa deverá continuar apresentando o menu até que o usuário escolha a opção Sair.
Para saques, o algoritmo deverá verificar se existe saldo suficiente.
*/
#include <stdio.h>

int main() {
  float saldo = 1000.0f;
  float valor;
  int opcao;

  do {
    printf("\n=== CAIXA ELETRONICO ===\n");
    printf("1. Consultar saldo\n");
    printf("2. Depositar\n");
    printf("3. Sacar\n");
    printf("4. Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    switch (opcao) {
      case 1:
        printf("\nSaldo atual: R$ %.2f\n", saldo);
        break;
      case 2:
        printf("Digite o valor para deposito: R$ ");
        scanf("%f", &valor);
        if (valor > 0) {
          saldo += valor;
          printf("Deposito realizado com sucesso! Saldo atual: R$ %.2f\n", saldo);
        } else {
          printf("Valor invalido para deposito!\n");
        }
        break;
      case 3:
        printf("Digite o valor para saque: R$ ");
        scanf("%f", &valor);
        if (valor <= 0) {
          printf("Valor invalido para saque!\n");
        } else if (valor > saldo) {
          printf("Saldo insuficiente! Saldo disponivel: R$ %.2f\n", saldo);
        } else {
          saldo -= valor;
          printf("Saque realizado com sucesso! Saldo atual: R$ %.2f\n", saldo);
        }
        break;
      case 4:
        printf("\nObrigado por utilizar nossos servicos!\n");
        break;
      default:
        printf("\nOpcao invalida. Tente novamente.\n");
        break;
    }
  } while (opcao != 4);

  return 0;
}
