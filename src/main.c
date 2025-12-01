#include <stdio.h>
#include <stdlib.h>
#include "../headers/interface.h"
#include "../headers/labirinto.h"


void pressEnter() {
    printf("\n\nPressione Enter para continuar...");
    while (getchar() != '\n');
    //getchar();
}


int main() {
    int opcao = 0;
    char opcoes[][50] = {"Abrir arquivo e mostrar labirinto",
                         "Mostrar solucao (BFS)",
                         "Sair"};
    int x[] = {10, 10, 10};
    int y[] = {8, 10, 12};

   
    do {
        TelaPrincipal();
        opcao = menu(opcoes, 3, x, y, opcao);
        if(opcao == 0) {
            Labirinto *meuLabirinto = lerLabirinto("labirinto.txt");

            if (meuLabirinto != NULL) {
                //printf("Labirinto carregado: %d x %d\n", meuLabirinto->linhas, meuLabirinto->colunas);

                TelaVazia();
                for (int i = 0; i < meuLabirinto->linhas; i++) {
                    gotoxy(30, i+5);
                    for (int j = 0; j < meuLabirinto->colunas; j++) {
                        printf("%c ", getCelula(meuLabirinto, i, j));
                    }
                    printf("\n");
                }
                free(meuLabirinto->dados);
                free(meuLabirinto);
            }
            pressEnter();
        }
        if(opcao == 1) {
            //Chama a função para resolver o labirinto com BFS
        }
    } while(opcao != 2);

    return 0;
}
