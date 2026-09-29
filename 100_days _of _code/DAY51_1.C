#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findFirst(int arr[], int n, int target) 
{
    int low = 0, high = n - 1, res = -1;
    while (low <= high) 
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) 
        {
            res = mid;
            high = mid - 1;
        } 
        else if (arr[mid] < target) 
        {
            low = mid + 1;
        } 
        else 
        {
            high = mid - 1;
        }
    }
    return res;
}

int findLast(int arr[], int n, int target) 
{
    int low = 0, high = n - 1, res = -1;
    while (low <= high) 
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) 
        {
            res = mid;
            low = mid + 1;
        } 
        else if (arr[mid] < target) 
        {
            low = mid + 1;
        } 
        else 
        {
            high = mid - 1;
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
    int target = 0;

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
        char *tPtr = strstr(end, "target");
        if (!tPtr) tPtr = end;
        while (*tPtr && !((*tPtr >= '0' && *tPtr <= '9') || *tPtr == '-')) tPtr++;
        if (*tPtr) 
        {
            target = (int)strtol(tPtr, NULL, 10);
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
                target = temp[count - 1];
            } 
            else 
            {
                n = count - 1;
                for (int i = 0; i < n; i++) arr[i] = temp[i];
                target = temp[count - 1];
            }
        }
    }

    int first = findFirst(arr, n, target);
    int last = findLast(arr, n, target);

    printf("%d,%d\n", first, last);
    return 0;
}
