#include <stdio.h>

#include "strutils.h"

/**
 * split string with separator. function is destructive for source pointer.
 */
int str_split(char **src, char *buff, char sep, size_t src_len, size_t buff_len)
{
    int i, shorter = src_len < buff_len ? src_len : buff_len;

    for (i = 0; i < shorter; i++)
    {
        if ((*src) == NULL || (*src)[0] == 0)
            break;
        if (*src[0] == sep)
        {
            /* skip separator */
            (*src)++;
            break;
        }
        
        buff[i] = *src[0];
        (*src)++;
    }
    buff[i] = 0;
    return i;
}

int   str_len(char *src, int src_len)
{
    int i;
    for (i = 0; i < src_len; i++)
    {
        if (src[i] == '\0')
        {
            return i;
        }
    }
    return src_len;
}

int   str_index(char *src, char search, size_t src_len)
{
    int i, src_actual_len;

    src_actual_len = str_len(src, src_len);
    
    for (i = 0; i < src_len || i < src_actual_len; i++)
    {
        if (src[i] == search)
        {
            return i;
        }
    }
    return -1;
}


char *str_trim(char *line, size_t max_len)
{
    int len;
    while (line[0] == ' ' && str_len(line, max_len) > 0)
    {
        line++;
    }
    
    len = str_len(line, max_len) - 1;

    while (line[len] == ' ' && len > 0)
    {
        line[len] = 0;
        len--;
    }

    return line;
}

