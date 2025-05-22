# ifndef DISKOPS_H
# define DISKOPS_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

bool file_exists(const char *filename);
void file_from_text(const char * filename, const char *content);

# endif // DISKOPS_H
