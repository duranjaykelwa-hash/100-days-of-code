/*
Q119: Write a program to take an integer array as input. Only one element will be repeated. Print the repeated element. Try to find the result in one single iteration.

Sample Test Cases:
Input 1:
nums1 = [1,3,3,4]
Output 1:
3

Input 2:
nums1 = [1,2,2]
Output 2:
2

Input 3:
nums1 = [0,4,1,1,5]
Output 3:
1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() 
{
    char buf[4096];
    int len = 0, c;
    while ((c = getchar()) != EOF && len < 4095) 
    {
        buf[len++] = (char)c;
    }
    buf[len] = '\0';

    int arr[2000];
    int n = 0;

    char *p = buf;
    while (*p) 
    {
        while (*p && !isdigit((unsigned char)*p) && *p != '-' && *p != '+') 
        {
            p++;
        }
        if (!*p) break;
        if ((*p == '-' || *p == '+') && !isdigit((unsigned char)*(p + 1))) 
        {
            p++;
            continue;
        }
        int val = (int)strtol(p, &p, 10);
        arr[n++] = val;
    }

    int repeated = -1;
    int found = 0;
    static int seen_pos[100000] = {0};
    static int seen_neg[100000] = {0};

    for (int i = 0; i < n; i++) 
    {
        int v = arr[i];
        if (v >= 0) 
        {
            if (v < 100000 && seen_pos[v]) 
            {
                repeated = v;
                found = 1;
                break;
            }
            if (v < 100000) seen_pos[v] = 1;
        } 
        else 
        {
            int abs_v = -v;
            if (abs_v < 100000 && seen_neg[abs_v]) 
            {
                repeated = v;
                found = 1;
                break;
            }
            if (abs_v < 100000) seen_neg[abs_v] = 1;
        }
    }

    if (found) 
    {
        printf("%d\n", repeated);
    }
    return 0;
}
