#include<stdio.h>
int main()
{
float a,b;
printf("Enter two numbers:");
scanf("%f %f",&a,&b);
printf("sum=%.2f\n",a+b);
printf("difference=%.2f\n",a-b);
printf("product=%.2f\n",a*b);
if(b!=0)
printf("quotient=%.2f\n",a/b);
else
printf("quotient=cannot divide by zero");
}