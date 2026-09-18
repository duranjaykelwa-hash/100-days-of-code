#include <stdio.h>

int main() 
{
    int rows, cols;
    if (scanf("%d %d", &rows, &cols) != 2) return 0;
    int a[rows][cols];
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            scanf("%d", &a[i][j]);
        }
    }

    int first = 1;
    for (int s = 0; s <= (rows - 1) + (cols - 1); s++) 
    {
        if (s % 2 == 1) 
        {
            int rStart = (s - cols + 1 > 0) ? (s - cols + 1) : 0;
            int rEnd = (rows - 1 < s) ? (rows - 1) : s;
            for (int r = rStart; r <= rEnd; r++) 
            {
                int c = s - r;
                if (!first) printf(" ");
                printf("%d", a[r][c]);
                first = 0;
            }
        } 
        else 
        {
            int rStart = (rows - 1 < s) ? (rows - 1) : s;
            int rEnd = (s - cols + 1 > 0) ? (s - cols + 1) : 0;
            for (int r = rStart; r >= rEnd; r--) 
            {
                int c = s - r;
                if (!first) printf(" ");
                printf("%d", a[r][c]);
                first = 0;
            }
        }
    }
    printf("\n");
    return 0;
}
