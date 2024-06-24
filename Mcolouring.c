#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 25
int n;
int *x;
int solutioncount=0,nodecount=0;
int G[MAX][MAX];

void printarr(int a[])
{
printf("The solution array :- ");
for(int i=1;i<=n;i++)
{
printf("%d ",a[i]);
}
}
void NextValue(int k,int m)
{
    while(1)
    {
        int j;
        x[k]=(x[k]+1)%(m+1);
        if(x[k]==0)
        {
            return;

        }
        for( j=1;j<=n;j++)
        {
            if(G[k][j]==1 && x[k]==x[j])
            {
                break;
            }
        }
        if(j==(n+1))
        {
            break;
        }
    }

}


void mColouring(int k,int m)
{
    int checked=0;
    while(1)
    {
        //Generate all legal assignments for x[k]
        NextValue(k,m); // Assign to x[k] a legal colour
        if(x[k]==0) return;
        if(k==n) // at most m colours have been used to colour n vertices
        {
           if(!checked)
           {
            ++solutioncount;
            checked=1;
            printf("Solution found\n") ;
            printarr(x);
           }
        }
        else
        {
            mColouring(k+1,m);
        }

        
    }
}




int main()
{
    int max=0,m;
    printf("Enter the number of terms - ");
    scanf("%d",&n);
    x=(int *)malloc((n+1)*sizeof(int));
    //Initialize array to 0
    for(int i=1;i<=n;i++)
    {
         x[i]=0;
    }
    printf("Enter the adjacency matrix of the graph : \n");
    m=0;
    for(int i=1;i<=n;i++)
    {
        max=0;
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&G[i][j]);
            if(G[i][j]==1)
            max++;
        }
        if(max>m)
        m=max;
    }
// max degree of the graph calculated
printf("the degree of the graph is : %d\n", ++m-1);
for(int i=1;i<=m;i++)
{
 mColouring(1,i);
 if(solutioncount!=0)
 { printf("\nThe number of solutions is - %d\n", solutioncount);
    solutioncount=0;

   
    printf("The chromatic number of the graph is %d\n",i);
    break;
 }
 for(int j=1;j<=n;j++)
 {
    x[j]=0;
 }
} 



return 0;
   
    
}
/*
ADJACENCY MATRIX
0 1 1 1 0 0 0 0 0
1 0 0 1 0 1 0 0 0 
1 0 0 1 1 0 1 0 0 
1 1 1 0 1 0 0 0 0
0 0 1 1 0 1 1 1 0
0 1 0 0 1 0 0 1 1
0 0 1 0 1 0 0 1 0
0 0 0 0 1 1 1 0 1
0 0 0 0 0 1 0 1 0
*/