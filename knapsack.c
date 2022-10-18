#include <stdio.h>
int w[] = {50, 5, 1000};
int v[] = {5000, 500000, 5000};
void fracKnapsack(int M, int n)
{
    int curVal;
    // Total value of items in bag
    float total;
    int i, max;
    // Check if item has been picked up
    int used[n];
    for (i = 0; i < n; ++i)
        used[i] = 0;
    curVal = M;
    while (curVal > 0)
    {
        max = -1;
        for (i = 0; i < n; ++i)
            if ((used[i] == 0) && ((max == -1) || (v[i] * 1.0 / w[i] > v[max] * 1.0 / w[max])))
                max = i;
        // Set that item has been picked up
        used[max] = 1;
        curVal -= w[max];
        total += v[max];
        if (curVal >= 0)
            printf("Add object %d (Rs. %d, %d weight). Space left: %d.\n", max + 1, v[max], w[max], curVal);
        else
        {
            printf("Add %d (Rs. %d, %d weight) of object %d.\n", (int)((1 + curVal * 1.0 / w[max]) * 100), v[max], w[max], max + 1);
            total -= v[max];
            total += (1 + (float)curVal / w[max]) * v[max];
        }
    }
    printf("Filled the knapsack with items worth Rs. %.2f.\n", total);
}
int main()
{
    // Max w
    int M = 60;
    // Number of items
    int n = 3;
    fracKnapsack(M, n);
    return 0;
}
