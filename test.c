#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INFINITY 999

int n;

bool *S;

void Initialize(int **cost) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cost[i][j] = INFINITY;
        }
    }
}

void SingleSource(int **cost, int *dist, int v) {
    for (int i = 1; i <= n; i++) {
        S[i] = false;
        dist[i] = cost[v][i]; // Initialize distance from source to each vertex
    }
    S[v] = true;
    dist[v] = 0;  // Distance to source itself is 0

    for (int num = 2; num <= n; num++) {
        int min = INFINITY;
        int u;
        for (int i = 1; i <= n; i++) {
            if (!S[i] && dist[i] < min) {  // Use !S[i] for clarity (not S[i]==false)
                min = dist[i];
                u = i;
            }
        }
        S[u] = true;

        for (int w = 1; w <= n; w++) {
            if (!S[w] && cost[u][w] != INFINITY && dist[w] > dist[u] + cost[u][w]) {
                dist[w] = dist[u] + cost[u][w];
            }
        }
    }
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int **cost = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++) {
        cost[i] = (int *)malloc((n + 1) * sizeof(int));
    }

    int *dist = (int *)malloc((n + 1) * sizeof(int));
    S = (bool *)malloc((n + 1) * sizeof(bool));

    Initialize(cost);

    int maxedges = n * (n - 1);
    int origin, destin, tempcost;

    printf("Enter the edges in the [source, destination, cost] format (-1, -1, -1) to quit:\n");
    for (int i = 1; i <= maxedges; i++) {
        scanf("%d %d %d", &origin, &destin, &tempcost);
        if (origin == -1 && destin == -1 && tempcost == -1) {
            break;
        } else if (origin < 1 || origin > n || destin < 1 || destin > n) {
            printf("\nInvalid edge. Please re-enter the edge.\n");
            i--; // Decrement i to avoid skipping an edge due to invalid input
        } else {
            cost[origin][destin] = tempcost;
            cost[destin][origin] = tempcost; // Add for undirected graph
        }
    }

    printf("Adjacency Matrix for the given graph is:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%4d ", cost[i][j]);
        }
        printf("\n");
    }

    SingleSource(cost, dist, 1); // Assuming source vertex is 1

    printf("Displaying the shortest path array:\n");
    for (int i = 1; i <= n; i++) {
        printf("%d --> %d\n", i, dist[i]);
    }

    free(cost);  // Deallocate memory for 2D array
    free(dist);
    free(S);

    return 0;
}
