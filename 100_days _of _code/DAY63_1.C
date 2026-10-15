/*
Q113: Write a program to take an integer array arr and an integer k as inputs. The task is to find the kth smallest element in the array. Print the kth smallest element as output.

Sample Test Cases:
Input 1:
arr[] = [10, 5, 4, 3, 48, 6, 2, 33, 53, 10], k = 4
Output 1:
5

Input 2:
arr[] = [7, 10, 4, 3, 20, 15], k = 3
Output 2:
7
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int cmp(const void *a, const void *b) 
{
    int ia = *(const int *)a;
    int ib = *(const int *)b;
    if (ia < ib) return -1;
    if (ia > ib) return 1;
    return 0;
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

    int arr[2000];
    int n = 0;
    int k = 1;

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

        // find k after close bracket
        char *k_ptr = strstr(close_br, "k");
        if (k_ptr) 
        {
            while (*k_ptr && !isdigit(*k_ptr) && *k_ptr != '-') k_ptr++;
            if (*k_ptr) k = atoi(k_ptr);
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
        if (n > 1) 
        {
            k = arr[n - 1];
            n--;
        }
    }

    if (n == 0 || k < 1 || k > n) return 0;

    qsort(arr, n, sizeof(int), cmp);
    printf("%d\n", arr[k - 1]);
    return 0;
}
