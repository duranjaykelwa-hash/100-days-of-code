#include <stdio.h>
int main()
{
float a, b, c;
printf("Enter three sides of the triangle: ");
scanf("%f %f %f", &a, &b, &c);
if (a + b <= c || a + c <= b || b + c <= a)
{
printf("Invalid triangle");
}
else if (a == b && b == c)
{
printf("Equilateral");
}
else if (a == b || b == c || a == c)
{
printf("Isosceles");
}
else
{
printf("Scalene");
}
}