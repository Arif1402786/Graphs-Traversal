#include <stdio.h>
#include <stdlib.h>
void dfs(int);
int graph[10][10], vertices, visited[10];
int arr[30];
static int k = 0,count = 0;
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
    dfs(1);
    return 0;
}

void dfs(int vertex)
{
    int j, c = 0;
    count++;
    printf("%d\t", vertex);
    visited[vertex] = 1;
    for (j = 1; j <= vertices; j++)
    {
        if (!visited[j] && graph[vertex][j] == 1)
        {
            arr[++k] = j;
            c = 1;
        }
        if(count== vertices)
        {
            exit(0);
        }
    }
    if (c == 1)
    {
        dfs(arr[k]);
    }
    else
    {
        k--;
        dfs(arr[k]);
    }
}