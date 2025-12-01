# Solucionador de Labirintos com Busca em Grafos

## Objetivo
Modelar um labirinto (lido de um arquivo) como um grafo e usar a Busca em Largura (BFS) para encontrar e exibir o caminho mais curto entre a entrada e a saída.

## Pré-requisitos (Windows)
**Atenção:** Este projeto foi desenvolvido para rodar **exclusivamente no Windows**, devido ao uso de bibliotecas específicas do sistema (`windows.h`, `conio.h`).

Você precisa ter o compilador **GCC** e o **Make** instalados:

* **GCC (MinGW):** Siga este guia: [Como instalar GCC no Windows](https://dev.to/gamegods3/how-to-install-gcc-in-windows-10-the-easier-way-422j)
* **Make:** Abra o terminal (PowerShell ou CMD) e execute:
    ```cmd
    winget install -e --id ezwinports.make
    ```

## Como Executar
Em um terminal no local onde deseja baixar o projeto:

```bash
git clone https://github.com/felipe-monteiro16/trabalho-final-aeds-3.git
cd trabalho-final-aeds-3
make
program.exe