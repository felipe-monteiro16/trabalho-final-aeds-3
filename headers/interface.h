#ifndef INTERFACE_H
#define INTERFACE_H

#define TEC_ESC 27
#define TEC_ENTER 13
#define TEC_DIR 1077
#define TEC_ESQ 1075
#define TEC_CIMA 1072
#define TEC_BAIXO 1080

#define BLACK 0
#define WHITE 15
#define LIGHT_GRAY 7
#define DARK_GRAY 8

int getTecla();
void gotoxy(int x, int y);
void textcolor(int iColor);
void textbackground(int iColor);
void Borda(int x, int y, int largura, int altura, int tipo, int sombra);

int menu(char opcoes[][50], int Quant, int x[], int y[], int opcao);

void TelaPrincipal();
void TelaVazia();

#endif
