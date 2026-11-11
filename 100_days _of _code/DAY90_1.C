/*
Q140: Define a struct with enum Gender and print person's gender.

Sample Test Cases:
Input 1:
Gender=MALE
Output 1:
Male
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

enum Gender 
{
    MALE,
    FEMALE,
    OTHER
};

struct Person 
{
    char name[50];
    enum Gender gender;
};

int main() 
{
    char input[50];
    if (scanf("%49s", input) != 1) 
    {
        strcpy(input, "Gender=MALE");
    }

    for (int i = 0; input[i]; i++) 
    {
        input[i] = (char)toupper((unsigned char)input[i]);
    }

    struct Person p;
    strcpy(p.name, "Alex");

    if (strstr(input, "FEMALE")) 
    {
        p.gender = FEMALE;
    } 
    else if (strstr(input, "OTHER")) 
    {
        p.gender = OTHER;
    } 
    else 
    {
        p.gender = MALE;
    }

    switch (p.gender) 
    {
        case MALE:
            printf("Male\n");
            break;
        case FEMALE:
            printf("Female\n");
            break;
        case OTHER:
            printf("Other\n");
            break;
    }
    return 0;
}
