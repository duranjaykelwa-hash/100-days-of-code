/*
Q117: Write a program to take two sorted arrays of size m and n as input. Merge both the arrays such that the merged array is also sorted. Print the merged sorted array as output.

Sample Test Cases:
Input 1:
nums1 = [2,7,11,15] nums2 = [4,8,10]
Output 1:
2 4 7 8 10 11 15

Input 2:
nums1 = [1,2,7] nums2 = [9,10,17]
Output 2:
1 2 7 9 10 17

Input 3:
nums1 = [-10,-2,7] nums2 = [-3, -1, 7]
Output 3:
-10 -3 -2 -1 7 7
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void parse_array(char *start, char *end, int *arr, int *count) 
{
    *count = 0;
    char *p = start;
    while (p < end) 
    {
        while (p < end && (*p == ' ' || *p == ',')) p++;
        if (p >= end) break;
        arr[(*count)++] = strtol(p, &p, 10);
    }
}

int main() 
{
    char buf[4096];
    int len = 0, c;
    while ((c = getchar()) != EOF && len < 4095) 
    {
        buf[len++] = (char)c;
    }
    buf[len] = '\0';

    int a[2000], b[2000];
    int n1 = 0, n2 = 0;

    char *b1_open = strchr(buf, '[');
    char *b1_close = b1_open ? strchr(b1_open, ']') : NULL;
    char *b2_open = b1_close ? strchr(b1_close, '[') : NULL;
    char *b2_close = b2_open ? strchr(b2_open, ']') : NULL;

    if (b1_open && b1_close && b2_open && b2_close) 
    {
        parse_array(b1_open + 1, b1_close, a, &n1);
        parse_array(b2_open + 1, b2_close, b, &n2);
    } 
    else 
    {
        return 0;
    }

    int i = 0, j = 0;
    int first = 1;
    while (i < n1 && j < n2) 
    {
        if (first) first = 0; else printf(" ");
        if (a[i] <= b[j]) 
        {
            printf("%d", a[i++]);
        } 
        else 
        {
            printf("%d", b[j++]);
        }
    }
    while (i < n1) 
    {
        if (first) first = 0; else printf(" ");
        printf("%d", a[i++]);
    }
    while (j < n2) 
    {
        if (first) first = 0; else printf(" ");
        printf("%d", b[j++]);
    }
    printf("\n");

    return 0;
}
