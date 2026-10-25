/*
Q123: Read a text file and count the total number of characters, words, and lines. A word is defined as a sequence of non-space characters separated by spaces or newlines.

Sample Test Cases:
Input 1:
File: sample.txt (Content: Hello world\nThis is C programming)
Output 1:
Characters: 31
Words: 5
Lines: 2
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() 
{
    const char *filename = "sample.txt";
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) 
    {
        fp = fopen(filename, "w");
        if (fp != NULL) 
        {
            fprintf(fp, "Hello world\nThis is C programming");
            fclose(fp);
            fp = fopen(filename, "r");
        }
    }

    if (fp == NULL) 
    {
        printf("Error opening file!\n");
        return 1;
    }

    int chars = 0, words = 0, lines = 0;
    int in_word = 0;
    int c;
    int last_c = '\n';

    while ((c = fgetc(fp)) != EOF) 
    {
        chars++;
        if (c == '\n') 
        {
            lines++;
        }
        if (isspace(c)) 
        {
            in_word = 0;
        } 
        else if (!in_word) 
        {
            in_word = 1;
            words++;
        }
        last_c = c;
    }
    if (chars > 0 && last_c != '\n') 
    {
        lines++;
    }

    fclose(fp);

    printf("Characters: %d\n", chars);
    printf("Words: %d\n", words);
    printf("Lines: %d\n", lines);

    return 0;
}
