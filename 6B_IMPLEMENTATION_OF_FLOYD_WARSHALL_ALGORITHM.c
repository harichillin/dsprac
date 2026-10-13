#include <stdio.h>

#include <limits.h>

#define MAX 10

#define INF 99999

int dist[MAX][MAX];

int V;

void floydWarshall() {

    for (int k = 0; k < V; k++) {

        for (int i = 0; i < V; i++) {

            for (int j = 0; j < V; j++) {

                if (dist[i][k] != INF &&

                    dist[k][j] != INF &&

                    dist[i][k] + dist[k][j] < dist[i][j]) {

                    dist[i][j] = dist[i][k] + dist[k][j];

                }

            }

        }

    }

}

void displayMatrix(char* title) {

    printf("\n%s\n", title);

    printf("         ");

    for (int i = 0; i < V; i++)

        printf("%6d", i);

    printf("\n             ");

    for (int i = 0; i < V; i++)

         printf("------");

    printf("\n");

    for (int i = 0; i < V; i++) {

         printf("%4d |", i);

         for (int j = 0; j < V; j++) {

             if (dist[i][j] == INF)

               printf("%6s", "INF");

             else

               printf("%6d", dist[i][j]);

         }

         printf("\n");

    }

}

int main() {

    V = 4;

    // Input graph adjacency matrix

    // INF = no direct edge, 0 = self loop

    int graph[4][4] = {

         { 0, 3, INF, 7},

         { 8, 0, 2, INF},

         { 5, INF, 0, 1},

         { 2, INF, INF, 0}

    };

    // Copy graph into dist matrix

    for (int i = 0; i < V; i++)

         for (int j = 0; j < V; j++)

             dist[i][j] = graph[i][j];

    displayMatrix("Initial Distance Matrix:");

    floydWarshall();

    displayMatrix("Shortest Distance Matrix (After Floyd Warshall):");

    printf("\nShortest Path between all pairs:\n");

    printf("------------------------------------------\n");

    printf("Source\tDest\tShortest Distance\n");

    printf("------------------------------------------\n");

    for (int i = 0; i < V; i++) {

        for (int j = 0; j < V; j++) {

            if (i != j) {

                printf(" %d \t %d \t", i, j);

                if (dist[i][j] == INF)

                  printf("Unreachable\n");

                else

                  printf("%d\n", dist[i][j]);

            }

        }

    }

    printf("------------------------------------------\n");

    return 0;

}
