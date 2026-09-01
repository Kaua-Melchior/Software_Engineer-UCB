/*
# Desafio 15: Custo ao Consumidor de um Carro Novo
O custo ao consumidor de um carro novo é a soma do preço de fábrica com o
percentual de lucro do distribuidor e dos impostos aplicados ao preço de
fábrica.
Faça um programa que receba o preço de fábrica de um veículo, o
percentual de lucro do distribuidor e o percentual de impostos. Calcule e
mostre:
a) O valor correspondente ao lucro do distribuidor;
b) O valor correspondente aos impostos;
c) O preço final do veículo.
*/
#include <stdio.h>

int main() {

  float preco_fabrica, lucro_distribuidor, impostos, preco_final;

  printf("Digite o preco de fabrica: ");
  scanf("%f", &preco_fabrica);
  printf("Digite o lucro do distribuidor: ");
  scanf("%f", &lucro_distribuidor);
  printf("Digite os impostos: ");
  scanf("%f", &impostos);

  lucro_distribuidor = preco_fabrica * (lucro_distribuidor / 100);
  impostos = preco_fabrica * (impostos / 100);
  preco_final = preco_fabrica + lucro_distribuidor + impostos;

  printf("a) O valor correspondente ao lucro do distribuidor e: %.2f\n",
         lucro_distribuidor);
  printf("b) O valor correspondente aos impostos e: %.2f\n", impostos);
  printf("c) O preco final do veiculo e: %.2f\n", preco_final);

  return 0;
}
