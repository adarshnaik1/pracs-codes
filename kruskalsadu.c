#include <stdio.h>
#include <stdlib.h>
int n; // number of vertices
int e; // number of edges
int t[100][2];
struct Edge 
{
    int source;
    int destin;
    int weight;

};

struct Edge edges[100];
int parent[100];
int find(int i)
{
    while(parent[i]>=0)
    i=parent[i];
    return i;

}
void Union(int i, int j)
{
    parent[i]=j;

}

void bubblesort(struct Edge edges[], int n)
{
    //NOTE- n here is not number of vertices but number of edges e
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(edges[j].weight >edges[j+1].weight)
            {
                struct Edge temp=edges[j];
                edges[j]=edges[j+1];
                edges[j+1]=temp;

            }
        }
    }
}

int kruskals(struct Edge edges[], int parent[], int e)
{
    bubblesort(edges,e);
    for(int i=1;i<=n;i++)
   {
    parent[i]=-1;
   }
    int i=0; int mincost=0;
   for(int ei=0; i<n-1 && ei<e;ei++)
   {
    struct Edge temp= edges[ei];
    int u= temp.source;
    int v= temp.destin;
    int j= find(u);
    int k= find(v);
    if(j!=k)
    {
        t[i][0]=j;
        t[i][1]=k;
        mincost+=temp.weight;
        Union(j,k);
        i++;
        
    }

   }
   return mincost;
}
int main()
{
   printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &e);

   

    printf("Enter source, destination, and weight for each edge:\n");
    for (int i = 0; i < e; i++) {
        scanf("%d%d%d", &edges[i].source, &edges[i].destin, &edges[i].weight);
    }

    int min_cost = kruskals(edges,parent,e);
    printf("Minimum cost of spanning tree: %d\n", min_cost);

    printf("Edges in the Minimum Spanning Tree:\n");
    for (int i = 0; i < n - 1; i++) {
        printf("%d --> %d\n", t[i][0], t[i][1]);
    }

   
    return 0;
}