#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
{
    char buf[1024];
    char name[100] = "Rahul";
    int age = 23;

    if (fgets(buf, sizeof(buf), stdin)) 
    {
        char *n_ptr = strstr(buf, "Name:");
        char *a_ptr = strstr(buf, "Age:");
        if (n_ptr && a_ptr) 
        {
            sscanf(n_ptr, "Name: %[^,]", name);
            sscanf(a_ptr, "Age: %d", &age);
        }
        else 
        {
            sscanf(buf, "%99s %d", name, &age);
        }
    }

    FILE *fp = fopen("info.txt", "w");
    if (fp == NULL) 
    {
        printf("Error creating file!\n");
        return 1;
    }

    fprintf(fp, "Name: %s\nAge: %d\n", name, age);
    fclose(fp);

    printf("File created successfully! Data written to info.txt\n");
    return 0;
}
