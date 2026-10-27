/*
Q125: Open an existing file in append mode and allow the user to enter a new line of text. Append the text at the end without overwriting existing content.

Sample Test Cases:
Input 1:
Existing File: data.txt (Content before execution: Hello world)
User Input: This is appended text.
Output 1:
File updated successfully with appended text.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
{
    const char *filename = "data.txt";
    FILE *chk = fopen(filename, "r");
    if (chk == NULL) 
    {
        chk = fopen(filename, "w");
        if (chk != NULL) 
        {
            fprintf(chk, "Hello world\n");
            fclose(chk);
        }
    } 
    else 
    {
        fclose(chk);
    }

    char append_text[256] = "This is appended text.";

    FILE *fp = fopen(filename, "a");
    if (fp == NULL) 
    {
        printf("Error opening file in append mode!\n");
        return 1;
    }

    fprintf(fp, "%s\n", append_text);
    fclose(fp);

    printf("File updated successfully with appended text.\n");
    return 0;
}
