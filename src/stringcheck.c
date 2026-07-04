
#include <string.h>

#include "stringcheck.h"

int sc_compare(const char *left, const char *right)
{
    if (left == NULL || right == NULL)
        return SC_ERROR;

    return strcmp(left, right);
}

sc_result sc_validate(const char *text)
{
    if (text == NULL)
        return SC_ERROR;

    return SC_OK;
}
