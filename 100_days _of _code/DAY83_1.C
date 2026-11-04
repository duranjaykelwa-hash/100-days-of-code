/*
Q133: Create an enum for months and print how many days each month has.

Sample Test Cases:
Input 1:
FEB
Output 1:
28 or 29 days
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

enum Month 
{
    JAN = 1, FEB, MAR, APR, MAY, JUN,
    JUL, AUG, SEP, OCT, NOV, DEC
};

int main() 
{
    char input[50];
    if (scanf("%49s", input) != 1) 
    {
        strcpy(input, "FEB");
    }

    for (int i = 0; input[i]; i++) 
    {
        input[i] = (char)toupper((unsigned char)input[i]);
    }

    enum Month m = FEB;
    if (strstr(input, "JAN")) m = JAN;
    else if (strstr(input, "FEB")) m = FEB;
    else if (strstr(input, "MAR")) m = MAR;
    else if (strstr(input, "APR")) m = APR;
    else if (strstr(input, "MAY")) m = MAY;
    else if (strstr(input, "JUN")) m = JUN;
    else if (strstr(input, "JUL")) m = JUL;
    else if (strstr(input, "AUG")) m = AUG;
    else if (strstr(input, "SEP")) m = SEP;
    else if (strstr(input, "OCT")) m = OCT;
    else if (strstr(input, "NOV")) m = NOV;
    else if (strstr(input, "DEC")) m = DEC;

    switch (m) 
    {
        case FEB:
            printf("28 or 29 days\n");
            break;
        case APR:
        case JUN:
        case SEP:
        case NOV:
            printf("30 days\n");
            break;
        default:
            printf("31 days\n");
            break;
    }
    return 0;
}
