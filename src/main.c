#include <stdio.h>
#include <stdlib.h>

#include "stringcheck.h"

static void usage(const char *progname)
{
    fprintf(stderr,
            "Usage: %s STRING1 STRING2\n",
            progname);
}

int main(int argc, char *argv[])
{
    int result;

    if (argc != 3)
    {
        usage(argv[0]);
        return 2;
    }

    result = sc_compare(argv[1], argv[2]);

    if (result == 0)
    {
        puts("MATCH");
        return 0;
    }

    puts("DIFFERENT");
    return 1;
}
