#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 90

char x[MAX];
char y[MAX];
int n;
int m;
int l[MAX][MAX];
int top = -1;
char stackarr[MAX];

void push(int item) {
    if (top == MAX - 1) {
        printf("Overflow");
    } else {
        stackarr[++top] = item;
    }
}

int pop() {
    if (top == -1) {
        printf("Stack empty");
    } else {
        int item = stackarr[top];
        top--;
        return item;
    }
    return -1;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

void lcs(char x[], char y[]) {
    for (int i = 0; i <= n; i++) {
        l[i][0] = 0;
    }

    for (int j = 0; j <= m; j++) {
        l[0][j] = 0;
    }

    for (int i = 1; i <=n; i++) {
        for (int j = 1; j <= m; j++) {
            if (x[i] == y[j ]) {
                l[i][j] = l[i - 1][j - 1] + 1;
            } else {
                l[i][j] = max(l[i - 1][j], l[i][j - 1]);
            }
        }
    }

    printf("Length of LCS: %d\n", l[n][m]);
}

void lcsdisplay() {
    int i = n;
    int j = m;
    while (i > 0 && j > 0) {
        if (x[i - 1] == y[j - 1]) {
            push(x[i - 1]);
            i--;
            j--;
        } else if (l[i - 1][j] > l[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    while (top != -1) {
        printf("%c", pop());
    }
    printf("\n");
}

int main() {
    printf("Enter the string X: ");
    scanf("%s", x);
    
    printf("Enter the string Y: ");
    scanf("%s", y);

    n = strlen(x);
    m = strlen(y);
    lcs(x, y);
    lcsdisplay();

    return 0;
}

/*
Example Input:
Enter the string X: GTCCTATTAGTA
Enter the string Y: TCATTGATTACCAGTA
Example Output:
Length of LCS: 10
TCATTAGTA
*/
