#include <stdio.h>
#include "../headers/interface.h"

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
            //Chama a função para abrir o arquivo e mostrar o labirinto
        }
        if(opcao == 1) {
            //Chama a função para resolver o labirinto com BFS
        }
    } while(opcao != 2);

    return 0;
}
