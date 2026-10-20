#include <stdio.h>

int main() 
{
    int n;
    printf("Enter n (size of array): ");
    if (scanf("%d", &n) != 1) return 0;

    int arr[100];
    int sum = 0;
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    int total = n * (n + 1) / 2;
    printf("Missing number: %d\n", total - sum);

    return 0;
}
