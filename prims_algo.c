#include <stdio.h>
#include <stdlib.h>

void prims(int n, int cost[10][10]);
int main()
{
    int i, j, n, cost[10][10];
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the Cost adjacency matrix: \n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
            {
                cost[i][j] = 999;
            }
        }
    }
    prims(n, cost);
    return 0;
}
void prims(int n, int cost[10][10])
{
    int i, j, u, v, minCost = 0, min, visited[10], nEdge = 1;
    for (i = 1; i <= n; i++)
    {
        visited[i] = 0; // Unvisited
    }
    printf("Edges considered for MST are: \n");
    visited[1] = 1;
    while (nEdge < n)
    {
        for (i = 1, min = 999; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (cost[i][j] < min)
                {
                    // if (visited[i] == 0)
                    // {
                    //     continue;
                    // }
                    //                    {
                    min = cost[i][j];
                    u = i;
                    v = j;
                    //    }
                }
            }
        }
        if (visited[u] == 0 || visited[v] == 0)
        {
            printf("%d Edge(%d,%d) = %d\n", nEdge++, u, v, min);
            minCost += min;
            visited[v] = 1;
        }
        cost[u][v] = cost[v][u] = 999;
    }
    printf("Minimum Cost of Spanning Tree: %d\n", minCost);
}