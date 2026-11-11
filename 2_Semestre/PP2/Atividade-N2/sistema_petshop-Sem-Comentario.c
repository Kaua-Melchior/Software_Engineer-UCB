#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#define LIMPAR_TELA "cls"
#else
#define LIMPAR_TELA "clear"
#endif

#define MAX_ITENS 100
#define TAM_NOME 100
#define TAM_TEL 30
#define TAM_TEXTO 60
#define NUM_PRODUTOS_CAT 3

void limparBuffer(void);
void pausar(void);
void lerTexto(char *destino, int tamanho);
int lerInteiro(const char *mensagem);

int realizarLogin(char usuarioLogado[]);

float servicoBanho(int porte);
float servicoTosa(int opcaoTosa);
float servicoVeterinaria(int opcaoVet);
const char* obterNomePorte(int porte);

void adicionarItem(char descricoes[][TAM_TEXTO], int quantidades[], float valoresUnitarios[], int *totalItens, const char *descricao, int quantidade, float valorUnitario);

void cadastrarCliente(char nomeCliente[], char telefoneCliente[], int *clienteCadastrado);
void cadastrarPet(char nomePet[], char especiePet[], char racaPet[], int *portePet, int *petCadastrado, int clienteCadastrado);

void menuCadastros(char nomeCliente[], char telefoneCliente[], int *clienteCadastrado,
                   char nomePet[], char especiePet[], char racaPet[], int *portePet, int *petCadastrado);

void menuServicos(char descricoes[][TAM_TEXTO], int quantidades[], float valoresUnitarios[], int *totalItens,
                  int petCadastrado, const char *nomePet, int portePet);

void menuProdutos(char descricoes[][TAM_TEXTO], int quantidades[], float valoresUnitarios[], int *totalItens);

void exibirComprovante(const char *funcionario, int clienteCadastrado, const char *nomeCliente, const char *telefoneCliente,
                       int petCadastrado, const char *nomePet, const char *especiePet, const char *racaPet, int portePet,
                       char descricoes[][TAM_TEXTO], int quantidades[], float valoresUnitarios[], int totalItens);

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif

    char usuarioLogado[TAM_NOME] = "";

    if (!realizarLogin(usuarioLogado)) {
        printf("\nPrograma encerrado devido ao excesso de tentativas de login.\n");
        return 0;
    }

    int clienteCadastrado = 0;
    char nomeCliente[TAM_NOME] = "";
    char telefoneCliente[TAM_TEL] = "";

    int petCadastrado = 0;
    char nomePet[TAM_NOME] = "";
    char especiePet[TAM_TEXTO] = "";
    char racaPet[TAM_TEXTO] = "";
    int portePet = 0;

    char itensDescricao[MAX_ITENS][TAM_TEXTO];
    int itensQuantidade[MAX_ITENS];
    float itensValorUnitario[MAX_ITENS];
    int totalItens = 0;

    int opcaoPrincipal;

    do {
        system(LIMPAR_TELA);
        printf("==============================\n");
        printf("      PETSHOP AMIGO FIEL      \n");
        printf("==============================\n");
        printf("  1 - Cadastros\n");
        printf("  2 - Serviços\n");
        printf("  3 - Produtos\n");
        printf("  4 - Comprovante final\n");
        printf("  0 - Sair\n");
        printf("==============================\n");
        opcaoPrincipal = lerInteiro("Escolha uma opção: ");

        switch (opcaoPrincipal) {
            case 1:
                menuCadastros(nomeCliente, telefoneCliente, &clienteCadastrado,
                             nomePet, especiePet, racaPet, &portePet, &petCadastrado);
                break;

            case 2:
                menuServicos(itensDescricao, itensQuantidade, itensValorUnitario, &totalItens,
                             petCadastrado, nomePet, portePet);
                break;

            case 3:
                menuProdutos(itensDescricao, itensQuantidade, itensValorUnitario, &totalItens);
                break;

            case 4: {
                exibirComprovante(usuarioLogado, clienteCadastrado, nomeCliente, telefoneCliente,
                                  petCadastrado, nomePet, especiePet, racaPet, portePet,
                                  itensDescricao, itensQuantidade, itensValorUnitario, totalItens);

                printf("\nOpções do Comprovante:\n");
                printf("  1 - Finalizar atendimento atual (iniciar novo cliente)\n");
                printf("  0 - Voltar ao menu principal\n");
                int opcaoComp = lerInteiro("Escolha uma opção: ");

                if (opcaoComp == 1) {
                    int confirma = lerInteiro("Confirma a finalização deste atendimento? (1 - Sim / 0 - Não): ");
                    if (confirma == 1) {
                        clienteCadastrado = 0;
                        petCadastrado = 0;
                        totalItens = 0;
                        nomeCliente[0] = '\0';
                        telefoneCliente[0] = '\0';
                        nomePet[0] = '\0';
                        especiePet[0] = '\0';
                        racaPet[0] = '\0';
                        portePet = 0;
                        printf("\nAtendimento finalizado com sucesso! Dados prontos para o próximo cliente.\n");
                        pausar();
                    }
                }
                break;
            }

            case 0:
                printf("\nEncerrando o sistema Petshop Amigo Fiel. Até logo!\n");
                break;

            default:
                printf("\nOpção inválida! Tente novamente.\n");
                pausar();
                break;
        }

    } while (opcaoPrincipal != 0);

    return 0;
}

void limparBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void pausar(void) {
    printf("\nPressione Enter para continuar...");
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void lerTexto(char *destino, int tamanho) {
    if (fgets(destino, tamanho, stdin) != NULL) {
        destino[strcspn(destino, "\r\n")] = '\0';
    } else {
        destino[0] = '\0';
    }
}

int lerInteiro(const char *mensagem) {
    int valor;
    int resultado;
    while (1) {
        printf("%s", mensagem);
        resultado = scanf("%d", &valor);
        if (resultado == 1) {
            limparBuffer();
            return valor;
        }
        if (resultado == EOF) {
            return 0;
        }
        printf("Entrada inválida! Digite apenas números inteiros.\n");
        limparBuffer();
    }
}

const char* obterNomePorte(int porte) {
    switch (porte) {
        case 1: return "Pequeno";
        case 2: return "Médio";
        case 3: return "Grande";
        default: return "Não definido";
    }
}

int realizarLogin(char usuarioLogado[]) {
    char usuario[TAM_NOME];
    char senha[TAM_NOME];
    int tentativas = 0;
    const int MAX_TENTATIVAS = 3;

    while (tentativas < MAX_TENTATIVAS) {
        system(LIMPAR_TELA);
        printf("==============================\n");
        printf("      PETSHOP AMIGO FIEL      \n");
        printf("       LOGIN DE ACESSO        \n");
        printf("==============================\n");
        printf("Tentativa %d de %d\n\n", tentativas + 1, MAX_TENTATIVAS);
        printf("(Credenciais padrão: admin / 1234)\n\n");

        printf("Usuário: ");
        lerTexto(usuario, TAM_NOME);

        printf("Senha: ");
        lerTexto(senha, TAM_NOME);

        if (strcmp(usuario, "admin") == 0 && strcmp(senha, "1234") == 0) {
            strcpy(usuarioLogado, usuario);
            printf("\nLogin realizado com sucesso! Bem-vindo(a), %s!\n", usuarioLogado);
            pausar();
            return 1;
        } else {
            tentativas++;
            printf("\nUsuário ou senha incorretos!\n");
            if (tentativas < MAX_TENTATIVAS) {
                printf("Você tem mais %d tentativa(s).\n", MAX_TENTATIVAS - tentativas);
                pausar();
            }
        }
    }

    printf("\nLimite máximo de tentativas atingido! Acesso bloqueado.\n");
    pausar();
    return 0;
}

void cadastrarCliente(char nomeCliente[], char telefoneCliente[], int *clienteCadastrado) {
    system(LIMPAR_TELA);
    printf("--------- CADASTRAR CLIENTE ---------\n");
    do {
        printf("Nome do cliente: ");
        lerTexto(nomeCliente, TAM_NOME);
        if (strlen(nomeCliente) == 0) {
            printf("O nome não pode ficar vazio. Digite novamente.\n");
        }
    } while (strlen(nomeCliente) == 0);

    do {
        printf("Telefone de contato: ");
        lerTexto(telefoneCliente, TAM_TEL);
        if (strlen(telefoneCliente) == 0) {
            printf("O telefone não pode ficar vazio. Digite novamente.\n");
        }
    } while (strlen(telefoneCliente) == 0);

    *clienteCadastrado = 1;
    printf("\nCliente cadastrado com sucesso!\n");
    pausar();
}

void cadastrarPet(char nomePet[], char especiePet[], char racaPet[], int *portePet, int *petCadastrado, int clienteCadastrado) {
    system(LIMPAR_TELA);
    printf("------------ CADASTRAR PET -----------\n");

    if (!clienteCadastrado) {
        printf("[ERRO] O pet só pode ser cadastrado depois do cliente!\n");
        printf("Por favor, realize primeiro o cadastro do cliente (opção 1).\n");
        pausar();
        return;
    }

    do {
        printf("Nome do pet: ");
        lerTexto(nomePet, TAM_NOME);
        if (strlen(nomePet) == 0) {
            printf("O nome do pet não pode ficar vazio. Digite novamente.\n");
        }
    } while (strlen(nomePet) == 0);

    int opcaoEspecie;
    do {
        printf("\nEspécie do pet:\n");
        printf("  1 - Cão\n");
        printf("  2 - Gato\n");
        opcaoEspecie = lerInteiro("Escolha a espécie: ");
        if (opcaoEspecie == 1) {
            strcpy(especiePet, "Cão");
        } else if (opcaoEspecie == 2) {
            strcpy(especiePet, "Gato");
        } else {
            printf("Opção inválida! Escolha 1 para Cão ou 2 para Gato.\n");
        }
    } while (opcaoEspecie != 1 && opcaoEspecie != 2);

    do {
        printf("\nRaça do pet: ");
        lerTexto(racaPet, TAM_TEXTO);
        if (strlen(racaPet) == 0) {
            printf("A raça não pode ficar vazia. Digite novamente.\n");
        }
    } while (strlen(racaPet) == 0);

    int opcaoPorte;
    do {
        printf("\nPorte do pet:\n");
        printf("  1 - Pequeno\n");
        printf("  2 - Médio\n");
        printf("  3 - Grande\n");
        opcaoPorte = lerInteiro("Escolha o porte: ");
        if (opcaoPorte >= 1 && opcaoPorte <= 3) {
            *portePet = opcaoPorte;
        } else {
            printf("Opção inválida! Escolha 1, 2 ou 3.\n");
        }
    } while (opcaoPorte < 1 || opcaoPorte > 3);

    *petCadastrado = 1;
    printf("\nPet cadastrado com sucesso!\n");
    pausar();
}

void menuCadastros(char nomeCliente[], char telefoneCliente[], int *clienteCadastrado,
                   char nomePet[], char especiePet[], char racaPet[], int *portePet, int *petCadastrado) {
    int opcao;
    do {
        system(LIMPAR_TELA);
        printf("--------- CADASTROS ----------\n");
        printf("  1 - Cadastrar cliente %s\n", *clienteCadastrado ? "[OK]" : "[Pendente]");
        printf("  2 - Cadastrar pet     %s\n", *petCadastrado ? "[OK]" : "[Pendente]");
        printf("  0 - Voltar\n");
        printf("------------------------------\n");
        opcao = lerInteiro("Escolha uma opção: ");

        switch (opcao) {
            case 1:
                cadastrarCliente(nomeCliente, telefoneCliente, clienteCadastrado);
                break;
            case 2:
                cadastrarPet(nomePet, especiePet, racaPet, portePet, petCadastrado, *clienteCadastrado);
                break;
            case 0:
                break;
            default:
                printf("\nOpção inválida! Tente novamente.\n");
                pausar();
                break;
        }
    } while (opcao != 0);
}

float servicoBanho(int porte) {
    switch (porte) {
        case 1:
            return 40.00f;
        case 2:
            return 55.00f;
        case 3:
            return 70.00f;
        default:
            return 0.00f;
    }
}

float servicoTosa(int opcaoTosa) {
    switch (opcaoTosa) {
        case 1:
            return 35.00f;
        case 2:
            return 50.00f;
        case 3:
            return 65.00f;
        default:
            return 0.00f;
    }
}

float servicoVeterinaria(int opcaoVet) {
    switch (opcaoVet) {
        case 1:
            return 120.00f;
        case 2:
            return 80.00f;
        case 3:
            return 95.00f;
        default:
            return 0.00f;
    }
}

void menuServicos(char descricoes[][TAM_TEXTO], int quantidades[], float valoresUnitarios[], int *totalItens,
                  int petCadastrado, const char *nomePet, int portePet) {
    if (!petCadastrado) {
        system(LIMPAR_TELA);
        printf("[ERRO] Os serviços só podem ser solicitados depois do pet ser cadastrado!\n");
        printf("Por favor, realize o cadastro do cliente e do pet primeiro.\n");
        pausar();
        return;
    }

    int opcao;
    do {
        system(LIMPAR_TELA);
        printf("---------- SERVIÇOS ----------\n");
        printf("Pet em atendimento: %s (Porte: %s)\n", nomePet, obterNomePorte(portePet));
        printf("------------------------------\n");
        printf("  1 - Banho\n");
        printf("  2 - Tosa\n");
        printf("  3 - Veterinária\n");
        printf("  0 - Voltar\n");
        printf("------------------------------\n");
        opcao = lerInteiro("Escolha uma opção: ");

        switch (opcao) {
            case 1: {
                float precoBanho = servicoBanho(portePet);
                char descricaoServico[TAM_TEXTO];
                snprintf(descricaoServico, sizeof(descricaoServico), "Banho (Porte %s)", obterNomePorte(portePet));

                printf("\nServiço: %s\n", descricaoServico);
                printf("Valor para o porte %s: R$ %.2f\n", obterNomePorte(portePet), precoBanho);
                int confirmar = lerInteiro("Deseja confirmar a inclusão do banho? (1 - Sim / 0 - Não): ");

                if (confirmar == 1) {
                    adicionarItem(descricoes, quantidades, valoresUnitarios, totalItens, descricaoServico, 1, precoBanho);
                    printf("\nServiço de banho adicionado ao atendimento!\n");
                } else {
                    printf("\nInclusão de banho cancelada.\n");
                }
                pausar();
                break;
            }

            case 2: {
                int opcaoTosa;
                do {
                    system(LIMPAR_TELA);
                    printf("------------ TOSA ------------\n");
                    printf("  1 - Tosa Higiênica   R$ 35,00\n");
                    printf("  2 - Tosa Completa    R$ 50,00\n");
                    printf("  3 - Tosa na Tesoura  R$ 65,00\n");
                    printf("  0 - Voltar\n");
                    printf("------------------------------\n");
                    opcaoTosa = lerInteiro("Escolha o tipo de tosa: ");

                    if (opcaoTosa >= 1 && opcaoTosa <= 3) {
                        float precoTosa = servicoTosa(opcaoTosa);
                        const char *nomeTosa = "";
                        if (opcaoTosa == 1) nomeTosa = "Tosa Higiênica";
                        else if (opcaoTosa == 2) nomeTosa = "Tosa Completa";
                        else if (opcaoTosa == 3) nomeTosa = "Tosa na Tesoura";

                        adicionarItem(descricoes, quantidades, valoresUnitarios, totalItens, nomeTosa, 1, precoTosa);
                        printf("\n%s adicionada com sucesso! (R$ %.2f)\n", nomeTosa, precoTosa);
                        pausar();
                        break;
                    } else if (opcaoTosa != 0) {
                        printf("\nOpção inválida! Escolha 1, 2, 3 ou 0 para voltar.\n");
                        pausar();
                    }
                } while (opcaoTosa != 0);
                break;
            }

            case 3: {
                int opcaoVet;
                do {
                    system(LIMPAR_TELA);
                    printf("-------- VETERINÁRIA ---------\n");
                    printf("  1 - Consulta         R$ 120,00\n");
                    printf("  2 - Vacina           R$  80,00\n");
                    printf("  3 - Exame            R$  95,00\n");
                    printf("  0 - Voltar\n");
                    printf("------------------------------\n");
                    opcaoVet = lerInteiro("Escolha o serviço veterinário: ");

                    if (opcaoVet >= 1 && opcaoVet <= 3) {
                        float precoVet = servicoVeterinaria(opcaoVet);
                        const char *nomeVet = "";
                        if (opcaoVet == 1) nomeVet = "Consulta Veterinária";
                        else if (opcaoVet == 2) nomeVet = "Vacina Veterinária";
                        else if (opcaoVet == 3) nomeVet = "Exame Laboratorial";

                        adicionarItem(descricoes, quantidades, valoresUnitarios, totalItens, nomeVet, 1, precoVet);
                        printf("\n%s adicionada com sucesso! (R$ %.2f)\n", nomeVet, precoVet);
                        pausar();
                        break;
                    } else if (opcaoVet != 0) {
                        printf("\nOpção inválida! Escolha 1, 2, 3 ou 0 para voltar.\n");
                        pausar();
                    }
                } while (opcaoVet != 0);
                break;
            }

            case 0:
                break;

            default:
                printf("\nOpção inválida! Tente novamente.\n");
                pausar();
                break;
        }

    } while (opcao != 0);
}

void menuProdutos(char descricoes[][TAM_TEXTO], int quantidades[], float valoresUnitarios[], int *totalItens) {
    char produtosAlimentos[NUM_PRODUTOS_CAT][TAM_TEXTO] = {
        "Ração cão 10kg",
        "Ração gato 3kg",
        "Petisco"
    };
    float precosAlimentos[NUM_PRODUTOS_CAT] = {120.00f, 65.00f, 15.00f};

    char produtosAcessorios[NUM_PRODUTOS_CAT][TAM_TEXTO] = {
        "Coleira e guia",
        "Brinquedo mordedor",
        "Caminha pet"
    };
    float precosAcessorios[NUM_PRODUTOS_CAT] = {45.00f, 25.00f, 110.00f};

    char produtosHigiene[NUM_PRODUTOS_CAT][TAM_TEXTO] = {
        "Shampoo neutro",
        "Escova para pelos",
        "Tapete higiênico 30un"
    };
    float precosHigiene[NUM_PRODUTOS_CAT] = {32.00f, 22.00f, 58.00f};

    int opcaoCategoria;
    do {
        system(LIMPAR_TELA);
        printf("---------- PRODUTOS ----------\n");
        printf("  1 - Alimentos\n");
        printf("  2 - Acessórios\n");
        printf("  3 - Higiene\n");
        printf("  0 - Voltar\n");
        printf("------------------------------\n");
        opcaoCategoria = lerInteiro("Escolha uma categoria: ");

        if (opcaoCategoria >= 1 && opcaoCategoria <= 3) {
            char (*prodEscolhidos)[TAM_TEXTO] = NULL;
            float *precosEscolhidos = NULL;
            const char *nomeCategoria = "";

            if (opcaoCategoria == 1) {
                prodEscolhidos = produtosAlimentos;
                precosEscolhidos = precosAlimentos;
                nomeCategoria = "ALIMENTOS";
            } else if (opcaoCategoria == 2) {
                prodEscolhidos = produtosAcessorios;
                precosEscolhidos = precosAcessorios;
                nomeCategoria = "ACESSÓRIOS";
            } else {
                prodEscolhidos = produtosHigiene;
                precosEscolhidos = precosHigiene;
                nomeCategoria = "HIGIENE";
            }

            int opcaoProduto;
            do {
                system(LIMPAR_TELA);
                printf("--------- %s ---------\n", nomeCategoria);
                for (int i = 0; i < NUM_PRODUTOS_CAT; i++) {
                    printf("  %d - %-20s R$ %6.2f\n", i + 1, prodEscolhidos[i], precosEscolhidos[i]);
                }
                printf("  0 - Voltar\n");
                printf("------------------------------\n");
                opcaoProduto = lerInteiro("Produto: ");

                if (opcaoProduto >= 1 && opcaoProduto <= NUM_PRODUTOS_CAT) {
                    int idx = opcaoProduto - 1;
                    int qtd;
                    do {
                        qtd = lerInteiro("Quantidade: ");
                        if (qtd <= 0) {
                            printf("Quantidade deve ser maior que zero!\n");
                        }
                    } while (qtd <= 0);

                    float subtotal = precosEscolhidos[idx] * (float)qtd;
                    printf("\nProduto: %s   Quantidade: %d    Valor: R$ %.2f\n", prodEscolhidos[idx], qtd, subtotal);

                    adicionarItem(descricoes, quantidades, valoresUnitarios, totalItens,
                                  prodEscolhidos[idx], qtd, precosEscolhidos[idx]);

                    printf("\nItem adicionado ao comprovante com sucesso!\n");
                    pausar();
                } else if (opcaoProduto != 0) {
                    printf("\nOpção de produto inválida!\n");
                    pausar();
                }

            } while (opcaoProduto != 0);

        } else if (opcaoCategoria != 0) {
            printf("\nOpção inválida! Escolha 1, 2, 3 ou 0 para voltar.\n");
            pausar();
        }

    } while (opcaoCategoria != 0);
}

void adicionarItem(char descricoes[][TAM_TEXTO], int quantidades[], float valoresUnitarios[], int *totalItens,
                   const char *descricao, int quantidade, float valorUnitario) {
    if (*totalItens >= MAX_ITENS) {
        printf("\n[AVISO] Limite máximo de itens do atendimento atingido!\n");
        return;
    }

    strncpy(descricoes[*totalItens], descricao, TAM_TEXTO - 1);
    descricoes[*totalItens][TAM_TEXTO - 1] = '\0';
    quantidades[*totalItens] = quantidade;
    valoresUnitarios[*totalItens] = valorUnitario;

    (*totalItens)++;
}

void exibirComprovante(const char *funcionario, int clienteCadastrado, const char *nomeCliente, const char *telefoneCliente,
                       int petCadastrado, const char *nomePet, const char *especiePet, const char *racaPet, int portePet,
                       char descricoes[][TAM_TEXTO], int quantidades[], float valoresUnitarios[], int totalItens) {
    system(LIMPAR_TELA);
    printf("======================================================================\n");
    printf("                         PETSHOP AMIGO FIEL                           \n");
    printf("                         COMPROVANTE FINAL                            \n");
    printf("======================================================================\n");
    printf("Funcionário responsável: %s\n", funcionario);
    printf("----------------------------------------------------------------------\n");

    printf("DADOS DO CLIENTE:\n");
    if (clienteCadastrado) {
        printf("  Nome:     %s\n", nomeCliente);
        printf("  Telefone: %s\n", telefoneCliente);
    } else {
        printf("  [Nenhum cliente cadastrado para este atendimento]\n");
    }
    printf("----------------------------------------------------------------------\n");

    printf("DADOS DO PET:\n");
    if (petCadastrado) {
        printf("  Nome:    %s\n", nomePet);
        printf("  Espécie: %s\n", especiePet);
        printf("  Raça:    %s\n", racaPet);
        printf("  Porte:   %s\n", obterNomePorte(portePet));
    } else {
        printf("  [Nenhum pet cadastrado para este atendimento]\n");
    }
    printf("----------------------------------------------------------------------\n");

    printf("ITENS DO ATENDIMENTO:\n");
    printf("%-5s %-32s %4s   %10s   %10s\n", "Item", "Descricao", "Qtd", "Unitario", "Total");
    printf("----------------------------------------------------------------------\n");

    float totalGeral = 0.0f;

    if (totalItens == 0) {
        printf("       Nenhum serviço ou produto registrado até o momento.\n");
    } else {
        for (int i = 0; i < totalItens; i++) {
            float subtotal = (float)quantidades[i] * valoresUnitarios[i];
            totalGeral += subtotal;
            printf("%02d    %-32s %4d   R$ %7.2f   R$ %7.2f\n",
                   i + 1,
                   descricoes[i],
                   quantidades[i],
                   valoresUnitarios[i],
                   subtotal);
        }
    }

    printf("----------------------------------------------------------------------\n");
    printf("VALOR TOTAL DO ATENDIMENTO:                             R$ %8.2f\n", totalGeral);
    printf("======================================================================\n");
}
