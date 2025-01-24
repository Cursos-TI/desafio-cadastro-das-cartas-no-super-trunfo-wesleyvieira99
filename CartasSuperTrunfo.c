#include <stdio.h>
#include <string.h>

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
    float densidade_populacional; // População / Área
    float pib_per_capita; // PIB / População
    float super_poder; // Soma de todas as propriedades
} Cidade;

// Função para calcular o "Super Poder" de uma cidade
float calcular_super_poder(Cidade cidade) {
    return cidade.populacao + cidade.area + cidade.pib * 1000 + cidade.pontos_turisticos +
           cidade.densidade_populacional + cidade.pib_per_capita / 1000;
}

// Função para comparar duas cidades e exibir o resultado
void comparar_cartas(Cidade c1, Cidade c2) {
    printf("Comparando cartas %s e %s:\n", c1.codigo, c2.codigo);

    // Comparação de Densidade Populacional (menor vence)
    printf("Densidade Populacional: ");
    if (c1.densidade_populacional < c2.densidade_populacional) {
        printf("%s vence (%.2f < %.2f)\n", c1.codigo, c1.densidade_populacional, c2.densidade_populacional);
    } else if (c1.densidade_populacional > c2.densidade_populacional) {
        printf("%s vence (%.2f > %.2f)\n", c2.codigo, c1.densidade_populacional, c2.densidade_populacional);
    } else {
        printf("Empate (%.2f = %.2f)\n", c1.densidade_populacional, c2.densidade_populacional);
    }

    // Comparação de outras propriedades (maior vence)
    printf("População: ");
    printf("%s vence (%d vs %d)\n", c1.populacao > c2.populacao ? c1.codigo : c2.codigo, c1.populacao, c2.populacao);

    printf("Área: ");
    printf("%s vence (%.2f vs %.2f)\n", c1.area > c2.area ? c1.codigo : c2.codigo, c1.area, c2.area);

    printf("PIB: ");
    printf("%s vence (%.2f vs %.2f)\n", c1.pib > c2.pib ? c1.codigo : c2.codigo, c1.pib, c2.pib);

    printf("Pontos Turísticos: ");
    printf("%s vence (%d vs %d)\n", c1.pontos_turisticos > c2.pontos_turisticos ? c1.codigo : c2.codigo, c1.pontos_turisticos, c2.pontos_turisticos);

    printf("PIB per Capita: ");
    printf("%s vence (%.2f vs %.2f)\n", c1.pib_per_capita > c2.pib_per_capita ? c1.codigo : c2.codigo, c1.pib_per_capita, c2.pib_per_capita);

    // Comparação de Super Poder
    printf("Super Poder: ");
    printf("%s vence (%.2f vs %.2f)\n", c1.super_poder > c2.super_poder ? c1.codigo : c2.codigo, c1.super_poder, c2.super_poder);
    printf("------------------------\n");
}

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

            // Calcular Densidade Populacional e PIB per Capita
            if (cartas[i][j].area > 0) {
                cartas[i][j].densidade_populacional = cartas[i][j].populacao / cartas[i][j].area;
            } else {
                cartas[i][j].densidade_populacional = 0;
            }

            if (cartas[i][j].populacao > 0) {
                cartas[i][j].pib_per_capita = cartas[i][j].pib * 1000000000 / cartas[i][j].populacao; // Converter PIB para reais
            } else {
                cartas[i][j].pib_per_capita = 0;
            }

            // Calcular Super Poder
            cartas[i][j].super_poder = calcular_super_poder(cartas[i][j]);

            printf("\n");
        }
    }

    // Comparação de cartas
    char c1_codigo[4], c2_codigo[4];
    Cidade *c1 = NULL, *c2 = NULL;

    printf("Digite o código da primeira carta para comparação: ");
    scanf("%s", c1_codigo);
    printf("Digite o código da segunda carta para comparação: ");
    scanf("%s", c2_codigo);

    // Procurar as cartas pelo código
    for (int i = 0; i < NUM_ESTADOS; i++) {
        for (int j = 0; j < NUM_CIDADES; j++) {
            if (strcmp(cartas[i][j].codigo, c1_codigo) == 0) {
                c1 = &cartas[i][j];
            }
            if (strcmp(cartas[i][j].codigo, c2_codigo) == 0) {
                c2 = &cartas[i][j];
            }
        }
    }

    if (c1 != NULL && c2 != NULL) {
        comparar_cartas(*c1, *c2);
    } else {
        printf("Erro: Um ou ambos os códigos das cartas não foram encontrados.\n");
    }

    return 0;
}
