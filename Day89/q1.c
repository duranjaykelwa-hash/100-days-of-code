#include <stdio.h>

enum OperationStatus 
{
    SUCCESS,
    FAILURE,
    TIMEOUT
};

int main() 
{
    enum OperationStatus s1 = SUCCESS;
    enum OperationStatus s2 = FAILURE;
    enum OperationStatus s3 = TIMEOUT;

    printf("SUCCESS=%d, FAILURE=%d, TIMEOUT=%d\n", s1, s2, s3);
    return 0;
}
