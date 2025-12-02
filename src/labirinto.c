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

    // Lê as dimensões
    if (fscanf(arquivo, "%d %d", &lab->linhas, &lab->colunas) != 2) {
        printf("Erro: Formato de dimensoes invalido.\n");
        free(lab);
        fclose(arquivo);
        return NULL;
    }

    // Pula qualquer coisa (espaço ou newline) até achar o primeiro caractere útil do labirinto
    char temp;
    while ((temp = fgetc(arquivo)) != EOF && (temp == '\n' || temp == '\r' || temp == ' '));
    ungetc(temp, arquivo);

    int totalCelulas = lab->linhas * lab->colunas;
    lab->dados = (char*) malloc(totalCelulas * sizeof(char));

    if (lab->dados == NULL) {
        printf("Erro: Memoria insuficiente.\n");
        free(lab);
        fclose(arquivo);
        return NULL;
    }

    int i = 0;
    int c;
    while (i < totalCelulas && (c = fgetc(arquivo)) != EOF) {
        // Agora ignoramos também o ESPAÇO (' '), pois seu labirinto usa '.' como caminho
        // e ' ' apenas para separar visualmente as colunas.
        if (c == '\n' || c == '\r' || c == ' ') {
            continue;
        }

        lab->dados[i] = (char)c;

        if (c == 'S') lab->inicio_idx = i;
        if (c == 'E') lab->fim_idx = i;

        i++;
    }

    if (i != totalCelulas) {
        printf("Aviso: Dimensoes erradas. Esperado %d celulas, lido %d.\n", totalCelulas, i);
    }

    fclose(arquivo);
    return lab;
}

char getCelula(Labirinto *lab, int linha, int coluna) {
    if (linha < 0 || linha >= lab->linhas || coluna < 0 || coluna >= lab->colunas) {
        return '#'; // Retorna parede se sair dos limites
    }
    return lab->dados[(linha * lab->colunas) + coluna];
}