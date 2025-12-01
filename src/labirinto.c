#include <stdio.h>
#include <stdlib.h>
#include "../headers/labirinto.h"

Labirinto* lerLabirinto(const char *caminhoArquivo) {
    FILE *arquivo = fopen(caminhoArquivo, "r");

    if (arquivo == NULL) {
        printf("Erro: Arquivo '%s' nao encontrado.\n", caminhoArquivo);
        return NULL;
    }

    Labirinto *lab = (Labirinto*) malloc(sizeof(Labirinto));

    if (fscanf(arquivo, "%d %d", &lab->linhas, &lab->colunas) != 2) {
        printf("Erro: Formato de dimensoes invalido.\n");
        free(lab);
        fclose(arquivo);
        return NULL;
    }

    int totalCelulas = lab->linhas * lab->colunas;
    lab->dados = (char*) malloc(totalCelulas * sizeof(char));

    if (lab->dados == NULL) {
        printf("Erro: Memoria insuficiente.\n");
        free(lab);
        fclose(arquivo);
        return NULL;
    }

    char caractereLido;
    int celulasLidas = 0;

    for (int i = 0; i < totalCelulas; i++) {
        if (fscanf(arquivo, " %c", &caractereLido) == 1) {
            lab->dados[i] = caractereLido;

            if (caractereLido == 'E') lab->inicio_idx = i;
            if (caractereLido == 'S') lab->fim_idx = i;

            celulasLidas++;
        }
    }

    if (celulasLidas != totalCelulas) {
        printf("Aviso: O numero de celulas lidas nao bate com as dimensoes.\n");
    }

    fclose(arquivo);
    return lab;
}

char getCelula(Labirinto *lab, int linha, int coluna) {
    if (linha < 0 || linha >= lab->linhas || coluna < 0 || coluna >= lab->colunas) {
        return '#';
    }
    return lab->dados[(linha * lab->colunas) + coluna];
}