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
    int val2[] = { 4, 105, 20, 92, 101, 148, 115, 102, 75, 104, 46, 28, 10, 30, 39, 80, 98, 2, 66, 99, 88, 126, 84, 110, 81, 116, 71, 95, 72, 91, 143, 31, 87, 145, 128, 130, 11, 93, 60, 47, 76, 3, 18, 32, 139, 65, 120, 83, 77, 78, 147, 44, 133, 97, 1, 19, 64, 106, 21, 146 };
    int wt2[] = { 10, 127, 112, 102, 122, 37, 50, 51, 107, 56, 38, 79, 86, 19, 104, 118, 110, 57, 35, 45, 74, 111, 5, 54, 26, 143, 75, 39, 84, 99, 41, 140, 58, 121, 142, 81, 42, 73, 61, 71, 7, 108, 43, 94, 80, 87, 30, 18, 52, 77, 135, 147, 96, 55, 114, 131, 12, 70, 13, 115 };
    int W = 50;
    int W2 = 2000;
    int n = sizeof(val) / sizeof(val[0]);
    int n2 = sizeof(val2) / sizeof(val2[0]);
    printf("%d\n", knapSack(W, wt, val, n));
    printf("%d\n", knapSack(W2, wt2, val2, n2));
    return 0;
}