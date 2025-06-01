#include <stdio.h>

int main() {
    // ========================
    // Simulação do movimento da Torre
    // ========================
    int movimentoTorre = 5; // Número de casas para a direita

    printf("Movimento da Torre:\n");
    // Usando estrutura de repetição for
    for (int i = 1; i <= movimentoTorre; i++) {
        printf("Direita\n"); // A torre se move apenas na horizontal (ou vertical)
    }

    printf("\n"); // Espaço entre as seções

    // ========================
    // Simulação do movimento do Bispo
    // ========================
    int movimentoBispo = 5; // Número de casas na diagonal superior direita
    int contadorBispo = 0; // Contador de passos

    printf("Movimento do Bispo:\n");
    // Usando estrutura de repetição while
    while (contadorBispo < movimentoBispo) {
        printf("Cima Direita\n"); // Bispo se move em diagonal
        contadorBispo++;
    }

    printf("\n");

    // ========================
    // Simulação do movimento da Rainha
    // ========================
    int movimentoRainha = 8; // Número de casas para a esquerda
    int contadorRainha = 0;

    printf("Movimento da Rainha:\n");
    // Usando estrutura de repetição do-while
    do {
        printf("Esquerda\n"); // Rainha se move em qualquer direção
        contadorRainha++;
    } while (contadorRainha < movimentoRainha);

    return 0;
}
