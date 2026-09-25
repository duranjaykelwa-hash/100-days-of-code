#include <stdio.h>

int main() 
{
    char str[1000];
    if (!fgets(str, sizeof(str), stdin)) return 0;
    int len = 0;
    while (str[len] != '\0' && str[len] != '\n' && str[len] != '\r') 
    {
        len++;
    }
    for (int i = len - 1; i >= 0; i--) 
    {
        printf("%c", str[i]);
    }
    printf("\n");
    return 0;
}
