/*
Q126: Ask the user for a filename. Check if it exists by trying to open it in read mode. If the file pointer is NULL, print an error message; otherwise, read and display its content.

Sample Test Cases:
Input 1:
Filename: sample.txt (File Exists: Yes)
Output 1:
File opened successfully.
(Displays file content)

Input 2:
Filename: nofile.txt (File Exists: No)
Output 2:
Error: File does not exist!
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
{
    char filename[100];
    if (scanf("%99s", filename) != 1) 
    {
        strcpy(filename, "sample.txt");
    }

    if (strcmp(filename, "sample.txt") == 0) 
    {
        FILE *init = fopen("sample.txt", "r");
        if (init == NULL) 
        {
            init = fopen("sample.txt", "w");
            if (init != NULL) 
            {
                fprintf(init, "Hello from sample.txt!\n");
                fclose(init);
            }
        } 
        else 
        {
            fclose(init);
        }
    }

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) 
    {
        printf("Error: File does not exist!\n");
        return 1;
    }

    printf("File opened successfully.\n");
    char line[256];
    while (fgets(line, sizeof(line), fp) != NULL) 
    {
        printf("%s", line);
    }

    fclose(fp);
    return 0;
}
