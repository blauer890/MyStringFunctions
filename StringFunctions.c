#include <string.h>

int StrFreq(char *str, char ch)
{
    int count = 0;
    while(*str != '\0')
    {
        if(*str == ch)
        {
            count++;
        }
        str++;
    }
    return count;
}

void RemoveNonAbet(char *str)
{
    size_t i = 0;
    size_t srcLen = strlen(str);
    char temp[srcLen];

    char *strStart = str;
    while(*str != '\0')
    {
        if((*str >= 'A' && *str <= 'Z') ||
             (*str >= 'a' && *str <= 'z'))
        {
            temp[i] = *str;
            i++;
        }
        str++;
    }
    str = strStart;

    strcpy(str, temp);
}

size_t StringLen(char *str)
{
    size_t size = 0;
    while(*str != '\0')
    {
        size++;
        str++;
    }
    return size;
}

void StringCat(char *dest, char *src)
{
    size_t initDestSize = strlen(dest);
    for(size_t i = 0; i < strlen(src); i++)
    {
        dest[i + initDestSize] = src[i];
    }
}

void StringCopy(char *dest, char *src)
{
    size_t index = 0;

    char *srcStart = src;
    while(*src != '\0')
    {
        dest[index] = *src;
        index++;
        src++;
    }
    src = srcStart;

    dest[strlen(src)] = '\0';
}

char *StringString(char *haystack, const char *needle)
{
    size_t haySize = strlen(haystack);
    size_t needleSize = strlen(needle);

    size_t j = 0;
    for(size_t i = 0; i < haySize; i++)
    {
        j = i;
        while((j < haySize) &&
              ((j - i) < needleSize) &&
              (haystack[j] == needle[j - i]))
        {
            j++;
        }

        if((j - i) == needleSize)
        {
            return &haystack[i];
        }
    }
    return NULL;
}
