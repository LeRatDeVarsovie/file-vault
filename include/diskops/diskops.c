# include <stdio.h>
# include <stdbool.h>

bool file_exists(const char *filename) {

    FILE *file = fopen(filename, "r");
    if (file) {

        fclose(file);
        return true;
    } else {

        return false;
    }
}
