#include <stdio.h>

enum Colors 
{
    RED,
    YELLOW,
    GREEN,
    COLOR_COUNT
};

int main() 
{
    const char *names[] = {"RED", "YELLOW", "GREEN"};

    for (int i = 0; i < COLOR_COUNT; i++) 
    {
        printf("%s=%d\n", names[i], i);
    }
    return 0;
}
