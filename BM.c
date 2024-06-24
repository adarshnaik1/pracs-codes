#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
char p[MAX]; // Pattern
char t[MAX]; //Text
int n; // Number of characters in the text
int m; // Number of characters in the pattern

int minval(int a, int b)
{
    if(a>b)return a;
    return b;
}
int last_occurence(char a) // calculates the last occurence of character a
{
    for(int i=m-1;i>=0;i--)
    {
        if(p[i]==a) return i;
    }
    return -1;
}

int BMmatch(char p[],char t[])
{
    int i=m-1;
    int j=m-1;
    do
    {
        if(p[j]==t[i])
        {
            if(j==0) return i;
            else
            {
                i=i-1;
                j=j-1;
            }
        }
        else
        {
            i=i+m-minval(j,1+last_occurence(t[i]));
            j=m-1;
        }
    } while (i<n);
    return -1;
    
}

int main()
{
    //INPUT
    printf("Enter the text string : ");
    scanf("%s",&t);
    printf("Enter the pattern string : ");
    scanf("%s",&p);

    //Processing
    n=strlen(t);
    m=strlen(p);

    //Call function BM
    int found_index= BMmatch(p,t);
    if(found_index==-1) printf("Pattern Not found");
    else
    printf("Pattern found at index %d", found_index);



}