#include <stdio.h>

int main() 
{
    int r1, c1, r2, c2;
    if (scanf("%d %d", &r1, &c1) != 2) return 0;
    int a[r1][c1];
    for (int i = 0; i < r1; i++) 
    {
        for (int j = 0; j < c1; j++) 
        {
            scanf("%d", &a[i][j]);
        }
    }

    if (scanf("%d %d", &r2, &c2) != 2) return 0;
    int b[r2][c2];
    for (int i = 0; i < r2; i++) 
    {
        for (int j = 0; j < c2; j++) 
        {
            scanf("%d", &b[i][j]);
        }
    }

    int c[r1][c2];
    for (int i = 0; i < r1; i++) 
    {
        for (int j = 0; j < c2; j++) 
        {
            c[i][j] = 0;
            for (int k = 0; k < c1; k++) 
            {
                c[i][j] += a[i][k] * b[k][j];
            }
            printf("%d", c[i][j]);
            if (j < c2 - 1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
