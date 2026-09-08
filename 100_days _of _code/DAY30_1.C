#include <stdio.h>
int main() 
{
int n, i;
int even = 0, odd = 0;
int arr[100];
printf("Enter the number of elements: ");
scanf("%d", &n);
printf("Enter the elements:\n");
for (i = 0; i < n; i++) 
{
scanf("%d", &arr[i]);
if (arr[i] % 2 == 0)
even++;
else
odd++;
}
printf("Even numbers = %d\n", even);
printf("Odd numbers = %d\n", odd);
}