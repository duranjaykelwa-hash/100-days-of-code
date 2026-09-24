#include <stdio.h>

int main() 
{
    char str[1000];
    if (!fgets(str, sizeof(str), stdin)) return 0;
    int vowels = 0, consonants = 0;
    for (int i = 0; str[i] != '\0'; i++) 
    {
        char ch = str[i];
        if (ch == '\n' || ch == '\r') break;
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) 
        {
            char lower = (ch >= 'A' && ch <= 'Z') ? (ch + 32) : ch;
            if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u')
                vowels++;
            else
                consonants++;
        }
    }
    printf("Vowels=%d, Consonants=%d\n", vowels, consonants);
    return 0;
}
