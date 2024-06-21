#include<stdio.h>
#include<stdlib.h>
#define INFINITY 999
int n; //Number of vertices
int *near; //near array
int **t;
void Initialize(int **cost,int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cost[i][j]= INFINITY; // defined near header file
        }
    }
}

void prims(int **cost)
{
    //find the minimum cost edge k, l in the graph
     int k, l;
     int min=INFINITY; //set min as infinity
     int mincost=0; // cost of the mst
     
     for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(cost[i][j]<min)
            {
                min=cost[i][j];
                k=i;
                l=j;
            }
        }
    }
    
    // now we have found the minimum cost edge, this will be the first edge of the minimum spanning tree
    mincost=cost[k][l];
    t[1][1]=k; t[1][2]=l;
    // record the edge in table matrix t

    //Initialize the near array
    for(int i=1;i<=n;i++)
    {
        if(cost[i][l]<cost[i][k])
        near[i]=l;
        else 
        near[i]=k;

    }
    near[k]=0; near[l]=0;

    for(int i=2;i<=n-1;i++)
    {
        // find an  index j such that near[j] != 0 and cost[j,near[j]] is minimum
        int j;
        min=INFINITY;
        for(int k=1;k<=n;k++)
        {
            if(near[k]!=0 && (cost[k][near[k]]<min))
            {
                min=cost[k][near[k]];
                j=k;// the min cost value
            }
        }
        mincost+=cost[j][near[j]];
        t[i][1]=j; t[i][2]=near[j];
        near[j]=0;
        // re initialize the near array
        for(int k=1;k<=n;k++)
        {
            if (near[k]!=0 &&(cost[k][near[k]]>cost[k][j]))
            {
                near[k]=j;

            }
        }
    }
    printf("The minimum cost is %d \n", mincost);

    printf("The Minimum cost spanning tree table is :- \n");
    for(int i=1;i<=n-1;i++)
    {
        printf("%d --> %d \n",t[i][1],t[i][2]);
    }




}



int main()
{
    printf("Enter the number of vertices in the graph :- ");
    scanf("%d",&n);
    //Dynamic memory allocation for an array
     // can use int cost[100][100] also
    int **cost=(int **)malloc((n+1)*sizeof(int *));
    for(int i=0;i<=n;i++)
    cost[i]=(int *)malloc((n+1)*sizeof(int));

    t=(int **)malloc((n+1)*sizeof(int *));
    for(int i=0;i<=n;i++)
    t[i]=(int *)malloc(3*sizeof(int));

    near=(int *)malloc((n+1)*sizeof(int));

    // Initialize the matrix to max values for edges not present
    Initialize(cost,n);

    // Now, Take Input
    int origin,destin,tempcost;
    int maxedges=(n*(n-1));
    printf("Now enter the edges in a [source,destin,cost] format (press -1 -1 -1 to exit) :- \n");
    for(int i=1;i<=maxedges;i++)
    {
        scanf("%d %d %d",&origin, &destin, &tempcost);

        if(origin ==-1 || destin ==-1 || tempcost==-1 || origin>n||destin>n) break;
        cost[origin][destin]=tempcost;
        cost[destin][origin]=tempcost;
    }
// This step is just to check if inputs are correct
    printf("Adjacency Matric for the given graph is :-\n");
    for(int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            printf("%4d ", cost[i][j]);
        }
        printf("\n");
      
    }

    // Call the prims function
     prims(cost);

    

    

}
/*
Test case
1 2 2
1 3 2
1 4 1
2 1 2 
2 3 2
2 4 1
3 1 2
3 2 2
3 4 3
4 1 1
4 2 1
4 3 3
5 1 1
5 6 1
5 7 3
6 3 2
6 7 2
6 8 3
7 8 1 
4 8 1
-1 -1 -1

solution -8
*/