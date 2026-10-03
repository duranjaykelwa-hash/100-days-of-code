#include <stdio.h>

int main() 
{
    int n, target;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1) return 0;

    int arr[100];
    printf("Enter sorted elements: ");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter target: ");
    scanf("%d", &target);

    int first = -1, last = -1;
    for (int i = 0; i < n; i++) 
    {
        if (arr[i] == target) 
        {
            if (first == -1) 
            {
                first = i;
            }
            last = i;
        }
    }

    if (first == -1) 
    {
        printf("-1, -1\n");
    } 
    else 
    {
        printf("%d, %d\n", first, last);
    }

    return 0;
}
