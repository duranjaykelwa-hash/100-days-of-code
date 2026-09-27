#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() 
{
    char line[1000];
    if (!fgets(line, sizeof(line), stdin)) return 0;

    char words[50][100];
    int count = 0;
    int i = 0;

    while (line[i] != '\0' && line[i] != '\n' && line[i] != '\r') 
    {
        while (line[i] == ' ') i++;
        if (line[i] == '\0' || line[i] == '\n' || line[i] == '\r') break;

        int len = 0;
        while (line[i] != ' ' && line[i] != '\0' && line[i] != '\n' && line[i] != '\r') 
        {
            words[count][len++] = line[i++];
        }
        words[count][len] = '\0';
        count++;
    }

    if (count == 0) return 0;

    if (count == 1) 
    {
        printf("%s\n", words[0]);
        return 0;
    }

    for (int k = 0; k < count - 1; k++) 
    {
        putchar(toupper(words[k][0]));
        putchar('.');
    }
    printf(" %s\n", words[count - 1]);

    return 0;
}
