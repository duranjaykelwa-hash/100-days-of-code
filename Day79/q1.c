#include <stdio.h>
#include <stdlib.h>

int main() 
{
    FILE *fp = fopen("numbers.txt", "r");
    if (fp == NULL) 
    {
        fp = fopen("numbers.txt", "w");
        if (fp != NULL) 
        {
            fprintf(fp, "10 20 30 40 50");
            fclose(fp);
            fp = fopen("numbers.txt", "r");
        }
    }

    if (fp == NULL) 
    {
        printf("Error opening numbers.txt!\n");
        return 1;
    }

    int num, count = 0;
    long long sum = 0;
    while (fscanf(fp, "%d", &num) == 1) 
    {
        sum += num;
        count++;
    }

    fclose(fp);

    double avg = (count > 0) ? ((double)sum / count) : 0.0;
    printf("Sum = %lld\n", sum);
    printf("Average = %.2f\n", avg);
    return 0;
}
