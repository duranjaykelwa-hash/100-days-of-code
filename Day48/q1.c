#include <stdio.h>
#include <string.h>

int main() 
{
    char s1[1000], s2[1000];
    if (scanf("%s %s", s1, s2) != 2) return 0;

    int len1 = strlen(s1);
    int len2 = strlen(s2);

    if (len1 != len2) 
    {
        printf("Not rotation\n");
        return 0;
    }

    char temp[2005];
    strcpy(temp, s1);
    strcat(temp, s1);

    if (strstr(temp, s2) != NULL) 
    {
        printf("Rotation\n");
    } 
    else 
    {
        printf("Not rotation\n");
    }

    return 0;
}
