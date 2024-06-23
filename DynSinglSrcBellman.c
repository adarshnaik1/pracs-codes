#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define INFINITY 999
int n;
void Initialize(int **cost)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cost[i][j]=INFINITY; // defined above
        }
    }
}
bool has_incoming(int u, int **cost)
{
    // check if the vertice u has any incoming edge
    for(int i=1;i<=n;i++)
    {
        if(cost[i][u]!=INFINITY) return true;
    }
    return false;
}
void SingleSource(int v, int **cost, int *dist)
{
  for(int i=1 ;i<=n;i++)
  {
    dist[i]=cost[v][i];
  }
  for(int m=2;m<=n-1;m++)// n-1 relaxations
  {
    // find a vertex u such that u has atleast 1 incoming edge and u!=v
    for(int u=1;u<=n;u++)
    {
        if(u==v)continue;
        if(has_incoming(u,cost))
        {
            // for every edge <i,u> in the graph check if dist[u]>dist[i]+cost[i][u]
            for(int i=1;i<=n;i++)
            {
                if(cost[i][u]!=INFINITY)
                {
                    if(dist[u]>dist[i]+cost[i][u])
                    {
                        dist[u]=dist[i]+cost[i][u];
                    }
                }

            }
        }

        
    }
  }

}

//Note - You can check for negative weight cycle after the completion of the function Single source / at the end of the function
// simply run 2 for loops (nested)--> for each vertice u try comparing its distance [dist array value] with all the adjacent vertices i + cost[i,u]
// for(int u=1;u<=n;u++)
//for(int i=1;i<=n;i++)
/*
if(dist[u]>dist[i]+cost[i,u])-->PRINT(negative weight cycle detected)
*/
int main()
{
     printf("Enter the number of vertices :- ");
     scanf("%d", &n);

    int **cost=(int **)malloc((n+1)*sizeof(int *));
    for(int i=0;i<=n;i++)
    {
        cost[i]=(int *)malloc((n+1)*sizeof(int));
    } 
    int *dist=(int *)malloc((n+1)*sizeof(int));
    int maxedges=n*(n-1);
    int origin,destin,tempcost;
    Initialize(cost);

    printf("Enter the Edge in the [source, destin, cost] format (-1,-1,-1) to quit :- \n");
    for(int i=1;i<=maxedges;i++)
    {
        scanf("%d %d %d",&origin,&destin,&tempcost);
          if((origin==-1) && (destin==-1) && (tempcost==-1))
        {
            break;
        }

       else if(origin<1 ||origin>n || destin<1 || destin>n) 
        {
            printf("\nInvalid Edge Please Re Enter the edge\n");
            i--;

        }
       
        else
        {
            cost[origin][destin]=tempcost;
          
        }
        

    }
      printf("Adjacency Matrix for the given graph is :-\n");
    for(int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
           
            printf("%4d ", cost[i][j]);
        }
        printf("\n");
      
    }
    
    SingleSource(1,cost,dist);
    dist[1]=0;
    printf("Displaying the shortest path array :- \n");
    for(int i=1;i<=n;i++)
    {
        printf("vertex 1 to %d--> distance= %d \n",i, dist[i]);
    }

}