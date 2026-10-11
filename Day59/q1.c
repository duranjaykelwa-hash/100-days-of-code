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

    if (k > n || k <= 0) 
    {
        printf("0\n");
        return 0;
    }

    int current_sum = 0;
    for (int i = 0; i < k; i++) 
    {
        current_sum += arr[i];
    }

    int max_sum = current_sum;
    for (int i = k; i < n; i++) 
    {
        current_sum += arr[i] - arr[i - k];
        if (current_sum > max_sum) 
        {
            max_sum = current_sum;
        }
    }

    printf("%d\n", max_sum);
    return 0;
}
