#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to skip certain characters


int main(int argc, char *argv[])
{
    int valid = 1;

    for (int i = 1; i < argc; i++)
    {
        if (not_number(argv[i]))
        {
            printf("Error: '%s' is not a valid number.\n", argv[i]);
            valid = 0;
        }
    }

    if (valid)
    {
        printf("All inputs are valid numbers.\n");
    }

    return 0;
}
