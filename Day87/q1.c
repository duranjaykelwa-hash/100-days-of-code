#include <stdio.h>
#include <string.h>
#include <ctype.h>

enum UserRole 
{
    ADMIN,
    USER,
    GUEST
};

int main() 
{
    char role_str[50];
    if (scanf("%49s", role_str) != 1) 
    {
        strcpy(role_str, "GUEST");
    }

    for (int i = 0; role_str[i]; i++) 
    {
        role_str[i] = (char)toupper((unsigned char)role_str[i]);
    }

    enum UserRole role = GUEST;
    if (strstr(role_str, "ADMIN")) role = ADMIN;
    else if (strstr(role_str, "USER")) role = USER;
    else role = GUEST;

    switch (role) 
    {
        case ADMIN:
            printf("Welcome Admin!\n");
            break;
        case USER:
            printf("Welcome User!\n");
            break;
        case GUEST:
            printf("Welcome Guest!\n");
            break;
    }
    return 0;
}
