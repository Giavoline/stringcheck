
#include <stdio.h>

#include "stringcheck.h"

int main(void)
{
    printf("StringCheck %s\n", sc_version());

    printf("compare(\"abc\", \"abc\") = %d\n",
           sc_compare("abc", "abc"));

    return 0;
}
