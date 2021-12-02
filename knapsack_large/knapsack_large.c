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
    int val2[] = { 121, 109, 90, 110, 42, 144, 24, 108, 6, 27, 53, 64, 39, 76, 101, 19, 52, 82, 123, 149, 143, 33, 88, 107, 117, 125, 11, 85, 105, 67 };
    int wt2[] = { 134, 113, 41, 38, 71, 66, 139, 111, 147, 105, 28, 106, 67, 12, 36, 136, 68, 48, 20, 34, 149, 137, 25, 10, 124, 35, 27, 126, 81, 120 };
    int W = 50;
    int W2 = 1000;
    int n = sizeof(val) / sizeof(val[0]);
    int n2 = sizeof(val2) / sizeof(val2[0]);
    printf("%d", knapSack(W, wt, val, n));
    printf("%d", knapSack(W2, wt2, val2, n2));
    return 0;
}