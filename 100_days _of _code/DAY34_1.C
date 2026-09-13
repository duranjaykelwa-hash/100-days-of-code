#include <stdio.h>
int main() 
{
int a[100], n, pos, x;
int i;
printf("Enter number of elements: ");
scanf("%d", &n);
printf("Enter array elements:\n");
for(i = 0; i < n; i++) 
{
scanf("%d", &a[i]);
}
printf("Enter position: ");
scanf("%d", &pos);
printf("Enter element: ");
scanf("%d", &x);
for(i = n; i >= pos; i--) 
{
a[i] = a[i - 1];
}
a[pos - 1] = x;
n++;
printf("Array after insertion:\n");
for(i = 0; i < n; i++) 
{
printf("%d ", a[i]);
}
}