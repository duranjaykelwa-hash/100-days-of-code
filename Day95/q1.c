#include <stdio.h>

struct Student 
{
    char name[50];
    int roll_no;
    int marks;
};

struct Student getTopStudent(struct Student arr[], int n) 
{
    int top_idx = 0;
    for (int i = 1; i < n; i++) 
    {
        if (arr[i].marks > arr[top_idx].marks) 
        {
            top_idx = i;
        }
    }
    return arr[top_idx];
}

int main() 
{
    struct Student students[3] = {
        {"Riya", 101, 89},
        {"Karan", 102, 96},
        {"Meena", 103, 92}
    };

    struct Student topper = getTopStudent(students, 3);
    printf("Top Student: %s | Roll: %d | Marks: %d\n", topper.name, topper.roll_no, topper.marks);
    return 0;
}
