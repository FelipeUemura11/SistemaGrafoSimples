#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTICES 100

typedef struct No{
    int vertice;
    struct No *prox;
}No;

typedef struct Grafo{
    int numVertices;
    No *adjList[MAX_VERTICES];
}Grafo;

No *criarNo(int v){
    No *novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }
    novoNo->vertice = v;
    novoNo->prox = NULL;
    return novoNo;
}

Grafo *criarGrafo(int vertices){
    if (vertices <= 0 || vertices > MAX_VERTICES) {
        printf("Numero de vertices invalido! Deve estar entre 1 e %i\n", MAX_VERTICES);
        exit(1);
    }
    
    Grafo *g = (Grafo*)malloc(sizeof(Grafo));
    if (g == NULL) {
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }
    
    g->numVertices = vertices;
    for(int i = 0; i < vertices; i++){
        g->adjList[i] = NULL;
    }
    return g;
}

void addAresta(Grafo *g, int origem, int destino){
    if (origem < 0 || origem >= g->numVertices || 
        destino < 0 || destino >= g->numVertices) {
        printf("Vertices invalidos! Deve estar entre 0 e %i\n", g->numVertices - 1);
        return;
    }

    No *novoNo = criarNo(destino);
    novoNo->prox = g->adjList[origem];
    g->adjList[origem] = novoNo;

    novoNo = criarNo(origem);
    novoNo->prox = g->adjList[destino];
    g->adjList[destino] = novoNo;
}

void printGrafo(Grafo *g){
    printf("\nRepresentacao do grafo:\n");
    printf("=====================\n");
    for(int i = 0; i < g->numVertices; i++){
        printf("Vertice %i: ", i);
        No *temp = g->adjList[i];
        while(temp){
            printf("%i -> ", temp->vertice);
            temp = temp->prox;
        }
        printf("NULL\n");
    }
    printf("=====================\n");
}

void liberarGrafo(Grafo *g) {
    for(int i = 0; i < g->numVertices; i++) {
        No *atual = g->adjList[i];
        while(atual) {
            No *temp = atual;
            atual = atual->prox;
            free(temp);
        }
    }
    free(g);
}

int main(void){

    int vertices = 6;
    printf("Criando grafo com %d vertices...\n", vertices);
    Grafo *g = criarGrafo(vertices);
    
    printf("\nAdicionando arestas predefinidas...\n");
    
    addAresta(g, 0, 1);  // Conecta vertice 0 ao 1
    addAresta(g, 0, 2);  // Conecta vertice 0 ao 2
    addAresta(g, 1, 3);  // Conecta vertice 1 ao 3
    addAresta(g, 2, 3);  // Conecta vertice 2 ao 3
    addAresta(g, 3, 4);  // Conecta vertice 3 ao 4
    addAresta(g, 4, 5);  // Conecta vertice 4 ao 5
    
    printf("\nEstrutura do grafo criado:\n");
    printf("0 -- 1 -- 3 -- 4 -- 5\n");
    printf("|    |\n");
    printf("2 -- 3\n");
    
    printGrafo(g);
    liberarGrafo(g);
    return 0;
}
