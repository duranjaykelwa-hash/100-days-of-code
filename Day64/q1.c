#include <stdio.h>
#include <string.h>

int main() 
{
    char str[1000];
    printf("Enter string: ");
    if (scanf("%s", str) != 1) return 0;

    int n = strlen(str);
    int max_len = 0;

    for (int i = 0; i < n; i++) 
    {
        int visited[256] = {0};
        int current_len = 0;
        for (int j = i; j < n; j++) 
        {
            unsigned char ch = (unsigned char)str[j];
            if (visited[ch]) 
            {
                break;
            }
            visited[ch] = 1;
            current_len++;
        }
        if (current_len > max_len) 
        {
            max_len = current_len;
        }
    }

    printf("%d\n", max_len);
    return 0;
}
