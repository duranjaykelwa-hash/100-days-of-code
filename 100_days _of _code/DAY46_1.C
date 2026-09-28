#include <stdio.h>

int main() 
{
    char str[1000];
    if (!fgets(str, sizeof(str), stdin)) return 0;

    for (int i = 0; str[i] != '\0'; i++) 
    {
        char ch = str[i];
        if (ch == '\n' || ch == '\r') break;

        if (ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u' &&
            ch != 'A' && ch != 'E' && ch != 'I' && ch != 'O' && ch != 'U') 
        {
            putchar(ch);
        }
    }
    putchar('\n');
    return 0;
}
