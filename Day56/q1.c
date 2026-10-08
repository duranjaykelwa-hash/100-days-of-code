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
        int next_greater = -1;
        for (int j = i + 1; j < n; j++) 
        {
            if (arr[j] > arr[i]) 
            {
                next_greater = arr[j];
                break;
            }
        }
        if (i == n - 1) 
        {
            printf("%d\n", next_greater);
        } 
        else 
        {
            printf("%d, ", next_greater);
        }
    }

    return 0;
}
