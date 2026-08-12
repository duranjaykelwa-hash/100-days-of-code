#include<stdio.h>
int main()
{
float length,breadth,area,perimeter;
printf("Enter the length of the rectangle:");
scanf("%f",&length);
printf("Enter the width of the rectangle:");
scanf("%f",&breadth);
area=length*breadth;
perimeter=2*(length+breadth);
printf("area=%.2f\n",area);
printf("perimeter=%.2f\n",perimeter);
}