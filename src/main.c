#include <stdio.h>
#include "stringcheck.h"

int main(void)
{
    printf("StringCheck %d.%d\n",
           STRINGCHECK_VERSION_MAJOR,
           STRINGCHECK_VERSION_MINOR);

    return 0;
}
