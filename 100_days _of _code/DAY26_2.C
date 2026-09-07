#include <stdio.h>
int main() 
{
int i, j, stars;
for (i = 1; i <= 5; i++) 
{
if (i <= 3)
stars = 2 * i - 1;
else
stars = 2 * (5 - i) + 1;
for (j = 1; j <= stars; j++) 
{
printf("*\n");
}
printf("\n");
}
}