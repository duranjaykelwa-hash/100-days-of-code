#include <stdio.h>

int main() 
{
    int n;
    printf("Enter n: ");
    if (scanf("%d", &n) != 1) return 0;

    int total_sum = n * (n + 1) / 2;
    int pivot = -1;

    for (int x = 1; x <= n; x++) 
    {
        int left_sum = x * (x + 1) / 2;
        int right_sum = total_sum - left_sum + x;
        if (left_sum == right_sum) 
        {
            pivot = x;
            break;
        }
    }

    printf("%d\n", pivot);
    return 0;
}
