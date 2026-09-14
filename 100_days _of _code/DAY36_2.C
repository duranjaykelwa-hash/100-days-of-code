#include <stdio.h>
int main() 
{
int rows, cols, sum = 0;
printf("Enter number of rows and columns: ");
scanf("%d %d", &rows, &cols);
int matrix[rows][cols];
printf("Enter the matrix elements:\n");
for (int i = 0; i < rows; i++)
{
for (int j = 0; j < cols; j++)
{
scanf("%d", &matrix[i][j]);
sum = sum + matrix[i][j];
}
}
printf("Sum of all elements = %d\n", sum);
}