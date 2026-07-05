#include <string.h>
#include "config.h"
#include "stringcheck.h"
#include "normalize.h"
#include "levenshtein.h"

static int compare_text(const char *a, const char *b)
{
    return sc_levenshtein(a, b) < 2 ? 0 : 1;
}

int sc_compare(const char *left, const char *right)
{
    char a[SC_MAX_LINE_LENGTH];
    char b[SC_MAX_LINE_LENGTH];

    if (left == NULL || right == NULL)
        return SC_ERROR;

    strcpy(a, left);
    strcpy(b, right);

    sc_normalize(a);
    sc_normalize(b);

    return compare_text(a, b);
}
