#include <stdio.h>

enum Day 
{
    SUNDAY,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY
};

int main() 
{
    const char *names[] = {
        "SUNDAY", "MONDAY", "TUESDAY", "WEDNESDAY", "THURSDAY", "FRIDAY", "SATURDAY"
    };

    for (int d = SUNDAY; d <= SATURDAY; d++) 
    {
        printf("%s = %d\n", names[d], d);
    }
    return 0;
}
