#include <ctype.h>
#include "accents.h"
#include "normalize.h"

void sc_normalize(char *text)
{
    char *src = text;
    char *dst = text;
    int saw_space = 0;

    /* Skip leading whitespace */
    while (*src && isspace((unsigned char)*src))
        src++;

    while (*src)
    {
        if (isspace((unsigned char)*src))
        {
            saw_space = 1;
        }
        else
        {
            if (saw_space && dst != text)
                *dst++ = ' ';

            *dst++ = *src;
            saw_space = 0;
        }

        src++;
    }

    *dst = '\0';
    sc_convert_accents(text);
}
