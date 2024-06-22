
//NOTE- The graph for a single source shortest path problem is a directed graph

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define INFINITY 999
int n;

bool *S;

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

void SingleSource(int **cost, int *dist, int v )// n is global hence not passed as a parameter
{

   for(int i=1;i<=n;i++)
   {
    S[i]=false; dist[i]=cost[v][i];

   }
  S[v]=true; dist[v]=0;
  // for remaining vertices assign permanent label so remaining are from 2 to n
  for(int num=2; num<=n;num++)
  {
    //Find a vertex u such that the distance u is minimum and s[u]= false
    //int min=999;
    int u=-1;
    for(int i=1;i<=n;i++)
    {
        if(!S[i] &&(u==-1 ||dist[i]<dist[u]))
        {
            //min=dist[i];
            u=i;
        }
    }
     S[u]=true;
    // for every vertex w adjacent to u 
    for(int w=1;w<=n;w++)
    {
        if((!S[w])&&(cost[u][w]!=INFINITY))
        {
            if((dist[w]>dist[u]+cost[u][w]))
            dist[w]=dist[u]+cost[u][w];
        }
    }
  }
        

}


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
    S=(bool *)malloc((n+1)*sizeof(bool));
    // INPUT OF COST MATRIX

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

    SingleSource(cost, dist, 1);
    printf("Displaying the shortest path array :- \n");
    for(int i=1;i<=n;i++)
    {
        printf("%d-->%d \n",i, dist[i]);
    }

   
    


}
/*
1 2 40
1 3 50
1 5 10
2 4 15
2 5 5
3 2 10
3 4 5
3 6 5
4 7 2
4 6 2
5 4 3
5 6 3
6 7 4
6 8 3
7 2 10
7 5 8
8 7 2
8 4 2
8 5 3
5 3 15
-1 -1 -1
*/