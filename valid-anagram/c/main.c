/*
    https://neetcode.io/problems/is-anagram/question?list=blind75
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char c;
    int count;
} Counter;

typedef struct {
    int size;
    Counter counts[];
} Map;

void
initMap(Map* m, int arrsize)
{
    Counter count = { .c='\0', .count=0};
    for (int i = 0; i < arrsize; i++)
    {
        m->counts[i] = count;
    }
    m->size = arrsize;
}

void
fillMap(Map* m, char* c)
{
    for (int strIndex = 0; strIndex < strlen(c); strIndex++)
    {
        for(int countsIndex = 0; countsIndex < m->size; countsIndex++)
        {
            int isEqual = m->counts[countsIndex].c == c[strIndex];
            if (isEqual)
            {
                m->counts[countsIndex].count++;
            }
        }
    }
}

void
printMap(Map* m)
{
    for(int i = 0; i<m->size; i++)
    {
        printf("char: %c; count: %d\n", m->counts[i].c, m->counts[i].count);
    }
}

int
isAnagram(char* s, char* t)
{
    int ssize = strlen(s);
    int tsize = strlen(t);
    if (ssize != tsize) return 0;

    Map *m1 = malloc(sizeof(Map) + ssize*sizeof(Counter));
    Map *m2 = malloc(sizeof(Map) + tsize*sizeof(Counter));
    fillMap(m1, s);
    fillMap(m2, t);
    printMap(m1);
    printMap(m2);

    free(m1);
    free(m2);
    return 0;
}

int
main(int argc, char *argv[])
{
    int isTrue;
    isTrue = isAnagram("racecar", "carrace");
    printf("%s\n", isTrue ? "OK":"WRONG");

    isTrue = isAnagram("jar", "jam");
    printf("%s\n", isTrue ? "OK":"WRONG");
    return 0;
}
