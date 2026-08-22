#include <stdio.h>
int main()
{
char op;
int a, b;
printf("Enter operator (+, -, *, /, %%): ");
scanf(" %c", &op);
printf("Enter two numbers: ");
scanf("%d %d", &a, &b);
switch (op) 
{
case '+':
printf("Result = %d", a + b);
break;
case '-':
printf("Result = %d", a - b);
break;
case '*':
printf("Result = %d", a * b);
break;
case '/':
if (b != 0)
printf("Result = %d", a / b);
else
printf("Error: Division by zero!");
break;
case '%':
if (b != 0)
printf("Result = %d", a % b);
else
printf("Error: Modulo by zero!");
break;
default:
printf("Invalid operator!");
}
}