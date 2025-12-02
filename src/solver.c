#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../headers/solver.h"
#include "../headers/interface.h"


int count;

///////////////////////////////////////////////////
// QUEUE FUNCIONS
///////////////////////////////////////////////////


queue* createQueue() {
    queue* newQueue = (queue*)malloc(sizeof(queue));
    newQueue->top = NULL;
    return newQueue;
}


bool isEmpty(queue* q) {
    return (q->top == NULL);
}


void enqueue(queue* q, int value) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = value;
    newNode->next = NULL;

    if(isEmpty(q)) {
        q->top = newNode;
        return;
    }
    node* current = q->top;
    while(current->next) {
        current = current->next;
    }
    current->next = newNode;
}


int dequeue(queue* q) {
    if(isEmpty(q)) {
        return -1;
    }
    node* temp = q->top;
    q->top = temp->next;
    int poppedValue = temp->data;
    free(temp);
    return poppedValue;
}


void displayQueue(queue* q) {
    if(isEmpty(q)) {
        return;
    }
    node* current = q->top;
    while(current) {
        printf("%d ", current->data);
        current = current->next;
    }
}


///////////////////////////////////////////////////
// ADJACENCY MATRIX FUNCTIONS
///////////////////////////////////////////////////


int* bfs(Labirinto* graph) {
    int size = graph->colunas * graph-> linhas;

    int* predecessor = (int*)malloc(size * sizeof(int));
    for(int k=0; k<size; k++) predecessor[k] = -1;

    int* visitedArray = (int*)calloc(size, sizeof(int));
    int visitedVertex, neighbourIndex, i;
    queue* q = createQueue();

    // calling start vertex
    enqueue(q, graph->inicio_idx);
    predecessor[graph->inicio_idx] = -1; // start has no dad
    visitedArray[graph->inicio_idx] = 1;

    // Visiting vertexes
    while(!isEmpty(q)) {
        // show visited
        visitedVertex = dequeue(q);
        
        // early exit
        if (visitedVertex == graph->fim_idx) {
            free(visitedArray);
            return predecessor;
        }

        // view the neighbours
        for(i = 0; i < 4; i++) {
            neighbourIndex = -1; // Reseta para garantir que nao usa lixo da iteracao anterior

            switch(i) {
                case 0: // CIMA
                    if(visitedVertex - graph->colunas >= 0) {
                        neighbourIndex = visitedVertex - graph->colunas;
                    }
                    break;
                case 1: // BAIXO
                    if(visitedVertex + graph->colunas < size) {
                        neighbourIndex = visitedVertex + graph->colunas;
                    }
                    break;
                case 2: // ESQUERDA
                    if(visitedVertex % graph->colunas != 0) {
                        neighbourIndex = visitedVertex - 1;
                    }
                    break;
                case 3: // DIREITA
                    if((visitedVertex + 1) % graph->colunas != 0) {
                        neighbourIndex = visitedVertex + 1;
                    }
                    break;
            }

            // SO EXECUTA SE UM VIZINHO VALIDO FOI ENCONTRADO
            if (neighbourIndex != -1) {
                // Verifica se eh caminho (assumindo que 1 eh caminho livre) E nao visitado
                // CUIDADO: Se 0 for parede e 1 for caminho, ok. Se for char, use aspas ex: ' ' ou '1'
                if(graph->dados[neighbourIndex] != '#' && visitedArray[neighbourIndex] == 0) {
                    visitedArray[neighbourIndex] = 1;
                    predecessor[neighbourIndex] = visitedVertex;
                    enqueue(q, neighbourIndex);
                }
            }
        }
    }
    free(visitedArray);
    return predecessor;
}


void DisplayShortestPath(int* predecessor, Labirinto* lab) {
    int targetNode = lab->fim_idx;

    // Se o alvo nao tem pai (e nao eh o inicio), nao existe caminho
    if (predecessor[targetNode] == -1 && targetNode != lab->inicio_idx) {
        gotoxy(40,20);
        printf("Caminho nao encontrado!\n");
        return;
    }

    // 1. Criar uma cópia do mapa para não alterar o original
    int size = lab->linhas * lab->colunas;
    char* mapaSolucao = (char*)malloc(size * sizeof(char));
    
    // Copia os dados originais
    for (int i = 0; i < size; i++) {
        mapaSolucao[i] = lab->dados[i];
    }

    // 2. Reconstrói o caminho de trás para frente marcando com 'O'
    int current = targetNode;
    while (current != -1) {
        // Se não for Inicio nem Fim, marca com o símbolo desejado
        if (current != lab->inicio_idx && current != lab->fim_idx) {
            mapaSolucao[current] = 'O';
            count++;
        }
        current = predecessor[current];
    }

    // 3. Imprime o labirinto formatado com a solução
    for (int i = 0; i < lab->linhas; i++) {
        gotoxy(30, i+5);
        for (int j = 0; j < lab->colunas; j++) {
            // Imprime o caractere correspondente do mapa modificado
            printf("%c ", mapaSolucao[i * lab->colunas + j]);
        }
        printf("\n");
    }
    gotoxy(40, 33);
    printf("Numero de Passos: %d", count+1);
    
    free(mapaSolucao); // Libera a memória da cópia
}