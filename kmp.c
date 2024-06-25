#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define MAX 30
char P[MAX];//Pattern P
char T[MAX]; //Text T
int n; //Number of elements in text
int m; // number of elements in pattern
int F[MAX];

void FF(char P[])
{
    int i=1;
    int j=0;
     F[0]=0;
    while(i<m)
    {
        if(P[i]==P[j])
        {
            F[i]=j+1;
            j=j+1;
            i=i+1;
        }

        else if (j>0)
        {
            j=F[j-1];
        }
        else
        {
            F[i]=0;
            i=i+1;
        }

    }
}

int KMP(char T[], char P[])
{
    FF(P);
    int i=0;
    int j=0;
    while(i<n)
    {
        if(P[j]==T[i])
        {
            if(j==m-1) return i-j;
            j=j+1;
            i=i+1;
        }

        else if (j>0)
        {
            j=F[j-1];
        }
        else
        {
           
            i=i+1;
        }

    }
    return -1;
}

int main()
{
  printf("Enter the text string :- ");
  scanf("%s",&T);
  printf("Enter the pattern string :- ");
  scanf("%s",&P);
  n=strlen(T);
  m=strlen(P);
  int index=KMP(T,P);
  if(index==-1)printf("Pattern not found");
  else
  printf("Pattern found at index %d", index);

}