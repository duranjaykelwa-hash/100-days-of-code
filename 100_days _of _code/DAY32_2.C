#include <stdio.h>
int main() 
{
int n, digit;
int count[10] = {0};
int max = 0, result = 0;
printf("Enter an integer: ");
scanf("%d", &n);
if (n < 0)
n = -n;
if (n == 0) 
{
count[0] = 1;
}
while (n > 0) 
{
digit = n % 10;
count[digit]++;
n = n / 10;
}
for (int i = 0; i < 10; i++)
{
if (count[i] > max) 
{
max = count[i];
result = i;
}
}
printf("%d\n", result);
}