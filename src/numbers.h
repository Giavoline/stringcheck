#ifndef NUMBERS_H
#define NUMBERS_H

#include <stdbool.h>

bool sc_parse_leading_number(const char *text,
                             long *value,
                             const char **remainder);

#endif

