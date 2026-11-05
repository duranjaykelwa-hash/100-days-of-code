/*
Q134: Define an enum with SUCCESS, FAILURE, and TIMEOUT, and print messages accordingly.

Sample Test Cases:
Input 1:
FAILURE
Output 1:
Operation failed
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

enum Status 
{
    SUCCESS,
    FAILURE,
    TIMEOUT
};

int main() 
{
    char input[50];
    if (scanf("%49s", input) != 1) 
    {
        strcpy(input, "FAILURE");
    }

    for (int i = 0; input[i]; i++) 
    {
        input[i] = (char)toupper((unsigned char)input[i]);
    }

    enum Status status = FAILURE;
    if (strstr(input, "SUCCESS")) status = SUCCESS;
    else if (strstr(input, "TIMEOUT")) status = TIMEOUT;
    else status = FAILURE;

    switch (status) 
    {
        case SUCCESS:
            printf("Operation successful\n");
            break;
        case FAILURE:
            printf("Operation failed\n");
            break;
        case TIMEOUT:
            printf("Operation timed out\n");
            break;
    }
    return 0;
}
