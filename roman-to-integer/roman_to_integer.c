#include <stdio.h>

int Strlen(const char* str)
{
    const char* s;
    for (s = str; *s != '\0'; ++s) {}
    return(s - str);
}

int
Char2Num(char c)
{
    switch (c)
    {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

int
main(int argc, char *argv[])
{
    int Result = 0;
    // Get the string.
    char* Roman = argv[1];
    int StringSize = Strlen(Roman);

    printf("ROMAN: %s\n", Roman);
    printf("SIZE: %d\n", StringSize);

    // Loop through it.
    for(int Index = 0;
        Index < StringSize;
        Index++)
    {
        printf("CHAR: %c\n", Roman[Index]);

        // Check if the next is inbounds.
        // If the current is lesser than next, subtract it.
        if(Index + 1 < StringSize &&
            Char2Num(Roman[Index+1]) > Char2Num(Roman[Index]))
        {
            Result -= Char2Num(Roman[Index]);
            printf("if: %c\n", Roman[Index]);
        }
        // Otherwise, sum it.
        else
        {
            Result += Char2Num(Roman[Index]);
        }
    }
    return Result;
}
