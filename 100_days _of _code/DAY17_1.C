#include <stdio.h>
int main() 
{
int n, original, remainder, reverse = 0;
printf("Enter a n: ");
scanf("%d", &n);
original = n;
while (n != 0) {
remainder = n % 10;
reverse = reverse + (remainder * remainder * remainder);
n = n / 10;
}
if (original == reverse)
printf("Armstrong number");
else
printf("Not an Armstrong number");
}
