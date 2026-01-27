#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char*
mergeAlternately(char* word1, char* word2)
{
    char* merged = malloc(strlen(word1) + strlen(word2) + 1);
    char* charAdderPtr = merged;
    char* p1 = word1;
    char* p2 = word2;
    int p1Running = 1; 
    int p2Running = 1; 

    while(p1Running || p2Running)
    {
        p1Running = !(*p1 == '\0');
        p2Running = !(*p2 == '\0');
        if(p1Running)*charAdderPtr++ = *p1++;
        if(p2Running)*charAdderPtr++ = *p2++;
    }
    *charAdderPtr = '\0';
    return merged;
}


int
main(int argc, char *argv[])
{
    char* test1 = mergeAlternately("abc", "pqr");
    printf("%s\n", test1);

    char* test2 = mergeAlternately("ab", "pqrs");
    printf("%s\n", test2);

    return 0;
}
