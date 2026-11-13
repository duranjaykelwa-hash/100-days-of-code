/*
Q142: Store details of 5 students in an array of structures and print all.

Sample Test Cases:
Input 1:
Details of 5 students (Name, Roll, Marks)
Output 1:
Tabular list of all 5 students with their details
*/

#include <stdio.h>

struct Student 
{
    char name[50];
    int roll_no;
    float marks;
};

int main() 
{
    struct Student students[5] = {
        {"Asha", 101, 85.0f},
        {"Ravi", 102, 92.0f},
        {"Sita", 103, 78.0f},
        {"Aman", 104, 88.0f},
        {"Neha", 105, 95.0f}
    };

    printf("==========================================\n");
    printf("%-10s %-10s %-10s\n", "Roll No", "Name", "Marks");
    printf("==========================================\n");
    for (int i = 0; i < 5; i++) 
    {
        printf("%-10d %-10s %-10.2f\n", students[i].roll_no, students[i].name, students[i].marks);
    }
    printf("==========================================\n");
    return 0;
}
