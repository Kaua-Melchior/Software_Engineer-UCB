#include <stdio.h>

int main() {
  float rendaMensal, precoCarro;
  int idade;
  int status;
  int continuar = 1;


  char nomesClientes[100][100];
  int statusClientes[100];


  int totalClientes = 0;
  int aprovados = 0;
  int emAnalise = 0;
  int reprovados = 0;

  printf("--- Sistema de Analise de Credito de Veiculos ---\n");


  while (continuar == 1) {
    printf("\n--- Cliente %d ---\n", totalClientes + 1);

    printf("Digite o nome do cliente: ");
    scanf(" %[^\n]s", nomesClientes[totalClientes]);

    printf("Digite a renda mensal do cliente (R$): ");
    scanf("%f", &rendaMensal);
    printf("Digite a idade do cliente: ");
    scanf("%d", &idade);
    printf("Digite o valor do carro desejado (R$): ");
    scanf("%f", &precoCarro);

    if (idade < 18) {
      status = 3;
    } else if (rendaMensal >= precoCarro * 0.30) {
      status = 1;
    } else if (rendaMensal >= precoCarro * 0.15) {
      status = 2;
    } else {
      status = 3;
    }

    statusClientes[totalClientes] = status;

    printf("\nResultado da Classificacao:\n");

    switch (status) {
    case 1:
      printf("Situacao: APROVADO\n");
      printf("Parabens! A renda do cliente eh compativel com o valor do "
             "veiculo.\n");
      aprovados++;
      break;
    case 2:
      printf("Situacao: EM ANALISE\n");
      printf("A renda esta proxima do limite. Sera necessaria uma analise de "
             "credito adicional ou um fiador.\n");
      emAnalise++;
      break;
    case 3:
      printf("Situacao: REPROVADO\n");
      if (idade < 18) {
        printf("Motivo: O cliente eh menor de idade.\n");
      } else {
        printf(
            "Motivo: Renda insuficiente para o financiamento deste veiculo.\n");
      }
      reprovados++;
      break;
    default:
      printf("Erro: Status de classificacao invalido.\n");
      break;
    }

    totalClientes++;

    printf("\nDeseja analisar outro cliente? (1 - Sim, 0 - Nao): ");
    scanf("%d", &continuar);
  }

  printf("\n========================================\n");
  printf("          RELATORIO FINAL               \n");
  printf("========================================\n");

  printf("--- Lista de Clientes Analisados ---\n");
  for (int i = 0; i < totalClientes; i++) {
    printf("Nome: %-20s | Status: ", nomesClientes[i]);
    if (statusClientes[i] == 1) {
      printf("APROVADO\n");
    } else if (statusClientes[i] == 2) {
      printf("EM ANALISE\n");
    } else {
      printf("REPROVADO\n");
    }
  }
  printf("----------------------------------------\n");


  printf("Total de clientes processados: %d\n", totalClientes);
  printf("Clientes APROVADOS: %d\n", aprovados);
  printf("Clientes EM ANALISE: %d\n", emAnalise);
  printf("Clientes REPROVADOS: %d\n", reprovados);
  printf("========================================\n");

  return 0;
}
