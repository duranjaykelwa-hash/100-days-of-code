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

    int diagLen = rows < cols ? rows : cols;
    int isDistinct = 1;
    for (int i = 0; i < diagLen; i++) 
    {
        for (int j = i + 1; j < diagLen; j++) 
        {
            if (a[i][i] == a[j][j]) 
            {
                isDistinct = 0;
                break;
            }
        }
        if (!isDistinct) break;
    }

    if (isDistinct)
        printf("True\n");
    else
        printf("False\n");

    return 0;
}
