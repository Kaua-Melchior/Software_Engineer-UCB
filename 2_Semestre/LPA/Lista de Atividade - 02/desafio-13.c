/*
# Desafio 13: Classificação de Infração de Trânsito
Desenvolva um programa em C para determinar a classificação de uma infração de trânsito
a partir da velocidade registrada de um veículo.
O programa deverá solicitar a velocidade máxima permitida na via e a velocidade
registrada do veículo.
- Se dentro do limite: informe que não houve infração.
- Se ultrapassado, use if, else if e else aninhados para classificar:
  * até 20% acima: infração média
  * acima de 20% e até 50%: infração grave
  * acima de 50%: infração gravíssima
- Se velocidade registrada > 120 km/h: acrescente alerta de velocidade extremamente elevada.
Apresente: limite da via, velocidade registrada, percentual excedido e classificação final.
*/
#include <stdio.h>

int main() {
  float vel_max, vel_reg;

  printf("Digite a velocidade maxima permitida na via (km/h): ");
  scanf("%f", &vel_max);

  printf("Digite a velocidade registrada do veiculo (km/h): ");
  scanf("%f", &vel_reg);

  if (vel_reg <= vel_max) {
    printf("\nVelocidade dentro do limite permitido (%.2f km/h).\n", vel_max);
    printf("Nao houve infracao de transito.\n");
  } else {
    float vel_excedida = vel_reg - vel_max;
    float percentual = (vel_excedida / vel_max) * 100.0f;
    char *classificacao;

    if (percentual <= 20.0f) {
      classificacao = "Media";
    } else {
      if (percentual <= 50.0f) {
        classificacao = "Grave";
      } else {
        classificacao = "Gravissima";
      }
    }

    printf("\n--- Relatorio de Infracao de Transito ---\n");
    printf("Limite da via: %.2f km/h\n", vel_max);
    printf("Velocidade registrada: %.2f km/h\n", vel_reg);
    printf("Percentual excedido: %.2f%%\n", percentual);
    printf("Classificacao final: Infracao %s\n", classificacao);

    if (vel_reg > 120.0f) {
      printf("ALERTA: Velocidade extremamente elevada (> 120 km/h)!\n");
    }
  }

  return 0;
}
