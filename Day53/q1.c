#include <stdio.h>

int main() 
{
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1) return 0;

    int arr[100];
    int total_sum = 0;
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
        total_sum += arr[i];
    }

    int left_sum = 0;
    int pivot = -1;
    for (int i = 0; i < n; i++) 
    {
        if (left_sum == total_sum - left_sum - arr[i]) 
        {
            pivot = i;
            break;
        }
        left_sum += arr[i];
    }

    printf("%d\n", pivot);
    return 0;
}
