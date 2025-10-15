#include <stdio.h>
#include <stdlib.h>
#include "aeroportos.h"

struct No {
    int rota;
    struct No* prox;
};

struct Grafo {
    int numAeroportos;            
    struct No** aresta;
};

struct No* criaNo(int rota) {
    struct No* newNode = (struct No*)malloc(sizeof(struct No));
    newNode->rota = rota;
    newNode->prox = NULL;
    return newNode;
}

struct Grafo* criaGrafo(int numAeroportos) {
    struct Grafo* grafo = (struct Grafo*)malloc(sizeof(struct Grafo));
    grafo->numAeroportos = numAeroportos;
    grafo->aresta = (struct No**)malloc(numAeroportos * sizeof(struct No*));

    for (int i = 0; i < numAeroportos; i++) {
        grafo->aresta[i] = NULL;
    }

    return grafo;
}


void addAresta(struct Grafo* grafo, int origem, int destino) {
    // Checa se destino já está na lista de origem
    struct No* temp = grafo->aresta[origem];
    while(temp) {
        if(temp->rota == destino)
            return; // já existe, não adiciona duplicado
        temp = temp->prox;
    }

    struct No* newNode = criaNo(destino);
    newNode->prox = grafo->aresta[origem];
    grafo->aresta[origem] = newNode;

    temp = grafo->aresta[destino];
    while(temp) {
        if(temp->rota == origem)
            return; // já existe
        temp = temp->prox;
    }
    newNode = criaNo(origem);
    newNode->prox = grafo->aresta[destino];
    grafo->aresta[destino] = newNode;
}


void printGrafo(struct Grafo* grafo) {
    for (int a = 0; a < grafo->numAeroportos; a++) {
        struct No* temp = grafo->aresta[a];
        printf("Rotas do aeroporto %d: ", a);

        while (temp) {
            printf("%d", temp->rota);
            if (temp->prox)
                printf(", ");
            temp = temp->prox;
        }

        printf("\n");
    }
}

void printArestasAeroporto(struct Grafo* grafo, int aeroportoDesejado) {
    if (aeroportoDesejado < 0 || aeroportoDesejado >= grafo->numAeroportos) {
        printf("Aeroporto inválido\n");
        return;
    }

    struct No* temp = grafo->aresta[aeroportoDesejado];
    printf("Rotas do aeroporto %d: ", aeroportoDesejado);

    int primeiro = 1;
    while (temp) {
        if (!primeiro)
            printf(", ");
        printf("%d", temp->rota);
        primeiro = 0;
        temp = temp->prox;
    }
    printf("\n");
}

int rotasAeroportos(struct Grafo* grafo, int aeroporto1, int aeroporto2) {
    if (aeroporto1 < 0 || aeroporto1 >= grafo->numAeroportos || aeroporto2 < 0 || aeroporto2 >= grafo->numAeroportos)
        return 0;

    struct No* temp = grafo->aresta[aeroporto1];
    while (temp) {
        if (temp->rota == aeroporto2) return 1;
        temp = temp->prox;
    }
    return 0;
}

void freeGrafo(struct Grafo* grafo) {
    if (!grafo) return;

    for (int i = 0; i < grafo->numAeroportos; i++) {
        struct No* temp = grafo->aresta[i];
        while (temp) {
            struct No* aux = temp;
            temp = temp->prox;
            free(aux);
        }
    }

    free(grafo->aresta);
    free(grafo);
}
