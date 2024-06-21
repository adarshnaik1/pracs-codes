#include <stdio.h>
#include <stdlib.h>

int n;
int *arr;

void Interchange(int i, int j) {
    int t = arr[i];
    arr[i] = arr[j];
    arr[j] = t;
}

int Partition(int *a, int m, int p) {
    int v = a[m];
    int i = m;
    int j = p;
    do {
        do {
            i = i + 1;
        } while ( a[i] < v);

        do {
            j = j - 1;
        } while (a[j] > v);

        if (i < j) {
            Interchange(i, j);
        }
    } while (i < j);

    a[m] = a[j];
    a[j] = v;
    return j;
}

void QuickSort(int p, int q) {
    if (p < q) {
        int j = Partition(arr, p, q+1);
        QuickSort(p, j - 1);
        QuickSort(j + 1, q);
    }
}

int main() {
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    arr = (int *)malloc((n + 1) * sizeof(int));
    arr[n] = 999; // 999 acts as infinity

    printf("Enter the terms of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    QuickSort(0, n - 1);

    printf("The sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}
