#include <stdio.h>

int
Strlen(const char* str)
{
    const char* s;
    for (s = str; *s != '\0'; ++s) {}
    return(s - str);
}

char *strcpy(char *dest, const char *src)
{
   char *save = dest;
   while(*dest)
   {
        *dest++ = *src++;
   }
   return save;
}

void
slice(const char* str, char* result, size_t start, size_t end)
{
    strcpy(result, str + start, end - start);
}

char*
longestCommonPrefix(char** strs, int strsSize)
{
    int maxIndex = Strlen(strs[0]);
    
    for (int i = 1;
        i < strsSize;
        i++)
    {

        int j = 0; 
        while(j < Strlen(strs[i]) &&
            strs[i][j] == strs[0][j])
        {
            j++;
        }
        maxIndex = maxIndex > j? maxIndex : j; 
    }

}

int main(int argc, char *argv[])
{
    char* strs[] = {"flower","flow","flight"};
    printf("%s", longestCommonPrefix(strs, 3));
    return 0;
}
