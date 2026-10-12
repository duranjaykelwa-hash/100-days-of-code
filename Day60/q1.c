#include <stdio.h>

int main() 
{
    int n, k;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1) return 0;

    int arr[100];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter k: ");
    scanf("%d", &k);

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
        printf("%d%s", max_val, (i == n - k) ? "" : " ");
    }
    printf("\n");

    return 0;
}
