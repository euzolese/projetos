#include <stdio.h>

// Função para limpar o buffer
void limparBuffer() {
    while (getchar() != '\n');
}

// Função auxiliar para exibir nome do atributo
const char* nomeAtributo(int opcao) {
    switch (opcao) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Demográfica";
        default: return "Desconhecido";
    }
}

// Função para obter valor do atributo com base na opção
float obterValor(int atributo, int pop, float area, float pib, int pontos, float densidade) {
    switch (atributo) {
        case 1: return (float)pop;
        case 2: return area;
        case 3: return pib;
        case 4: return (float)pontos;
        case 5: return densidade;
        default: return 0;
    }
}

int main() {
    // Cadastro de duas cartas (resumo)
    char nome1[100], nome2[100];
    int populacao1, populacao2;
    float area1, area2, pib1, pib2;
    int pontos1, pontos2;
    float densidade1, densidade2;

    printf("Cadastro da Carta 1\n");
    printf("Nome do país: ");
    scanf(" %[^\n]", nome1);
    printf("População: ");
    scanf("%d", &populacao1);
    printf("Área (km²): ");
    scanf("%f", &area1);
    printf("PIB (bilhões): ");
    scanf("%f", &pib1);
    printf("Pontos Turísticos: ");
    scanf("%d", &pontos1);
    densidade1 = populacao1 / area1;

    printf("\nCadastro da Carta 2\n");
    limparBuffer();
    printf("Nome do país: ");
    scanf(" %[^\n]", nome2);
    printf("População: ");
    scanf("%d", &populacao2);
    printf("Área (km²): ");
    scanf("%f", &area2);
    printf("PIB (bilhões): ");
    scanf("%f", &pib2);
    printf("Pontos Turísticos: ");
    scanf("%d", &pontos2);
    densidade2 = populacao2 / area2;

    // Menu 1: escolha do primeiro atributo
    int atributo1, atributo2;
    printf("\nEscolha o primeiro atributo para comparação:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Opção: ");
    scanf("%d", &atributo1);

    // Validação básica
    if (atributo1 < 1 || atributo1 > 5) {
        printf("Atributo inválido! Encerrando.\n");
        return 1;
    }

    // Menu 2: escolha do segundo atributo (excluindo o primeiro)
    printf("\nEscolha o segundo atributo para comparação (diferente do primeiro):\n");
    for (int i = 1; i <= 5; i++) {
        if (i != atributo1) {
            printf("%d - %s\n", i, nomeAtributo(i));
        }
    }
    printf("Opção: ");
    scanf("%d", &atributo2);

    if (atributo2 < 1 || atributo2 > 5 || atributo2 == atributo1) {
        printf("Atributo inválido ou repetido! Encerrando.\n");
        return 1;
    }

    // Obter valores para cada atributo e carta
    float valor1_attr1 = obterValor(atributo1, populacao1, area1, pib1, pontos1, densidade1);
    float valor2_attr1 = obterValor(atributo1, populacao2, area2, pib2, pontos2, densidade2);

    float valor1_attr2 = obterValor(atributo2, populacao1, area1, pib1, pontos1, densidade1);
    float valor2_attr2 = obterValor(atributo2, populacao2, area2, pib2, pontos2, densidade2);

    // Comparação individual de atributos
    int vitoria1 = 0, vitoria2 = 0;

    // Atributo 1
    if (atributo1 == 5) { // Densidade → menor vence
        (valor1_attr1 < valor2_attr1) ? (vitoria1++) : (valor2_attr1 < valor1_attr1 ? vitoria2++ : 0);
    } else {
        (valor1_attr1 > valor2_attr1) ? (vitoria1++) : (valor2_attr1 > valor1_attr1 ? vitoria2++ : 0);
    }

    // Atributo 2
    if (atributo2 == 5) { // Densidade → menor vence
        (valor1_attr2 < valor2_attr2) ? (vitoria1++) : (valor2_attr2 < valor1_attr2 ? vitoria2++ : 0);
    } else {
        (valor1_attr2 > valor2_attr2) ? (vitoria1++) : (valor2_attr2 > valor1_attr2 ? vitoria2++ : 0);
    }

    // Soma dos valores
    float soma1 = valor1_attr1 + valor1_attr2;
    float soma2 = valor2_attr1 + valor2_attr2;

    // Exibição dos resultados
    printf("\n=== Comparação Final ===\n");
    printf("País 1: %s\n", nome1);
    printf("  %s: %.2f\n", nomeAtributo(atributo1), valor1_attr1);
    printf("  %s: %.2f\n", nomeAtributo(atributo2), valor1_attr2);
    printf("  Soma: %.2f\n\n", soma1);

    printf("País 2: %s\n", nome2);
    printf("  %s: %.2f\n", nomeAtributo(atributo1), valor2_attr1);
    printf("  %s: %.2f\n", nomeAtributo(atributo2), valor2_attr2);
    printf("  Soma: %.2f\n\n", soma2);

    // Resultado final
    if (soma1 > soma2) {
        printf("Resultado: %s venceu a rodada!\n", nome1);
    } else if (soma2 > soma1) {
        printf("Resultado: %s venceu a rodada!\n", nome2);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}
