#include <ctype.h>
#include <stdlib.h>

#include "numbers.h"

bool sc_parse_leading_number(const char *text,
                             long *value,
                             const char **remainder)
{
    char *end;

    while (isspace((unsigned char)*text))
        text++;

    if (!isdigit((unsigned char)*text))
    {
        if (remainder)
            *remainder = text;
        return false;
    }

    *value = strtol(text, &end, 10);

    while (isspace((unsigned char)*end))
        end++;

    if (remainder)
        *remainder = end;

    return true;
}

