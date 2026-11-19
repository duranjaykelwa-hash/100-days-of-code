/*
Q148: Take two structs as input and check if they are identical.

Sample Test Cases:
Input 1:
Student1: Asha 101 90
Student2: Asha 101 90
Output 1:
Same
*/

#include <stdio.h>
#include <string.h>

struct Student 
{
    char name[50];
    int roll_no;
    int marks;
};

int areIdentical(struct Student s1, struct Student s2) 
{
    if (strcmp(s1.name, s2.name) == 0 && s1.roll_no == s2.roll_no && s1.marks == s2.marks) 
    {
        return 1;
    }
    return 0;
}

int main() 
{
    struct Student s1 = {"Asha", 101, 90};
    struct Student s2 = {"Asha", 101, 90};

    if (areIdentical(s1, s2)) 
    {
        printf("Same\n");
    } 
    else 
    {
        printf("Different\n");
    }
    return 0;
}
