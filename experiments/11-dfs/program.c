#include <stdio.h>

int adj[20][20], visited[20];
int n;

void DFS(int v)
{
    int j;
    visited[v] = 1;
    printf("%d ", v);

    for (j = 0; j < n; j++)
    {
        if (adj[v][j] == 1 && visited[j] == 0)
        {
            DFS(j);
        }
    }
}

int main()
{
    int i, j, start;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%1d", &adj[i][j]);
        }
    }

    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("Enter the starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    printf("DFS Traversal: ");
    DFS(start);
    printf("\n");

    return 0;
}
