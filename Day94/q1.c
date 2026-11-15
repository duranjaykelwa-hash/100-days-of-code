#include <stdio.h>

struct Student 
{
    char name[50];
    int roll_no;
    int marks;
};

void printStudent(struct Student s) 
{
    printf("Name: %s | Roll: %d | Marks: %d\n", s.name, s.roll_no, s.marks);
}

int main() 
{
    struct Student s1 = {"Neha", 104, 92};
    printStudent(s1);
    return 0;
}
