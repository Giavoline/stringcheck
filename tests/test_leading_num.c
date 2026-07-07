
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "numbers.h"

struct testcase
{
    const char *input;
    bool expected_found;
    long expected_value;
    const char *expected_remainder;
};

int main(void)
{
    struct testcase tests[] =
    {
        { "123 hello",  true, 123, "hello" },
        { "001 hello",  true,   1, "hello" },
        { "42",         true,  42, ""      },
        { "hello",      false,  0, "hello" },
        { "",           false,  0, ""      },
        { "   55 abc",  true,  55, "abc"   },
	{ "0 hello",      true, 0, "hello" },
        { "0000 hello",   true, 0, "hello" },
        { "999999 hello", true, 999999, "hello" },
	{ "123hello", true, 123, "hello" }
    };

    int failures = 0;

    for (size_t i = 0; i < sizeof(tests)/sizeof(tests[0]); i++)
    {
        long value = -1;
        const char *remainder = NULL;

        bool found = sc_parse_leading_number(
                        tests[i].input,
                        &value,
                        &remainder);

        if (found != tests[i].expected_found)
        {
            printf("FAIL: \"%s\"\n", tests[i].input);
            printf("    expected found=%d got=%d\n",
                   tests[i].expected_found,
                   found);
            failures++;
            continue;
        }

        if (found)
        {
            if (value != tests[i].expected_value)
            {
                printf("FAIL: \"%s\"\n", tests[i].input);
                printf("    expected value=%ld got=%ld\n",
                       tests[i].expected_value,
                       value);
                failures++;
                continue;
            }
        }

        if (strcmp(remainder, tests[i].expected_remainder) != 0)
        {
            printf("FAIL: \"%s\"\n", tests[i].input);
            printf("    expected remainder=\"%s\"\n",
                   tests[i].expected_remainder);
            printf("    got=\"%s\"\n", remainder);
            failures++;
            continue;
        }

        printf("PASS: \"%s\"\n", tests[i].input);
    }

    printf("\n%d failure(s)\n", failures);

    return failures != 0;
}
