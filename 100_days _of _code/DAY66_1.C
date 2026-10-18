/*
Q116: Write a program to take an integer array nums which contains only positive integers, and an integer target as inputs. The goal is to find two distinct indices i and j such that nums[i] + nums[j] == target. Assume that each input would have exactly one solution, and you may not use the same element twice. Print the indices separated by a space in increasing order of index.

Sample Test Cases:
Input 1:
nums = [2,7,11,15], target = 9
Output 1:
0 1

Input 2:
nums = [3,2,4], target = 6
Output 2:
1 2

Input 3:
nums = [3,3], target = 6
Output 3:
0 1
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
    int target = 0;

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

        char *t_ptr = strstr(close_br, "target");
        if (t_ptr) 
        {
            while (*t_ptr && !isdigit(*t_ptr) && *t_ptr != '-') t_ptr++;
            if (*t_ptr) target = atoi(t_ptr);
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
        if (n > 1) 
        {
            target = nums[n - 1];
            n--;
        }
    }

    for (int i = 0; i < n; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {
            if (nums[i] + nums[j] == target) 
            {
                printf("%d %d\n", i, j);
                return 0;
            }
        }
    }

    return 0;
}
