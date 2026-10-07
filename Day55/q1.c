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

    int majority = -1;
    for (int i = 0; i < n; i++) 
    {
        int count = 0;
        for (int j = 0; j < n; j++) 
        {
            if (arr[j] == arr[i]) 
            {
                count++;
            }
        }
        if (count > n / 2) 
        {
            majority = arr[i];
            break;
        }
    }

    printf("%d\n", majority);
    return 0;
}
