#include <stdio.h>

#define NUM_ESTADOS 8
#define NUM_CIDADES 4

// Estrutura para representar uma cidade
typedef struct {
    char codigo[4]; // Código da cidade, ex: A01, B02
    char nome[50]; // Nome da cidade
    int populacao; // População da cidade
    float area; // Área da cidade em km²
    float pib; // PIB da cidade em bilhões de reais
    int pontos_turisticos; // Número de pontos turísticos
} Cidade;

int main() {
    Cidade cartas[NUM_ESTADOS][NUM_CIDADES]; // Array para armazenar as cartas
    char estados[] = "ABCDEFGH"; // Identificação dos estados

    printf("Bem-vindo ao desafio Super Trunfo - Países!\n");
    printf("Vamos cadastrar as cartas de cada cidade.\n\n");

    // Cadastro das cartas
    for (int i = 0; i < NUM_ESTADOS; i++) {
        for (int j = 0; j < NUM_CIDADES; j++) {
            printf("Cadastro da cidade %c%d:\n", estados[i], j + 1);

            // Gerar código da cidade automaticamente
            sprintf(cartas[i][j].codigo, "%c%02d", estados[i], j + 1);

            printf("Digite o nome da cidade: ");
            scanf(" %[^\n]s", cartas[i][j].nome);

            printf("Digite a populacao: ");
            scanf("%d", &cartas[i][j].populacao);

            printf("Digite a area (em km²): ");
            scanf("%f", &cartas[i][j].area);

            printf("Digite o PIB (em bilhões de reais): ");
            scanf("%f", &cartas[i][j].pib);

            printf("Digite o número de pontos turísticos: ");
            scanf("%d", &cartas[i][j].pontos_turisticos);

            printf("\n");
        }
    }

    // Exibição dos dados cadastrados
    printf("Cartas cadastradas:\n\n");
    for (int i = 0; i < NUM_ESTADOS; i++) {
        for (int j = 0; j < NUM_CIDADES; j++) {
            printf("Código da cidade: %s\n", cartas[i][j].codigo);
            printf("Nome: %s\n", cartas[i][j].nome);
            printf("População: %d\n", cartas[i][j].populacao);
            printf("Área: %.2f km²\n", cartas[i][j].area);
            printf("PIB: %.2f bilhões de reais\n", cartas[i][j].pib);
            printf("Pontos turísticos: %d\n", cartas[i][j].pontos_turisticos);
            printf("------------------------\n");
        }
    }

    return 0;
}
