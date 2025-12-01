#ifndef LABIRINTO_H
#define LABIRINTO_H

typedef struct {
    int linhas;
    int colunas;
    char *dados;
    int inicio_idx;
    int fim_idx;
} Labirinto;

Labirinto* lerLabirinto(const char *caminhoArquivo);
char getCelula(Labirinto *lab, int linha, int coluna);


#endif
