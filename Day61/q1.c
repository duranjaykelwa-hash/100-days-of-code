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
        int first_neg = 0;
        for (int j = 0; j < k; j++) 
        {
            if (arr[i + j] < 0) 
            {
                first_neg = arr[i + j];
                break;
            }
        }
        printf("%d%s", first_neg, (i == n - k) ? "" : " ");
    }
    printf("\n");

    return 0;
}
