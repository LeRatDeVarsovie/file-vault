# ifndef PASSWORD_H
# define PASSWORD_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>

void create_master_password(char *password);
bool check_password(char *password);

# endif // PASSWORD_H
