#include <stdio.h>
int main() 
{
int n, i, search;
int arr[100];
int found = 0;
printf("Enter the number of elements: ");
scanf("%d", &n);
printf("Enter the elements:\n");
for (i = 0; i < n; i++) 
{
scanf("%d", &arr[i]);
}
printf("Enter the element to search: ");
scanf("%d", &search);
for (i = 0; i < n; i++) 
{
if (arr[i] == search) 
{
printf("Element found at position %d\n", i + 1);
found = 1;
break;
}
}
if (found == 0) 
{
printf("Element not found\n");
}
}