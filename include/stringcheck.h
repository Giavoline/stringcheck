
#ifndef STRINGCHECK_H
#define STRINGCHECK_H

#ifdef __cplusplus
extern "C" {
#endif

const char *sc_version(void);

/* Return codes */
typedef enum
{
    SC_OK = 0,
    SC_ERROR = -1
} sc_result;

/* Compare two strings. */
int sc_compare(const char *left, const char *right);

/* Check whether a string is valid. */
sc_result sc_validate(const char *text);

#ifdef __cplusplus
}
#endif

#endif
