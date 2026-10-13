#include <stdio.h>
#define MAX 10
int graph[MAX][MAX];
int visited[MAX];
int n;
void DFS(int vertex)
{
  int i;
  visited[vertex] = 1;
  printf("%d ", vertex);
  for(i = 0; i < n; i++)
  {
     if(graph[vertex][i] == 1 && visited[i] == 0)
     {
         DFS(i);
     }
  }
}
int main()
{
  int i, j, start;
  printf("Enter the number of vertices: ");
  scanf("%d", &n);
  printf("Enter the adjacency matrix:\n");

  for(i = 0; i < n; i++)

  {

      for(j = 0; j < n; j++)
      {
        scanf("%d", &graph[i][j]);
      }
  }
  for(i = 0; i < n; i++)
  {
    visited[i] = 0;
  }
  printf("Enter the starting vertex: ");
  scanf("%d", &start);
  printf("DFS Traversal: ");

  DFS(start);
  printf("\n");
  return 0;
}
