#include <stdio.h>
#include <stdlib.h>
#include "aeroportos.h"

int main() {
    int numAeroportos = 2939;
    struct Grafo* grafo = criaGrafo(numAeroportos);
    FILE *f;
    int origem, destino;

    f = fopen("openflights.csv", "r");
    if (!f) {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    // Leitura CSV com validação
    while (fscanf(f, "%d;%d;", &origem, &destino) == 2) {
        if(origem >= 0 && origem < numAeroportos && destino >= 0 && destino < numAeroportos)
            addAresta(grafo, origem, destino);
    }

    fclose(f);

    int escolha, aeroporto1, aeroporto2;

    do {
        printf("\nMenu:\n");
        printf("1. Imprimir todas as rotas\n");
        printf("2. Verificar se dois aeroportos tem rota entre si\n");
        printf("3. Imprimir as rotas de um aeroporto\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &escolha) != 1) {
            printf("Entrada invalida!\n");
            while(getchar() != '\n'); // limpa buffer
            continue;
        }

        switch (escolha) {
            case 1:
                printGrafo(grafo);
                break;
            case 2:
                printf("Digite o numero do primeiro aeroporto: ");
                scanf("%d", &aeroporto1);
                printf("Digite o numero do segundo aeroporto: ");
                scanf("%d", &aeroporto2);

                if (rotasAeroportos(grafo, aeroporto1, aeroporto2))
                    printf("Os aeroportos %d e %d possuem rotas entre si.\n", aeroporto1, aeroporto2);
                else
                    printf("Os aeroportos %d e %d nao possuem rotas entre si.\n", aeroporto1, aeroporto2);
                break;
            case 3:
                printf("Digite o numero do aeroporto que deseja imprimir: ");
                scanf("%d", &aeroporto1);
                printArestasAeroporto(grafo, aeroporto1);
                break;
            case 4:
                printf("Encerrando o programa\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (escolha != 4);

    freeGrafo(grafo);
    return 0;
}