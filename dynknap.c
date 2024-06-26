#include <stdio.h>
#include <stdlib.h>

struct Pair {
    double p; // Profit
    double w; // Weight
} pair[10000];

int b[101];

// Binary search to find the largest index with weight <= to
int Largest(struct Pair pair[], int t, int h, double to) {
    int left = t;
    int right = h;
    int mid;

    while (left <= right) {
        mid = left + (right - left) / 2;

        if (pair[mid].w == to) {
            return mid;
        } else if (pair[mid].w < to) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return right; // Return the largest index where weight <= to
}

// Traceback using binary search
void TraceBack(double p[], double w[], struct Pair pair[], int x[], double to, int n) {
    double totalProfit = pair[b[n + 1] - 1].p;
    double weight = pair[b[n + 1] - 1].w;

    for (int i = n - 1; i >= 0; i--) {
        int flag = 0;
        int low = b[i];
        int high = b[i + 1] - 1;
        int mid;

        while (low <= high) {
            mid = low + (high - low) / 2;

            if (pair[mid].p == totalProfit) {
                x[i] = 0;
                flag = 1;
                break;
            } else if (pair[mid].p < totalProfit) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        if (flag == 0) {
            totalProfit -= p[i + 1];
            weight -= w[i + 1];
            x[i] = 1;
        }
    }

    // Print maximum profit
    printf("Maximum profit: %.2lf\n", pair[b[n + 1] - 1].p);
}

// Dynamic Knapsack Algorithm
void AlgorithmDKnap(double p[], double w[], int x[], int n, double to) {
    pair[1].p = 0;
    pair[1].w = 0;
    int t = 1;
    int h = 1;
    int next = 2;
    b[0] = 1;
    b[1] = 2;

    for (int i = 1; i <= n; i++) {
        int k = t;
        int u = Largest(pair, t, h, to);

        for (int j = t; j <= u; j++) {
            double pp = pair[j].p + p[i];
            double ww = pair[j].w + w[i];

            while (k <= h && pair[k].w < ww) {
                pair[next].p = pair[k].p;
                pair[next].w = pair[k].w;
                next++;
                k++;
            }

            if (k <= h && pair[k].w == ww) {
                if (pp < pair[k].p) {
                    pp = pair[k].p;
                }
                k++;
            }

            if (pp > pair[next - 1].p && ww <= to) {
                pair[next].p = pp;
                pair[next].w = ww;
                next++;
            }

            while (k <= h && pair[k].p <= pair[next - 1].p) {
                k++;
            }
        }

        while (k <= h) {
            pair[next].p = pair[k].p;
            pair[next].w = pair[k].w;
            next++;
            k++;
        }

        t = h + 1;
        h = next - 1;
        b[i + 1] = next;
    }

    TraceBack(p, w, pair, x, to, n);
}

int main() {
    double p[100]; // Profits
    double w[100]; // Weights
    int x[100]; // Solution vector
    int n; // Number of items
    double to; // Maximum weight capacity

    // Input
    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the profits of items:\n");
    for (int i = 1; i <= n; i++) {
        scanf("%lf", &p[i]);
    }

    printf("Enter the weights of items:\n");
    for (int i = 1; i <= n; i++) {
        scanf("%lf", &w[i]);
    }

    printf("Enter the maximum weight capacity: ");
    scanf("%lf", &to);

    // Solve the knapsack problem
    AlgorithmDKnap(p, w, x, n, to);

    // Output the solution vector
    printf("Solution vector (1 for selected, 0 for not selected):\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d] = %d\n", i + 1, x[i]);
    }

    return 0;
}
