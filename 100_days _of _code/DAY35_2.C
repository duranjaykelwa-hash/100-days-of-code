#include <stdio.h>
int main() 
{
int a[100], n, k;
int i, j, temp;
printf("Enter number of elements: ");
scanf("%d", &n);
printf("Enter array elements:\n");
for(i = 0; i < n; i++) 
{
scanf("%d", &a[i]);
}
printf("Enter k: ");
scanf("%d", &k);
for(i = 0; i < k; i++) 
{
temp = a[n - 1];
for(j = n - 1; j > 0; j--) 
{
a[j] = a[j - 1];
}
a[0] = temp;
}
printf("Array after rotation:\n");
for(i = 0; i < n; i++) 
{
printf("%d ", a[i]);
}
}