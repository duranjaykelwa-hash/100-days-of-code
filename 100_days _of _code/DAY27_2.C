#include <stdio.h>
int main() 
{
int i, j, spaces, stars;
for (i = 1; i <= 7; i++) 
{
if (i <= 4) 
{
stars = 2 * i - 1;
spaces = 4 - i;
}
else 
{
stars = 2 * (8 - i) - 1;
spaces = i - 4;
}
for (j = 1; j <= spaces; j++) 
{
printf(" ");
}
for (j = 1; j <= stars; j++) 
{
printf("*");
}
printf("\n");
}
}