/*
Q114: Write a program to take a string s as input. The task is to find the length of the longest substring without repeating characters. Print the length as output.

Sample Test Cases:
Input 1:
s = "abcabcbb"
Output 1:
3

Input 2:
s = "bbbbb"
Output 2:
1

Input 3:
s = "pwwkew"
Output 3:
3
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
{
    char buf[4096];
    if (!fgets(buf, sizeof(buf), stdin)) return 0;

    char str[4096];
    str[0] = '\0';

    char *q1 = strchr(buf, '"');
    char *q2 = q1 ? strchr(q1 + 1, '"') : NULL;
    if (q1 && q2) 
    {
        int slen = q2 - (q1 + 1);
        strncpy(str, q1 + 1, slen);
        str[slen] = '\0';
    } 
    else 
    {
        char *eq = strchr(buf, '=');
        char *start = eq ? eq + 1 : buf;
        while (*start == ' ') start++;
        int slen = 0;
        while (start[slen] && start[slen] != '\r' && start[slen] != '\n') slen++;
        strncpy(str, start, slen);
        str[slen] = '\0';
    }

    int n = strlen(str);
    int last_idx[256];
    for (int i = 0; i < 256; i++) last_idx[i] = -1;

    int max_len = 0;
    int start = 0;

    for (int i = 0; i < n; i++) 
    {
        unsigned char ch = (unsigned char)str[i];
        if (last_idx[ch] >= start) 
        {
            start = last_idx[ch] + 1;
        }
        last_idx[ch] = i;
        int cur_len = i - start + 1;
        if (cur_len > max_len) max_len = cur_len;
    }

    printf("%d\n", max_len);
    return 0;
}
