#include <stdio.h>

int main() 
{
    char str[1000];
    if (!fgets(str, sizeof(str), stdin)) return 0;
    for (int i = 0; str[i] != '\0'; i++) 
    {
        if (str[i] == '\n' || str[i] == '\r') break;
        if (str[i] == ' ')
            printf("-");
        else
            printf("%c", str[i]);
    }
    printf("\n");
    return 0;
}
