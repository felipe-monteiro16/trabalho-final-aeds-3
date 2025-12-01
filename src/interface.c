#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "../headers/interface.h"

int getTecla() {
    int ch = getch();
    if (ch == 224) ch = getch() + 1000;
    return ch;
}

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x - 1;
    coord.Y = y - 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void textcolor(int iColor) {
    HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    GetConsoleScreenBufferInfo(hl, &bufferInfo);
    bufferInfo.wAttributes &= 0x00F0;
    SetConsoleTextAttribute(hl, bufferInfo.wAttributes |= iColor);
}

void textbackground(int iColor) {
    HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    GetConsoleScreenBufferInfo(hl, &bufferInfo);
    bufferInfo.wAttributes &= 0x000F;
    SetConsoleTextAttribute(hl, bufferInfo.wAttributes |= (iColor << 4));
}

void Borda(int x, int y, int largura, int altura, int tipo, int sombra) {
    char C[][6] = {"\xda\xbf\xc0\xd9\xc4\xb3",
                   "\xc9\xbb\xc8\xbc\xcd\xba"};
    int i, j;
    gotoxy(x, y);
    printf("%c", C[tipo][0]);
    for(i = 0; i < largura; i++) printf("%c", C[tipo][4]);
    printf("%c", C[tipo][1]);
    for(j = 0; j < altura; j++) {
        gotoxy(x, y+j+1);
        printf("%c", C[tipo][5]);
        for(i = 0; i < largura; i++) printf(" ");
        printf("%c", C[tipo][5]);
        if(sombra) printf("\xb2");
    }
    gotoxy(x, y+altura);
    printf("%c", C[tipo][2]);
    for(i = 0; i < largura; i++) printf("%c", C[tipo][4]);
    printf("%c", C[tipo][3]);
    if(sombra) {
        gotoxy(x+1, y+altura+1);
        for(i = 0; i < largura+2; i++) printf("\xb2");
    }
}

int menu(char opcoes[][50], int Quant, int x[], int y[], int opcao) {
    int i, Tecla;
    textcolor(BLACK);
    textbackground(LIGHT_GRAY);
    for(i=0; i<Quant; i++) {
        gotoxy(x[i], y[i]);
        printf("%s", opcoes[i]);
    }
    do {
        textcolor(BLACK);
        textbackground(WHITE);
        gotoxy(x[opcao], y[opcao]);
        printf("%s", opcoes[opcao]);
        Tecla = getTecla();
        if(Tecla == TEC_ENTER) break;
        textcolor(BLACK);
        textbackground(WHITE);
        gotoxy(x[opcao], y[opcao]);
        printf("%s", opcoes[opcao]);
        if(Tecla == TEC_DIR) opcao++;
        if(Tecla == TEC_ESQ) opcao--;
        if(opcao > Quant-1) opcao = 0;
        if(opcao < 0) opcao = Quant-1;
    } while(Tecla != TEC_ESC);
    return opcao;
}

void TelaPrincipal() {
    system("cls");
    textcolor(BLACK);
    textbackground(LIGHT_GRAY);
    Borda(1,1,110,40,1,0);
    gotoxy(40, 3);
    printf("Projeto Labirinto - BFS");
    gotoxy(50,25);
    printf("Versao 1.0");
    gotoxy(25,27);
    printf("By Felipe Monteiro, Luiz Guilherme, Matheus Vieira e Maria Isabel");
    textcolor(WHITE);
    textbackground(BLACK);
}

void TelaVazia() {
    system("cls");
    textbackground(LIGHT_GRAY);
    Borda(1,1,110,40,1,0);
    textbackground(LIGHT_GRAY);
    textcolor(BLACK);
}
