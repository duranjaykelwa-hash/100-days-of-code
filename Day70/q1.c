#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() 
{
    char str[1000];
    printf("Enter a string: ");
    if (!fgets(str, sizeof(str), stdin)) 
    {
        return 0;
    }

    int in_word = 0;
    for (int i = 0; str[i] != '\0'; i++) 
    {
        if (isalpha((unsigned char)str[i])) 
        {
            if (!in_word) 
            {
                str[i] = (char)toupper((unsigned char)str[i]);
                in_word = 1;
            } 
            else 
            {
                str[i] = (char)tolower((unsigned char)str[i]);
            }
        } 
        else 
        {
            in_word = 0;
        }
    }

    printf("%s", str);
    return 0;
}
