/* A Naive recursive implementation
of 0-1 Knapsack problem */
#include <stdio.h>
#include <omp.h>
#include "time.h"

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
	if (wt[n - 1] > W) {
		int ks;
		#pragma omp parallel default(none) shared(W, wt, val, n, ks)
		{
			ks = knapSack(W, wt, val, n - 1);
		}
		return ks;
	}

	// Return the maximum of two cases:
	// (1) nth item included
	// (2) not included
	else {
		int maximum;
		#pragma omp parallel default(none) shared(W, wt, val, n, maximum)
		{
			maximum = max(
				val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1),
				knapSack(W, wt, val, n - 1)
			);
		}
		return maximum;
	}
}

// Driver program to test above function
int main()
{
	omp_set_num_threads(16);
	double begin, end;

	begin = clock();

	int val[] = { 60, 100, 120 };
	int wt[] = { 10, 20, 30 };
	int W = 50;
	int n = sizeof(val) / sizeof(val[0]);
	printf("%d\n", knapSack(W, wt, val, n));

	end = clock();

	printf("My serial code took %g seconds\n", ((end - begin) / CLOCKS_PER_SEC));
}
