#include <string.h>

#include "accents.h"

static void emit_utf8(char **dst, const char *utf8)
{
    while (*utf8)
        *(*dst)++ = *utf8++;
}

void sc_convert_accents(char *text)
{
    char buffer[2048];
    char *dst = buffer;
    const char *src = text;

    while (*src)
    {
        if (src[1] == '\'' || src[1] == '`')
        {
            switch (*src)
            {
            case 'a':
                emit_utf8(&dst, "à");
                src += 2;
                continue;

            case 'e':
                if (src[1] == '\'')
                    emit_utf8(&dst, "é");
                else
                    emit_utf8(&dst, "è");
                src += 2;
                continue;

            case 'i':
                emit_utf8(&dst, "ì");
                src += 2;
                continue;

            case 'o':
                emit_utf8(&dst, "ò");
                src += 2;
                continue;

            case 'u':
                emit_utf8(&dst, "ù");
                src += 2;
                continue;
            }
        }

        *dst++ = *src++;
    }

    *dst = '\0';

    strcpy(text, buffer);
}

