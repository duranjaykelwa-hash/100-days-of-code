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

    int max_so_far = arr[0];
    int current_max = arr[0];

    for (int i = 1; i < n; i++) 
    {
        if (current_max + arr[i] > arr[i]) 
        {
            current_max += arr[i];
        } 
        else 
        {
            current_max = arr[i];
        }

        if (current_max > max_so_far) 
        {
            max_so_far = current_max;
        }
    }

    printf("%d\n", max_so_far);
    return 0;
}
