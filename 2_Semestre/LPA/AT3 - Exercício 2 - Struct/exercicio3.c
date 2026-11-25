#include <stdio.h>

#define MAX_FUNC 8

struct Funcionario {
  int codigo;
  char nome[50];
  char cargo[40];
  float salarioBase;
  int horasExtras;
  float salarioBruto;
  float salarioLiquido;
};

int main() {
  struct Funcionario funcionarios[MAX_FUNC];
  int total = 0;
  int continuar = 1;
  int i, idxMaior = 0;
  float valorHora, valorExtras, desconto;
  float custoTotalFolha = 0.0;

  printf("=== FOLHA DE PAGAMENTO (ATE %d FUNCIONARIOS) ===\n", MAX_FUNC);

  while (total < MAX_FUNC && continuar == 1) {
    printf("\n--- Funcionario %d ---\n", total + 1);
    printf("Codigo: ");
    scanf("%d", &funcionarios[total].codigo);
    printf("Nome: ");
    scanf(" %[^\n]", funcionarios[total].nome);
    printf("Cargo: ");
    scanf(" %[^\n]", funcionarios[total].cargo);
    printf("Salario-base: R$ ");
    scanf("%f", &funcionarios[total].salarioBase);
    printf("Quantidade de horas extras: ");
    scanf("%d", &funcionarios[total].horasExtras);

    valorHora = funcionarios[total].salarioBase / 160.0;
    valorExtras = funcionarios[total].horasExtras * (valorHora * 1.5);
    funcionarios[total].salarioBruto =
        funcionarios[total].salarioBase + valorExtras;
    desconto = funcionarios[total].salarioBruto * 0.10;
    funcionarios[total].salarioLiquido =
        funcionarios[total].salarioBruto - desconto;

    custoTotalFolha += funcionarios[total].salarioLiquido;

    if (funcionarios[total].salarioLiquido >
        funcionarios[idxMaior].salarioLiquido) {
      idxMaior = total;
    }

    total++;

    if (total < MAX_FUNC) {
      printf("Deseja cadastrar outro funcionario? (1 - Sim / 0 - Nao): ");
      scanf("%d", &continuar);
    }
  }

  printf("\n=== RELATORIO DA FOLHA ===\n");
  for (i = 0; i < total; i++) {
    printf("Cod: %d | %s (%s) | Bruto: R$ %.2f | Liquido: R$ %.2f\n",
           funcionarios[i].codigo, funcionarios[i].nome,
           funcionarios[i].cargo, funcionarios[i].salarioBruto,
           funcionarios[i].salarioLiquido);
  }

  printf("\nMaior salario liquido: %s (R$ %.2f)\n",
         funcionarios[idxMaior].nome, funcionarios[idxMaior].salarioLiquido);
  printf("Custo total da folha (salarios liquidos): R$ %.2f\n",
         custoTotalFolha);

  return 0;
}
