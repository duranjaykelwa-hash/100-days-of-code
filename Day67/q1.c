#include <stdio.h>

int main() 
{
    int m, n;
    printf("Enter size of first array: ");
    if (scanf("%d", &m) != 1) return 0;

    int arr1[100];
    printf("Enter elements of first array: ");
    for (int i = 0; i < m; i++) 
    {
        scanf("%d", &arr1[i]);
    }

    printf("Enter size of second array: ");
    scanf("%d", &n);

    int arr2[100];
    printf("Enter elements of second array: ");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr2[i]);
    }

    int merged[200];
    int i = 0, j = 0, k = 0;
    while (i < m && j < n) 
    {
        if (arr1[i] <= arr2[j]) 
        {
            merged[k++] = arr1[i++];
        } 
        else 
        {
            merged[k++] = arr2[j++];
        }
    }

    while (i < m) 
    {
        merged[k++] = arr1[i++];
    }
    while (j < n) 
    {
        merged[k++] = arr2[j++];
    }

    printf("Merged array: ");
    for (int x = 0; x < k; x++) 
    {
        printf("%d%s", merged[x], (x == k - 1) ? "" : " ");
    }
    printf("\n");

    return 0;
}
