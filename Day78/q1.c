#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() 
{
    FILE *fp = fopen("text.txt", "r");
    if (fp == NULL) 
    {
        fp = fopen("text.txt", "w");
        if (fp != NULL) 
        {
            fprintf(fp, "Welcome to C language");
            fclose(fp);
            fp = fopen("text.txt", "r");
        }
    }

    if (fp == NULL) 
    {
        printf("Error opening text.txt!\n");
        return 1;
    }

    int vowels = 0, consonants = 0;
    int c;
    while ((c = fgetc(fp)) != EOF) 
    {
        if (isalpha(c)) 
        {
            char low = (char)tolower(c);
            if (low == 'a' || low == 'e' || low == 'i' || low == 'o' || low == 'u') 
            {
                vowels++;
            } 
            else 
            {
                consonants++;
            }
        }
    }

    fclose(fp);

    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);
    return 0;
}
