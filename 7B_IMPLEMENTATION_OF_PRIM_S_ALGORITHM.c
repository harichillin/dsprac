#include <stdio.h>

#define INF 9999
#define MAX 10

int main()
{
  int graph[MAX][MAX];
  int selected[MAX];
  int V, i, j, no_edge = 0;
  int x, y;
  int min, cost = 0;

  printf("Enter the number of vertices: ");
  scanf("%d", &V);

  printf("Enter the adjacency matrix:\n");

  for(i = 0; i < V; i++)
  {
    for(j = 0; j < V; j++)
    {
       scanf("%d", &graph[i][j]);

          if(graph[i][j] == 0)
             graph[i][j] = INF;
      }
  }

  for(i = 0; i < V; i++)
    selected[i] = 0;

  selected[0] = 1;

  printf("\nEdges in Minimum Spanning Tree:\n");

  while(no_edge < V - 1)
  {
    min = INF;
    x = 0;
    y = 0;

      for(i = 0; i < V; i++)
      {
        if(selected[i])
        {
           for(j = 0; j < V; j++)
           {
              if(!selected[j] && graph[i][j])
              {
                 if(min > graph[i][j])
                 {
                    min = graph[i][j];
                    x = i;
                    y = j;
                 }
              }
           }
        }
      }

      printf("%d - %d : %d\n", x, y, graph[x][y]);

      cost += graph[x][y];
      selected[y] = 1;

      no_edge++;
  }

  printf("\nMinimum Cost = %d\n", cost);

  return 0;
}
