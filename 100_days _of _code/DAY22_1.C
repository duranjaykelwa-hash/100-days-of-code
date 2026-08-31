#include <stdio.h>
int main() 
{
int n, temp, digit, sum = 0, fact, i;
printf("Enter a number: ");
scanf("%d", &n);
temp = n;
while (temp > 0) 
{
digit = temp % 10;
fact = 1;
for (i = 1; i <= digit; i++) 
{
fact = fact * i;
}
sum = sum + fact;
temp = temp / 10;
}
if (sum == n)
printf("Strong Number");
else
printf("Not a Strong Number");
}