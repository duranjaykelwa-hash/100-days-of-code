#include <stdio.h>

int main() 
{
    int rows, cols;
    if (scanf("%d %d", &rows, &cols) != 2) return 0;
    int a[rows][cols];
    int sum = 0;
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            scanf("%d", &a[i][j]);
            if (i == j) 
            {
                sum += a[i][j];
            }
        }
    }

    printf("%d\n", sum);
    return 0;
}
