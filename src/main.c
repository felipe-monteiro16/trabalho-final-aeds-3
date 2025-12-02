#include <stdio.h>
#include <stdlib.h>
#include "../headers/interface.h"
#include "../headers/labirinto.h"
#include "../headers/solver.h"


void pressEnter() {
    gotoxy(40,35);
    printf("Pressione Enter para continuar...");
    while (getchar() != '\n');
    //getchar();
}


int main() {
    int opcao = 0;
    char opcoes[][50] = {"Abrir arquivo e mostrar labirinto",
                         "Mostrar solucao (BFS)",
                         "Sair"};
    int x[] = {10, 45, 70};
    int y[] = {8, 8, 8};

    Labirinto *meuLabirinto;

    do {
        TelaPrincipal();
        opcao = menu(opcoes, 3, x, y, opcao);
        
        // Mostrar o labirinto apenas
        if(opcao == 0) {
            meuLabirinto = lerLabirinto("labirinto.txt");
            if (meuLabirinto != NULL) {
                TelaVazia();
                for (int i = 0; i < meuLabirinto->linhas; i++) {
                    gotoxy(30, i+5);
                    for (int j = 0; j < meuLabirinto->colunas; j++) {
                        printf("%c ", getCelula(meuLabirinto, i, j));
                    }
                    printf("\n");
                }
            }
            pressEnter();
        }

        // Mostrar a resolução do labirinto com BFS
        if(opcao == 1) {
            meuLabirinto = lerLabirinto("labirinto.txt");
            int* predecessor = bfs(meuLabirinto);
            TelaVazia();
            DisplayShortestPath(predecessor, meuLabirinto);
            pressEnter();
        }
    } while(opcao != 2);
    system("cls");
    //free(meuLabirinto->dados);
    //free(meuLabirinto);
    return 0;
}
