#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findCeil(int arr[], int n, int x) 
{
    int low = 0, high = n - 1, res = -1;
    while (low <= high) 
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= x) 
        {
            res = mid;
            high = mid - 1;
        } 
        else 
        {
            low = mid + 1;
        }
    }
    return res;
}

int main() 
{
    char buf[4096];
    int bytesRead = 0;
    int c;
    while ((c = getchar()) != EOF && bytesRead < (int)sizeof(buf) - 1) 
    {
        buf[bytesRead++] = (char)c;
    }
    buf[bytesRead] = '\0';

    int arr[1000];
    int n = 0;
    int x = 0;

    char *start = strchr(buf, '[');
    char *end = strchr(buf, ']');

    if (start && end && end > start) 
    {
        char *p = start + 1;
        while (p < end) 
        {
            while (p < end && (*p == ' ' || *p == ',')) p++;
            if (p < end && ((*p >= '0' && *p <= '9') || *p == '-')) 
            {
                char *nextP;
                arr[n++] = (int)strtol(p, &nextP, 10);
                p = nextP;
            } 
            else 
            {
                p++;
            }
        }
        char *xPtr = strstr(end, "x");
        if (!xPtr) xPtr = end;
        while (*xPtr && !((*xPtr >= '0' && *xPtr <= '9') || *xPtr == '-')) xPtr++;
        if (*xPtr) 
        {
            x = (int)strtol(xPtr, NULL, 10);
        }
    } 
    else 
    {
        int temp[1000];
        int count = 0;
        char *p = buf;
        while (*p) 
        {
            while (*p && !((*p >= '0' && *p <= '9') || *p == '-')) p++;
            if (!*p) break;
            char *nextP;
            temp[count++] = (int)strtol(p, &nextP, 10);
            p = nextP;
        }
        if (count >= 2) 
        {
            if (temp[0] == count - 2) 
            {
                n = temp[0];
                for (int i = 0; i < n; i++) arr[i] = temp[i + 1];
                x = temp[count - 1];
            } 
            else 
            {
                n = count - 1;
                for (int i = 0; i < n; i++) arr[i] = temp[i];
                x = temp[count - 1];
            }
        }
    }

    int ans = findCeil(arr, n, x);
    printf("%d\n", ans);
    return 0;
}
