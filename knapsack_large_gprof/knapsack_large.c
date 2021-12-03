/* A Naive recursive implementation
of 0-1 Knapsack problem */
#include <stdio.h>
 
// A utility function that returns
// maximum of two integers
int max(int a, int b) { return (a > b) ? a : b; }
 
// Returns the maximum value that can be
// put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n)
{
    // Base Case
    if (n == 0 || W == 0)
        return 0;
 
    // If weight of the nth item is more than
    // Knapsack capacity W, then this item cannot
    // be included in the optimal solution
    if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1);
 
    // Return the maximum of two cases:
    // (1) nth item included
    // (2) not included
    else
        return max(
            val[n - 1]
                + knapSack(W - wt[n - 1],
                           wt, val, n - 1),
            knapSack(W, wt, val, n - 1));
}
 
// Driver program to test above function
int main()
{
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int val2[] = { 62, 131, 128, 15, 119, 80, 143, 87, 24, 72, 144, 83, 22, 109, 135, 147, 55, 60, 137, 59, 82, 11, 63, 6, 36, 96, 86, 92, 51, 115 };
    int wt2[] = { 78, 79, 109, 34, 56, 90, 149, 69, 138, 99, 4, 17, 20, 26, 88, 36, 61, 112, 27, 84, 11, 123, 116, 14, 68, 132, 3, 46, 135, 122 };
    int W = 50;
    int W2 = 1200;
    int n = sizeof(val) / sizeof(val[0]);
    int n2 = sizeof(val2) / sizeof(val2[0]);
    printf("%d\n", knapSack(W, wt, val, n));
    printf("%d\n", knapSack(W2, wt2, val2, n2));
    return 0;
}