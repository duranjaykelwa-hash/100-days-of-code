#include <stdio.h>

int main() 
{
    char str[1000];
    if (!fgets(str, sizeof(str), stdin)) return 0;

    int freq[26] = {0};
    for (int i = 0; str[i] != '\0'; i++) 
    {
        if (str[i] >= 'a' && str[i] <= 'z') 
        {
            freq[str[i] - 'a']++;
        }
    }

    char ans = '\0';
    for (int i = 0; str[i] != '\0'; i++) 
    {
        if (str[i] >= 'a' && str[i] <= 'z') 
        {
            if (freq[str[i] - 'a'] > 1) 
            {
                ans = str[i];
                break;
            }
        }
    }

    if (ans != '\0') 
    {
        printf("%c\n", ans);
    } 
    else 
    {
        printf("-1\n");
    }

    return 0;
}
