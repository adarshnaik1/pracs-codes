#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 20
#define INFINITY 99999
int n; // Number of Identifiers

int w[MAX][MAX], c[MAX][MAX],r[MAX][MAX];
char strings[][10]={"do", "if","int", "while"};
void printroot(int k)
{
    printf("%s, ",strings[k-1]);
}

void preorder(int r[][20], int i , int j)
{
    if(i==j) return;
    else
    {
       
        printroot(r[i][j]);
        preorder(r, i, r[i][j]-1);
        preorder(r,r[i][j],j);

    }

}

int find(int c[][MAX], int r[][MAX], int i, int j)
{
    int min= INFINITY;
    int l;
    for(int m=r[i][j-1]; m<=r[i+1][j]; m++)
    {
        if(c[i][m-1]+c[m][j]<min)
        {
            min=c[i][m-1]+c[m][j];
            l=m;

        }
    }
    return l;

}

void OBST(int p[], int q[])
{
    for(int i=0;i<=n-1;i++)
    {
        w[i][i]=q[i];
        c[i][i]=r[i][i]=0;
        w[i][i+1]=q[i]+p[i+1]+q[i+1];
        c[i][i+1]=q[i]+p[i+1]+q[i+1];
        r[i][i+1]=i+1;
    }
    w[n][n]=q[n]; c[n][n]=r[n][n]=0;

    // remaining Iterations from 2 to n
    for(int m=2;m<=n;m++)
    {
        for(int i=0;i<=n-m;i++)
        {
            int j=i+m;
            w[i][j]=w[i][j-1]+p[j]+q[j];
            int k= find(c,r,i,j);
            c[i][j]=w[i][j]+c[i][k-1]+c[k][j];
            r[i][j]=k;
        }
    }
    printf("The final values are :- \n");
    printf("W[0,%d]=%d\n",n,w[0][n]);
    printf("C[0,%d]=%d\n",n,c[0][n]);
    printf("R[0,%d]=%d\n",n,r[0][n]);
     
    printf("The preorder traversal is  :- \n");
    preorder(r,0,n);
}

int main()
{
    int p[20];// array for successful search probabilities P
    int q[20]; // array for unsuccessful search probabilities q
    printf("Enter the number of identifiers:- ");
    scanf("%d",&n);
    printf("Enter the array of P(Successful search) :- ");
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&p[i]);
    }
     printf("Enter the array of Q :- ");
    for(int i=0;i<=n;i++)
    {
        scanf("%d",&q[i]);
    }
    OBST(p,q);

}