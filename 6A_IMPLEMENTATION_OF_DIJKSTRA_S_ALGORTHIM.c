#include <stdio.h>

#include <limits.h>

#define MAX 10

int graph[MAX][MAX];

int dist[MAX];

int visited[MAX];

int V;

// Find the unvisited vertex with minimum distance

int minDistance() {

    int min = INT_MAX, minIndex = -1;

    for (int v = 0; v < V; v++) {

        if (!visited[v] && dist[v] <= min) {

            min = dist[v];

            minIndex = v;

        }

    }

    return minIndex;

}

void dijkstra(int src) {

    // Initialize distances and visited array

    for (int i = 0; i < V; i++) {

        dist[i] = INT_MAX;

        visited[i] = 0;

    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {

        int u = minDistance();

        if (u == -1) break;

        visited[u] = 1;

        for (int v = 0; v < V; v++) {

            if (!visited[v] &&

                graph[u][v] &&

                dist[u] != INT_MAX &&

                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];

            }

        }

    }

}

void display(int src) {

    printf("\nShortest distances from source vertex %d:\n", src);

    printf("----------------------------------\n");

    printf("Vertex\t\tDistance\n");

    printf("----------------------------------\n");

    for (int i = 0; i < V; i++) {

        printf(" %d\t\t", i);

        if (dist[i] == INT_MAX)

            printf("Unreachable\n");

        else

            printf("%d\n", dist[i]);

    }

    printf("----------------------------------\n");

}

int main() {

  V = 5;

  // Graph represented as adjacency matrix

  // 0 = no edge

  int g[5][5] = {

       {0, 10, 0, 0, 5},

       {10, 0, 1, 0, 2},

       {0, 1, 0, 4, 0},

       {0, 0, 4, 0, 0},

       {5, 2, 0, 0, 0}

  };

  for (int i = 0; i < V; i++)

       for (int j = 0; j < V; j++)

         graph[i][j] = g[i][j];

  printf("Adjacency Matrix:\n");

  printf("      ");

  for (int i = 0; i < V; i++)

       printf("%4d", i);

  printf("\n");

  for (int i = 0; i < V; i++) {

       printf("%4d ", i);

       for (int j = 0; j < V; j++)

         printf("%4d", graph[i][j]);

       printf("\n");

  }

  int src = 0;

  dijkstra(src);

  display(src);

  return 0; }
