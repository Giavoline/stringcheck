#include <ctype.h>
#include "accents.h"
#include "normalize.h"



static char ascii_tolower(char c)
{
    if (c >= 'A' && c <= 'Z')
        return c + ('a' - 'A');

    return c;
}

static void fold_word_initial_case(char *text)
{
    int new_word = 1;

    while (*text)
    {
        if (*text == ' ')
        {
            new_word = 1;
        }
        else
        {
            if (new_word)
            {
                *text = (char)ascii_tolower((unsigned char)*text);
                new_word = 0;
            }
        }

        text++;
    }

}

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
    fold_word_initial_case(text);
}
