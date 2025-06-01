#include <stdio.h>

// ==========================
// Função recursiva da Torre
// ==========================
void moverTorre(int casasRestantes) {
    if (casasRestantes == 0) return;
    printf("Direita\n");
    moverTorre(casasRestantes - 1);
}

// ===========================
// Função recursiva da Rainha
// ===========================
void moverRainha(int casasRestantes) {
    if (casasRestantes == 0) return;
    printf("Esquerda\n");
    moverRainha(casasRestantes - 1);
}

// =============================================
// Função recursiva com loops aninhados do Bispo
// =============================================
void moverBispo(int casasRestantes) {
    if (casasRestantes == 0) return;

    // Loop externo (vertical)
    for (int linha = 0; linha < 1; linha++) {
        // Loop interno (horizontal)
        for (int coluna = 0; coluna < 1; coluna++) {
            printf("Cima Direita\n");
        }
    }

    moverBispo(casasRestantes - 1);
}

// ============================================
// Movimento complexo do Cavalo com loops aninhados
// ============================================
void moverCavalo() {
    int movimentosVerticais = 2;
    int movimentosHorizontais = 1;
    int contadorV = 0;

    printf("Movimento do Cavalo:\n");

    // Loop externo: movimento para cima (2 vezes)
    for (int i = 0; i < 3; i++) {
        if (i >= movimentosVerticais) {
            break; // já moveu o suficiente para cima
        }

        // condição de controle de fluxo
        if (i == 1) {
            printf("Cima\n");
            continue;
        }

        printf("Cima\n");
        contadorV++;
    }

    // Loop interno: movimento para a direita (1 vez)
    for (int j = 0; j < 2; j++) {
        if (j == movimentosHorizontais) {
            break;
        }

        if (j == 0) {
            printf("Direita\n");
        }
    }
}

int main() {
    // ========================
    // Movimento da TORRE
    // ========================
    int casasTorre = 5;
    printf("Movimento da Torre:\n");
    moverTorre(casasTorre);

    printf("\n");

    // ========================
    // Movimento do BISPO
    // ========================
    int casasBispo = 5;
    printf("Movimento do Bispo:\n");
    moverBispo(casasBispo);

    printf("\n");

    // ========================
    // Movimento da RAINHA
    // ========================
    int casasRainha = 8;
    printf("Movimento da Rainha:\n");
    moverRainha(casasRainha);

    printf("\n");

    // ========================
    // Movimento do CAVALO
    // ========================
    moverCavalo();

    return 0;
}
