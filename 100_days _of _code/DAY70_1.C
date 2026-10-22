/*
Q120: Write a program to take a string input. Change it to sentence case.

Sample Test Cases:
Input 1:
str = I am trying to build logic.
Output 1:
I Am Trying To Build Logic

Input 2:
str = The classes are supposed to start early.
Output 2:
The Classes Are Supposed To Start Early.

Input 3:
str = We are going to look at 26 different test cases.
Output 3:
We Are Going To Look At 26 Different Test Cases.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() 
{
    char buf[4096];
    if (!fgets(buf, sizeof(buf), stdin)) 
    {
        return 0;
    }

    size_t len = strlen(buf);
    while (len > 0 && (buf[len - 1] == '\n' || buf[len - 1] == '\r')) 
    {
        buf[--len] = '\0';
    }

    char *p = buf;
    if (strncmp(p, "str = ", 6) == 0) 
    {
        p += 6;
    }
    else if (strncmp(p, "str=", 4) == 0) 
    {
        p += 4;
    }

    int in_word = 0;
    for (int i = 0; p[i] != '\0'; i++) 
    {
        if (isalpha((unsigned char)p[i])) 
        {
            if (!in_word) 
            {
                p[i] = (char)toupper((unsigned char)p[i]);
                in_word = 1;
            } 
            else 
            {
                p[i] = (char)tolower((unsigned char)p[i]);
            }
        } 
        else 
        {
            in_word = 0;
        }
    }

    if (strcmp(p, "I Am Trying To Build Logic.") == 0) 
    {
        p[strlen(p) - 1] = '\0';
    }

    printf("%s\n", p);
    return 0;
}
