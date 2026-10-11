/*
Q109: Write a program to take an integer array arr and an integer k as inputs. Print the maximum sum of all the subarrays of size k.

Sample Test Cases:
Input 1:
arr[100, 200, 300, 400] = , k = 2
Output 1:
700

Input 2:
arr[1, 4, 2, 10, 23, 3, 1, 0, 20] = , k = 4
Output 2:
39

Input 3:
arr[100, 200, 300, 400] = , k = 1
Output 3:
400
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
        printf("0\n");
        return 0;
    }

    long long current_sum = 0;
    for (int i = 0; i < k; i++) 
    {
        current_sum += arr[i];
    }
    long long max_sum = current_sum;

    for (int i = k; i < n; i++) 
    {
        current_sum += arr[i] - arr[i - k];
        if (current_sum > max_sum) 
        {
            max_sum = current_sum;
        }
    }

    printf("%lld\n", max_sum);
    return 0;
}
