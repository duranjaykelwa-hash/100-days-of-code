/*
Q143: Find and print the student with the highest marks.

Sample Test Cases:
Input 1:
3 students: Ravi 101 95, Sita 102 85, Aman 103 88
Output 1:
Topper: Ravi (Marks: 95)
*/

#include <stdio.h>
#include <string.h>

struct Student 
{
    char name[50];
    int roll_no;
    int marks;
};

int main() 
{
    struct Student s[3] = {
        {"Ravi", 101, 95},
        {"Sita", 102, 85},
        {"Aman", 103, 88}
    };

    int top_idx = 0;
    for (int i = 1; i < 3; i++) 
    {
        if (s[i].marks > s[top_idx].marks) 
        {
            top_idx = i;
        }
    }

    printf("Topper: %s (Marks: %d)\n", s[top_idx].name, s[top_idx].marks);
    return 0;
}
