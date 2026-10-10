/*
Q108: Write a Program to take an integer array nums. Print an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i]. The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

Sample Test Cases:
Input 1:
nums = [1,2,3,4]
Output 1:
[24,12,8,6]

Input 2:
nums = [-1,1,0,-3,3]
Output 2:
[0,0,9,0,0]
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

    int arr[1000];
    int n = 0;

    char *open_br = strchr(buf, '[');
    char *close_br = strchr(buf, ']');
    if (open_br && close_br && open_br < close_br) 
    {
        char *p = open_br + 1;
        while (p < close_br) 
        {
            while (p < close_br && (*p == ' ' || *p == ',')) p++;
            if (p >= close_br) break;
            arr[n++] = strtol(p, &p, 10);
        }
    } 
    else 
    {
        char *p = buf;
        while (*p) 
        {
            while (*p && !isdigit(*p) && *p != '-') p++;
            if (!*p) break;
            arr[n++] = strtol(p, &p, 10);
        }
    }

    int left[1000], right[1000];
    left[0] = 1;
    for (int i = 1; i < n; i++) 
    {
        left[i] = left[i - 1] * arr[i - 1];
    }

    right[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) 
    {
        right[i] = right[i + 1] * arr[i + 1];
    }

    printf("[");
    for (int i = 0; i < n; i++) 
    {
        int ans = left[i] * right[i];
        if (i > 0) printf(",");
        printf("%d", ans);
    }
    printf("]\n");

    return 0;
}
