#include <stdio.h>
int main() 
{
int n, first, last, digits = 1, temp, result;
printf("Enter a number: ");
scanf("%d", &n);
temp = n;
last = n % 10;
while (temp >= 10) 
{
temp = temp / 10;
digits = digits * 10;
}
first = temp;
result = last * digits + (n % digits) / 10 * 10 + first;
printf("Number after swapping first and last digit: %d", result);
}