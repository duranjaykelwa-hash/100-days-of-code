#include <stdio.h>
#include <string.h>
#include <ctype.h>

enum TrafficLight 
{
    RED,
    YELLOW,
    GREEN
};

int main() 
{
    char input[50];
    if (scanf("%49s", input) != 1) 
    {
        strcpy(input, "GREEN");
    }

    for (int i = 0; input[i]; i++) 
    {
        input[i] = (char)toupper((unsigned char)input[i]);
    }

    enum TrafficLight light = GREEN;
    if (strstr(input, "RED")) 
    {
        light = RED;
    } 
    else if (strstr(input, "YELLOW")) 
    {
        light = YELLOW;
    } 
    else 
    {
        light = GREEN;
    }

    switch (light) 
    {
        case RED:
            printf("Stop\n");
            break;
        case YELLOW:
            printf("Wait\n");
            break;
        case GREEN:
            printf("Go\n");
            break;
    }
    return 0;
}
