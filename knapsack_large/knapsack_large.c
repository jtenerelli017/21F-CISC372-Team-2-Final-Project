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
    int val2[] = { 74, 165, 238, 198, 298, 489, 459, 48, 228, 304, 376, 10, 168, 8, 108, 172, 424, 292, 333, 495, 4, 233, 362, 107, 283, 404, 361, 447, 344, 184, 170, 131, 150, 40, 389, 54, 226, 132, 57, 438, 31, 101, 466, 406, 355, 32, 278, 248, 303, 322, 294, 356, 234, 52, 86, 197, 189, 421, 161, 188, 467, 85, 89, 244, 204, 77, 265, 306, 250, 435, 326, 464, 83, 332, 126, 407, 468, 144, 138, 124, 231, 178, 44, 113, 190, 273, 95, 287, 474, 72, 460, 59, 317, 403, 388, 272, 301, 328, 49, 436 };
    int wt2[] = { 348, 121, 340, 317, 470, 273, 293, 154, 23, 484, 244, 89, 316, 303, 278, 246, 182, 272, 46, 477, 439, 100, 392, 369, 106, 35, 281, 38, 237, 215, 232, 401, 210, 380, 27, 280, 195, 87, 452, 126, 398, 438, 222, 61, 490, 313, 298, 326, 9, 346, 191, 164, 227, 259, 495, 271, 371, 417, 73, 40, 444, 212, 198, 56, 91, 98, 158, 473, 475, 386, 132, 460, 143, 64, 184, 123, 459, 451, 457, 66, 206, 223, 493, 186, 336, 354, 214, 55, 276, 117, 163, 379, 456, 131, 16, 29, 7, 58, 22, 436 };
    int W = 50;
    int W2 = 5000;
    int n = sizeof(val) / sizeof(val[0]);
    int n2 = sizeof(val2) / sizeof(val2[0]);
    printf("%d", knapSack(W, wt, val, n));
    printf("%d", knapSack(W2, wt2, val2, n2));
    return 0;
}