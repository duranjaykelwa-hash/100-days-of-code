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
    struct Student s;
    struct Student *ptr = &s;

    strcpy(ptr->name, "John");
    ptr->roll_no = 106;
    ptr->marks = 91;

    printf("Modified Data: Name: %s | Roll: %d | Marks: %d\n", ptr->name, ptr->roll_no, ptr->marks);
    return 0;
}
