#ifndef AEROPORTOS_H
#define AEROPORTOS_H

struct No;
struct Grafo;
struct No* criaNo(int vizinho);
struct Grafo* criaGrafo(int numAeroportos);
void addAresta(struct Grafo* grafo, int origem, int destino);
void printGrafo(struct Grafo* grafo);
void printArestasAeroporto(struct Grafo* grafo, int aeroportoDesejado);
int rotasAeroportos(struct Grafo* grafo, int aeroporto1, int aeroporto2);
void freeGrafo(struct Grafo* grafo);

#endif
