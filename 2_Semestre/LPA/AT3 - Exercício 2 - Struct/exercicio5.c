#include <stdio.h>

#define MAX_PACIENTES 15
#define MAX_CONSULTAS 30

struct Data {
  int dia;
  int mes;
  int ano;
};

struct Paciente {
  int codigo;
  char nome[50];
  char telefone[20];
};

struct Consulta {
  struct Paciente paciente;
  struct Data data;
  char descricao[100];
};

int main() {
  struct Paciente pacientes[MAX_PACIENTES];
  struct Consulta consultas[MAX_CONSULTAS];
  int totalPacientes = 0;
  int totalConsultas = 0;
  int opcao, i, j, codBusca, pos, achou;
  int diaBusca, mesBusca, anoBusca;
  int qtdConsultas, maiorQtd, idxMaior;

  do {
    printf("\n=== CLINICA MEDICA - CONSULTAS ===\n");
    printf("1 - Cadastrar paciente\n");
    printf("2 - Registrar consulta\n");
    printf("3 - Pesquisar consultas por codigo do paciente\n");
    printf("4 - Listar consultas por data\n");
    printf("5 - Relatorio de atendimentos por paciente\n");
    printf("0 - Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1:
      if (totalPacientes >= MAX_PACIENTES) {
        printf("\nLimite de %d pacientes atingido!\n", MAX_PACIENTES);
      } else {
        printf("\nCodigo do paciente: ");
        scanf("%d", &pacientes[totalPacientes].codigo);
        printf("Nome: ");
        scanf(" %[^\n]", pacientes[totalPacientes].nome);
        printf("Telefone: ");
        scanf(" %[^\n]", pacientes[totalPacientes].telefone);
        totalPacientes++;
        printf("Paciente cadastrado com sucesso!\n");
      }
      break;

    case 2:
      if (totalPacientes == 0) {
        printf("\nCadastre um paciente primeiro!\n");
      } else if (totalConsultas >= MAX_CONSULTAS) {
        printf("\nLimite de %d consultas atingido!\n", MAX_CONSULTAS);
      } else {
        printf("\nCodigo do paciente: ");
        scanf("%d", &codBusca);

        pos = -1;
        for (i = 0; i < totalPacientes; i++) {
          if (pacientes[i].codigo == codBusca) {
            pos = i;
            break;
          }
        }

        if (pos == -1) {
          printf("Paciente nao encontrado!\n");
        } else {
          consultas[totalConsultas].paciente = pacientes[pos];
          printf("Data da consulta (dia mes ano): ");
          scanf("%d %d %d", &consultas[totalConsultas].data.dia,
                &consultas[totalConsultas].data.mes,
                &consultas[totalConsultas].data.ano);
          printf("Descricao do atendimento: ");
          scanf(" %[^\n]", consultas[totalConsultas].descricao);
          totalConsultas++;
          printf("Consulta registrada para %s!\n", pacientes[pos].nome);
        }
      }
      break;

    case 3:
      printf("\nDigite o codigo do paciente: ");
      scanf("%d", &codBusca);

      achou = 0;
      for (i = 0; i < totalConsultas; i++) {
        if (consultas[i].paciente.codigo == codBusca) {
          printf("Data: %02d/%02d/%04d | Paciente: %s | Descricao: %s\n",
                 consultas[i].data.dia, consultas[i].data.mes,
                 consultas[i].data.ano, consultas[i].paciente.nome,
                 consultas[i].descricao);
          achou = 1;
        }
      }

      if (!achou) {
        printf("Nenhuma consulta encontrada para esse paciente.\n");
      }
      break;

    case 4:
      printf("\nDigite a data (dia mes ano): ");
      scanf("%d %d %d", &diaBusca, &mesBusca, &anoBusca);

      achou = 0;
      for (i = 0; i < totalConsultas; i++) {
        if (consultas[i].data.dia == diaBusca &&
            consultas[i].data.mes == mesBusca &&
            consultas[i].data.ano == anoBusca) {
          printf("Paciente: %s (Cod: %d) | Descricao: %s\n",
                 consultas[i].paciente.nome, consultas[i].paciente.codigo,
                 consultas[i].descricao);
          achou = 1;
        }
      }

      if (!achou) {
        printf("Nenhuma consulta encontrada nessa data.\n");
      }
      break;

    case 5:
      if (totalPacientes == 0) {
        printf("\nNenhum paciente cadastrado.\n");
      } else {
        maiorQtd = -1;
        idxMaior = 0;

        printf("\n=== CONSULTAS POR PACIENTE ===\n");
        for (i = 0; i < totalPacientes; i++) {
          qtdConsultas = 0;
          for (j = 0; j < totalConsultas; j++) {
            if (consultas[j].paciente.codigo == pacientes[i].codigo) {
              qtdConsultas++;
            }
          }

          printf("Cod: %d | %s | Total de consultas: %d\n",
                 pacientes[i].codigo, pacientes[i].nome, qtdConsultas);

          if (qtdConsultas > maiorQtd) {
            maiorQtd = qtdConsultas;
            idxMaior = i;
          }
        }

        printf("\nPaciente com maior numero de atendimentos: %s (%d consultas)\n",
               pacientes[idxMaior].nome, maiorQtd);
      }
      break;

    case 0:
      printf("\nEncerrando o programa...\n");
      break;

    default:
      printf("\nOpcao invalida!\n");
      break;
    }
  } while (opcao != 0);

  return 0;
}
