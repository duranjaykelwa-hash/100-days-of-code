#include <stdio.h>

int main() 
{
    int n, target;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1) return 0;

    int arr[100];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter target: ");
    scanf("%d", &target);

    int found = 0;
    for (int i = 0; i < n; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {
            if (arr[i] + arr[j] == target) 
            {
                printf("%d %d\n", i, j);
                found = 1;
                break;
            }
        }
        if (found) break;
    }

    if (!found) 
    {
        printf("-1 -1\n");
    }

    return 0;
}
