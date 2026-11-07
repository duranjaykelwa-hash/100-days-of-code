/*
Q136: Use enum to represent menu choices (ADD, SUBTRACT, MULTIPLY) and perform operations using switch.

Sample Test Cases:
Input 1:
ADD 10 20
Output 1:
30
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

enum MenuChoice 
{
    ADD = 1,
    SUBTRACT,
    MULTIPLY
};

int main() 
{
    char op[50];
    int a = 10, b = 20;
    if (scanf("%49s %d %d", op, &a, &b) < 3) 
    {
        strcpy(op, "ADD");
        a = 10;
        b = 20;
    }

    for (int i = 0; op[i]; i++) 
    {
        op[i] = (char)toupper((unsigned char)op[i]);
    }

    enum MenuChoice choice = ADD;
    if (strstr(op, "SUB")) choice = SUBTRACT;
    else if (strstr(op, "MUL")) choice = MULTIPLY;
    else choice = ADD;

    switch (choice) 
    {
        case ADD:
            printf("%d\n", a + b);
            break;
        case SUBTRACT:
            printf("%d\n", a - b);
            break;
        case MULTIPLY:
            printf("%d\n", a * b);
            break;
    }
    return 0;
}
