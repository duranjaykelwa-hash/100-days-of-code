#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
{
    const char *src = "source.txt";
    const char *dest = "destination.txt";

    FILE *chk = fopen(src, "r");
    if (chk == NULL) 
    {
        chk = fopen(src, "w");
        if (chk != NULL) 
        {
            fprintf(chk, "Learning C File Handling");
            fclose(chk);
        }
    } 
    else 
    {
        fclose(chk);
    }

    FILE *f_src = fopen(src, "r");
    if (f_src == NULL) 
    {
        printf("Error opening source file!\n");
        return 1;
    }

    FILE *f_dest = fopen(dest, "w");
    if (f_dest == NULL) 
    {
        fclose(f_src);
        printf("Error opening destination file!\n");
        return 1;
    }

    int ch;
    while ((ch = fgetc(f_src)) != EOF) 
    {
        fputc(ch, f_dest);
    }

    fclose(f_src);
    fclose(f_dest);

    printf("File copied successfully to %s\n", dest);
    return 0;
}
