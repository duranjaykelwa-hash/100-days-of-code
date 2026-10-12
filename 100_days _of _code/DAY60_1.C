/*
Q110: Write a program to take an integer array arr and an integer k as inputs. The task is to find the maximum element in each subarray of size k moving from left to right. Print the maximum elements for each window separated by spaces as output.

Sample Test Cases:
Input 1:
arr[1, 2, 3, 1, 4, 5, 2, 3, 6] = , k = 3
Output 1:
3 3 4 5 5 5 6

Input 2:
arr[5, 1, 3, 4, 2] = , k = 1
Output 2:
5 1 3 4 2
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
    int k = 1;

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
        char *k_ptr = strstr(close_br, "k");
        if (!k_ptr) k_ptr = strstr(buf, "k =");
        if (k_ptr) 
        {
            while (*k_ptr && !isdigit(*k_ptr) && *k_ptr != '-') k_ptr++;
            if (*k_ptr) k = atoi(k_ptr);
        }
    } 
    else 
    {
        char *p = buf;
        int vals[1000], vcount = 0;
        while (*p) 
        {
            while (*p && !isdigit(*p) && *p != '-') p++;
            if (!*p) break;
            vals[vcount++] = strtol(p, &p, 10);
        }
        if (vcount > 1) 
        {
            k = vals[vcount - 1];
            n = vcount - 1;
            for (int i = 0; i < n; i++) arr[i] = vals[i];
        }
    }

    if (k > n || n == 0 || k <= 0) 
    {
        return 0;
    }

    for (int i = 0; i <= n - k; i++) 
    {
        int max_val = arr[i];
        for (int j = 1; j < k; j++) 
        {
            if (arr[i + j] > max_val) 
            {
                max_val = arr[i + j];
            }
        }
        if (i > 0) printf(" ");
        printf("%d", max_val);
    }
    printf("\n");
    return 0;
}
