#include <stdio.h>

int main() {
    // ========================
    // Movimento da TORRE
    // ========================
    int movimentoTorre = 5;

    printf("Movimento da Torre:\n");
    for (int i = 1; i <= movimentoTorre; i++) {
        printf("Direita\n");
    }

    printf("\n");

    // ========================
    // Movimento do BISPO
    // ========================
    int movimentoBispo = 5;
    int contadorBispo = 0;

    printf("Movimento do Bispo:\n");
    while (contadorBispo < movimentoBispo) {
        printf("Cima Direita\n");
        contadorBispo++;
    }

    printf("\n");

    // ========================
    // Movimento da RAINHA
    // ========================
    int movimentoRainha = 8;
    int contadorRainha = 0;

    printf("Movimento da Rainha:\n");
    do {
        printf("Esquerda\n");
        contadorRainha++;
    } while (contadorRainha < movimentoRainha);

    printf("\n");

    // ========================
    // Movimento do CAVALO
    // ========================
    int movimentoVertical = 2; // Baixo
    int movimentoHorizontal = 1; // Esquerda

    printf("Movimento do Cavalo:\n");

    // Loop externo (obrigatoriamente um 'for') – movimento para baixo
    for (int i = 0; i < movimentoVertical; i++) {
        printf("Baixo\n");
    }

    // Loop interno (usando 'while') – movimento para a esquerda
    int j = 0;
    while (j < movimentoHorizontal) {
        printf("Esquerda\n");
        j++;
    }

    return 0;
}
