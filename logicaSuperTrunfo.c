#include <stdio.h>

typedef struct {
    char estado[50];
    char codigo[10];
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
} CartaCidade;

// Função para cadastrar as informações de uma carta
void cadastrarCarta(CartaCidade* carta) {
    printf("Digite o estado da cidade: ");
    scanf("%s", carta->estado);
    printf("Digite o código da carta: ");
    scanf("%s", carta->codigo);
    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]%*c", carta->cidade);  // Lê o nome da cidade com espaços
    printf("Digite a população da cidade: ");
    scanf("%d", &carta->populacao);
    printf("Digite a área da cidade (em km²): ");
    scanf("%f", &carta->area);
    printf("Digite o PIB da cidade (em bilhões): ");
    scanf("%f", &carta->pib);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta->pontos_turisticos);
}

// Função para exibir os dados de uma carta
void exibirCarta(CartaCidade carta) {
    printf("\n-- Dados da Cidade --\n");
    printf("Estado: %s\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Cidade: %s\n", carta.cidade);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontos_turisticos);
    printf("----------------------\n");
}

// Função para comparar as cartas com base no critério escolhido
void compararCartas(CartaCidade carta1, CartaCidade carta2, int criterio) {
    if (criterio == 1) {
        // Comparando População
        if (carta1.populacao > carta2.populacao) {
            printf("%s venceu com a maior população!\n", carta1.cidade);
        } else if (carta1.populacao < carta2.populacao) {
            printf("%s venceu com a maior população!\n", carta2.cidade);
        } else {
            printf("As duas cidades têm a mesma população.\n");
        }
    } else if (criterio == 2) {
        // Comparando Área
        if (carta1.area > carta2.area) {
            printf("%s venceu com a maior área!\n", carta1.cidade);
        } else if (carta1.area < carta2.area) {
            printf("%s venceu com a maior área!\n", carta2.cidade);
        } else {
            printf("As duas cidades têm a mesma área.\n");
        }
    } else if (criterio == 3) {
        // Comparando PIB
        if (carta1.pib > carta2.pib) {
            printf("%s venceu com o maior PIB!\n", carta1.cidade);
        } else if (carta1.pib < carta2.pib) {
            printf("%s venceu com o maior PIB!\n", carta2.cidade);
        } else {
            printf("As duas cidades têm o mesmo PIB.\n");
        }
    } else if (criterio == 4) {
        // Comparando Densidade Populacional
        float densidade1 = carta1.populacao / carta1.area;
        float densidade2 = carta2.populacao / carta2.area;
        if (densidade1 < densidade2) {
            printf("%s venceu com a menor densidade populacional!\n", carta1.cidade);
        } else if (densidade1 > densidade2) {
            printf("%s venceu com a menor densidade populacional!\n", carta2.cidade);
        } else {
            printf("As duas cidades têm a mesma densidade populacional.\n");
        }
    }
}

int main() {
    CartaCidade carta1, carta2;
    int criterio;

    // Cadastro das duas cartas
    printf("Cadastro da primeira carta:\n");
    cadastrarCarta(&carta1);

    printf("\nCadastro da segunda carta:\n");
    cadastrarCarta(&carta2);

    // Exibir as cartas cadastradas
    printf("\nExibindo as cartas cadastradas:\n");
    exibirCarta(carta1);
    exibirCarta(carta2);

    // Escolher o critério para comparar
    printf("\nEscolha o critério para comparação:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Densidade Populacional\n");
    printf("Digite o número do critério: ");
    scanf("%d", &criterio);

    // Comparar as cartas
    compararCartas(carta1, carta2, criterio);

    return 0;
}
