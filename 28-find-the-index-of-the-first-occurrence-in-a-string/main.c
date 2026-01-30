/*
* https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/?envType=study-plan-v2&envId=programming-skills
*/

#include <stdio.h>

int Strlen(const char* str)
{
    const char* s;
    for (s = str; *s != '\0'; ++s) {}
    return(s - str);
}

int
strStr(char* haystack, char* needle)
{
    int index = 0;
    // i copy the pointers se we don't destroy the pointer they sent :)
    char* hptr = haystack;
    if (Strlen(needle) > Strlen(haystack))
    {
        return -1;
    }

    // loop until the end of haystack
    while (*hptr != '\0')
    {
        // reset the needle pointer
        char* nptr = needle;
        // loop until we reach the end of the needle
        while (*nptr != '\0')
        {
            // if chars differ, it's not the needle we seek
            if(*nptr != *hptr) 
            {
                break;
            }
            // advance both
            nptr++;
            hptr++;
        }
        // if the break above wasn't reached, then we found the needle inside
        // the haystack. So nptr reached the end of the string.
        if(*nptr == '\0')
        {
            return index;
        }
        index++;
        hptr = haystack + index;
    }
    return -1;
}


int
main(int argc, char *argv[])
{
    printf("index=%d\n", strStr("sadbutsad", "sad"));
    printf("%d\n", strStr("leetcode", "leeto"));
    printf("%d\n", strStr("mississippi", "issip"));

    return 0;
}
