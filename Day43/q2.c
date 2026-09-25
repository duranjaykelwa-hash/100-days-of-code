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
    int isPal = 1;
    for (int i = 0; i < len / 2; i++) 
    {
        if (str[i] != str[len - 1 - i]) 
        {
            isPal = 0;
            break;
        }
    }
    if (isPal)
        printf("Palindrome\n");
    else
        printf("Not palindrome\n");
    return 0;
}
