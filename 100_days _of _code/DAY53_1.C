/*
Q103: Write a Program to take an array of integers as input, calculate the pivot index of this array. The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right. If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array. Print the leftmost pivot index. If no such index exists, print -1.

Sample Test Cases:
Input 1:
nums = [1,7,3,6,5,6]
Output 1:
3

Input 2:
nums = [1,2,3]
Output 2:
-1

Input 3:
nums = [2,1,-1]
Output 3:
0
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

    int total_sum = 0;
    for (int i = 0; i < n; i++) 
    {
        total_sum += arr[i];
    }

    int left_sum = 0;
    int pivot = -1;
    for (int i = 0; i < n; i++) 
    {
        if (left_sum == total_sum - left_sum - arr[i]) 
        {
            pivot = i;
            break;
        }
        left_sum += arr[i];
    }

    printf("%d\n", pivot);
    return 0;
}
