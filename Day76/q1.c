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
