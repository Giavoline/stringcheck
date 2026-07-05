#include <string.h>

#include "config.h"
#include "levenshtein.h"

static inline int min3(int a, int b, int c)
{
    int m = (a < b) ? a : b;
    return (m < c) ? m : c;
}

int sc_levenshtein(const char *a, const char *b)
{
    size_t i, j;
    size_t len_a = strlen(a);
    size_t len_b = strlen(b);

    int previous[SC_MAX_LINE_LENGTH + 1];
    int current[SC_MAX_LINE_LENGTH + 1];

    if (len_a > SC_MAX_LINE_LENGTH ||
    len_b > SC_MAX_LINE_LENGTH)
    return -1;

    /* Initialize first row */
    for (j = 0; j <= len_b; j++)
        previous[j] = (int)j;

    for (i = 1; i <= len_a; i++)
    {
        current[0] = (int)i;

        for (j = 1; j <= len_b; j++)
        {
            int cost = (a[i - 1] == b[j - 1]) ? 0 : 1;

            current[j] = min3(
                previous[j] + 1,
                current[j - 1] + 1,
                previous[j - 1] + cost);
        }

        for (j = 0; j <= len_b; j++)
            previous[j] = current[j];
    }

    return previous[len_b];
}

