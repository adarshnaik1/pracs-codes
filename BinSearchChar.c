#include<stdio.h>
#include<stdlib.h>
int n;

int BinSearch(char *arr, int i, int l, char x)
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
    char element;
   printf("Enter the number of terms :- ");
   scanf("%d",&n);
   char *arr=(char *)malloc(n*sizeof(char));
   // get array input
   printf("Enter the terms of the array :- ");
   for(int i=0;i<n;i++)
   scanf(" %c",&arr[i]);// blank space before %c to avoid scanning newline

   printf("Enter the element to be searched :- ");
   scanf(" %c",&element);// blank space before %c to avoid scanning newline


   solution=BinSearch(arr,0,n-1,element);
   printf("The element was found at index %d\n", solution);}
    

}