/*
Q105: Write a program to take an integer array nums of size n, and print the majority element. The majority element is the element that appears strictly more than [n / 2] times. Print -1 if no such element exists. Note: Majority Element is not necessarily the element that is present most number of times.

Sample Test Cases:
Input 1:
nums = [3,2,3]
Output 1:
3

Input 2:
nums = [2,2,1,1,1,2,2]
Output 2:
2

Input 3:
nums = [2,2,1,1,1,2,2,3]
Output 3:
-1
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

    if (n == 0) 
    {
        printf("-1\n");
        return 0;
    }

    // Boyer-Moore voting
    int candidate = arr[0], count = 0;
    for (int i = 0; i < n; i++) 
    {
        if (count == 0) 
        {
            candidate = arr[i];
            count = 1;
        } 
        else if (arr[i] == candidate) 
        {
            count++;
        } 
        else 
        {
            count--;
        }
    }

    // Verify
    int freq = 0;
    for (int i = 0; i < n; i++) 
    {
        if (arr[i] == candidate) freq++;
    }

    if (freq > n / 2) 
    {
        printf("%d\n", candidate);
    } 
    else 
    {
        printf("-1\n");
    }

    return 0;
}
