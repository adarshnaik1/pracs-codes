#include<stdio.h>
#include<stdlib.h>
int n;
int *arr;
void Interchange(int i, int j)
{
 int t=arr[i];
 arr[i]=arr[j];
 arr[j]=t;
}
int Partition(int *a, int m, int p)
{
    int v=a[m]; int i=m; int j=p;
    do
    {  do
    {
         i=i+1;
    } while (a[i]<v);

     do
    {
         j=j-1;
    } while (a[j]>v);
       

if(i<j) Interchange(i,j);
    } while (i<j);

    a[m]=a[j]; a[j]=v; return j;
    

}


void QuickSort(int p, int q)
{
    if(p<q)
    {
        // small P
     printf("test 1");
        int j= Partition(arr,p,q); // always pass q+1 and set the q+1 element as infinity before passing in the array
        
        QuickSort(p,j-1);
      
        QuickSort(j+1,q);

        // we do not pass j because jth element is already sorted

        //There is no need to combine solutions because at the end of each Partition function call the element at the jth position which it returns is already sorted, in the same way the entire array gets sorted on multipe calls to the partition function
    }
}

int main()
{

   printf("Enter the number of terms :- ");
   scanf("%d",&n);
   arr=(int *)malloc((n+1)*sizeof(int));
   // Set arr[n] as infinity required  for quick sort function
   arr[n]=999 ;// 999 acts as infinity 
   // get array input
   printf("Enter the terms of the array :- ");
   for(int i=0;i<n;i++)
   scanf("%d",&arr[i]);
   //QuickSort
   QuickSort(0,n-1);
   printf("The sorted array :- ");
   for(int i=0;i<n;i++)
   {
    printf("%d ", arr[i]);
   }

}