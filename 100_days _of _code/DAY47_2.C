#include <stdio.h>
#include <string.h>

int main() 
{
    char line[1000];
    if (!fgets(line, sizeof(line), stdin)) return 0;

    char longest[1000] = "";
    int maxLen = 0;

    int i = 0;
    while (line[i] != '\0' && line[i] != '\n' && line[i] != '\r') 
    {
        while (line[i] == ' ') i++;
        if (line[i] == '\0' || line[i] == '\n' || line[i] == '\r') break;

        char current[1000];
        int len = 0;
        while (line[i] != ' ' && line[i] != '\0' && line[i] != '\n' && line[i] != '\r') 
        {
            current[len++] = line[i++];
        }
        current[len] = '\0';

        if (len > maxLen) 
        {
            maxLen = len;
            strcpy(longest, current);
        }
    }

    printf("%s\n", longest);
    return 0;
}
