#include <stdio.h>
#include <stdlib.h>

struct Edge{
    int source;
    int destination;
    int weight;
};

int parent[100];
struct Edge edges[100];

int find(int i){
   
    while(parent[i]>=0)
    i=parent[i];
   
    return i;
}

void Union(int i,int j){
    parent[i]=j;
}


void bubblesort(struct Edge arr[],int n){
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].weight > arr[j + 1].weight) {
                struct Edge temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int kruskals(int n, int t[n-1][2], int e) {
    bubblesort(edges, e);
   
    for (int i = 1; i <= n; i++)
        parent[i] = -1;
   
    int i = 0, mincost = 0;
    for (int ei = 0; i < n - 1 && ei < e; ei++) {
        struct Edge current = edges[ei];
        int j = find(current.source);
        int k = find(current.destination);
        if (j != k) {
            t[i][0] = current.source;
            t[i][1] = current.destination;
            mincost += current.weight;
            Union(j, k);
            i++;
        }
    }
    return mincost;
}

int main() {
    int n, e;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &e);

    int t[n-1][2];

    printf("Enter source, destination, and weight for each edge:\n");
    for (int i = 0; i < e; i++) {
        scanf("%d%d%d", &edges[i].source, &edges[i].destination, &edges[i].weight);
    }

    int min_cost = kruskals(n, t, e);
    printf("Minimum cost of spanning tree: %d\n", min_cost);

    printf("Edges in the Minimum Spanning Tree:\n");
    for (int i = 0; i < n - 1; i++) {
        printf("%d --> %d\n", t[i][0], t[i][1]);
    }

   
    return 0;
}