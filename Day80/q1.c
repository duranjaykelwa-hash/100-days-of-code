#include <stdio.h>
#include <stdlib.h>

struct Student 
{
    char name[50];
    int roll;
    int marks;
};

int main() 
{
    struct Student students[2] = {
        {"Asha", 101, 85},
        {"Ravi", 102, 92}
    };

    FILE *fp = fopen("students.txt", "w");
    if (fp == NULL) 
    {
        printf("Error opening file for writing!\n");
        return 1;
    }

    for (int i = 0; i < 2; i++) 
    {
        fprintf(fp, "%s %d %d\n", students[i].name, students[i].roll, students[i].marks);
    }
    fclose(fp);

    fp = fopen("students.txt", "r");
    if (fp == NULL) 
    {
        printf("Error opening file for reading!\n");
        return 1;
    }

    char name[50];
    int roll, marks;
    while (fscanf(fp, "%49s %d %d", name, &roll, &marks) == 3) 
    {
        printf("Name: %s | Roll: %d | Marks: %d\n", name, roll, marks);
    }

    fclose(fp);
    return 0;
}
