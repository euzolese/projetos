#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_HABILIDADE 5

// Função utilitária para checar se a coordenada está dentro do tabuleiro
int dentroDosLimites(int linha, int coluna) {
    return linha >= 0 && linha < TAMANHO_TABULEIRO && coluna >= 0 && coluna < TAMANHO_TABULEIRO;
}

// Função para inicializar o tabuleiro com água
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Posiciona um exemplo de navios
void posicionarNavios(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    tabuleiro[2][2] = 3;
    tabuleiro[2][3] = 3;
    tabuleiro[2][4] = 3;

    tabuleiro[6][6] = 3;
    tabuleiro[7][6] = 3;
    tabuleiro[8][6] = 3;
}

// Gera matriz Cone (5x5)
void gerarMatrizCone(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            // Condição para formar o cone (pirâmide invertida)
            if (j >= (2 - i) && j <= (2 + i)) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

// Gera matriz Cruz (5x5)
void gerarMatrizCruz(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            // Afeta linha e coluna centrais
            if (i == 2 || j == 2) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

// Gera matriz Octaedro (losango 5x5)
void gerarMatrizOctaedro(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            // Distância de Manhattan ≤ 2 do centro
            if (abs(i - 2) + abs(j - 2) <= 2) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

// Aplica a matriz de habilidade ao tabuleiro no ponto de origem
void aplicarHabilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
                       int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE],
                       int origemLinha, int origemColuna) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (habilidade[i][j] == 1) {
                int linhaTabuleiro = origemLinha - 2 + i;
                int colunaTabuleiro = origemColuna - 2 + j;

                if (dentroDosLimites(linhaTabuleiro, colunaTabuleiro)) {
                    // Só sobrescreve se não for navio
                    if (tabuleiro[linhaTabuleiro][colunaTabuleiro] != 3) {
                        tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5;
                    }
                }
            }
        }
    }
}

// Exibe o tabuleiro final
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\n=== TABULEIRO FINAL ===\n\n   ");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%2d ", j);
    }
    printf("\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d ", i);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            char simbolo;
            switch (tabuleiro[i][j]) {
                case 0: simbolo = '~'; break; // água
                case 3: simbolo = '#'; break; // navio
                case 5: simbolo = '*'; break; // área de habilidade
                default: simbolo = '?';
            }
            printf(" %c ", simbolo);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    inicializarTabuleiro(tabuleiro);
    posicionarNavios(tabuleiro);

    gerarMatrizCone(cone);
    gerarMatrizCruz(cruz);
    gerarMatrizOctaedro(octaedro);

    // Pontos de origem (fixos para este exemplo)
    aplicarHabilidade(tabuleiro, cone, 3, 3);
    aplicarHabilidade(tabuleiro, cruz, 5, 5);
    aplicarHabilidade(tabuleiro, octaedro, 7, 7);

    exibirTabuleiro(tabuleiro);

    return 0;
}
