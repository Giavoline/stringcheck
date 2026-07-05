#include <stdio.h>

#include "levenshtein.h"

struct testcase
{
    const char *a;
    const char *b;
    int expected;
};

int main(void)
{
    struct testcase tests[] =
    {
        {"", "", 0},
        {"a", "a", 0},
        {"a", "b", 1},
        {"cat", "cats", 1},
        {"kitten", "sitting", 3},
        {"book", "back", 2},
        {"flaw", "lawn", 2},
    };

    int failures = 0;

    for (size_t i = 0; i < sizeof(tests)/sizeof(tests[0]); i++)
    {
        int d = sc_levenshtein(tests[i].a, tests[i].b);

        if (d != tests[i].expected)
        {
            printf("FAIL: \"%s\" \"%s\" -> %d (expected %d)\n",
                   tests[i].a,
                   tests[i].b,
                   d,
                   tests[i].expected);
            failures++;
        }
        else
        {
            printf("PASS: \"%s\" \"%s\" -> %d\n",
                   tests[i].a,
                   tests[i].b,
                   d);
        }
    }

    return failures != 0;
}

