# include <stdio.h>
# include <stdlib.h>
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

void file_from_text(const char * filename, const char *content) {

    if (file_exists(filename)) {

        printf("File already exists.\n");
        exit(1);
    }

    FILE *file = fopen(filename, "w");
    if (file == NULL) {

        printf("Failed creating file.\n");
        exit(1);
    }

    fprintf(file, "%s", content);
    fclose(file);
}
