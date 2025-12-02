#ifndef SOLVER_H
#define SOLVER_H
#include "labirinto.h"

typedef struct node {
    int data;
    struct node* next;
} node;


typedef struct queue {
    node* top;
} queue;


int* bfs(Labirinto* graph);
void DisplayShortestPath(int* predecessor, Labirinto* lab);


#endif