#include <stdio.h>
#include <string.h>

int main() 
{
    char s[500], t[500];
    printf("Enter first string: ");
    if (scanf("%s", s) != 1) return 0;
    printf("Enter second string: ");
    if (scanf("%s", t) != 1) return 0;

    if (strlen(s) != strlen(t)) 
    {
        printf("Not Anagram\n");
        return 0;
    }

    int count[256] = {0};
    for (int i = 0; s[i] != '\0'; i++) 
    {
        count[(unsigned char)s[i]]++;
        count[(unsigned char)t[i]]--;
    }

    int is_anagram = 1;
    for (int i = 0; i < 256; i++) 
    {
        if (count[i] != 0) 
        {
            is_anagram = 0;
            break;
        }
    }

    if (is_anagram) 
    {
        printf("Anagram\n");
    } 
    else 
    {
        printf("Not Anagram\n");
    }

    return 0;
}
