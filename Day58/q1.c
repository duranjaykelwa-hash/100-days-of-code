#include <stdio.h>

int main() 
{
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1) return 0;

    int arr[100];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    int ans[100];
    for (int i = 0; i < n; i++) 
    {
        int prod = 1;
        for (int j = 0; j < n; j++) 
        {
            if (i != j) 
            {
                prod *= arr[j];
            }
        }
        ans[i] = prod;
    }

    printf("[");
    for (int i = 0; i < n; i++) 
    {
        printf("%d%s", ans[i], (i == n - 1) ? "" : ",");
    }
    printf("]\n");

    return 0;
}
