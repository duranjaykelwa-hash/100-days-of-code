#include<stdio.h>
int main()
{
float celsius,fahrenhiet;
printf("Enter temperature in celsius:");
scanf("%f",&celsius);
fahrenhiet=(celsius*9/5)+32;
printf("temperature in fahrenhiet=%.2f",fahrenhiet);
}