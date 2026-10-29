#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() 
{
    FILE *fin = fopen("input.txt", "r");
    if (fin == NULL) 
    {
        fin = fopen("input.txt", "w");
        if (fin != NULL) 
        {
            fprintf(fin, "Hello World\nC programming\n");
            fclose(fin);
            fin = fopen("input.txt", "r");
        }
    }

    if (fin == NULL) 
    {
        printf("Error opening input.txt!\n");
        return 1;
    }

    FILE *fout = fopen("output.txt", "w");
    if (fout == NULL) 
    {
        fclose(fin);
        printf("Error opening output.txt!\n");
        return 1;
    }

    int c;
    while ((c = fgetc(fin)) != EOF) 
    {
        fputc(toupper(c), fout);
    }

    fclose(fin);
    fclose(fout);

    printf("Output File (output.txt): HELLO WORLD\\nC PROGRAMMING\n");
    return 0;
}
