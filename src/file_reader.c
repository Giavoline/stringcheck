#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool sc_read_next_line(FILE *fp, char *buffer)
{
	while (fgets(buffer, sizeof(buffer), fp)) {
            // Print each line to the standard output.
            if(strlen(buffer)>0) return true;
            else if(feof(fp)==EOF) return false;
	}
        return false;   
	}
