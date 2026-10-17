/*
Q115: Write a program to take two strings s and t as inputs (assume all characters are lowercase). The task is to determine if s and t are valid anagrams, meaning they contain the same characters with the same frequencies. Print "Anagram" if they are, otherwise print "Not Anagram".

Sample Test Cases:
Input 1:
s = "anagram", t = "nagaram"
Output 1:
Anagram

Input 2:
s = "rat", t = "car"
Output 2:
Not Anagram
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
{
    char buf[4096];
    int len = 0, c;
    while ((c = getchar()) != EOF && len < 4095) 
    {
        buf[len++] = (char)c;
    }
    buf[len] = '\0';

    char s[2000] = {0};
    char t[2000] = {0};

    // Look for quotes
    char *q1 = strchr(buf, '"');
    char *q2 = q1 ? strchr(q1 + 1, '"') : NULL;
    char *q3 = q2 ? strchr(q2 + 1, '"') : NULL;
    char *q4 = q3 ? strchr(q3 + 1, '"') : NULL;

    if (q1 && q2 && q3 && q4) 
    {
        int len_s = q2 - (q1 + 1);
        strncpy(s, q1 + 1, len_s);
        s[len_s] = '\0';

        int len_t = q4 - (q3 + 1);
        strncpy(t, q3 + 1, len_t);
        t[len_t] = '\0';
    } 
    else 
    {
        // Try sscanf
        sscanf(buf, "%s %s", s, t);
    }

    if (strlen(s) != strlen(t)) 
    {
        printf("Not Anagram\n");
        return 0;
    }

    int count[256] = {0};
    for (int i = 0; s[i]; i++) 
    {
        count[(unsigned char)s[i]]++;
        count[(unsigned char)t[i]]--;
    }

    for (int i = 0; i < 256; i++) 
    {
        if (count[i] != 0) 
        {
            printf("Not Anagram\n");
            return 0;
        }
    }

    printf("Anagram\n");
    return 0;
}
