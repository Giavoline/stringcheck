#include <string.h>
#include "config.h"
#include "stringcheck.h"
#include "normalize.h"
#include "levenshtein.h"
#include "numbers.h"


static int compare_text(const char *a, const char *b)
{
/*    printf("A=[%s]\n", a);
    printf("B=[%s]\n", b);

    printf("distance=%d\n", sc_levenshtein(a, b));
*/
    return (sc_levenshtein(a, b) < 2)
           ? SC_MATCH
           : SC_DIFFERENT;
}
int sc_compare(char *a, char *b)
{
sc_normalize(a);
sc_normalize(b);
long key_value = -1;
long file_value = -1;
const char *key_remainder = NULL;
const char *file_remainder = NULL;
long ignored;


int kbd_has_number = sc_parse_leading_number(a,&key_value,&key_remainder);

if (kbd_has_number)
{
    int file_has_number = sc_parse_leading_number(b,&ignored,&file_remainder);

    if (!file_has_number)
        return SC_DIFFERENT;

    if (key_value != file_value)
        return SC_DIFFERENT;

    return compare_text(key_remainder, file_remainder);
}

/* Keyboard line has no number */

sc_parse_leading_number(b, &ignored, &file_remainder);

return compare_text(a, file_remainder);
}

