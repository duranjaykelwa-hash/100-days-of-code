#include <stdio.h>

int main() 
{
    char str[1000];
    if (!fgets(str, sizeof(str), stdin)) return 0;
    for (int i = 0; str[i] != '\0'; i++) 
    {
        if (str[i] == '\n' || str[i] == '\r') break;
        printf("%c\n", str[i]);
    }
    return 0;
}
