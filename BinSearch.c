#include<stdio.h>
#include<stdlib.h>
int n;

int BinSearch(int *arr, int i, int l, int x)
{
    //i--> start index, l--> end index, x--> element to be searched
    if(i==l) // small problem (array of only 1 element)
    {
        if (arr[i]==x) return i;
        else return -1;
    }
    else
    {
        int mid= (i+l)/2;
        if(arr[mid]==x) return mid;
        else if (x<arr[mid]) return BinSearch(arr,i,mid-1,x);
        else return BinSearch(arr,mid+1,l,x);
        

    }
}

int main()
{while(1)
{
    int solution;
    int element;
   printf("Enter the number of terms :- ");
   scanf("%d",&n);
   int *arr=(int *)malloc(n*sizeof(int));
   // get array input
   printf("Enter the terms of the array :- ");
   for(int i=0;i<n;i++)
   scanf("%d",&arr[i]);

   printf("Enter the element to be searched :- ");
   scanf("%d",&element);


   solution=BinSearch(arr,0,n-1,element);
   printf("The element was found at index %d\n", solution);}
    

}