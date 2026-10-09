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

    for (int i = 0; i < n; i++) 
    {
        int prev_greater = -1;
        for (int j = i - 1; j >= 0; j--) 
        {
            if (arr[j] > arr[i]) 
            {
                prev_greater = arr[j];
                break;
            }
        }
        if (i == n - 1) 
        {
            printf("%d\n", prev_greater);
        } 
        else 
        {
            printf("%d, ", prev_greater);
        }
    }

    return 0;
}
