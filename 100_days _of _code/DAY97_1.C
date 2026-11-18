/*
Q147: Store employee data in a binary file using fwrite() and read using fread().

Sample Test Cases:
Input 1:
Employee details entered and stored in file.
Output 1:
Displays employee data read from file.
*/

#include <stdio.h>
#include <stdlib.h>

struct Employee 
{
    char name[50];
    int id;
    float salary;
};

int main() 
{
    struct Employee emp_write = {"Rajesh", 101, 55000.0f};

    FILE *fp = fopen("employee.bin", "wb");
    if (fp == NULL) 
    {
        printf("Error opening file for writing!\n");
        return 1;
    }
    fwrite(&emp_write, sizeof(struct Employee), 1, fp);
    fclose(fp);

    struct Employee emp_read;
    fp = fopen("employee.bin", "rb");
    if (fp == NULL) 
    {
        printf("Error opening file for reading!\n");
        return 1;
    }
    if (fread(&emp_read, sizeof(struct Employee), 1, fp) == 1) 
    {
        printf("Name: %s | ID: %d | Salary: %.2f\n", emp_read.name, emp_read.id, emp_read.salary);
    }
    fclose(fp);

    return 0;
}
