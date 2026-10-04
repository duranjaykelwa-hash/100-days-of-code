#include <stdio.h>

int main() 
{
    int n, x;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1) return 0;

    int arr[100];
    printf("Enter sorted elements: ");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter x: ");
    scanf("%d", &x);

    int ceil_idx = -1;
    for (int i = 0; i < n; i++) 
    {
        if (arr[i] >= x) 
        {
            ceil_idx = i;
            break;
        }
    }

    printf("%d\n", ceil_idx);
    return 0;
}
