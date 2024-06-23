#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 20

int n; // global n, number of elements in the array
int m;// Target sum
int x[MAX]={0};
int *w;
//Function to print array
void printarr(int a[])
{
printf("The solution array :- ");
for(int i=1;i<=n;i++)
{
printf("%d ",a[i]);
}
}

//Function to calculate the sum of subsets

void SumofSub(int s, int k, int r)
{
//Generate the left subchild
x[k]=1;
if((s+w[k])==m)
{
printf("\nSolution Found....\n");
//call a function to print the array
printarr(x);
//Once you get one solution you reinitialize the final vector so as to make sure that it doesnt cause issues in the later solutions
for(int i=1;i<=n;i++)
{
    x[i]=0;
}

}
else if ((s+w[k]+w[k+1]<=m))
{
SumofSub(s+w[k],k+1,r-w[k]);

}
//Generate the right subchild
if((s+r-w[k])&&(s+w[k+1]<=m))
{
x[k]=0;
SumofSub(s,k+1,r-w[k]);

}
     
}


int main()
{

int remaining_sum=0;
//Input 
printf("Enter the number of elements in the array :- ");
scanf("%d", &n);

w=(int *)malloc((n+1)*sizeof(int));

printf("Enter the elements in the array :- ");
for(int i=1;i<=n;i++)
{
  scanf("%d",&w[i]);
  remaining_sum+=w[i];
 
  
}
printf("Enter the target sum :- ");
scanf("%d", &m);

//Function call
SumofSub(0,1,remaining_sum);
return 0;
}