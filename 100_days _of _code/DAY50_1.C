#include <stdio.h>

int main() 
{
    char dateStr[100];
    if (scanf("%s", dateStr) != 1) return 0;

    int day, month, year;
    if (sscanf(dateStr, "%d/%d/%d", &day, &month, &year) != 3) return 0;

    const char *months[] = {
        "", "Jan", "Feb", "Mar", "Apr", "May", "Jun",
        "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };

    if (month >= 1 && month <= 12) 
    {
        printf("%02d-%s-%04d\n", day, months[month], year);
    }

    return 0;
}
