#include <stdio.h>
#include <stdlib.h>

int main() 
{
    FILE *fp = fopen("info.txt", "r");
    if (fp == NULL) 
    {
        fp = fopen("info.txt", "w");
        if (fp != NULL) 
        {
            fprintf(fp, "Name: Rahul\nAge: 23\n");
            fclose(fp);
            fp = fopen("info.txt", "r");
        }
    }

    if (fp == NULL) 
    {
        printf("Error: Could not open info.txt\n");
        return 1;
    }

    char line[256];
    while (fgets(line, sizeof(line), fp) != NULL) 
    {
        printf("%s", line);
    }

    fclose(fp);
    return 0;
}
