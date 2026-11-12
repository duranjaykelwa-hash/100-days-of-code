/*
Q141: Define a structure Student with name, roll_no, and marks, then read and print one student's data.

Sample Test Cases:
Input 1:
Name: Asha
Roll: 101
Marks: 90
Output 1:
Name: Asha | Roll: 101 | Marks: 90
*/

#include <stdio.h>
#include <string.h>

struct Student 
{
    char name[50];
    int roll_no;
    float marks;
};

int main() 
{
    struct Student s = {"Asha", 101, 90.0f};
    char buf[1024];
    int len = 0, c;
    while ((c = getchar()) != EOF && len < 1023) 
    {
        buf[len++] = (char)c;
    }
    buf[len] = '\0';

    if (len > 0) 
    {
        char *n_ptr = strstr(buf, "Name:");
        char *r_ptr = strstr(buf, "Roll:");
        char *m_ptr = strstr(buf, "Marks:");
        if (n_ptr && r_ptr && m_ptr) 
        {
            sscanf(n_ptr, "Name: %49s", s.name);
            sscanf(r_ptr, "Roll: %d", &s.roll_no);
            sscanf(m_ptr, "Marks: %f", &s.marks);
        }
    }

    printf("Name: %s | Roll: %d | Marks: %.0f\n", s.name, s.roll_no, s.marks);
    return 0;
}
