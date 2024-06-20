#include<stdio.h>
#include<stdlib.h>

char *arr; // Input array
int n;   // Number of terms
char *b; // Auxillary array

void Merge(int low, int mid, int high)
{
    int h= low; int i=low; int j= mid+1;
    while((h<=mid) && (j<=high))
    {
        if(arr[h]>arr[j])
        {
            b[i]=arr[h];
            h=h+1;
        }
        else
        {
            b[i]=arr[j];
            j=j+1;

        }
        i=i+1;
    }
    if(h>mid)
    {
        for(int k=j; k<=high;k++)
        {
            b[i]=arr[k];
            i=i+1;

        }
    }
    else
    for(int k=h; k<=mid;k++)
        {
            b[i]=arr[k];
            i=i+1;

        }

        for(int k=low ;k<=high;k++)
        arr[k]=b[k];
}
void Mergesort(int low, int high)
{
    if(low < high) // if not a small p --> more than 1 terms
    {
        int mid=(low+high)/2;
        Mergesort(low,mid);
        Mergesort(mid+1,high);

        // Merge the smaller sub problems
        Merge(low,mid,high);

    }
}

int main()
{
    //This Sorts in descending order
 printf("Enter the number of terms :- ");
   scanf("%d",&n);
   arr=(char *)malloc(n*sizeof(char));
   b=(char *)malloc(n*sizeof(char));


   // Get Input
   printf("Enter the alphabets of the array :- ");
   for(int i=0;i<n;i++)
   scanf(" %c",&arr[i]); // blank space before %c to avoid scanning newline
    
   // Call merge sort function
   Mergesort(0,n-1);
   // Now the array is sorted
   printf("\nThe sorted sequence is :- ");
   for(int i=0;i<=n-1;i++)
   {
    printf("%c ",arr[i]);
   }

}