/*
* https://leetcode.com/problems/find-the-difference/description/?envType=study-plan-v2&envId=programming-skills
*/

#include <stdio.h>
char
findTheDifference(char* s, char* t)
{
    char* w1ptr = s;
    char* w2ptr = t;
    int sum_s = 0, sum_t = 0;

    while(*w1ptr != '\0')
    {
        sum_s += *w1ptr++;
    }
    while(*w2ptr != '\0')
    {
        sum_t += *w2ptr++;
    }
    return sum_t - sum_s;
}


int
main(int argc, char *argv[])
{
    printf("%c\n", findTheDifference("abcd", "abcde"));
    return 0;
}
