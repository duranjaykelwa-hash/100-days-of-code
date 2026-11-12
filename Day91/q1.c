#include <stdio.h>

struct Student 
{
    char name[50];
    int roll_no;
    float marks;
};

int main() 
{
    struct Student s;
    printf("Enter student name: ");
    if (scanf("%s", s.name) != 1) return 0;
    printf("Enter roll number: ");
    scanf("%d", &s.roll_no);
    printf("Enter marks: ");
    scanf("%f", &s.marks);

    printf("Name: %s | Roll: %d | Marks: %.2f\n", s.name, s.roll_no, s.marks);
    return 0;
}
