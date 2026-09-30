#include <stdio.h>

int main() 
{
    char str[1000];
    if (!fgets(str, sizeof(str), stdin)) return 0;

    int i = 0;
    while (str[i] != '\0' && str[i] != '\n' && str[i] != '\r') 
    {
        if (str[i] == ' ') 
        {
            putchar(' ');
            i++;
        } 
        else 
        {
            int start = i;
            while (str[i] != ' ' && str[i] != '\0' && str[i] != '\n' && str[i] != '\r') 
            {
                i++;
            }
            for (int j = i - 1; j >= start; j--) 
            {
                putchar(str[j]);
            }
        }
    }
    putchar('\n');
    return 0;
}
