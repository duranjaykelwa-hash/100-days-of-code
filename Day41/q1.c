#include <stdio.h>

int main() 
{
    char str[1000];
    if (!fgets(str, sizeof(str), stdin)) return 0;
    int len = 0;
    while (str[len] != '\0') 
    {
        if (str[len] == '\n' || str[len] == '\r') 
        {
            break;
        }
        len++;
    }
    printf("%d\n", len);
    return 0;
}
