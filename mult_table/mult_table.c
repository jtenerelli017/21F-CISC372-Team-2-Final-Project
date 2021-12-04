/* Takes an input integer n and prints a multiplication table with n rows and n columns.
If the table has a certain amount of rows and columns, the printout is shortened to the
last couple of rows and columns. */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void mult_table(int n, int print) {
  const int N = n + 2;
  const int M = N - 14;

  if((N >= 2) && (n <= 1000)) {
    int table[N][N];
    table[0][0] = 0;

    for(int i = 1; i < N; i++) {
      table[0][i] = i - 1;
      table[i][0] = i - 1;
    }

    int r, c = 1;

    for(r = 1; r < N; r++) {
      for(c = 1; c < N; c++) {
        table[r][c] = (r - 1) * (c - 1);
      }
    }

    if(print) {
      printf("\n");
      for(r = 0; r < N; r++) {
        printf("\n");
        for(c = M; c < N; c++) {
          if((r == 0) && (c == M))
            printf("X\t");
          else if(c == M)
            printf("%d\t", table[r][0]);
          else if(r == 0)
            printf("%d\t", table[0][c]);
          else printf("%d\t", table[r][c]);
        }
      }
      printf("\n");
    }

  } else if(n > 1000) {
    printf("\nInput must be less than or equal to 1000\n");
  } else {
    printf("\nInput must be positive\n");
  }
}

int main() {
  mult_table(12, 1);
  mult_table(30, 1);
  mult_table(100, 1);
  mult_table(1000, 1);
  mult_table(-1, 1);
  mult_table(1001, 1);
  for(int i = 0; i < 1000; i++) {
    mult_table(1000, 0); // :^)
  }
  exit(0);
}
