/*
Q112: Write a program to take an integer array arr as input. The task is to find the maximum sum of any contiguous subarray using Kadane's algorithm. Print the maximum subarray sum as output.

Sample Test Cases:
Input 1:
arr[] = [2, 3, -8, 7, -1, 2, 3]
Output 1:
11

Input 2:
arr[] = [-2, -4]
Output 2:
-2

Input 3:
arr[] = [5, 4, 1, 7, 8]
Output 3:
25
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

    char *eq = strchr(buf, '=');
    char *open_br = eq ? strchr(eq, '[') : strchr(buf, '[');
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

    if (n == 0) return 0;

    long long max_so_far = arr[0];
    long long curr_max = arr[0];
    for (int i = 1; i < n; i++) 
    {
        if (curr_max + arr[i] > arr[i])
            curr_max += arr[i];
        else
            curr_max = arr[i];
        if (curr_max > max_so_far)
            max_so_far = curr_max;
    }

    printf("%lld\n", max_so_far);
    return 0;
}
