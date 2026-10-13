/*
Q111: Write a program to take an integer array arr and an integer k as inputs. The task is to find the first negative integer in each subarray of size k moving from left to right. If no negative exists in a window, print "0" for that window. Print the results separated by spaces as output.

Sample Test Cases:
Input 1:
arr[] = [-8, 2, 3, -6, 10], k = 2
Output 1:
-8 0 -6 -6

Input 2:
arr[] = [12, -1, -7, 8, -15, 30, 16, 28], k = 3
Output 2:
-1 -1 -7 -15 -15 0

Input 3:
arr[] = [12, 1, 3, 5], k = 3
Output 3:
0 0
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

    // Find the bracket pair that actually contains numbers
    char *open_br = buf;
    char *chosen_open = NULL;
    char *chosen_close = NULL;
    while ((open_br = strchr(open_br, '[')) != NULL) 
    {
        char *close_br = strchr(open_br, ']');
        if (close_br && close_br > open_br + 1) 
        {
            int has_digit = 0;
            for (char *p = open_br; p < close_br; p++) 
            {
                if (isdigit(*p)) { has_digit = 1; break; }
            }
            if (has_digit) 
            {
                chosen_open = open_br;
                chosen_close = close_br;
                break;
            }
        }
        open_br++;
    }

    if (chosen_open && chosen_close) 
    {
        char *p = chosen_open + 1;
        while (p < chosen_close) 
        {
            while (p < chosen_close && (*p == ' ' || *p == ',')) p++;
            if (p >= chosen_close) break;
            arr[n++] = strtol(p, &p, 10);
        }
        char *k_ptr = strstr(chosen_close, "k");
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
        int first_neg = 0;
        for (int j = 0; j < k; j++) 
        {
            if (arr[i + j] < 0) 
            {
                first_neg = arr[i + j];
                break;
            }
        }
        if (i > 0) printf(" ");
        printf("%d", first_neg);
    }
    printf("\n");
    return 0;
}
