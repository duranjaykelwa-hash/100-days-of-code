#include <stdio.h>
#include <ctype.h>

int main() 
{
    char name[1000];
    if (!fgets(name, sizeof(name), stdin)) return 0;

    int inWord = 0;
    for (int i = 0; name[i] != '\0' && name[i] != '\n' && name[i] != '\r'; i++) 
    {
        if (name[i] != ' ' && !inWord) 
        {
            putchar(toupper(name[i]));
            putchar('.');
            inWord = 1;
        } 
        else if (name[i] == ' ') 
        {
            inWord = 0;
        }
    }
    putchar('\n');
    return 0;
}
