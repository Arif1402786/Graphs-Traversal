#include <stdio.h>
void bfs(int);
int graph[10][10], vertices, visited[10];
int main()
{
    int i, j;
    printf("Enter the total number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the adjacency matrix:\n");
    for (i = 1; i <= vertices; i++)
    {
        for (j = 1; j <= vertices; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    for (i = 1; i <= vertices; i++)
    {
        visited[i] = 0;
    }
    bfs(1);
    return 0;
}
void bfs(int vertex)
{
    int j;
    printf("%d\t", vertex);
    visited[vertex] = 1;
    for(j=1;j<=vertices;j++)
    {
        if(!visited[j] && graph[vertex][j] == 1)
        {
            bfs(j);
        }
    }
}