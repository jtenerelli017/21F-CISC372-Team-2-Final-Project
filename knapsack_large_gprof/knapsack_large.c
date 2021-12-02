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
    int val2[] = { 101, 125, 104, 15, 47, 9, 99, 44, 149, 138, 150, 137, 14, 49, 110, 123, 59, 113, 76, 48, 57, 112, 61, 68, 81, 142, 12, 1, 145, 65, 26, 21, 72, 139, 120, 130, 143, 87, 89, 134 };
    int wt2[] = { 101, 117, 10, 18, 16, 76, 32, 129, 137, 6, 45, 96, 99, 80, 11, 73, 52, 125, 98, 141, 64, 35, 34, 60, 70, 135, 30, 144, 27, 136, 122, 53, 24, 25, 22, 95, 121, 42, 147, 89 };
    int W = 50;
    int W2 = 1200;
    int n = sizeof(val) / sizeof(val[0]);
    int n2 = sizeof(val2) / sizeof(val2[0]);
    printf("%d\n", knapSack(W, wt, val, n));
    printf("%d\n", knapSack(W2, wt2, val2, n2));
    return 0;
}