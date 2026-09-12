#include <stdio.h>

int main() {
  float rendaMensal, precoCarro;
  int idade;
  int status;
  int continuar = 1;

  float valorParcela;
  int numParcelas;
  char nomeCliente[100];

  // Contadores para o relatório final
  int totalClientes = 0;
  int aprovados = 0;
  int emAnalise = 0;
  int reprovados = 0;

  printf("--- Sistema de Analise de Credito de Veiculos ---\n");

  // Etapa 4: Repetição
  while (continuar == 1) {
    printf("\n--- Cliente %d ---\n", totalClientes + 1);

    printf("Digite o nome do cliente: ");
    scanf(" %[^\n]s", nomeCliente);

    printf("Digite a renda mensal do cliente (R$): ");
    scanf("%f", &rendaMensal);
    printf("Digite a idade do cliente: ");
    scanf("%d", &idade);
    printf("Digite o valor do carro desejado (R$): ");
    scanf("%f", &precoCarro);
    printf("Digite a quantidade de parcelas desejada: ");
    scanf("%d", &numParcelas);

    if (numParcelas <= 0) {
      numParcelas = 1; // Evita divisao por zero
    }
    valorParcela = precoCarro / numParcelas;

    // Regra definida:
    // Menor de 18 anos -> Reprovado (3)
    // Renda >= 3 vezes o valor da parcela (parcela <= 1/3 da renda) -> Aprovado (1)
    // Renda >= 2 vezes o valor da parcela -> Em Analise (2)
    // Renda < 2 vezes o valor da parcela -> Reprovado (3)

    if (idade < 18) {
      status = 3;
    } else if (rendaMensal >= valorParcela * 3.0) {
      status = 1;
    } else if (rendaMensal >= valorParcela * 2.0) {
      status = 2;
    } else {
      status = 3;
    }

    printf("\nResultado da Classificacao:\n");

    // Utilizando switch para classificar o cliente a partir da regra definida
    switch (status) {
    case 1:
      printf("Situacao: APROVADO\n");
      printf("Parabens! A renda do cliente eh compativel com a parcela de R$ "
             "%.2f.\n", valorParcela);
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
            "Motivo: Renda insuficiente para a parcela de R$ %.2f.\n", valorParcela);
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

  // Etapa 4: Relatório final completo
  printf("\n========================================\n");
  printf("          RELATORIO FINAL               \n");
  printf("========================================\n");

  // Exibicao de clientes individuais removida conforme as novas regras.

  // Resumo final
  printf("Total de clientes processados: %d\n", totalClientes);
  printf("Clientes APROVADOS: %d\n", aprovados);
  printf("Clientes EM ANALISE: %d\n", emAnalise);
  printf("Clientes REPROVADOS: %d\n", reprovados);
  printf("========================================\n");

  return 0;
}
