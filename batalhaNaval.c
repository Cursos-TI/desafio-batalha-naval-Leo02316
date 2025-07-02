#include <stdio.h>

#define TAM 10
#define NAVIO_TAM 3
#define NUM_NAVIOS 2

// Representação do tabuleiro
char tabuleiro[TAM][TAM];

// Estrutura para um navio
typedef struct {
    int x; // linha
    int y; // coluna
    int horizontal; // 1 = horizontal, 0 = vertical
} Navio;

// Lista de navios com posições fixas
Navio navios[NUM_NAVIOS] = {
    {0, 0, 1}, // Navio 1: horizontal a partir de (0,0)
    {2, 5, 0}, // Navio 2: vertical a partir de (2,5)
};

// Inicializa o tabuleiro com '~' (água)
void inicializar_tabuleiro() {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = '~';
        }
    }
}

// Posiciona os navios no tabuleiro com marcação 'N'
void posicionar_navios() {
    for (int i = 0; i < NUM_NAVIOS; i++) {
        Navio n = navios[i];
        for (int j = 0; j < NAVIO_TAM; j++) {
            int x = n.x + (n.horizontal ? 0 : j);
            int y = n.y + (n.horizontal ? j : 0);
            // Simples verificação se dentro dos limites
            if (x < TAM && y < TAM) {
                tabuleiro[x][y] = 'N';
            }
        }
    }
}

// Exibe o tabuleiro
void imprimir_tabuleiro() {
    printf("   ");
    for (int j = 0; j < TAM; j++) {
        printf("%2d", j);
    }
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%2d ", i);
        for (int j = 0; j < TAM; j++) {
            printf(" %c", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    inicializar_tabuleiro();
    posicionar_navios();
    imprimir_tabuleiro();
    return 0;
}