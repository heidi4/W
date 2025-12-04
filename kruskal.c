#include <stdio.h>

int find(int parent[], int i){ 
    while (parent[i] != i) i = parent[i];
    return i;
}

void unionSet(int parent[], int x, int y){
    parent[y] = x;
}

int main() {
    int n, cost[10][10], parent[10];
    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    for (int i = 0; i < n; i++) parent[i] = i;

    int edges = 0, mincost = 0;

    while (edges < n - 1) {
        int min = 999, a = -1, b = -1;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (find(parent, i) != find(parent, j) && cost[i][j] < min) {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }

        unionSet(parent, find(parent, a), find(parent, b));
        printf("Edge: %d - %d  Cost: %d\n", a, b, min);
        mincost += min;
        edges++;
    }

    printf("Minimum cost = %d\n", mincost);
}