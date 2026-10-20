/*
Q118: Write a program to take an input array of size n. The array should contain all the integers between 0 to n except for one. Print that missing number as output.

Sample Test Cases:
Input 1:
nums1 = [0,3,2,4]
Output 1:
1

Input 2:
nums1 = [1,2,3]
Output 2:
0

Input 3:
nums1 = [0,4,3,1,5]
Output 3:
2
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

    int nums[2000];
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
            nums[n++] = strtol(p, &p, 10);
        }
    } 
    else 
    {
        char *p = buf;
        while (*p) 
        {
            while (*p && !isdigit(*p) && *p != '-') p++;
            if (!*p) break;
            nums[n++] = strtol(p, &p, 10);
        }
    }

    if (n == 0) return 0;

    // Numbers are between 0 to n. Total elements should be n + 1.
    long long expected_sum = (long long)n * (n + 1) / 2;
    long long actual_sum = 0;
    for (int i = 0; i < n; i++) 
    {
        actual_sum += nums[i];
    }

    printf("%lld\n", expected_sum - actual_sum);
    return 0;
}
